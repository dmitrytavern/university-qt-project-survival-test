add_executable(${APP_PROJECT_NAME}
  main.cpp
  MainWindow.cpp
)

target_link_libraries(${APP_PROJECT_NAME}
  PRIVATE Qt6::Widgets
  HomeWidget
  AboutWidget
  ResultWidget
  TestingWidget
)

set_target_properties(${APP_PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MinGW" OR CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_custom_command(TARGET ${APP_PROJECT_NAME} POST_BUILD
        COMMAND "${Qt6Core_DIR}/../../../bin/windeployqt.exe"         
                --verbose 1
                --release
                --no-svg
                --no-opengl
                --no-opengl-sw
                --no-translations
                --no-compiler-runtime
                --no-system-d3d-compiler
                \"$<TARGET_FILE:${APP_PROJECT_NAME}>\"
        COMMENT "Deploying Qt libraries using windeployqt for compilation target '${APP_PROJECT_NAME}' ..."
    )
endif()
