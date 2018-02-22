cmake_minimum_required (VERSION 2.6)
project (HW2.5)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(USER hdamron)
set(COMP_DIR ${USER}/hw/02_05)

include_directories(include)

add_executable(test_complex
  src/test_complex.cc
  src/complex.cc
)

add_custom_target(compress
  COMMAND mkdir -p ${COMP_DIR}
  COMMAND cp src/complex.cc include/complex.h ${COMP_DIR}
  COMMAND zip -r ${USER}.zip ${USER}
  COMMAND rm -rf ${USER}
)
