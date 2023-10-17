# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\StudentManagerSolution_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\StudentManagerSolution_autogen.dir\\ParseCache.txt"
  "StudentManagerSolution_autogen"
  )
endif()
