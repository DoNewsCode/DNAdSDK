//
//  DNAdSDKManager.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/28.
//  Copyright © 2020 Kinsun. All rights reserved.
//

//  当前测试通过的SDK版本
//  --百度 = 4.67
//  --穿山甲 = 3.3.0.5
//  --广点通 = 4.11.12
//  --快手 = 3.3.5
//  --Sigmob = 2.22.0
//  --Mintegral = 6.6.8
//  请尽量使用上述版本，其他版本未经过测试
//  快手SDK不支持x86构架所以在使用模拟器环境下，会在控制台显示没有导入快手的包，也无法展示快手广告，该错误为正常现象。

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

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
@property (nonatomic, copy, nullable) void (^AVAudioSessionControlCallback)(BOOL isNeedStopBackgroundSound);
/// 当上面的回调没有被实现，SDK需要暂停或恢复背景音乐的时候会设置下面的值，入无特殊需求请不要更改。
/// 如果您希望应用在播放广告的时候视频媒体是不随静音按钮状态而静音的请设置suspendBackgroundSoundAudioSessionCategory = AVAudioSessionCategoryPlayback
/// 当SDK需要暂停背景音乐的时候，会将`AVAudioSession setCategory`设置下面的值默认=AVAudioSessionCategorySoloAmbient
@property (nonatomic) AVAudioSessionCategory suspendBackgroundSoundAudioSessionCategory;
/// 当SDK需要恢复背景音乐的时候，会将`AVAudioSession setCategory`设置下面的值默认=AVAudioSessionCategoryAmbient
@property (nonatomic) AVAudioSessionCategory resumeBackgroundSoundAudioSessionCategory;

+ (instancetype)sharedManager;

/// 请在app启动Appdelegate中尽早调用-startService，否则会导致SDK无法正常工作
- (void)startService;

/// 打印SDK依赖所有联盟广告供应商SDK的信息及版本，可以用来检查SDK支持情况
- (NSString *)printAllSDKVersionInfo;

@end

NS_ASSUME_NONNULL_END
