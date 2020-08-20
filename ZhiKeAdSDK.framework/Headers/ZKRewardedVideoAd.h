//
//  ZKRewardedVideoAd.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/8/17.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZKRewardedVideoAdDelegate;
@class UIViewController;
@interface ZKRewardedVideoAd : NSObject

/// 代理对象
@property (nonatomic, weak) id <ZKRewardedVideoAdDelegate> delegate;

@property (nonatomic, copy, readonly) NSString *placeId;

/// 构造方法
/// @param placeId placeId - 广告位 ID
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 加载广告方法
- (void)loadAD;
 
/// 展示激励视频
/// @param controller 用于展示激励视频的控制器
- (void)rewardedVideoShowInController:(UIViewController *)controller;

@end

@protocol ZKRewardedVideoAdDelegate <NSObject>

@optional
/// 广告数据加载成功回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidLoad:(ZKRewardedVideoAd *)rewardedVideoAd;

/// 视频广告各种错误信息回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
/// @param error 错误信息
- (void)rewardVideoAd:(ZKRewardedVideoAd *)rewardedVideoAd didFaildWithError:(NSError *)error;
 
/// 视频数据下载成功回调，已经下载过的视频会直接回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdVideoDidLoad:(ZKRewardedVideoAd *)rewardedVideoAd;

/// 视频播放页即将展示回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdWillVisible:(ZKRewardedVideoAd *)rewardedVideoAd;

/// 视频广告曝光回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidExposed:(ZKRewardedVideoAd *)rewardedVideoAd;

/// 视频播放页关闭回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidClose:(ZKRewardedVideoAd *)rewardedVideoAd;

/// 视频广告信息点击回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidClicked:(ZKRewardedVideoAd *)rewardedVideoAd;

/// 视频广告播放达到激励条件回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidRewardEffective:(ZKRewardedVideoAd *)rewardedVideoAd;

/// 视频广告视频播放完成
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidPlayFinish:(ZKRewardedVideoAd *)rewardedVideoAd;

@end

NS_ASSUME_NONNULL_END
