//!
//! @file Pl/Manager.h
//! @author Luk2010
//! @date 2024/01/21
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_MANAGER_H__
#define __PL_MANAGER_H__

#include "Pl/Platform.h"

namespace Pl
{
    PLUTON_DEFINE_ERROR(ManagerAlreadyHasEntry)
    
    template < class T, bool Unique = true >
    class Manager
    {
    public:
        
        typedef Ref < T > Ptr;
        typedef std::vector < Ptr > List;
        
    private:
        
        List mVals;
        
    public:
        
        virtual ~Manager()
        {
            clear();
        }
        
        void add(const Ptr& val)
        {
            if (!val) throw NullArg("Pl::Manager: Arg 'val' is null.");
            
            if constexpr (Unique == true)
            {
                auto it = std::find(mVals.begin(), mVals.end(), val);
                
                if (it != mVals.end())
                    throw ManagerAlreadyHasEntry("Pl::Manager: Entry already exists.");
            }
            
            mVals.push_back(val);
            onAdd(val);
        }
        
        void remove(const Ptr& val)
        {
            auto it = std::find(mVals.begin(), mVals.end(), val);
            
            if (it != mVals.end())
            {
                mVals.erase(it);
                onRemove(val);
            }
        }
        
        void clear()
        {
            while (!mVals.empty())
                remove(*mVals.rbegin());
        }
        
        void forEach(std::function < bool(const T&) > fun)
        {
            for (auto& val : mVals)
                if (fun(val))
                    return;
        }
        
        template < class Pfn >
        void forEach(Pfn&& fun)
        {
            for (auto& val : mVals)
                fun(val);
        }

        template < class Pfn >
        void forEach(Pfn&& fun) const
        {
            for (const auto& val : mVals)
                fun(val);
        }
        
        const auto& values() const
        {
            return mVals;
        }
        
    protected:
        
        virtual void onAdd(const Ptr& obj) { }
        virtual void onRemove(const Ptr& obj) { }
    };
}

#endif
