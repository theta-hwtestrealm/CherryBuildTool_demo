cmake_minimum_required(VERSION 3.14)

project(prerun)

set(SOURCES
    prerun.cpp
)

set(wxBUILD_SHARED OFF CACHE BOOL "Static build" FORCE)
set(wxBUILD_MONOLITHIC ON CACHE BOOL "Single library" FORCE)

include(FetchContent)

FetchContent_Declare(
  cJSON
  GIT_REPOSITORY https://github.com/DaveGamble/cJSON
  GIT_TAG        v1.7.19
)

FetchContent_Declare(
  wxwidgets
  GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
  GIT_TAG        v3.3.2
)
FetchContent_MakeAvailable(cJSON wxwidgets)


add_executable(prerun ${SOURCES})

target_include_directories(prerun PRIVATE ${cjson_SOURCE_DIR})

target_link_libraries(prerun PRIVATE 
    wx::mono
    cjson
) # wx::net wx::core wx::base

if(WIN32)
    set_target_properties(prerun PROPERTIES 
        WIN32_EXECUTABLE TRUE
        LINK_FLAGS "/SUBSYSTEM:WINDOWS"
    )
endif()