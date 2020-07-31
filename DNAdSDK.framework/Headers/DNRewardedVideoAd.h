//
//  DNRewardedVideoAd.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/15.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DNAdDelegateCallbackProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class DNRewardedVideoAd, UIViewController;
@protocol DNRewardedVideoAdDelegate <NSObject>

@optional
/// 广告数据加载成功回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidLoad:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告各种错误信息回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
/// @param error 错误信息
- (void)rewardVideoAd:(DNRewardedVideoAd *)rewardedVideoAd didFaildWithError:(NSError *)error;
 
/// 视频数据下载成功回调，已经下载过的视频会直接回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdVideoDidLoad:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频播放页即将展示回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdWillVisible:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告曝光回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidExposed:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频播放页关闭回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidClose:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告信息点击回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidClicked:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告播放达到激励条件回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidRewardEffective:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告视频播放完成
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidPlayFinish:(DNRewardedVideoAd *)rewardedVideoAd;

@end

@interface DNRewardedVideoAd : NSObject <DNAdDelegateCallbackProtocol>

/// 代理对象
@property (nonatomic, weak) id <DNRewardedVideoAdDelegate> delegate;

@property (nonatomic, copy, readonly) NSString *placeId;

/// 构造方法
/// @param placeId placeId - 广告位 ID
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 加载广告方法 支持 iOS9.0 及以上系统
- (void)loadAD;
 
/// 展示激励视频
/// @param controller 用于展示激励视频的控制器
- (void)rewardedVideoShowInController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
