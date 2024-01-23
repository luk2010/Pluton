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
#include <filesystem>
#include <string_view>

#define PLUTON_PRIVATE_DATA  void*

#ifdef __APPLE__

#   include <TargetConditionals.h>
#   include <dlfcn.h>

#   define PLUTON_DYNLIB_HANDLE      void*
#   define PLUTON_DYNLIB_DLOPEN(a)   dlopen(a, RTLD_LAZY)
#   define PLUTON_DYNLIB_DLSYM(a, b) dlsym(a, b)
#   define PLUTON_DYNLIB_DLCLOSE(a)  dlclose(a)
#   define PLUTON_DYNLIB_EXT         ".dylib"

#   if TARGET_OS_OSX

#       define PLUTON_TARGET_OSX    1
#       define PLUTON_WINSYS_COCOA  1
#       define PLUTON_EXPORT        __attribute__((visibility("default")))

#       include <objc/objc-runtime.h>

#       ifdef __OBJC__

#           include <Cocoa/Cocoa.h>

#           define PLUTON_LANG_OBJC 1

#       endif 

#   endif 

#endif

namespace Pl 
{
    template < class T > using Ref = std::shared_ptr < T >;
    template < class T > using Weak = std::weak_ptr < T >;
    template < class T, class... Params > inline auto Make(Params&&... params) 
        { return std::make_shared < T >(std::forward < Params >(params)...); }

    struct PLUTON_EXPORT Error : public std::exception
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
    
    PLUTON_DEFINE_ERROR(RuntimeError)
    PLUTON_DEFINE_ERROR(WinSysError)
    PLUTON_DEFINE_ERROR(FileNotFound)
    PLUTON_DEFINE_ERROR(NullArg)
    
    struct PLUTON_EXPORT Point
    {
        double x = 0;
        double y = 0;
        
        inline Point operator + (const Point& rhs) const
        {
            return { x + rhs.x, y + rhs.y };
        }
        
        inline Point operator + (double rhs) const
        {
            return { x + rhs, y + rhs };
        }
        
        inline Point operator - (const Point& rhs) const
        {
            return { x - rhs.x, y - rhs.y };
        }
        
        inline Point operator - (double rhs) const
        {
            return { x - rhs, y - rhs };
        }
    };
    
    struct PLUTON_EXPORT Size
    {
        double width = 0;
        double height = 0;
    };
    
    struct PLUTON_EXPORT Rect
    {
        Point origin;
        Size size;
        
        inline Rect(const Point& origin = {}, const Size& size = {}):
        origin(origin), size(size) { }
        
        inline Rect(const Size& size):
        size(size) { }
        
        inline Rect shrink(double left, double top, double right, double bottom) const
        {
            return Rect({ origin.x + left, origin.y + top },
                        { size.width - left - right, size.height - top - bottom });
        }
        
        inline Rect expand(double left, double top, double right, double bottom) const
        {
            return Rect({
                origin.x - left,
                origin.y - top
            }, {
                size.width + left + right,
                size.height + top + bottom
            });
        }
    };
    
    struct PLUTON_EXPORT RectCorners
    {
        double topLeft = 0.0;
        double topRight = 0.0;
        double bottomLeft = 0.0;
        double bottomRight = 0.0;
    };
    
    struct PLUTON_EXPORT RGBAColor
    {
        double red;
        double green;
        double blue;
        double alpha;
        
        inline RGBAColor(double r, double g, double b, double a = 1):
        red(r), green(g), blue(b), alpha(a) { }
        
        inline RGBAColor operator + (const RGBAColor& rhs) const
        {
            return RGBAColor(red + rhs.red,
                             green + rhs.green,
                             blue + rhs.blue,
                             std::clamp(alpha + rhs.alpha, 0.0, 1.0));
        }
        
        inline RGBAColor operator + (double rhs) const
        {
            return RGBAColor(red + rhs,
                             green + rhs,
                             blue + rhs,
                             std::clamp(alpha + rhs, 0.0, 1.0));
        }
        
        inline RGBAColor operator - (const RGBAColor& rhs) const
        {
            return RGBAColor(red - rhs.red,
                             green - rhs.green,
                             blue - rhs.blue,
                             std::clamp(alpha - rhs.alpha, 0.0, 1.0));
        }
        
        inline RGBAColor operator - (double rhs) const
        {
            return RGBAColor(red - rhs,
                             green - rhs,
                             blue - rhs,
                             std::clamp(alpha - rhs, 0.0, 1.0));
        }
    };
}

#endif
