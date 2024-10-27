file( GLOB ALL_COMPOUND_JSON_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.json )

set( bifrost_file_io_compounds )
foreach( compound_json_file ${ALL_COMPOUND_JSON_FILES})
   get_filename_component( basename ${compound_json_file} NAME )
   list( APPEND bifrost_file_io_compounds ${basename})
endforeach()

install(FILES ${bifrost_file_io_compounds}
    DESTINATION "${BIFROST_FILE_IO_INSTALL_DIR}/json")