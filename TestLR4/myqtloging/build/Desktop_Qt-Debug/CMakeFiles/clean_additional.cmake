# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/myqtloging_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/myqtloging_autogen.dir/ParseCache.txt"
  "myqtloging_autogen"
  )
endif()
