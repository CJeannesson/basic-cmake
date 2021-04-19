# create the local project
project(sandbox CXX )
cmake_minimum_required( VERSION 2.8 )

# set local project name (equal to directory name)
set( PROJECT_NAME sandbox )

# set library name
set( LIB_NAME  ${PROJECT_NAME} )

# set executable names
set( MAIN_PROGRAM_NAMES
       hello-world
   )

# set the internal library dependencies for this library/executable
set( INTERNAL_LIBRARIES
       # sandbox has no dependencies
   )

# set the external library dependencies for this library/executable
set( EXTERNAL_LIBRARIES
       # eg. gsl
   )

# set include directories for the library and executable
foreach ( LIBRARY ${INTERNAL_LIBRARIES})

  include_directories( ${MASTER_PROJECT_SOURCE_DIR}/${LIBRARY}/src )

endforeach ()

# indicate the project source directory
add_subdirectory( src )

# indicate the test source directory
add_subdirectory( test/src )

