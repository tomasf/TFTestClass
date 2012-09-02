//
//  main.m
//  ClassTest
//
//  Created by Tomas Franzén on 2012-09-02.
//  Copyright (c) 2012 Tomas Franzén. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TFTestObject.h"


int main(int argc, const char * argv[]) {
	@autoreleasepool {
	    
		TFTestObjectRef object = TFTestObjectCreate(NULL, 15);
		TFTestObjectIncrement(object);
		
	    NSLog(@"Description: %@", object);
	    
		NSArray *array = @[@"foo", (__bridge id)object];
		NSLog(@"Array: %@", array);
		
		id object2 = CFBridgingRelease(TFTestObjectCreate(NULL, 100));
		id object3 = CFBridgingRelease(TFTestObjectCreate(NULL, 16));
		
		NSLog(@"Equal to %@? %d", object2, [(__bridge id)object isEqual:object2]);
		NSLog(@"Equal to %@? %d", object3, [(__bridge id)object isEqual:object3]);
		
		CFRelease(object);
	}
    return 0;
}