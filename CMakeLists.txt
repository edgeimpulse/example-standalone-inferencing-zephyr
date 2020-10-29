cmake_minimum_required(VERSION 3.13.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(example-standalone-inferencing-zephyr)

include(utils/cmake/utils.cmake)
# Needed for colorful output
zephyr_compile_options(-fdiagnostics-color=always)

# Use hardware acceleration for DSP and Neural Network code
# You'll need to disable these on non-Arm cores
add_definitions(-DEIDSP_USE_CMSIS_DSP=1
                -DEIDSP_LOAD_CMSIS_DSP_SOURCES=1
                -DEI_CLASSIFIER_TFLITE_ENABLE_CMSIS_NN=1
                -DEIDSP_QUANTIZE_FILTERBANK=0
                -DARM_MATH_LOOPUNROLL
                )

# Edge impulse SDK include directories
set(INCLUDES
    .
    src
    tflite-model
    model-parameters
    edge-impulse-sdk
    edge-impulse-sdk/third_party/ruy
    edge-impulse-sdk/third_party/gemmlowp
    edge-impulse-sdk/third_party/flatbuffers/include
    edge-impulse-sdk/third_party
    edge-impulse-sdk/tensorflow
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
RECURSIVE_FIND_FILE(MODEL_FILES "tflite-model" "*.cpp")
RECURSIVE_FIND_FILE(CC_FILES "edge-impulse-sdk" "*.cc")
RECURSIVE_FIND_FILE(S_FILES "edge-impulse-sdk" "*.s")
RECURSIVE_FIND_FILE(C_FILES "edge-impulse-sdk" "*.c")
list(APPEND SOURCE_FILES ${S_FILES})
list(APPEND SOURCE_FILES ${C_FILES})
list(APPEND SOURCE_FILES ${CC_FILES})
list(APPEND SOURCE_FILES ${MODEL_FILES})

# add all sources to the project
target_sources(app PRIVATE ${SOURCE_FILES})
target_sources(app PRIVATE src/main.cpp)
