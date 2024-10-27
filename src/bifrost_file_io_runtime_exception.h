#ifndef BIFROST_FILE_IO_RUNTIME_EXCEPTION_H
#define BIFROST_FILE_IO_RUNTIME_EXCEPTION_H

#include <exception>
#include <string>

class BifrostFileIORuntimeException : public std::exception {
public:
    BifrostFileIORuntimeException(const char* message);

    const char* what() const noexcept override;

private:
    static const std::string EXCEPTION_NAME;
    std::string m_message;
};

#endif // BIFROST_FILE_IO_RUNTIME_EXCEPTION_H