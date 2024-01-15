//!
//! @file Pl/Application.mm
//! @author Luk2010
//! @date 2024/01/15
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/Application.h"

@interface PLApplicationDelegate : NSObject < NSApplicationDelegate >
{
    Pl::Application* _app;
}

- (instancetype)initWithPl:(Pl::Application*)app;

@end

@implementation PLApplicationDelegate

- (instancetype)initWithPl:(Pl::Application *)app
{
    self = [super init];
    
    if (self)
        _app = app;
    
    return self;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return _app->shouldTerminateAfterLastWindowClosed();
}

- (void)applicationDidFinishLaunching:(NSNotification *)notification
{
    _app->onLaunched();
}

- (void)applicationDidBecomeActive:(NSNotification *)notification
{
    _app->onActivated();
}

- (void)applicationWillTerminate:(NSNotification *)notification
{
    _app->onTerminate();
}

@end

namespace Pl
{
    struct ApplicationPriv
    {
        PLApplicationDelegate* delegate = [PLApplicationDelegate alloc];
    };
    
    Application* _instance = NULL;
    
    Application::Application()
    {
        if (_instance)
            throw ApplicationAlreadyExists("Pl::Application: App already exists.");
        
        _instance = this;
        
        ApplicationPriv* priv = new ApplicationPriv;
        [priv->delegate initWithPl:this];
        mPriv = priv;
        
        NSApp = [NSApplication sharedApplication];
        NSApp.delegate = priv->delegate;
        NSApp.activationPolicy = NSApplicationActivationPolicyRegular;
    }
    
    Application::~Application()
    {
        delete (ApplicationPriv*) mPriv;
    }
    
    int Application::run(int argc, char** argv)
    {
        [NSApp run];
        return EXIT_SUCCESS;
    }
    
    void Application::activate()
    {
        [NSApp activateIgnoringOtherApps:YES];
    }
    
    void Application::terminate()
    {
        [NSApp terminate:nil];
    }
    
    void Application::setShouldTerminateAfterLastWindowClosed(bool value)
    {
        mShouldTerminateAfterLastWindowClosed = value;
    }
    
    bool Application::shouldTerminateAfterLastWindowClosed() const
    {
        return mShouldTerminateAfterLastWindowClosed.load();
    }
    
    void Application::onLaunched()
    {
        
    }
    
    void Application::onActivated()
    {
        
    }
    
    void Application::onTerminate()
    {
        
    }
}
