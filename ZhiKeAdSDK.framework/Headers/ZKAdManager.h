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
    ZhiKeAdSDKApiTypeDebug = 1 //注意⚠️！！！Debug环境为demo使用的，如需要自己测试请配置为Release环境
};

NS_ASSUME_NONNULL_BEGIN

@interface ZKAdManager : NSObject

/// 注意⚠️！！！Debug环境为demo使用的，如需要自己测试请配置为Release环境，默认=ZhiKeAdSDKApiTypeRelease
@property (nonatomic, assign) ZhiKeAdSDKApiType apiType;

@property (nonatomic, strong, readonly) NSString *SDKVersion;
/// 网络请求超时时间，默认为3
@property (nonatomic) NSTimeInterval timeoutInterval;

@property (nonatomic, copy, nullable) NSString *appId;

@property (nonatomic, copy, nullable) void (^AVAudioSessionContrlCallback)(BOOL isNeedStopBackgroundSound);

+ (instancetype)sharedManager;

- (void)startService;

@end

NS_ASSUME_NONNULL_END
