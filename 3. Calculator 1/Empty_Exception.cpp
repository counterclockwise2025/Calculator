#include "Empty_Exception.h"

// Returns error message.
const char * Empty_Exception::what() const throw()
{
    return error_message.c_str();
}

/// Default constructor.
Empty_Exception::Empty_Exception(void)
    : std::exception()
{
}

/**
* Initializing constructor.
*
* @param[in]      msg         Error message.
*/
Empty_Exception::Empty_Exception(const char *msg)
    : error_message{msg}
{
}
