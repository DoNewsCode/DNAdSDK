//
//  DNExpressDrawAd.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/8/6.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DNExpressDrawAdView.h"
#import "DNAdMacros.h"

NS_ASSUME_NONNULL_BEGIN

@class DNExpressDrawAd;
@protocol DNExpressDrawAdDelegate <NSObject>
@optional;

/// 拉取原生模板广告成功
/// @param expressDrawAd expressDrawAd对象本身
/// @param views 模版广告视图数组
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd loadSuccessWithViews:(NSArray<DNExpressDrawAdView *> *)views;

/// 拉取原生模板广告失败
/// @param expressDrawAd expressDrawAd对象本身
/// @param error 错误信息
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd loadFailureWithError:(NSError *)error;

/// 原生模板广告渲染成功,。
/// @param expressDrawAd expressDrawAd对象本身
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd renderSuccessForView:(DNExpressDrawAdView *)view;

/// 原生模板广告渲染失败
/// @param expressDrawAd expressDrawAd对象本身
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd renderFailureForView:(DNExpressDrawAdView *)view;

/// 原生模板广告曝光回调
/// @param expressDrawAd expressDrawAd对象本身
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd exposureForView:(DNExpressDrawAdView *)view;

/// 原生模板广告点击回调
/// @param expressDrawAd expressDrawAd对象本身
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd didClickedForView:(DNExpressDrawAdView *)view;

/// 原生模板广告被关闭
/// @param expressDrawAd expressDrawAd对象本身
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd didClosedForView:(DNExpressDrawAdView *)view;

/// 即将打开广告落地页
/// @param expressDrawAd expressDrawAd对象本身
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd willShowDetailsForView:(DNExpressDrawAdView *)view;

/// 关闭广告落地页
/// @param expressDrawAd expressDrawAd对象本身
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd didCloseDetailsForView:(DNExpressDrawAdView *)view;

/// 播放器状态发生变化时回调
/// @param expressDrawAd expressDrawAd对象本身
/// @param status 当前播放器状态
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd playerDidChangedStatus:(DNExpressPlayerStatus)status forView:(DNExpressDrawAdView *)view;

/// 视频广告播放完毕
/// @param expressDrawAd expressDrawAd对象本身
/// @param view 模板View
- (void)expressDrawAd:(DNExpressDrawAd *)expressDrawAd playerDidPlayFinishForView:(DNExpressDrawAdView *)view;

@end

@interface DNExpressDrawAd : NSObject

@property (nonatomic, copy, readonly) NSString *placeId;
/// 代理对象
@property (nonatomic, weak) id <DNExpressDrawAdDelegate> delegate;
/// [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 指定构造器
/// @param placeId 广告位id
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 请求信息流广告
/// @param count 请求广告的数量
- (void)loadAdWithCount:(NSInteger)count;

@end

NS_ASSUME_NONNULL_END
