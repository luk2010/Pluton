//!
//! @file Pl/Window.mm
//! @author Luk2010
//! @date 2024/01/15
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/Window.h"

@interface PLWindowDelegate : NSObject < NSWindowDelegate >
{
    Pl::Window* _window;
}

- (instancetype)initWithPl:(Pl::Window*)wnd;

@end

@implementation PLWindowDelegate

- (instancetype)initWithPl:(Pl::Window*)wnd
{
    self = [super init];
    if (self)
        _window = wnd;
    return self;
}

- (void)windowDidMove:(NSNotification *)notification
{
    CGPoint location = [(NSWindow*)notification.object frame].origin;
    _window->onMove({ location.x, location.y });
}

- (void)windowDidResize:(NSNotification *)notification
{
    CGSize size = [(NSWindow*)notification.object frame].size;
    _window->onSize({ size.width, size.height });
}

- (void)windowWillClose:(NSNotification *)notification
{
    _window->onClose();
}

@end

namespace Pl
{
    static NSWindowStyleMask NSWindowStyleMaskWithPl(const Window::Style& rhs)
    {
        NSWindowStyleMask mask = 0;
        
        if (rhs.closable) mask |= NSWindowStyleMaskClosable;
        if (rhs.resizable) mask |= NSWindowStyleMaskResizable;
        if (rhs.titled) mask |= NSWindowStyleMaskTitled;
        
        return mask;
    }
    
    static Window::Style WindowStyleWithNSWindowStyleMask(NSWindowStyleMask mask)
    {
        Window::Style rhs;
        
        rhs.closable = mask & NSWindowStyleMaskClosable;
        rhs.resizable = mask & NSWindowStyleMaskResizable;
        rhs.titled = mask & NSWindowStyleMaskTitled;
        
        return rhs;
    }
    
    Window::Window(const Rect& rect, const Window::Style& style, const std::string& title)
    {
        mHandle = [[NSWindow alloc] initWithContentRect:NSMakeRect(rect.origin.x,
                                                                   rect.origin.y,
                                                                   rect.size.width,
                                                                   rect.size.height)
                                              styleMask:NSWindowStyleMaskWithPl(style)
                                                backing:NSBackingStoreBuffered
                                                  defer:NO];
        mDelegate = [[PLWindowDelegate alloc] initWithPl:this];
        
        [(NSWindow*)mHandle setDelegate:mDelegate];
        [(NSWindow*)mHandle setReleasedWhenClosed:FALSE];
        [(NSWindow*)mHandle setTitle:[NSString stringWithUTF8String:title.data()]];
    }
    
    Window::Window(id handle)
    {
        if (![handle isKindOfClass:NSWindow.class])
            throw WinSysError("Pl::Window: Given id is not of kind NSWindow.");
        
        mHandle = handle;
        mDelegate = [[PLWindowDelegate alloc] initWithPl:this];
        
        [(NSWindow*)mHandle setDelegate:mDelegate];
        [(NSWindow*)mHandle setReleasedWhenClosed:FALSE];
    }
    
    id Window::handle() const
    {
        return mHandle;
    }
    
    Window::~Window()
    {
        
    }
    
    void Window::setFrame(const Rect& rect)
    {
        [(NSWindow*)mHandle setFrame:NSMakeRect(rect.origin.x,
                                                rect.origin.y,
                                                rect.size.width,
                                                rect.size.height)
                             display:YES
                             animate:YES];
    }
    
    Rect Window::frame() const
    {
        NSRect rect = [(NSWindow*)mHandle frame];
        
        return Rect({ rect.origin.x, rect.origin.y },
                    { rect.size.width, rect.size.height });
    }
    
    Rect Window::frameOfContent() const
    {
        NSRect rect = [(NSWindow*)mHandle contentLayoutRect];
        
        return Rect({ rect.origin.x, rect.origin.y },
                    { rect.size.width, rect.size.height });
    }
    
    void Window::setStyle(const Window::Style& style)
    {
        [(NSWindow*)mHandle setStyleMask:NSWindowStyleMaskWithPl(style)];
    }
    
    Window::Style Window::style() const
    {
        return WindowStyleWithNSWindowStyleMask([(NSWindow*)mHandle styleMask]);
    }
    
    void Window::setTitle(const std::string& title)
    {
        [(NSWindow*)mHandle setTitle:[NSString stringWithUTF8String:title.data()]];
    }
    
    std::string Window::title() const
    {
        return std::string([[(NSWindow*)mHandle title] UTF8String]);
    }
    
    void Window::show()
    {
        [(NSWindow*)mHandle makeKeyAndOrderFront:nil];
    }
    
    void Window::center()
    {
        [(NSWindow*)mHandle center];
    }
    
    void Window::close()
    {
        [(NSWindow*)mHandle performClose:nil];
    }
    
    void Window::onMove(const Point& newOrigin)
    {
        
    }
    
    void Window::onSize(const Size& newSize)
    {
        
    }
    
    void Window::onClose()
    {
        
    }
}
