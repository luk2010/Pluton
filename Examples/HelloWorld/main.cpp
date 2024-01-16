//! 
//! @file Pluton/Examples/HelloWorld/main.cpp
//! @author Luk2010
//! @date 2024/01/15
//! @copyright Atlanti's Corp(r) 2024
//! 

#include "Pl/Pl.h"

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
    }
};

int main(int argc, char** argv) 
{
    return MyApp().run(argc, argv);
}
