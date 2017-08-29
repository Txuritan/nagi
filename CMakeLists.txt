cmake_minimum_required (VERSION 3.2)

project (nagi VERSION 1.0.0 LANGUAGES C CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-ignored-attributes")

option (NAGI_PRINT_COMPILER "Prints out the compiler being used (used for release building)" OFF)

if (NAGI_PRINT_COMPILER)
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        message ("Clang")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        message ("GCC")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
        message ("Intel C++")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        message ("Visual Studio C++")
    endif ()
endif (NAGI_PRINT_COMPILER)

find_package (CURL REQUIRED)
include_directories (${CURL_INCLUDE_DIRS})

find_package(Lua51 REQUIRED)
include_directories(${LUA_INCLUDE_DIR})

find_package (PkgConfig REQUIRED)

pkg_check_modules (GTKMM REQUIRED gtkmm-3.0)

link_directories (${GTKMM_LIBRARY_DIRS})
include_directories (${GTKMM_INCLUDE_DIRS})
add_definitions (${GTKMM_CFLAGS_OTHER})

set (GLIB_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/nagi/gui/Resource.c)

_pkgconfig_invoke ("glib-2.0" GLIB2 PREFIX "" "--variable=prefix")
find_program (GLIB_COMPILE_RESOURCES
              NAMES glib-compile-resources
              HINTS ${GLIB2_PREFIX})
set (GCR_COMMAND "${GLIB_COMPILE_RESOURCES} --generate-source --sourcedir=${CMAKE_CURRENT_SOURCE_DIR}/data --target=${CMAKE_CURRENT_SOURCE_DIR}/src/nagi/gui/Resource.c ${CMAKE_CURRENT_SOURCE_DIR}/data/nagi.gresource.xml")
message (${GCR_COMMAND})
add_custom_command (
        OUTPUT ${GLIB_RESOURCES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data
        COMMAND ${GCR_COMMAND}
)

file (
        GLOB_RECURSE

        nagi_SRC

        src/*.*
)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-ignored-attributes")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-register -Wno-ignored-attributes")

if (WIN32)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-incompatible-ms-struct")
    add_executable (nagi WIN32 ${nagi_SRC})
    set_source_files_properties (Nagi.cpp PROPERTIES COMPILE_DEFINITIONS main=WinMain)
else ()
    add_executable (nagi ${nagi_SRC})
endif ()

target_link_libraries (nagi ${CURL_LIBRARIES} ${LUA_LIBRARIES} ${GTKMM_LIBRARIES})