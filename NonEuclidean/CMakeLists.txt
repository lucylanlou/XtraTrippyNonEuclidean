set(PROJECT_NAME NonEuclidean)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "Camera.h"
    "Collider.h"
    "Engine.h"
    "FrameBuffer.h"
    "GameHeader.h"
    "Input.h"
    "Mesh.h"
    "Object.h"
    "Physical.h"
    "Resources.h"
    "Scene.h"
    "Shader.h"
    "Sky.h"
    "Sphere.h"
    "Texture.h"
    "Timer.h"
    "Vector.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Header_Files__GameObjects
    "Floorplan.h"
    "Ground.h"
    "House.h"
    "Pillar.h"
    "PillarRoom.h"
    "Player.h"
    "Portal.h"
    "Statue.h"
    "Tunnel.h"
)
source_group("Header Files\\GameObjects" FILES ${Header_Files__GameObjects})

set(Header_Files__Scenes
    "Level1.h"
    "Level2.h"
    "Level3.h"
    "Level4.h"
    "Level5.h"
    "Level6.h"
)
source_group("Header Files\\Scenes" FILES ${Header_Files__Scenes})

set(Source_Files
    "Camera.cpp"
    "Collider.cpp"
    "Engine.cpp"
    "FrameBuffer.cpp"
    "Input.cpp"
    "Main.cpp"
    "Mesh.cpp"
    "Object.cpp"
    "Physical.cpp"
    "Resources.cpp"
    "Shader.cpp"
    "Texture.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(Source_Files__GameObjects
    "Player.cpp"
    "Portal.cpp"
)
source_group("Source Files\\GameObjects" FILES ${Source_Files__GameObjects})

set(Source_Files__Scenes
    "Level1.cpp"
    "Level2.cpp"
    "Level3.cpp"
    "Level4.cpp"
    "Level5.cpp"
    "Level6.cpp"
)
source_group("Source Files\\Scenes" FILES ${Source_Files__Scenes})

set(ALL_FILES
    ${Header_Files}
    ${Header_Files__GameObjects}
    ${Header_Files__Scenes}
    ${Source_Files}
    ${Source_Files__GameObjects}
    ${Source_Files__Scenes}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE NonEuclidean)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()
################################################################################
# MSVC runtime library
################################################################################
get_property(MSVC_RUNTIME_LIBRARY_DEFAULT TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY)
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
        $<$<CONFIG:Debug>:
            MultiThreadedDebug
        >
        $<$<CONFIG:Release>:
            MultiThreaded
        >
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
        $<$<CONFIG:Debug>:
            MultiThreadedDebug
        >
        $<$<CONFIG:Release>:
            MultiThreaded
        >
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY_STR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../glew-2.1.0/include"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../glew-2.1.0/include"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "GLEW_STATIC;"
        "WIN32_LEAN_AND_MEAN;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "GLEW_STATIC;"
        "WIN32_LEAN_AND_MEAN;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /sdl;
            /W4;
            /WX;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR-;
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /sdl;
            /W4;
            /WX;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR-;
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG:FULL
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG:FULL
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "OpenGL32;"
        "glew32s"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "OpenGL32;"
        "glew32s"
    )
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

