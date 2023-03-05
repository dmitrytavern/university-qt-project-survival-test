set(LIBRARY_NAME AboutWidget)

add_library(${LIBRARY_NAME} STATIC
  AboutWidget.cpp
)

target_link_libraries(${LIBRARY_NAME}
  PRIVATE Qt6::Widgets
  AppComponents
)

set_target_properties(${LIBRARY_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)