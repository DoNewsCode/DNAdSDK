//
//  DNAdSDKManager.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/28.
//  Copyright © 2020 Kinsun. All rights reserved.
//

//  当前测试通过的SDK版本
//  --百度 = 4.67
//  --穿山甲 = 2.9.5.6
//  --广点通 = 4.11.5/4.11.7/4.11.8
//  其他烦请自测，如有问题请及时联系我们

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, DNAdSDKApiType) {
    DNAdSDKApiTypeRelease = 0,
    DNAdSDKApiTypeDebug = 1
};

NS_ASSUME_NONNULL_BEGIN

@interface DNAdKitManager : NSObject

@property (nonatomic, assign) DNAdSDKApiType apiType;

@property (nonatomic, strong, readonly) NSString *SDKVersion;
/// 网络请求超时时间，默认为3
@property (nonatomic) NSTimeInterval timeoutInterval;

@property (nonatomic, assign, getter=isShowDebugLog) BOOL showDebugLog;

+ (instancetype)sharedManager;

- (void)startService;

- (void)printAllSDKVersionInfo;

@end

NS_ASSUME_NONNULL_END
