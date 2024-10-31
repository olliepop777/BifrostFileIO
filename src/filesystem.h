#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "bifrost_file_io_export.h"
#include "header_macros.h"

#include "bifrost_file_io_runtime_exception.h"
#include "filesystem_io.h"

namespace BifrostFileIO {
namespace Filesystem {

    BIFROST_FILE_IO_DECL
    void read_from_filesystem(Amino::String file_path BIFROST_FILE_IO_FILE_BROWSER_OPEN_ALL,
        bool utf8_only BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(true),
        bool debug BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
        Amino::MutablePtr<Amino::Array<Amino::String>>& read_lines,
        bool& success,
        Amino::String& msg_if_failed)
        BIFROST_FILE_IO_SET_NODE_METADATA("read_from_filesystem", "json_logo.svg", "false");

}
}

#endif // FILESYSTEM_H
