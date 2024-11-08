#ifndef BIFROST_FILE_IO_HEADER_PARSER_MACROS
#define BIFROST_FILE_IO_HEADER_PARSER_MACROS

#include <Amino/Cpp/Annotate.h>

#define BIFROST_FILE_IO_FILE_BROWSER_OPEN(FILE_TYPES)                   \
    AMINO_ANNOTATE(                                                     \
        "Amino::Port metadata=[{UIWidget, string, FileBrowserWidget}, " \
        "{UIWidgetProp, string, browserMode=open;filter=\"" FILE_TYPES  \
        ";;All (*.*)\"}] ")

#define BIFROST_FILE_IO_FILE_BROWSER_OPEN_ALL                           \
    AMINO_ANNOTATE(                                                     \
        "Amino::Port metadata=[{UIWidget, string, FileBrowserWidget}, " \
        "{UIWidgetProp, string, browserMode=open;filter=\";All (*.*)\"}] ")

#define BIFROST_FILE_IO_SET_INPUT_DEFAULT_VAL(DEFAULT_VALUE) \
    AMINO_ANNOTATE(                                          \
        "Amino::Port value=" #DEFAULT_VALUE)

#define BIFROST_FILE_IO_SET_NODE_METADATA(DOC_FILENAME, ICON_FILENAME, INTERNAL) \
    AMINO_ANNOTATE("Amino::Node "                                                \
                   "metadata=[{documentation, string, \\../docs/" DOC_FILENAME   \
                   ".md},"                                                       \
                   "{icon, string, \\../icons/" ICON_FILENAME "},"               \
                   "{internal, bool," INTERNAL "}]")

#endif