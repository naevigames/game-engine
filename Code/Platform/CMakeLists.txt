project(Platform)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl_public.hpp PRIVATE stl_private.hpp)

target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_INCLUDE_NONE)
target_compile_features(${PROJECT_NAME}    PUBLIC cxx_std_23)
target_link_libraries(${PROJECT_NAME}      PUBLIC glad PRIVATE glfw)

target_sources(${PROJECT_NAME} PRIVATE glfw/window.cpp glfw/platform.cpp platform_manager.cpp window/screen.cpp)