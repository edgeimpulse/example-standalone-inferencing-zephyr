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
add_definitions(-DEI_CLASSIFIER_TFLITE_ENABLE_CMSIS_NN=1
                -DEIDSP_USE_CMSIS_DSP
                -DEIDSP_LOAD_CMSIS_DSP_SOURCES
                -DARM_MATH_LOOPUNROLL
                -DEI_PORTING_ZEPHYR=1
                -DEI_CLASSIFIER_HR_LIB=1
                )

# If using Nordic boards, add the following definition
# -DEI_NORDIC

# Add the Edge Impulse SDK
add_subdirectory(edge-impulse-sdk/cmake/zephyr)

# Edge impulse SDK include directories
set(INCLUDES
    .
    src
    tflite-model
    model-parameters
    )
include_directories(${INCLUDES})

RECURSIVE_FIND_FILE(MODEL_FILES "tflite-model" "*.cpp")
list(APPEND SOURCE_FILES ${MODEL_FILES})

# add all sources to the project
target_sources(app PRIVATE ${SOURCE_FILES})
target_sources(app PRIVATE src/main.cpp)

add_library(ei_hr_lib STATIC IMPORTED GLOBAL)
set_target_properties(ei_hr_lib PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/hr/lib/libhr.a)

target_link_libraries(ei_hr_lib INTERFACE app)
# Link the library in the main app
target_link_libraries(app PRIVATE ei_hr_lib)
