#--------------------------------------------------------------------------------

# Copyright 2009-2023 CLO Virtual Fashion. All rights reserved.

# Sample CMakeLists.txt file for ExportPlugin (Refined)

#--------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.20)

project(ExportPlugin
DESCRIPTION "Sample Export Plugin for CLO"

LANGUAGES CXX
)

#--------------------------------------------------------------------------------

# Qt Configuration

#--------------------------------------------------------------------------------

set(CMAKE_AUTOUIC ON)        # run uic on .ui files
set(CMAKE_AUTOMOC ON)        # run moc on Q\_OBJECT headers
set(CMAKE_AUTORCC ON)        # run rcc on .qrc files
set(CMAKE_INCLUDE_CURRENT_DIR ON)  # adds build dir (for ui\_\*.h) to include paths

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

#--------------------------------------------------------------------------------

# Target Definition

#--------------------------------------------------------------------------------
add_library(${PROJECT_NAME} SHARED
# Source files
ExportPlugin.cpp
ExportPlugin.h
Qt_file/mainwindow.cpp
Qt_file/mainwindow.h
Qt_file/mainwindow.ui
Qt_file/resources.qrc   
)

#--------------------------------------------------------------------------------

# Include Directories

#--------------------------------------------------------------------------------

# Pull in UIC-generated headers and CLO API headers

target_include_directories(${PROJECT_NAME} PRIVATE
${CMAKE_CURRENT_BINARY_DIR}/_autogen/include
../../CLOAPIInterface
)

#--------------------------------------------------------------------------------

# Find & Link Libraries

#--------------------------------------------------------------------------------

# Find CLO API Interface library

find_library(CLO_API_INTERFACE
NAMES CLOAPIInterface
PATHS ../../CLOAPIInterface/Lib
REQUIRED
)

# Link against Qt and CLO API

target_link_libraries(${PROJECT_NAME} PRIVATE
Qt5::Widgets
Qt5::Gui
Qt5::Core
${CLO_API_INTERFACE}
)

#--------------------------------------------------------------------------------

# Compiler & Build Settings

#--------------------------------------------------------------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES
CXX_STANDARD 11
CXX_STANDARD_REQUIRED ON
CXX_EXTENSIONS OFF
)

if(MSVC)
# Use MultiThreaded DLL runtime
set_target_properties(${PROJECT_NAME} PROPERTIES
MSVC_RUNTIME_LIBRARY "MultiThreadedDLL"
)
endif()

#--------------------------------------------------------------------------------

# Post-Build (macOS adjustments)
#--------------------------------------------------------------------------------
if(APPLE)
set(CMAKE_OSX_DEPLOYMENT_TARGET 12.0)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
COMMAND install_name_tool -change
"@rpath/libCLOAPIInterface.dylib"
"@executable_path/../Frameworks/libCLOAPIInterface.dylib"
"lib${PROJECT_NAME}.dylib"
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
endif()
if(MSVC)
    # Use MultiThreaded DLL runtime
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreadedDLL"
    )
    # Define export symbols for DLL build
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        UNICODE
        _WINDOWS
        _USRDLL
        BOMAPIDLL_EXPORTS
    )
endif()