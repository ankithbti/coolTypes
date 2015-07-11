/* 
 * File:   CallbackHelper.hpp
 * Author: ankithbti
 *
 * Created on 11 July, 2015, 3:00 PM
 */

#ifndef CALLBACKHELPER_HPP
#define	CALLBACKHELPER_HPP

#include <map>
#include <Callback.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <stdexcept>

namespace coolTypes
{

/**
 * Class to hold the callbacks of same return & argument types.
 */
template <typename R = void, typename... Args>
class CallbackHelper : private boost::noncopyable
{
public:
    typedef boost::shared_ptr<CallbackHelper> SmartPtr;
    typedef boost::shared_ptr<const CallbackHelper> SmartConstPtr;
    typedef std::map<int, typename CallbackInterface<R, Args...>::SmartPtr> CallbackContainer;
    typedef typename CallbackContainer::iterator CallbackContainerIt;
    typedef typename CallbackContainer::const_iterator CallbackContainerConstIt;

private:
    CallbackContainer _callbackContainer;

public:

    void registerCallback(int no, typename CallbackInterface<R, Args...>::SmartPtr callback)
    {
        _callbackContainer.insert(std::pair<int, typename CallbackInterface<R, Args...>::SmartPtr > (no, callback));
    }

    typename CallbackInterface<R, Args...>::SmartPtr getCallback(int no)
    {
        CallbackContainerConstIt it = _callbackContainer.find(no);
        if(it == _callbackContainer.end()){
            throw std::runtime_error("CallbackHelper::getCallback() - No callback present for no: " + boost::lexical_cast<std::string>(no));
        }
        return it->second;
    }
    
    void removeCallback(int no){
        
    }
    
};

}

#endif	/* CALLBACKHELPER_HPP */

