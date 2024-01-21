//! 
//! @file Pluton/Examples/HelloWorld/main.cpp
//! @author Luk2010
//! @date 2024/01/15
//! @copyright Atlanti's Corp(r) 2024
//! 

#include "Pl/Pl.h"

class MyView : public Pl::Element
{
    Pl::Ref < Pl::Element > mLeftMenu;
    Pl::Ref < Pl::Element > mContent;
    
public:
    
    using Pl::Element::Element;
    
    void layout()
    {
        if (!mLeftMenu || !mContent)
            return;
        
        auto fr = bounds();
        
        fr.size.width -= 250;
        mContent->setFrame(fr);
        
        fr.size.width = 250;
        mLeftMenu->setFrame(fr);
    }
    
protected:
    
    virtual void onCreate()
    {
        Pl::View::onCreate();
        
        setBackgroundColor(Pl::RGBAColor(0.8, 0.7, 0.6));
        
        auto fr = bounds();
        
        auto lmfr = fr;
        lmfr.size.width = 250;
            
        mLeftMenu = Pl::Make < Pl::Element >(lmfr);
        mLeftMenu->setBackgroundColor(Pl::RGBAColor(0.6, 0.7, 0.8, 0.5));
        addChild(mLeftMenu);
        
        lmfr.size.width = fr.size.width - 250;
            
        mContent = Pl::Make < Pl::Element >(lmfr);
        addChild(mContent);
    }
};

class MyApp : public Pl::Application
{
    Pl::Ref < Pl::Window > mWindow;
    
public:
    
    void onLaunched()
    {
        activate();
        
        mWindow = Pl::Make < Pl::Window >(Pl::Size{1024, 768},
                                          Pl::Window::Style(),
                                          "Hello World!");
        
        mWindow->show();
        mWindow->center();
        
        auto view = Pl::Make < MyView >(mWindow->frameOfContent().size);
        mWindow->setContentView(view);
    }
};

int main(int argc, char** argv) 
{
    Pl::PluginManager::Get().loadDirectory("Plugins");
    
    return MyApp().run(argc, argv);
}
