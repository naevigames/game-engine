find_package(Vulkan)

target_link_libraries(${PROJECT_NAME}      PRIVATE Vulkan::Vulkan)
target_precompile_headers(${PROJECT_NAME}  PRIVATE stl_private.hpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_WIN32_KHR PUBLIC VULKAN_API)
target_sources(${PROJECT_NAME}             PRIVATE instance.cpp surface.cpp physical_device.cpp)