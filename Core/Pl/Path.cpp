//!
//! @file Pl/Path.cpp
//! @author Luk2010
//! @date 2024/01/23
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/Path.h"

namespace Pl
{
    void Path::moveTo(const Point& to)
    {
        mElements.push_back(PathElement{
            .type = PathElementType::MoveToPoint,
            .points = { to }
        });
    }
    
    void Path::addLineTo(const Point& to)
    {
        mElements.push_back(PathElement{
            .type = PathElementType::AddLineToPoint,
            .points = { to }
        });
    }
    
    void Path::addQuadCurveTo(const Point &ctrl, const Point &to)
    {
        mElements.push_back({
            .type = PathElementType::AddQuadCurveToPoint,
            .points = { to, ctrl }
        });
    }
    
    void Path::addCurveTo(const Point& ctrl0, const Point& ctrl1, const Point& to)
    {
        mElements.push_back({
            .type = PathElementType::AddCurveToPoint,
            .points = { to, ctrl0, ctrl1 }
        });
    }
    
    void Path::addRect(const Rect& rect)
    {
        moveTo(rect.origin);
        addLineTo({ rect.origin.x + rect.size.width, rect.origin.y });
        addLineTo({ rect.origin.x + rect.size.width, rect.origin.y + rect.size.height });
        addLineTo({ rect.origin.x, rect.origin.y + rect.size.height });
        addLineTo(rect.origin);
        close();
    }
    
    void Path::addRoundedRect(const Rect& rect, const RectCorners& cornerRadii)
    {
        if (rect.size.width <= 0 || rect.size.height <= 0 ||
            cornerRadii.topLeft <= 0 || cornerRadii.topRight <= 0 ||
            cornerRadii.bottomRight <= 0 || cornerRadii.bottomLeft <= 0)
        {
            // Invalid parameters, do nothing
            return;
        }
        
        const double halfWidth = rect.size.width * 0.5;
        const double halfHeight = rect.size.height * 0.5;
        
        const double topLeftControl = cornerRadii.topLeft * (1.0 - 1.0 / std::sqrt(2.0));
        const double topRightControl = cornerRadii.topRight * (1.0 - 1.0 / std::sqrt(2.0));
        const double bottomRightControl = cornerRadii.bottomRight * (1.0 - 1.0 / std::sqrt(2.0));
        const double bottomLeftControl = cornerRadii.bottomLeft * (1.0 - 1.0 / std::sqrt(2.0));
        
        moveTo(Point{rect.origin.x + halfWidth, rect.origin.y});
        
        addLineTo(Point{rect.origin.x + rect.size.width - cornerRadii.topRight, rect.origin.y});
        
        addQuadCurveTo(Point{rect.origin.x + rect.size.width - topRightControl, rect.origin.y},
                       Point{rect.origin.x + rect.size.width, rect.origin.y + cornerRadii.topRight});
        
        addLineTo(Point{rect.origin.x + rect.size.width, rect.origin.y + rect.size.height - cornerRadii.bottomRight});
        
        addQuadCurveTo(Point{rect.origin.x + rect.size.width, rect.origin.y + rect.size.height - bottomRightControl},
                       Point{rect.origin.x + rect.size.width - cornerRadii.bottomRight, rect.origin.y + rect.size.height});
        
        addLineTo(Point{rect.origin.x + cornerRadii.bottomLeft, rect.origin.y + rect.size.height});
        
        addQuadCurveTo(Point{rect.origin.x + bottomLeftControl, rect.origin.y + rect.size.height},
                       Point{rect.origin.x, rect.origin.y + rect.size.height - cornerRadii.bottomLeft});
        
        addLineTo(Point{rect.origin.x, rect.origin.y + cornerRadii.topLeft});
        
        addQuadCurveTo(Point{rect.origin.x, rect.origin.y + topLeftControl},
                       Point{rect.origin.x + cornerRadii.topLeft, rect.origin.y});
        
        close();
    }
    
    void Path::close()
    {
        mElements.push_back({
            .type = PathElementType::CloseSubPath
        });
    }
    
    const std::vector < PathElement >& Path::elements() const
    {
        return mElements;
    }
}
