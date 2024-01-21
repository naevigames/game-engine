project(platform)

option(USE_GLFW_PLATFORM "use glfw platform" OFF)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl_public.hpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_sources(${PROJECT_NAME}          PRIVATE platform_manager.cpp window_manager.cpp)

if (USE_GLFW_PLATFORM)
    add_subdirectory(glfw)
endif()