#include "Exception.h"

namespace whyengine
{
  Exception::Exception(const std::string& message)
  {
    this->message = message;
  }

  Exception::~Exception() throw() { }

  const char* Exception::what() const throw()
  {
    return message.c_str();
  }
}
