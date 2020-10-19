zephyr_include_directories(.)

target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ei_classifier_porting.cpp)
target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/debug_log.cpp)
