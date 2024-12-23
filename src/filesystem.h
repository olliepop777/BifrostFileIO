#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "bifrost_file_io_export.h"
#include "header_macros.h"

#include "bifrost_file_io_runtime_exception.h"
#include "filesystem_io.h"

namespace BifrostFileIO {
namespace Filesystem {

    BIFROST_FILE_IO_DECL
    void read_file(const Amino::String& file_path BIFROST_FILE_IO_FILE_BROWSER_ALL("open"),
        bool utf8_only BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(true),
        bool debug BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
        Amino::MutablePtr<Amino::Array<Amino::String>>& read_lines,
        bool& success,
        Amino::String& msg_if_failed)
        BIFROST_FILE_IO_SET_NODE_METADATA("read_file", "json_logo.svg", "false");

    BIFROST_FILE_IO_DECL
    void write_file(bool enable BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
        const Amino::String& file_path BIFROST_FILE_IO_FILE_BROWSER_ALL("save"),
        bool overwrite BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
        bool dry_run BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
        bool debug BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
        Amino::Array<Amino::String>& write_lines AMINO_ANNOTATE("Amino::InOut outName=out_write_lines Amino::Port isDefaultFanIn=true"),
        bool& success,
        Amino::String& msg_if_failed)
        BIFROST_FILE_IO_SET_NODE_METADATA("write_file", "json_logo.svg", "false");

}
}

#endif // FILESYSTEM_H
