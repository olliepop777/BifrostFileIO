#ifndef BIFROST_JSON_H
#define BIFROST_JSON_H

#include "bifrost_file_io_export.h"
#include "header_macros.h"

#include "bifrost_file_io_runtime_exception.h"
#include "json_to_bif_obj.h"
#include "parse_access_expr.h"

namespace BifrostFileIO {
namespace JSON {

BIFROST_FILE_IO_DECL
void read_json(Amino::String json_file BIFROST_FILE_IO_FILE_BROWSER_OPEN,
    Amino::String json_str,
    bool output_a_bifrost_object BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(true),
    bool output_a_json_str BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
    bool null_to_string BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
    bool force_any_arrays BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
    bool debug BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(false),
    int print_indent_level BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(4),
    Amino::MutablePtr<Bifrost::Object>& out_json_obj,
    Amino::String& out_json_str,
    bool& success,
    Amino::String& msg_if_failed)
    BIFROST_FILE_IO_SET_NODE_METADATA("read_json", "json_logo.svg", "false");

BIFROST_FILE_IO_DECL
void get_property_access_tokens(Amino::String access_expr,
    Amino::MutablePtr<Amino::Array<Amino::Ptr<Bifrost::Object>>>& token_arr,
    bool& success,
    Amino::String& msg_if_failed)
    BIFROST_FILE_IO_SET_NODE_METADATA("get_property_access_tokens", "json_logo.svg", "true");
}
}

#endif // BIFROST_JSON_H
