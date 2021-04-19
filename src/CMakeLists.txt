#Simple CMake architecture. 
#Credits go to W. Haeck for the job, modifs by C. Jeannesson

# create a master project
project( MASTER_PROJECT NONE )
cmake_minimum_required( VERSION 2.8 )

# the different libraries/executables in the MASTER_PROJECT
set( MASTER_PROJECT
       sandbox
   )

# ---------------------------------------------------------------------
# build types and options
# ---------------------------------------------------------------------

# set compiler flags
set( CMAKE_CXX_FLAGS         "-std=c++11 -g -Wall"   CACHE STRING "Set the compiler flags for the c++11 standard" )

# ---------------------------------------------------------------------
# BOOST
# ---------------------------------------------------------------------

# default Boost options
set( Boost_USE_STATIC_LIBS    ON )  # use the static libraries
set( Boost_USE_MULTITHREADED  ON  )  # use multi-threaded libraries
set( Boost_USE_STATIC_RUNTIME ON  )  # use libraries linked to static C++ standard library

set( BOOST_LIBRARYDIR /usr/lib/x86_64-linux-gnu  )  
find_package( Boost 1.62.0 COMPONENTS unit_test_framework REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})

# if dynamic Boost libraries are used
if (NOT Boost_USE_STATIC_LIBS)

  # the BOOST_TEST_DYN_LINK define
  #set( TEST_FLAG " -D BOOST_TEST_DYN_LINK" )

  # remove the compiler flag (to avoid adding the flag multiple times)
  string( REPLACE ${TEST_FLAG} "" CMAKE_CXX_FLAGS   ${CMAKE_CXX_FLAGS} )
  set( CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS}${TEST_FLAG}"   CACHE STRING "Set the compiler flags" FORCE )

endif ()


# ---------------------------------------------------------------------
# Add subdirectory
# ---------------------------------------------------------------------

# build and run all tests
add_custom_target( test-all )

# do for each project
foreach( PROJECT ${MASTER_PROJECT} )

  # add the subdirectories for each library/executable
  add_subdirectory( ${PROJECT} )

endforeach ()

