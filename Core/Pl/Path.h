//!
//! @file Pl/Path.h
//! @author Luk2010
//! @date 2024/01/23
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_PATH_H__
#define __PL_PATH_H__

#include "Pl/Platform.h"

namespace Pl
{
    enum class PathElementType
    {
        MoveToPoint,
        AddLineToPoint,
        AddQuadCurveToPoint,
        AddCurveToPoint,
        CloseSubPath
    };
    
    struct PathElement
    {
        PathElementType type;
        std::vector < Point > points;
    };
    
    class Path
    {
        std::vector < PathElement > mElements;
        
    public:
        
        void moveTo(const Point& p);
        
        void addLineTo(const Point& to);
        
        void addQuadCurveTo(const Point& ctrl, const Point& to);
        
        void addCurveTo(const Point& ctrl0, const Point& ctrl1, const Point& to);
        
        void addRect(const Rect& rect);
        
        void addRoundedRect(const Rect& rect, const RectCorners& cornerRadii);
        
        void close();
        
        const std::vector < PathElement >& elements() const;
    };
}

#endif
