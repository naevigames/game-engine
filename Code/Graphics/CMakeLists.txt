project(graphics)

option(USE_OPENGL_API "use opengl api" OFF)
option(USE_VULKAN_API "use vulkan api" OFF)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl_public.hpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

if (USE_OPENGL_API)
    add_subdirectory(gl)
endif()

if (USE_VULKAN_API)
    add_subdirectory(vk)
endif()