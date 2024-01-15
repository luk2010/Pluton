//! 
//! @file Pl/Application.h
//! @author Luk2010
//! @date 2024/01/15
//! @copyright Atlanti's Corp(r) 2024
//! 

#ifndef __PL_APPLICATION_H__
#define __PL_APPLICATION_H__

#include "Pl/Platform.h"

namespace Pl 
{
    class Application 
    {
        PLUTON_PRIVATE_DATA mPriv;

        std::atomic_bool mShouldTerminateAfterLastWindowClosed;

    public:
        
        static Application& Get();

        Application();

        virtual ~Application();

        virtual int run(int argc = 0, char** argv = NULL);
        
        virtual void activate();

        virtual void terminate();

        virtual void setShouldTerminateAfterLastWindowClosed(bool value);

        virtual bool shouldTerminateAfterLastWindowClosed() const;

    public:

        virtual void onLaunched();

        virtual void onActivated();

        virtual void onTerminate();
    };

    PLUTON_DEFINE_ERROR(ApplicationAlreadyExists)
}

#endif 
