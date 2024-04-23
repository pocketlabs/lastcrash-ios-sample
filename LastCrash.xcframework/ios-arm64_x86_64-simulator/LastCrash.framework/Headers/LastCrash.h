//
//  LastCrash.h
//  LastCrash
//
//  Created by Kyle Shank on 9/12/19.
//  Copyright © 2019 Kyle Shank. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for LastCrash.
FOUNDATION_EXPORT double LastCrashVersionNumber;

//! Project version string for LastCrash.
FOUNDATION_EXPORT const unsigned char LastCrashVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <LastCrash/PublicHeader.h>

@protocol LastCrashDelegate
@required
-(void)lastCrashDidCrash;
@end

@interface LastCrash : NSObject
+(void)configure:(NSString*)apiKey;
+(void)setDelegate:(id<LastCrashDelegate>)delegate;
+(void)enabledLogging;
+(void)disableLogging;
+(void)pause;
+(void)unpause;
+(void)send;
+(void)event:(NSString*)name;
+(void)event:(NSString*)name value:(NSString*)value;
+(void)applicationInitialized;
@end
