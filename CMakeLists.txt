cmake_minimum_required(VERSION 3.16)
project(whatever-pp VERSION 1.0 DESCRIPTION "A discord bot that does whatever :3")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(${PROJECT_NAME})

# TODO: Pull D++ if not found
find_package(DPP REQUIRED)

target_link_libraries(${PROJECT_NAME} 
    ${DPP_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${DPP_INCLUDE_DIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

add_subdirectory(src)
