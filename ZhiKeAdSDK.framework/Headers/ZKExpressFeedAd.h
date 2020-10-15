//
//  ZKExpressFeedAd.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/10/9.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZKExpressFeedAdView.h"
#import "ZKAdMacros.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZKExpressFeedAdDelegate;
@interface ZKExpressFeedAd : NSObject

@property (nonatomic, copy, readonly) NSString *placeId;
/// 信息流数据结果状态的 代理对象
@property (nonatomic, weak) id<ZKExpressFeedAdDelegate> delegate;
/// [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 指定构造器
/// @param placeId 广告位id
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 请求信息流广告
/// @param count 请求广告的数量
- (void)loadAdWithCount:(NSInteger)count;

@end

@protocol ZKExpressFeedAdDelegate <NSObject>
@optional

/// 拉取原生模板广告成功
/// @param expressFeedAd expressFeedAd对象本身
/// @param views 模版广告视图数组
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd loadSuccessWithViews:(NSArray<ZKExpressFeedAdView *> *)views;

/// 拉取原生模板广告失败
/// @param expressFeedAd expressFeedAd对象本身
/// @param error 错误信息
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd loadFailureWithError:(NSError *)error;

/// 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd renderSuccessForView:(ZKExpressFeedAdView *)view;

/// 原生模板广告渲染失败
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd renderFailureForView:(ZKExpressFeedAdView *)view;

/// 原生模板广告曝光回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd exposureForView:(ZKExpressFeedAdView *)view;

/// 原生模板广告点击回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd didClickedForView:(ZKExpressFeedAdView *)view;

/// 原生模板广告被关闭
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd didClosedForView:(ZKExpressFeedAdView *)view;

/// 即将打开广告落地页
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd willShowDetailsForView:(ZKExpressFeedAdView *)view;

/// 关闭广告落地页
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd didCloseDetailsForView:(ZKExpressFeedAdView *)view;

/// 播放器状态发生变化时回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param status 当前播放器状态
/// @param view 模板View
//- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd playerDidChangedStatus:(ZKExpressPlayerStatus)status forView:(ZKExpressFeedAdView *)view;

/// 视频广告播放完毕
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
//- (void)expressFeedAd:(ZKExpressFeedAd *)expressFeedAd playerDidPlayFinishForView:(ZKExpressFeedAdView *)view;

@end


NS_ASSUME_NONNULL_END
