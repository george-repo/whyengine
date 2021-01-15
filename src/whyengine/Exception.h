/// \brief Allows the use of exception to help manage the engine
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_EXCEPTION_H
#define WHYENGINE_EXCEPTION_H

#include <exception>
#include <string>

namespace whyengine
{
  struct Exception : public std::exception
  {
  public:
    Exception(const std::string& io_message);
    virtual ~Exception() throw();

    virtual const char* output() const throw();

  private:
    std::string message;
  };
}

#endif // _EXCEPTION_H_