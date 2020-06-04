//
//  DNInterstitialAd.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/15.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DNAdDelegateCallbackProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class DNInterstitialAd, UIViewController;
@protocol DNInterstitialAdDelegate <NSObject>

@optional
/// 当接收服务器返回的广告数据成功且预加载后调用该函数
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDidLoadSuccessForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 当接收服务器返回的广告数据失败后调用该函数
/// @param interstitialAd interstitialAd对象本身
/// @param error 错误信息
- (void)interstitialAdDidLoadFaildForInterstitialAd:(DNInterstitialAd *)interstitialAd error:(NSError *)error;

/// 插屏广告即将展示回调该函数
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdWillVisibleForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 插屏广告展示结束回调该函数
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDidClosedForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 插屏广告曝光回调
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDidExposureForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 插屏广告点击回调
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDidClickForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 全屏广告页将要关闭
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDetailsDidClosedForInterstitialAd:(DNInterstitialAd *)interstitialAd;

@end

@interface DNInterstitialAd : NSObject <DNAdDelegateCallbackProtocol>

/// 代理对象
@property (nonatomic, weak) id <DNInterstitialAdDelegate> delegate;

@property (nonatomic, copy, readonly) NSString *placeId;

/// 构造方法
/// @param placeId placeId - 广告位 ID
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 加载广告方法
- (void)loadAD;
 
/// 展示插屏广告
/// @param controller 用于展示插屏的控制器
- (void)interstitialAdShowInController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
