include_directories(${PROJECT_SOURCE_DIR}/libnet/net)
set(src echo.cc main.cc)

add_executable(echo ${src})
target_link_libraries(echo net)