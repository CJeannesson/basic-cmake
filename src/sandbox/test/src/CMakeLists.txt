# set include directories for the tests
include_directories(${PROJECT_SOURCE_DIR}/src)

# define the test source files
file( GLOB TEST_SOURCEFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} test_*.cpp ) # select all test_*.cpp files in the test/src directory

# add a custom target to compile all tests for this project
enable_testing()
add_custom_target( test-${MASTER_PROJECT_NAME} COMMAND ${CMAKE_CTEST_COMMAND} )

# process each test
foreach( PROJECT_TEST_FILE ${TEST_SOURCEFILES} )

  # remove the cpp extension
  string( REPLACE ".cpp" "" PROJECT_TEST ${PROJECT_TEST_FILE} )

  # add executable
  add_executable( ${PROJECT_TEST} ${PROJECT_TEST_FILE} )

  # link exectutable to libraries
  target_link_libraries( ${PROJECT_TEST} ${LIB_NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARIES} )
  
  # if internal library dependencies have been defined
  if    ( DEFINED INTERNAL_LIBRARIES AND NOT INTERNAL_LIBRARIES EQUAL "" )

    # add library dependencies
    target_link_libraries( ${PROJECT_TEST} ${INTERNAL_LIBRARIES} )

  endif ()

  # if external library dependencies have been defined
  if ( DEFINED EXTERNAL_LIBRARIES AND NOT EXTERNAL_LIBRARIES EQUAL "" )

    # add library dependencies
    target_link_libraries( ${PROJECT_TEST} ${EXTERNAL_LIBRARIES} )

  endif ()

  # add test
  add_test( ${PROJECT_TEST} ${PROJECT_TEST} )

  # set dependencies for other custom targets
  add_dependencies( test-${MASTER_PROJECT_NAME} ${PROJECT_TEST} )
  add_dependencies( test-all test-${MASTER_PROJECT_NAME} )

endforeach ()

