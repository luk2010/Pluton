//!
//! @file Pl/Node.h
//! @author Luk2010
//! @date 2024/01/18
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_NODE_H__
#define __PL_NODE_H__

#include "Pl/Platform.h"

namespace Pl
{
    PLUTON_DEFINE_ERROR(CannotAddNullChild)
    PLUTON_DEFINE_ERROR(CannotFindChild)
    
    template < class T >
    class Node : public std::enable_shared_from_this < T >
    {
    public:
        
        typedef Ref < T > RefT;
        typedef Weak < T > WkT;
        typedef std::vector < RefT > RefList;
        
    private:
        
        WkT mParent;
        RefList mChildren;
        
    public:
        
        virtual RefT parent() const
        {
            return mParent.lock();
        }
        
        virtual size_t childrenCount() const
        {
            return mChildren.size();
        }
        
        virtual RefT child(size_t index) const
        {
            return mChildren[index];
        }
        
    protected:
        
        virtual bool onWillAddChild(const RefT& child, const RefT& before)
        {
            return true;
        }
        
        virtual void onAddChild(const RefT& child)
        {
            
        }
        
        virtual bool onWillRemoveChild(const RefT& child)
        {
            return true;
        }
        
        virtual void onRemoveChild(const RefT& child)
        {
            
        }
        
        virtual void onNewParent(const RefT& parent)
        {
            mParent = parent;
        }
        
    public:
        
        virtual bool addChild(const RefT& child, const RefT& before = nullptr)
        {
            if (!child)
                throw CannotAddNullChild("Pl::Node: Cannot add Null child.");
            
            if (!onWillAddChild(child, before))
                return false;
            
            auto it = std::find(mChildren.begin(),
                                mChildren.end(),
                                before);
            
            mChildren.insert(it, child);
            child->onNewParent(this->shared_from_this());
            
            onAddChild(child);
            
            return true;
        }
        
        virtual bool removeChild(const RefT& child)
        {
            if (!child)
                return true;
            
            if (!onWillRemoveChild(child))
                return false;
            
            auto it = std::find(mChildren.begin(),
                                mChildren.end(),
                                child);
            
            if (it == mChildren.end())
                throw CannotFindChild("Pl::Node: Cannot find provided child.");
            
            mChildren.erase(it);
            
            child->onNewParent(nullptr);
            onRemoveChild(child);
            
            return true;
        }
    };
}

#endif
