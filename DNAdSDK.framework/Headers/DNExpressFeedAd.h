//
//  DNExpressFeedAd.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/15.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DNExpressFeedAdView.h"
#import "DNAdDelegateCallbackProtocol.h"
#import "DNAdSlot.h"

NS_ASSUME_NONNULL_BEGIN

@class DNExpressFeedAd;
@protocol DNExpressFeedAdDelegate <NSObject>
@optional;

/// 拉取原生模板广告成功
/// @param expressFeedAd expressFeedAd对象本身
/// @param views 模版广告视图数组
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd loadSuccessWithViews:(NSArray<DNExpressFeedAdView *> *)views;

/// 拉取原生模板广告失败
/// @param expressFeedAd expressFeedAd对象本身
/// @param error 错误信息
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd loadFailureWithError:(NSError *)error;

/// 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd renderSuccessForView:(DNExpressFeedAdView *)view;

/// 原生模板广告渲染失败
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd renderFailureForView:(DNExpressFeedAdView *)view;

/// 原生模板广告曝光回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd exposureForView:(DNExpressFeedAdView *)view;

/// 原生模板广告点击回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd didClickedForView:(DNExpressFeedAdView *)view;

/// 原生模板广告被关闭
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd didClosedForView:(DNExpressFeedAdView *)view;

/// 即将打开广告落地页
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd willShowDetailsForView:(DNExpressFeedAdView *)view;

/// 关闭广告落地页
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd didCloseDetailsForView:(DNExpressFeedAdView *)view;

/// 播放器状态发生变化时回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param status 当前播放器状态
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd playerDidChangedStatus:(DNExpressPlayerStatus)status forView:(DNExpressFeedAdView *)view;

/// 视频广告播放完毕
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd playerDidPlayFinishForView:(DNExpressFeedAdView *)view;

@end

@interface DNExpressFeedAd : NSObject <DNAdDelegateCallbackProtocol>

/// 信息流数据结果状态的 代理对象
@property (nonatomic, weak) id<DNExpressFeedAdDelegate> delegate;

/// [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 广告位
@property (nonatomic, readonly, strong) DNAdSlot *slot;


/// 请求广告
- (void)loadAdWithSlot:(DNAdSlot *)slot;

@end

NS_ASSUME_NONNULL_END
