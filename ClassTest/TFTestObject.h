//
//  TFTestObject.h
//  ClassTest
//
//  Created by Tomas Franzén on 2012-09-02.
//  Copyright (c) 2012 Tomas Franzén. All rights reserved.
//

#ifndef ClassTest_TFTestObject_h
#define ClassTest_TFTestObject_h

#import <CoreFoundation/CoreFoundation.h>

typedef struct __TFTestObject *TFTestObjectRef;

extern CFTypeID TFTestObjectGetTypeID(void);
extern TFTestObjectRef TFTestObjectCreate(CFAllocatorRef allocator, int integer);

extern void TFTestObjectIncrement(TFTestObjectRef testObject);
extern void TFTestObjectDecrement(TFTestObjectRef testObject);
extern int TFTestObjectGetInteger(TFTestObjectRef testObject);
extern void TFTestObjectSetInteger(TFTestObjectRef testObject, int integer);

#endif