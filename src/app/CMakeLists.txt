add_executable(${APP_PROJECT_NAME}
  main.cpp
  MainWindow.cpp
)

target_link_libraries(${APP_PROJECT_NAME}
  PRIVATE Qt6::Widgets
  HomeWidget
  TestingWidget
  ResultWidget
)

set_target_properties(${APP_PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)