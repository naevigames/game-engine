target_link_libraries(${PROJECT_NAME}      PRIVATE glad)
target_precompile_headers(${PROJECT_NAME}  PRIVATE stl_private.hpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE PUBLIC OPENGL_API)
target_sources(${PROJECT_NAME}             PRIVATE commands.cpp)