/* 
 * File:   CallbackInterface.hpp
 * Author: ankithbti
 *
 * Created on 11 July, 2015, 1:37 PM
 */

#ifndef CALLBACKINTERFACE_HPP
#define	CALLBACKINTERFACE_HPP

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace coolTypes
{

template <typename R = void, typename... Args>
class CallbackInterface : private boost::noncopyable
{
public:
    typedef boost::shared_ptr<CallbackInterface> SmartPtr;
    typedef boost::shared_ptr<const CallbackInterface> SmartConstPtr;

    virtual R operator()(Args...) = 0;

    virtual ~CallbackInterface()
    {

    }

};
}
#endif	/* CALLBACKINTERFACE_HPP */

