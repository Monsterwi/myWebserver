set(http_SRCS
  HttpServer.cc
  HttpResponse.cc
  HttpContext.cc
  )

add_library(http ${http_SRCS})
target_link_libraries(http net)

install(TARGETS http DESTINATION lib)
set(HEADERS
  HttpContext.h
  HttpRequest.h
  HttpResponse.h
  HttpServer.h
  )
install(FILES ${HEADERS} DESTINATION include/libnet/net/http)

#if(LIBNET_BUILD_EXAMPLES)
#add_executable(httpserver_test tests/HttpServer_test.cc)
#target_link_libraries(httpserver_test libnet_http)
#
#if(BOOSTTEST_LIBRARY)
#add_executable(httprequest_unittest tests/HttpRequest_unittest.cc)
#target_link_libraries(httprequest_unittest libnet_http boost_unit_test_framework)
#endif()
#
#endif()

add_subdirectory(tests)
