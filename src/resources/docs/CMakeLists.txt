file( GLOB ALL_MD_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.md )

set( bifrost_file_io_docs )
foreach( doc_file ${ALL_MD_FILES})
   get_filename_component( basename ${doc_file} NAME )
   list( APPEND bifrost_file_io_docs ${basename})
endforeach()

install(FILES ${bifrost_file_io_docs}
    DESTINATION "${BIFROST_FILE_IO_INSTALL_DIR}/docs")