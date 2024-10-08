# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\indexer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\indexer_autogen.dir\\ParseCache.txt"
  "indexer_autogen"
  )
endif()
