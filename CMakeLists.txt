cmake_minimum_required(VERSION 3.16)

project(pngHandler LANGUAGES CXX)

set(PNG_HANDLER_VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(pngHandler SHARED
    src/pngHandler.cpp
    src/alphaSeparation.cpp
    src/imageData.cpp

)

target_include_directories(pngHandler
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/pngHandler>    # Headers públicos
        $<INSTALL_INTERFACE:include>
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(pngHandler PROPERTIES VERSION ${PNG_HANDLER_VERSION} SOVERSION 1)

add_executable(pngHandlerTest main.cpp)

target_link_libraries(pngHandlerTest PRIVATE pngHandler)

install(TARGETS pngHandler
    EXPORT pngHandlerTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(FILES pngHandler.h DESTINATION include)
