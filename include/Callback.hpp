/* 
 * File:   Callback.hpp
 * Author: ankithbti
 *
 * Created on 11 July, 2015, 1:37 PM
 */

#ifndef CALLBACK_HPP
#define	CALLBACK_HPP

#include <CallbackInterface.hpp>

namespace coolTypes
{

/**
 * Class to behave as a callback for any function of any signature
 */
template <typename T, typename R = void, typename... Args>
class Callback : public CallbackInterface<R, Args...>
{
public:
    typedef R (T::*Funct)(Args...);
private:
    T* _t;
    Funct _funct;
public:
    
    Callback(T& t, Funct f) : _t(&t), _funct(f){
        
    }

    virtual R operator()(Args... args)
    {
        return (_t->*_funct)(args...);
    }

    virtual ~Callback()
    {
    }

};

}

#endif	/* CALLBACK_HPP */

