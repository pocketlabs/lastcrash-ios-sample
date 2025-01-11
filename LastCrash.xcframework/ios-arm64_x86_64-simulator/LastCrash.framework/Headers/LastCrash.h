//
//  LastCrash.h
//  LastCrash
//
//  Created by Kyle Shank on 9/12/19.
//  Copyright © 2019 Kyle Shank. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LastCrash/LastCrashURLProtocol.h>
#import <UIKit/UIKit.h>

//! Project version number for LastCrash.
FOUNDATION_EXPORT double LastCrashVersionNumber;

//! Project version string for LastCrash.
FOUNDATION_EXPORT const unsigned char LastCrashVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <LastCrash/PublicHeader.h>

@protocol LastCrashReportSenderDelegate
@required
-(void)lastCrashReportSenderHandleCrash;
@end

@interface LastCrash : NSObject
+(void)configure:( NSString* _Nonnull  )apiKey;
+(void)setCrashReportSenderDelegate:(id<LastCrashReportSenderDelegate> _Nullable)crashReportSenderDelegate;
+(void)enabledLogging;
+(void)disableLogging;
+(void)pause;
+(void)unpause;
+(void)sendCrashes;
+(void)event:(NSString* _Nonnull)name;
+(void)event:(NSString* _Nonnull )name value:(NSString* _Nonnull )value;
+(void)applicationInitialized;
+(void)addNetworkTrackingToDefaultSession;
+(void)setNetworkTrackingSessionConfiguration:(NSURLSessionConfiguration* _Nonnull )configuration;
+(nullable NSURLSessionConfiguration*)networkTrackingSessionConfiguration;
+(void)networkEvent:(NSURLRequest* _Nonnull )request response:(NSHTTPURLResponse* _Nullable)response  duration:(CFAbsoluteTime)duration taskErrorCode:(NSInteger)errorCode cancelled:(BOOL)cancelled requestBytes:(long)requestBytes responseBytes:(long)responseBytes;
+(void)addMaskRect:(CGRect)rect maskId:(NSString* _Nonnull)maskId;
+(void)removeMaskRect:(NSString* _Nonnull)maskId;
+(void)removeAllMaskRects;
+(void)addMaskView:(UIView* _Nonnull)view;
+(void)removeMaskView:(UIView* _Nonnull)view;
+(void)removeAllMaskViews;
@end
