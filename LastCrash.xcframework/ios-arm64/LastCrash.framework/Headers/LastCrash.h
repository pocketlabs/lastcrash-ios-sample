//
//  LastCrash.h
//  LastCrash
//
//  Created by Kyle Shank on 9/12/19.
//  Copyright © 2019 Kyle Shank. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LastCrash/LastCrashURLProtocol.h>

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
+(void)configure:( NSString* _Nonnull  )apiKey;
+(void)setDelegate:(id<LastCrashDelegate> _Nullable)delegate;
+(void)enabledLogging;
+(void)disableLogging;
+(void)pause;
+(void)unpause;
+(void)send;
+(void)event:(NSString* _Nonnull)name;
+(void)event:(NSString* _Nonnull )name value:(NSString* _Nonnull )value;
+(void)applicationInitialized;
+(void)addNetworkTrackingToDefaultSession;
+(void)setNetworkTrackingSessionConfiguration:(NSURLSessionConfiguration* _Nonnull )configuration;
+(nullable NSURLSessionConfiguration*)networkTrackingSessionConfiguration;
+(void)networkEvent:(NSURLRequest* _Nonnull )request response:(NSHTTPURLResponse* _Nullable)response  duration:(CFAbsoluteTime)duration taskErrorCode:(NSInteger)errorCode cancelled:(BOOL)cancelled requestBytes:(long)requestBytes responseBytes:(long)responseBytes;
@end
