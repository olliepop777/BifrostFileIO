#include "filesystem.h"

void BifrostFileIO::Filesystem::read_from_filesystem(Amino::String file_path,
    bool utf8_only,
    bool debug,
    Amino::MutablePtr<Amino::Array<Amino::String>>& read_lines,
    bool& success,
    Amino::String& msg_if_failed)
{

    read_lines = Amino::newMutablePtr<Amino::Array<Amino::String>>(0);
    success = true;
    try {
        read_file_to_arr_amino_str(file_path, read_lines, utf8_only, debug, success, msg_if_failed);
    } catch (const std::exception& e) {
        success = false;
        msg_if_failed = e.what();
    }
}