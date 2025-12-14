#ifndef _Insufficent_Funds_Exception_HPP_
#define _Insufficent_Funds_Exception_HPP_

#include <iostream>

class InsufficentFundsException : public std::exception{

    public:
    InsufficentFundsException () noexcept = default;
    ~ InsufficentFundsException () = default ;

    virtual const  char* what () const noexcept {
        return "Insufficent Funds Exception" ;
    } 
};

#endif