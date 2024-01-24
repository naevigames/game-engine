target_precompile_headers(${PROJECT_NAME}  PRIVATE stl_private.hpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE PUBLIC GLFW_PLATFORM)
target_link_libraries(${PROJECT_NAME}      PRIVATE glfw)
target_sources(${PROJECT_NAME}             PRIVATE platform.cpp platform_factory.cpp window.cpp)