//!
//! @file PLView.h
//! @author Luk2010
//! @date 2024/01/18
//! @copyright Atlanti's Corp(r) 2024
//!

#ifndef __PL_PLVIEW_H__
#define __PL_PLVIEW_H__

#include "Pl/OSX/NSView+Pl.h"

@interface PLView : NSView

- (instancetype)initWithPl:(Pl::View*)hdl frameRect:(NSRect)rect;

@end

#endif
