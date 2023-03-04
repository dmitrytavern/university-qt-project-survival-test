set(LIBRARY_NAME TestingLayout)

add_library(${LIBRARY_NAME} STATIC
TestingLayout.cpp
)

target_link_libraries(${LIBRARY_NAME}
  PRIVATE Qt6::Widgets
)

set_target_properties(${LIBRARY_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)