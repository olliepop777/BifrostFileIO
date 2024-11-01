#include "filesystem_io.h"

void read_file_to_arr_amino_str(const Amino::String amino_file_path,
    Amino::MutablePtr<Amino::Array<Amino::String>>& read_lines,
    bool utf8_only,
    bool debug,
    bool& success,
    Amino::String& msg_if_failed)
{
    if (amino_file_path.empty()) {
        success = false;
        msg_if_failed = "file_path is empty";
        return;
    }

    Amino::String debug_msg("");
    if (debug) {
        debug_msg = "Reading file: " + amino_file_path;
        _print_debug_msg(debug_msg);
        debug_msg = "Read UTF-8 encoding only: " + std::to_string(utf8_only);
        _print_debug_msg(debug_msg);
    }

    if (!Bifrost::FileUtils::filePathExists(amino_file_path, &msg_if_failed)) {
        success = false;
        if (debug) {
            _print_debug_msg(msg_if_failed);
        }
        return;
    }

    const char* file_path = amino_file_path.c_str();
    std::ifstream text_file(file_path);

    if (!text_file) {
        success = false;
        msg_if_failed = "There was an error reading the file: " + amino_file_path;
        if (debug) {
            _print_debug_msg(msg_if_failed);
        }
        return;
    }

    std::string line;
    const char* line_c_str;
    int line_num = 1;
    while (std::getline(text_file, line)) {
        line_c_str = line.c_str();
        if (utf8_only && !is_valid_utf8_str(line_c_str)) {
            success = false;
            msg_if_failed = "File contains non UTF-8 values, first detected at line num: "
                + std::to_string(line_num);
            (*read_lines).resize(0);
            if (debug) {
                _print_debug_msg(msg_if_failed);
            }
            break;
        }
        (*read_lines).push_back(Amino::String(line_c_str));
        line_num++;
    }

    text_file.close();
};

bool is_valid_utf8_str(const char* check_str_ptr)
{
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(check_str_ptr);
    int remaining_bytes = 0;
    // See the UTF-8 Standard chart on wikipedia: https://en.wikipedia.org/wiki/UTF-8#Description
    // 0xxxxxxx
    const unsigned char one_byte_seq = 0x00;
    // 110xxxxx
    const unsigned char two_byte_seq = 0xC0;
    // 1110xxxx
    const unsigned char three_byte_seq = 0xE0;
    // 1111xxxx
    const unsigned char four_byte_seq = 0xF0;
    // 10xxxxxx
    const unsigned char continue_byte = 0x80;
    // Reset first bit to 1
    const unsigned char reset_first_bit = 0x80;

    size_t i = 0;
    while (bytes[i] != '\0') {
        unsigned char cur_byte = bytes[i];

        if (remaining_bytes == 0) {
            /* We shift to the right and reset the first bit to 1.
                This allows us to check if the byte is greater than the
                patterns for the corresponding length byte sequences
            */
            if ((cur_byte & (((unsigned char)(one_byte_seq >> 1)) | reset_first_bit)) == one_byte_seq) {
                // ASCII
                remaining_bytes = 0;
            } else if ((cur_byte & (((unsigned char)(two_byte_seq >> 1)) | reset_first_bit)) == two_byte_seq) {
                // 2-byte sequence
                remaining_bytes = 1;
            } else if ((cur_byte & (((unsigned char)(three_byte_seq >> 1)) | reset_first_bit)) == three_byte_seq) {
                // 3-byte sequence
                remaining_bytes = 2;
            } else if ((cur_byte & (((unsigned char)(four_byte_seq >> 1)) | reset_first_bit)) == four_byte_seq) {
                // 3-byte sequence
                remaining_bytes = 3;
            } else {
                return false;
            }
        } else {
            if ((cur_byte & ((continue_byte >> 1) | reset_first_bit)) != continue_byte) {
                return false;
            }
            remaining_bytes--;
        }
        i++;
    }
    return remaining_bytes == 0;
};

void _print_debug_msg(const Amino::String& debug_msg)
{
    std::cout << debug_msg.c_str() << std::endl;
};