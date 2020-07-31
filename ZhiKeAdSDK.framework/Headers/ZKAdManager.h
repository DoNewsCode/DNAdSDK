//
//  ZKAdManager.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/5/9.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZhiKeAdSDKApiType) {
    ZhiKeAdSDKApiTypeRelease = 0,
    ZhiKeAdSDKApiTypeDebug = 1
};

NS_ASSUME_NONNULL_BEGIN

@interface ZKAdManager : NSObject

+ (instancetype)sharedManager;

@property (nonatomic, assign) ZhiKeAdSDKApiType apiType;
@property (nonatomic, strong, readonly) NSString *SDKVersion;
/// 网络请求超时时间，默认为3
@property (nonatomic) NSTimeInterval timeoutInterval;

- (void)startService;

@end

NS_ASSUME_NONNULL_END
