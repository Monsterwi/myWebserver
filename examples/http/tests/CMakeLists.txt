include_directories(${PROJECT_SOURCE_DIR}/libnet/net)
include_directories(${PROJECT_SOURCE_DIR}/http)
add_executable(http_test HttpServer_test.cc)
target_link_libraries(http_test net http)



