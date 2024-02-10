# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Chapter8_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Chapter8_autogen.dir\\ParseCache.txt"
  "Chapter8_autogen"
  )
endif()
