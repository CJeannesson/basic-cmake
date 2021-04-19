# define the program sources
file( GLOB SOURCEFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp ) # select all cpp files in the current directory

# if main executables have been defined
foreach ( MAIN_PROGRAM_NAME ${MAIN_PROGRAM_NAMES} )

  # remove the main file from the source files
  set( PROJECT_MAINFILE    _${MAIN_PROGRAM_NAME}.cpp )
  list( REMOVE_ITEM SOURCEFILES ${PROJECT_MAINFILE} )

endforeach ()

# if there are source files left
if ( DEFINED SOURCEFILES AND NOT SOURCEFILES EQUAL "" )

  # add the source for the library
  add_library( ${LIB_NAME} ${SOURCEFILES} )

  # if some library dependencies have been defined
  if    ( DEFINED INTERNAL_LIBRARIES AND NOT INTERNAL_LIBRARIES EQUAL "" )

    # add library dependencies
    add_dependencies( ${LIB_NAME} ${INTERNAL_LIBRARIES} )

  endif ()

  # if external library dependencies have been defined
  if    ( DEFINED EXTERNAL_LIBRARIES AND NOT EXTERNAL_LIBRARIES EQUAL "" )

    # add library dependencies
    add_dependencies( ${LIB_NAME} ${EXTERNAL_LIBRARIES} )

  endif ()

endif ()

# if main executables have been defined
foreach ( MAIN_PROGRAM_NAME ${MAIN_PROGRAM_NAMES} )

  # set some variables
  set( PROJECT_EXE_NAME    ${MAIN_PROGRAM_NAME}.exe )
  set( PROJECT_MAINFILE    _${MAIN_PROGRAM_NAME}.cpp )

  # add the source for the main executable
  add_executable( ${PROJECT_EXE_NAME} ${PROJECT_MAINFILE} )

  # if there are source files left
  if    ( DEFINED SOURCEFILES AND NOT SOURCEFILES EQUAL "" )

    # link to the project library
    target_link_libraries( ${PROJECT_EXE_NAME} ${LIB_NAME} )

  endif ()

  # if internal library dependencies have been defined
  if    ( DEFINED INTERNAL_LIBRARIES AND NOT INTERNAL_LIBRARIES EQUAL "" )

    # add library dependencies
    target_link_libraries( ${PROJECT_EXE_NAME} ${INTERNAL_LIBRARIES} )

  endif ()

  # if external library dependencies have been defined
  if    ( DEFINED EXTERNAL_LIBRARIES AND NOT EXTERNAL_LIBRARIES EQUAL "" )

    # add library dependencies
    target_link_libraries( ${PROJECT_EXE_NAME} ${EXTERNAL_LIBRARIES} )

  endif ()

endforeach ()

