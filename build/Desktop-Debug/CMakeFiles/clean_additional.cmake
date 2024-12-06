# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/pngHandler_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/pngHandler_autogen.dir/ParseCache.txt"
  "pngHandler_autogen"
  )
endif()
