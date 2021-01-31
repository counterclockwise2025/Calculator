#ifndef _EMPTY_EXCEPTION_
#define _EMPTY_EXCEPTION_

#include <string>
#include <exception>

/**
 * I moved the the empty exception into its own class.
 */
class Empty_Exception : public std::exception
{
    public:
        /// Default constructor.
        Empty_Exception(void);
        
        /**
         * Initializing constructor.
         *
         * @param[in]      msg         Error message.
         */
        Empty_Exception(const char *msg);

        /**
         * Override the what() function in standard exception.
         * Enables polymorphism. 
         */
        virtual const char * what() const throw();

    protected:
        std::string error_message;
};

#endif //!defined _EMPTY_EXCEPTION_
