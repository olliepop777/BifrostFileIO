#include "filesystem.h"

void BifrostFileIO::Filesystem::read_file(const Amino::String& file_path,
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

void BifrostFileIO::Filesystem::write_file(bool enable,
    const Amino::String& file_path,
    bool overwrite,
    bool dry_run,
    bool debug,
    Amino::Array<Amino::String>& write_lines,
    bool& success,
    Amino::String& msg_if_failed)
{
    if (!enable) {
        success = false;
        return;
    }
    success = true;
    try {
        write_file_arr_amino_str(file_path, write_lines, overwrite, dry_run, debug, success, msg_if_failed);
    } catch (const std::exception& e) {
        success = false;
        msg_if_failed = e.what();
    }
}