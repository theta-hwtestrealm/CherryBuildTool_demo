cmake_minimum_required(VERSION 3.14)

project(CherryR_demo)

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "" FORCE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.10" CACHE STRING "" FORCE)
endif()

set(wxBUILD_SHARED OFF CACHE BOOL "Static build" FORCE)
set(wxBUILD_MONOLITHIC ON CACHE BOOL "Single library" FORCE)

include(FetchContent)

FetchContent_Declare(
  wxwidgets
  GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
  GIT_TAG        v3.3.2
)
FetchContent_MakeAvailable(wxwidgets)

add_executable(CherryR_demo main.cpp)
target_link_libraries(CherryR_demo PRIVATE wx::mono) # wx::net wx::core wx::base

if(WIN32)
    set_target_properties(CherryR_demo PROPERTIES 
        WIN32_EXECUTABLE TRUE
        LINK_FLAGS "/SUBSYSTEM:WINDOWS"
    )
endif()
