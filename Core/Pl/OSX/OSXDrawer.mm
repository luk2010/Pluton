//!
//! @file Pl/OSX/OSXDrawer.mm
//! @author Luk2010
//! @date 2024/01/20
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/OSX/OSXDrawer.h"

namespace Pl
{
    OSXDrawer::OSXDrawer(NSGraphicsContext* hdl): mHandle(hdl)
    {
        
    }
    
    void OSXDrawer::setFillColor(const RGBAColor& color)
    {
        CGContextRef ctxt = [mHandle CGContext];
        CGContextSetRGBFillColor(ctxt, color.red, color.green, color.blue, color.alpha);
    }
    
    void OSXDrawer::setStrokeColor(const RGBAColor& color)
    {
        CGContextRef ctxt = [mHandle CGContext];
        CGContextSetRGBStrokeColor(ctxt, color.red, color.green, color.blue, color.alpha);
    }
    
    void OSXDrawer::fill(const Rect& rect, double cornerRadius)
    {
        CGContextRef ctxt = [mHandle CGContext];
        NSRect _rect = NSMakeRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
        CGPathRef _path = CGPathCreateWithRoundedRect(_rect, cornerRadius, cornerRadius, NULL);
        
        CGContextAddPath(ctxt, _path);
        CGContextFillPath(ctxt);
        
        CFRelease(_path);
    }
    
    void OSXDrawer::stroke(const Rect& rect, double lineWidth, double cornerRadius)
    {
        CGContextRef ctxt = [mHandle CGContext];
        NSRect _rect = NSMakeRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
        CGPathRef _path = CGPathCreateWithRoundedRect(_rect, cornerRadius, cornerRadius, NULL);
        
        CGContextSetLineWidth(ctxt, lineWidth);
        CGContextAddPath(ctxt, _path);
        CGContextStrokePath(ctxt);
        
        CFRelease(_path);
    }
    
    void OSXDrawer::fill(const Path& path)
    {
        setPath(path);
        
        CGContextRef ctxt = [mHandle CGContext];
        CGContextFillPath(ctxt);
    }
    
    void OSXDrawer::stroke(const Path& path, double lineWidth)
    {
        setPath(path);
        
        CGContextRef ctxt = [mHandle CGContext];
        CGContextSetLineWidth(ctxt, lineWidth);
        CGContextStrokePath(ctxt);
    }
    
    void OSXDrawer::setPath(const Path& path)
    {
        CGContextRef ctxt = [mHandle CGContext];
        
        for (auto& element : path.elements())
        {
            switch (element.type)
            {
                case PathElementType::MoveToPoint:
                    CGContextMoveToPoint(ctxt, element.points[0].x, element.points[0].y);
                    break;
                    
                case PathElementType::AddLineToPoint:
                    CGContextAddLineToPoint(ctxt, element.points[0].x, element.points[0].y);
                    break;
                    
                case PathElementType::AddQuadCurveToPoint:
                    CGContextAddQuadCurveToPoint(ctxt, element.points[1].x, element.points[1].y, element.points[0].x, element.points[0].y);
                    break;
                    
                case PathElementType::AddCurveToPoint:
                    CGContextAddCurveToPoint(ctxt, element.points[1].x, element.points[1].y, element.points[2].x, element.points[2].y, element.points[0].x, element.points[0].y);
                    break;
                    
                case PathElementType::CloseSubPath:
                    CGContextClosePath(ctxt);
                    break;
            }
        }
    }
}
