//
//  DNAdSDKManager.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/28.
//  Copyright © 2020 Kinsun. All rights reserved.
//

//  当前测试通过的SDK版本
//  --百度 = 4.67
//  --穿山甲 = 3.1.0.4
//  --广点通 = 4.11.9
//  --快手 = 3.2.1
//  --Sigmob = 2.19.1
//  --Mintegral = 6.3.5.0
//  请务必使用上述版本，其他版本未经过测试

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, DNAdSDKApiType) {
    DNAdSDKApiTypeRelease = 0,
    DNAdSDKApiTypeDebug = 1 //注意⚠️！！！Debug环境为demo使用的，如需要自己测试请配置为Release环境
};

NS_ASSUME_NONNULL_BEGIN

@interface DNAdKitManager : NSObject

/// 注意⚠️！！！Debug环境为demo使用的，如需要自己测试请配置为Release环境，默认=DNAdSDKApiTypeRelease
@property (nonatomic, assign) DNAdSDKApiType apiType;

@property (nonatomic, strong, readonly) NSString *SDKVersion;
/// 网络请求超时时间，默认为3
@property (nonatomic) NSTimeInterval timeoutInterval;

@property (nonatomic, assign, getter=isShowDebugLog) BOOL showDebugLog;

/// 媒体控制回调（需在startService前调用），该方法会回调控制的需求，每当SDK设定背景音乐需要关闭或恢复时都会回调此方法。
/// 如果此回调为空SDK将会在内部控制AVAudioSession，从而达到控制背景音乐的要求。
/// 如果您的应用对于声音控制比较严格请使用此回调以禁用SDK对AVAudioSession的控制
/// 注：文档中已开源此项内部实现，可供您参考。此方法对于某些供应商的SDK可能无效，烦请自测。
@property (nonatomic, copy, nullable) void (^AVAudioSessionContrlCallback)(BOOL isNeedStopBackgroundSound);

+ (instancetype)sharedManager;

/// 请在app启动Appdelegate中尽早调用-startService，否则会导致SDK无法正常工作
- (void)startService;

/// 打印SDK依赖所有联盟广告供应商SDK的信息及版本，可以用来检查SDK支持情况
- (NSString *)printAllSDKVersionInfo;

@end

NS_ASSUME_NONNULL_END
