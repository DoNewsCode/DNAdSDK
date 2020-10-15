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

NS_ASSUME_NONNULL_BEGIN

@class DNExpressFeedAd;
@protocol DNExpressFeedAdDelegate <NSObject>
@optional

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

@property (nonatomic, copy, readonly) NSString *placeId;
@property (nonatomic, assign, readonly) CGSize adSize;
/// 信息流数据结果状态的 代理对象
@property (nonatomic, weak) id<DNExpressFeedAdDelegate> delegate;
/// [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;
/// 默认=NO。
/// 此方法如果设置为YES则将会在聚合SDK最后一个可控Controller时自动查找传入控制器的栈顶控制器，以避免广告无法正常弹出的问题。
@property (nonatomic, assign, getter=isAdShowCompatibilityMode) BOOL adShowCompatibilityMode;

/// 指定构造器
/// @param placeId 广告位id
/// @param adSize 广告尺寸
- (instancetype)initWithPlaceId:(NSString *)placeId adSize:(CGSize)adSize;

/// 请求信息流广告
/// @param count 请求广告的数量
- (void)loadAdWithCount:(NSInteger)count;

@end

NS_ASSUME_NONNULL_END
