//
//  DNFullscreenVideoAd.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/8/21.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNAdDelegateCallbackProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class DNFullscreenVideoAd;
@protocol DNFullscreenVideoAdDelegate <NSObject>

/// 全屏视频广告数据加载成功回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdDidLoad:(DNFullscreenVideoAd *)fullscreenVideoAd;

/// 全屏视频广告各种错误与失败回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
/// @param error 错误信息
- (void)fullscreenVideoAd:(DNFullscreenVideoAd *)fullscreenVideoAd didFailWithError:(NSError *)error;

/// 全屏视频广告视频资源加载成功回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdVideoDidLoad:(DNFullscreenVideoAd *)fullscreenVideoAd;

/// 全屏视频广告即将显示回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdWillVisible:(DNFullscreenVideoAd *)fullscreenVideoAd;

/// 全屏视频广告已经显示回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdDidVisible:(DNFullscreenVideoAd *)fullscreenVideoAd;

/// 全凭视频广告即将关闭回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdWillClose:(DNFullscreenVideoAd *)fullscreenVideoAd;

/// 全凭视频广告已经关闭回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdDidClose:(DNFullscreenVideoAd *)fullscreenVideoAd;

/// 全屏视频广告点击回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdDidClick:(DNFullscreenVideoAd *)fullscreenVideoAd;

/// 全屏视频广告视频播放完成回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdDidPlayFinish:(DNFullscreenVideoAd *)fullscreenVideoAd;

/// 全屏视频广告点击跳过回调
/// @param fullscreenVideoAd DNFullscreenVideoAd对象本身
- (void)fullscreenVideoAdDidClickSkip:(DNFullscreenVideoAd *)fullscreenVideoAd;

@end

@interface DNFullscreenVideoAd : NSObject <DNAdDelegateCallbackProtocol>

/// 代理对象
@property (nonatomic, weak) id <DNFullscreenVideoAdDelegate> delegate;

@property (nonatomic, copy, readonly) NSString *placeId;
/// 默认=NO。
/// 此方法如果设置为YES则将会在-fullscreenVideoShowInController:调用时自动查找传入控制器的栈顶控制器，以避免广告无法正常弹出的问题。
@property (nonatomic, assign, getter=isAdShowCompatibilityMode) BOOL adShowCompatibilityMode;

/// 构造方法
/// @param placeId placeId - 广告位 ID
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 加载广告
- (void)loadAD;
 
/// 展示全屏视频
/// @param controller 用于展示激励视频的控制器
- (void)fullscreenVideoShowInController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
