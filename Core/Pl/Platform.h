//! 
//! @file Pl/Platform.h
//! @author Luk2010
//! @date 2024/01/15
//! @copyright Atlanti's Corp(r) 2024
//! 

#ifndef __PL_PLATFORM_H__
#define __PL_PLATFORM_H__

#include "Pl/Config.h"

#include <memory>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <sstream>
#include <atomic>

#define PLUTON_PRIVATE_DATA  void*

#ifdef __APPLE__

#   include <TargetConditionals.h>

#   if TARGET_OS_OSX

#       define PLUTON_TARGET_OSX    1
#       define PLUTON_WINSYS_COCOA  1
#       define PLUTON_EXPORT        __attribute__((visibility("default")))

#       ifdef __OBJC__

#           include <Cocoa/Cocoa.h>

#       else  

#           include <objc/objc-runtime.h>

#       endif 

#   endif 

#endif

namespace Pl 
{
    template < class T > using Ref = std::shared_ptr < T >;
    template < class T > using Weak = std::weak_ptr < T >;
    template < class T, class... Params > inline auto Make(Params&&... params) 
        { return std::make_shared < T >(std::forward < Params >(params)...); }

    struct Error : public std::exception
    {
        std::string mMessage;

    public:

        template < class... Params > 
        Error(Params&&... params)
        {
            std::stringstream ss;
            ((ss << params), ...);
            mMessage = ss.str();
        }

        const char* what() const noexcept 
        {
            return mMessage.c_str();
        }
    };

#   define PLUTON_DEFINE_ERROR(NAME) \
    struct NAME : public Error { using Error::Error; };
}   

#endif