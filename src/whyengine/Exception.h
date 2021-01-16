/// \brief Allows the use of exception to help manage the engine
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_EXCEPTION_H
#define WHYENGINE_EXCEPTION_H

// system includes
#include <exception>
#include <string>

namespace whyengine // namepsace
{
  struct Exception : public std::exception  // inherits from std::exception
  {
  public:
    Exception(const std::string& io_message); //  the main exception with the message  
    virtual ~Exception() throw(); // virtual destructor

    virtual const char* output() const throw(); // virutual function

  private:
    std::string message;  // local value function
  };
}

#endif // _EXCEPTION_H_