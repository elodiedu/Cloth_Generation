# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ExportPlugin_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ExportPlugin_autogen.dir\\ParseCache.txt"
  "ExportPlugin_autogen"
  )
endif()
