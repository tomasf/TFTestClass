//
//  TFTestObject.c
//  ClassTest
//
//  Created by Tomas Franzén on 2012-09-02.
//  Copyright (c) 2012 Tomas Franzén. All rights reserved.
//

#include "TFTestObject.h"
#import "CFRuntime.h"


struct __TFTestObject {
	CFRuntimeBase base;
	int integer;
};


static void TFTestObjectFinalize(CFTypeRef cf) {
	//printf("finalize\n");
}


static CFStringRef TFTestObjectCopyDescription(CFTypeRef object) {
	TFTestObjectRef testObject = (TFTestObjectRef)object;
	return CFStringCreateWithFormat(CFGetAllocator(object), NULL, CFSTR("<TFTestObject %p: %d>"), testObject, testObject->integer);
}


static Boolean TFTestObjectEqual(CFTypeRef obj1, CFTypeRef obj2) {	
	return ((TFTestObjectRef)obj1)->integer == ((TFTestObjectRef)obj2)->integer;
}


CFTypeID TFTestObjectGetTypeID(void) {
	static dispatch_once_t predicate;
	static CFTypeID typeID = _kCFRuntimeNotATypeID;
	
	dispatch_once(&predicate, ^{
		static const CFRuntimeClass class = {
			.version = 0,
			.className = "TFTestObject",
			.init = NULL,
			.copy = NULL,
			.finalize = TFTestObjectFinalize,
			.equal = TFTestObjectEqual,
			.hash = NULL,
			.copyFormattingDesc = NULL,
			.copyDebugDesc = TFTestObjectCopyDescription,
		};
		
		typeID = _CFRuntimeRegisterClass(&class);
	});
	
	return typeID;
}



TFTestObjectRef TFTestObjectCreate(CFAllocatorRef allocator, int integer) {
	CFIndex contentSize = sizeof(struct __TFTestObject) - sizeof(CFRuntimeBase);
	TFTestObjectRef object = (TFTestObjectRef)_CFRuntimeCreateInstance(allocator, TFTestObjectGetTypeID(), contentSize, NULL);
	
	object->integer = integer;
	return object;
}


void TFTestObjectIncrement(TFTestObjectRef testObject) {
	testObject->integer++;
}


void TFTestObjectDecrement(TFTestObjectRef testObject) {
	testObject->integer--;
}


int TFTestObjectGetInteger(TFTestObjectRef testObject) {
	return testObject->integer;
}


void TFTestObjectSetInteger(TFTestObjectRef testObject, int integer) {
	testObject->integer = integer;
}