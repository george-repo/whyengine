#ifndef WHYENGINE_EXCEPTION_H
#define WHYENGINE_EXCEPTION_H
#include <exception>
#include <string>

namespace whyengine
{
  struct Exception : public std::exception
  {
    Exception(const std::string& message);
    virtual ~Exception() throw();
    virtual const char* what() const throw();

  private:
    std::string message;

  };

}
#endif