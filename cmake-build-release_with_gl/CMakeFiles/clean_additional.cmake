# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/cp_cg_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/cp_cg_autogen.dir/ParseCache.txt"
  "cp_cg_autogen"
  )
endif()
