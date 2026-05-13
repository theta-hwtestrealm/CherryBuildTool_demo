cmake_minimum_required(VERSION 3.14)

project(CherryR_demo)

if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.10" CACHE STRING "Target Yosemite" FORCE)
endif()

include(FetchContent)

FetchContent_Declare(
  wxwidgets
  GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
  GIT_TAG        v3.3.2
)
FetchContent_MakeAvailable(wxwidgets)

add_executable(CherryR_demo main.cpp)
target_link_libraries(CherryR_demo PRIVATE wx::net wx::core wx::base)

if(WIN32)
    set(wxUSE_WEBVIEW ON CACHE BOOL "Enable Webview")
    target_link_libraries(CherryR_demo PRIVATE comctl32 rpcrt4 winmm advapi32 wsock32 ws2_32)
endif()
