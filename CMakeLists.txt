cmake_minimum_required(VERSION 3.14)

project(CherryR_demo)

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "x86_64" CACHE STRING "" FORCE) #"arm64;x86_64"
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

if(APPLE)
    set_target_properties(CherryR_demo PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.yourname.CherryR"
        MACOSX_BUNDLE_BUNDLE_NAME "CherryR"
        MACOSX_BUNDLE_BUNDLE_VERSION "1.0.0"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0"
    )
endif()
