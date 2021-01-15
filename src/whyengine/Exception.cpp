///
///  @file  Exception.cpp
///  @brief Takes the exception and then outputs the message.

#include "Exception.h"

namespace whyengine
{
  Exception::Exception(const std::string& io_message)
  {
    this->message = io_message;
  }

  Exception::~Exception() throw() { }

  const char* Exception::output() const throw()
  {
    return message.c_str();
  }
}
