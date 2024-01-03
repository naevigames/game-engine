project(Graphics)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl_public.hpp
                                          PRIVATE stl_private.hpp)
find_package(Vulkan)

target_compile_features(${PROJECT_NAME}    PUBLIC cxx_std_23)
target_compile_definitions(${PROJECT_NAME} PUBLIC VK_USE_PLATFORM_WIN32_KHR)
target_link_libraries(${PROJECT_NAME}      PUBLIC Vulkan::Vulkan glad)

target_sources(${PROJECT_NAME} PRIVATE gl/shader_stage.cpp gl/shader.cpp gl/buffer.cpp gl/vertex_array.cpp)
target_sources(${PROJECT_NAME} PRIVATE vk/instance.cpp)