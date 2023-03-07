add_executable(${APP_EXECUTABLE_FILENAME}
  main.cpp
  MainWindow.cpp
)

target_link_libraries(${APP_EXECUTABLE_FILENAME}
  PRIVATE Qt6::Widgets
  HomeWidget
  AboutWidget
  ResultWidget
  TestingWidget
)

set_target_properties(${APP_EXECUTABLE_FILENAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
