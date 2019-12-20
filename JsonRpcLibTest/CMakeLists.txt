set (ProjectName "JsonRpcLibTest")

file (GLOB JsonRpcLibTest_src "*.cpp")

message("json11 bin directory: ${JSON11_BIN_DIR}")
link_directories(${JSON11_BIN_DIR})

add_executable(${ProjectName} ${JsonRpcLibTest_src})

source_group("" FILES ${JsonRpcLibTest_src})

include_directories(".")
include_directories("../JsonRpcLib/include")

add_dependencies(${ProjectName} ${JSON11_PROJECT_NAME})

target_link_libraries(${ProjectName} "JsonRpcLib")
target_link_libraries(${ProjectName} "json11.lib")
