cmake_minimum_required(VERSION 3.13.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(example-standalone-inferencing-zephyr)

include(utils/cmake/utils.cmake)
# Needed for colorful output
zephyr_compile_options(-fdiagnostics-color=always)

add_definitions(-DEIDSP_USE_CMSIS_DSP=1
				-DEIDSP_QUANTIZE_FILTERBANK=1
				-DARM_MATH_LOOPUNROLL
				-DEIDSP_PRINT_ALLOCATIONS=0
				-DEIDSP_TRACK_ALLOCATIONS=0
				-DEIDSP_USE_ASSERTS=1
				)

# Edge impulse SDK include directories
set(INCLUDES
	.
	src
	tflite-model
	model-parameters
	edge-impulse-sdk
	edge-impulse-sdk/porting
	edge-impulse-sdk/third_party/ruy
	edge-impulse-sdk/third_party/gemmlowp
	edge-impulse-sdk/third_party/flatbuffers/include
	edge-impulse-sdk/third_party
	edge-impulse-sdk/tensorflow/lite/schema
	edge-impulse-sdk/tensorflow/lite/micro/testing
	edge-impulse-sdk/tensorflow
	edge-impulse-sdk/dsp/speechpy
	edge-impulse-sdk/dsp/spectral
	edge-impulse-sdk/dsp/kissfft
	edge-impulse-sdk/dsp/dct
	edge-impulse-sdk/dsp
	edge-impulse-sdk/classifier
	edge-impulse-sdk/anomaly
	edge-impulse-sdk/CMSIS/NN/Include
	edge-impulse-sdk/CMSIS/DSP/PrivateInclude
	edge-impulse-sdk/CMSIS/DSP/Include
	edge-impulse-sdk/CMSIS/Core/Include
	)
include_directories(${INCLUDES})

RECURSIVE_FIND_FILE(SOURCE_FILES "edge-impulse-sdk" "*.cpp")
RECURSIVE_FIND_FILE(PORTING_FILES "porting/zephyr" "*.cpp")
RECURSIVE_FIND_FILE(MODEL_FILES "tflite-model" "*.cpp")
RECURSIVE_FIND_FILE(CC_FILES "edge-impulse-sdk" "*.cc")
RECURSIVE_FIND_FILE(S_FILES "edge-impulse-sdk" "*.s")
RECURSIVE_FIND_FILE(C_FILES "edge-impulse-sdk" "*.c")
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
add_subdirectory(porting/zephyr)

# add all sources to the project
target_sources(app PRIVATE ${SOURCE_FILES})
target_sources(app PRIVATE src/main.cpp)
