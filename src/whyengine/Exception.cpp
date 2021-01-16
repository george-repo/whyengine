///
///  @file  Exception.cpp
///  @brief Takes the exception and then outputs the message.

// header includes
#include "Exception.h"

namespace whyengine
{
  Exception::Exception(const std::string& io_message)
  {
    this->message = io_message; // assigning the local message value to the value message used elsewhere
  }

  Exception::~Exception() throw() { } // virtual destructor

  const char* Exception::output() const throw()
  {
    return message.c_str(); // returning the newly assigned message value
  }
}
