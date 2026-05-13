include(FetchContent)
FetchContent_Declare(
  wxwidgets
  GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
  GIT_TAG        v3.3.2
)
FetchContent_MakeAvailable(wxwidgets)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE wx::net wx::core wx::base)
