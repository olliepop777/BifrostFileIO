# Build and install the library
add_library( BifrostFileIOOps SHARED)
target_compile_definitions( BifrostFileIOOps PRIVATE BIFROST_FILE_IO_BUILD_NODEDEF_DLL )
target_sources( BifrostFileIOOps PRIVATE 
    json_to_bif_obj.cpp 
    parse_access_expr.cpp
    bifrost_file_io_runtime_exception.cpp
    filesystem_io.cpp
    bifrost_json.cpp
    filesystem.cpp
)
target_link_libraries( BifrostFileIOOps PUBLIC Amino::Cpp )
target_link_libraries( BifrostFileIOOps PUBLIC Amino::Core )
target_link_libraries( BifrostFileIOOps PUBLIC Bifrost::Object )
target_link_libraries( BifrostFileIOOps PUBLIC Bifrost::FileUtils )
bifrost_set_install_rpath(BifrostFileIOOps)
install( TARGETS BifrostFileIOOps DESTINATION lib )

# Generate and install the json files
set( headers_to_parse 
    bifrost_json.h
    filesystem.h
)

bifrost_header_parser( 
    BifrostFileIOJsonFiles  # Name of the target.
    "json"                 # Install dir - relative to install prefix.
    INCLUDE_DIRS    ${CMAKE_CURRENT_SOURCE_DIR}
    ${HEADER_FILE_ARG}      ${headers_to_parse})

# Create config json file to load the bifrost pack
set( CONFIG_PACK_VERSION "${PROJECT_VERSION}")
set( CONFIG_PACK_NAME "bifrost_file_io")
set( CONFIG_SHARED_LIBS "./lib")
set( CONFIG_JSON_FILES "./json")
set( config_json ${CMAKE_BINARY_DIR}/${PROJECT_NAME}PackConfig.json )
configure_file(PackConfig.json.in ${config_json} )
install(FILES ${config_json} DESTINATION . )

add_subdirectory(resources)
add_subdirectory(compounds)