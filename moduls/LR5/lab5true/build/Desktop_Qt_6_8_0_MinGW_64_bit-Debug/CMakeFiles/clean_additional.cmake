# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\applab5true_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\applab5true_autogen.dir\\ParseCache.txt"
  "applab5true_autogen"
  )
endif()
