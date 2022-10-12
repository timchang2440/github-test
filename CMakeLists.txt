cmake_minimum_required ( VERSION 3.0)

project(hello)

include_directories(${CMAKE_CURRENT_LIST_DIR}/input)
include_directories(${CMAKE_CURRENT_LIST_DIR}/output)

#link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/input input_src)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/output output_src)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src test_src)

add_executable(${PROJECT_NAME} ${test_src} ${input_src} ${output_src})
