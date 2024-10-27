#include "bifrost_file_io_runtime_exception.h"

const std::string BifrostFileIORuntimeException::EXCEPTION_NAME = "BifrostFileIORuntimeException: ";

BifrostFileIORuntimeException::BifrostFileIORuntimeException(const char* message)
    : m_message(EXCEPTION_NAME)
{
    m_message += message;
}

const char* BifrostFileIORuntimeException::what() const noexcept
{
    return m_message.c_str();
}