#ifndef BIFROST_FILE_IO_EXPORT_H
#define BIFROST_FILE_IO_EXPORT_H

#if defined(_WIN32)
#define BIFROST_FILE_IO_EXPORT __declspec(dllexport)
#define BIFROST_FILE_IO_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define BIFROST_FILE_IO_EXPORT __attribute__((visibility("default")))
#define BIFROST_FILE_IO_IMPORT __attribute__((visibility("default")))
#else
#error Unsupported platform.
#endif

#if defined(BIFROST_FILE_IO_BUILD_NODEDEF_DLL)
#define BIFROST_FILE_IO_DECL BIFROST_FILE_IO_EXPORT
#else
#define BIFROST_FILE_IO_DECL BIFROST_FILE_IO_IMPORT
#endif

#endif
