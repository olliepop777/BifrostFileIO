#ifndef FILESYSTEM_IO_H
#define FILESYSTEM_IO_H

// std includes
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

// Bifrost includes
#include <Amino/Core/Array.h>
#include <Amino/Core/Ptr.h>
#include <Amino/Core/String.h>
#include <Bifrost/FileUtils/FileUtils.h>

void read_file_to_arr_amino_str(const Amino::String& file_path,
    Amino::MutablePtr<Amino::Array<Amino::String>>& read_lines,
    bool utf8_only,
    bool debug,
    bool& success,
    Amino::String& msg_if_failed);

bool is_valid_utf8_str(const char* check_str_ptr);

void write_file_arr_amino_str(const Amino::String& amino_file_path,
    Amino::Array<Amino::String>& write_lines,
    bool overwrite,
    bool dry_run,
    bool debug,
    bool& success,
    Amino::String& msg_if_failed);

void _print_debug_msg(const Amino::String& debug_msg);

#endif // FILESYSTEM_IO_H