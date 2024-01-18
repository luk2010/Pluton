//!
//! @file NSView+Pl.h
//! @author Luk2010
//! @date 2024/01/18
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_NSVIEW_PL_H__
#define __PL_NSVIEW_PL_H__

#include "Pl/View.h"

@interface NSView (Pl)

- (Pl::View*) Pl;

- (void) setPl:(Pl::View*)hdl;

@end

#endif
