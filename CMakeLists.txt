cmake_minimum_required(VERSION 3.13.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(example-standalone-inferencing-nrf52-zephyr)

include(utils/cmake/utils.cmake)
# Needed for colorful output
zephyr_compile_options(-fdiagnostics-color=always)

add_definitions(-DEIDSP_USE_CMSIS_DSP=1
                -DEIDSP_QUANTIZE_FILTERBANK=1 
                -DARM_MATH_LOOPUNROLL 
                -DEIDSP_PRINT_ALLOCATIONS=0 
                -DEIDSP_TRACK_ALLOCATIONS=0 
				-DEIDSP_USE_ASSERTS=1)

# Edge impulse SDK include directories
set(INCLUDES 
    .
    src
	src/tflite-model
	src/model-parameters
	src/porting
	src/edge-impulse-sdk
	src/edge-impulse-sdk/third_party/ruy
	src/edge-impulse-sdk/third_party/gemmlowp
	src/edge-impulse-sdk/third_party/flatbuffers/include
	src/edge-impulse-sdk/third_party
	src/edge-impulse-sdk/tensorflow/lite/schema
	src/edge-impulse-sdk/tensorflow/lite/micro/testing
	src/edge-impulse-sdk/tensorflow
	src/edge-impulse-sdk/dsp/speechpy
	src/edge-impulse-sdk/dsp/spectral
	src/edge-impulse-sdk/dsp/kissfft
	src/edge-impulse-sdk/dsp/dct
	src/edge-impulse-sdk/dsp
	src/edge-impulse-sdk/classifier
	src/edge-impulse-sdk/anomaly
	src/edge-impulse-sdk/CMSIS/NN/Include
	src/edge-impulse-sdk/CMSIS/DSP/PrivateInclude
	src/edge-impulse-sdk/CMSIS/DSP/Include
	src/edge-impulse-sdk/CMSIS/Core/Include
	)
include_directories(${INCLUDES})

RECURSIVE_FIND_FILE(SOURCE_FILES "src/edge-impulse-sdk" "*.cpp")
RECURSIVE_FIND_FILE(PORTING_FILES "src/porting/zephyr" "*.cpp")
RECURSIVE_FIND_FILE(MODEL_FILES "src/tflite-model" "*.cpp")
RECURSIVE_FIND_FILE(CC_FILES "src/edge-impulse-sdk" "*.cc")
RECURSIVE_FIND_FILE(S_FILES "src/edge-impulse-sdk" "*.s")
RECURSIVE_FIND_FILE(C_FILES "src/edge-impulse-sdk" "*.c")
list(APPEND SOURCE_FILES ${S_FILES})
list(APPEND SOURCE_FILES ${C_FILES})
list(APPEND SOURCE_FILES ${CC_FILES})
list(APPEND SOURCE_FILES ${PORTING_FILES})
list(APPEND SOURCE_FILES ${MODEL_FILES})

# remove edge-impulse-sdk/porting files from project
set(EXCLUDE_DIR "/edge-impulse-sdk/porting/")
foreach (TMP_PATH ${SOURCE_FILES})
    string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
    if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
        list (REMOVE_ITEM SOURCE_FILES ${TMP_PATH})
    endif ()
endforeach(TMP_PATH)

# remove edge-impulse-sdk/ei_run_classifier_c files from project
set(EXCLUDE_DIR "ei_run_classifier_c")
foreach (TMP_PATH ${SOURCE_FILES})
    string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
    if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
        list (REMOVE_ITEM SOURCE_FILES ${TMP_PATH})
    endif ()
endforeach(TMP_PATH)

# remove edge-impulse-sdk/utensor files from project
set(EXCLUDE_DIR "/edge-impulse-sdk/utensor")
foreach (TMP_PATH ${SOURCE_FILES})
    string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
    if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
        list (REMOVE_ITEM SOURCE_FILES ${TMP_PATH})
    endif ()
endforeach(TMP_PATH)

# add porting files for zephyr
# additional CMake file in porting folder
add_subdirectory(src/porting/zephyr)

# add all sources to the project
target_sources(app PRIVATE ${SOURCE_FILES})
target_sources(app PRIVATE src/main.cpp)

