target_precompile_headers(${PROJECT_NAME}  PRIVATE stl_private.hpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_EXPOSE_NATIVE_WIN32 GLFW_INCLUDE_NONE PUBLIC GLFW_PLATFORM)
target_link_libraries(${PROJECT_NAME}      PRIVATE glfw glad)
target_sources(${PROJECT_NAME}             PRIVATE platform_factory.cpp window.cpp window_callbacks.cpp context.cpp
                                                   platform.cpp)