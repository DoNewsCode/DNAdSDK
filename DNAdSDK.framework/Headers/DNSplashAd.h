//
//  DNSplashAd.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/27.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNAdDelegateCallbackProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class DNSplashAd;
@protocol DNSplashAdDelegate <NSObject>

@optional;
/// 开屏广告加载成功的回调
/// @param splashAd 产生该事件的 DNSplashAd 对象
- (void)splashAdDidLoadSuccess:(DNSplashAd *)splashAd;

///  开屏广告加载失败的回调
/// @param splashAd 产生该事件的 DNSplashAd 对象
/// @param error Error对象
- (void)splashAdDidLoadFaild:(DNSplashAd *)splashAd withError:(NSError *)error;

/// 开屏广告点击的回调
/// @param splashAd 产生该事件的 DNSplashAd 对象
- (void)splashAdClicked:(DNSplashAd *)splashAd;

/// 开屏广告点击关闭按钮的回调
/// @param splashAd 产生该事件的 DNSplashAd 对象
- (void)splashAdDidClickCloseButton:(DNSplashAd *)splashAd;

/// 关闭开屏广告的回调
/// @param splashAd DNSplashAd 对象
- (void)splashAdDidClose:(DNSplashAd *)splashAd;

/// 广告将要消失的回调
/// @param splashAd 产生该事件的 DNSplashAd 对象
- (void)splashAdWillClose:(DNSplashAd *)splashAd;

/// 开屏广告完成曝光的回调
/// @param splashAd splashAd 对象
- (void)splashAdExposured:(DNSplashAd *)splashAd;

/// 直客开屏视频广告准备播放回调！！！！！！！仅仅用于直客视频类型开屏，其他无效！！！！！
/// @param splashAd splashAd 对象
/// @param isLoadInCache 视频资源是不是从缓存加载的，YES从缓存加载，NO当前直接加载全部后播放
- (void)splashAdVideoWillPlay:(DNSplashAd *)splashAd isLoadInCache:(BOOL)isLoadInCache;

@end

/// 聚合开屏广告类。 提示: Splash广告只支持竖屏
@interface DNSplashAd : NSObject <DNAdDelegateCallbackProtocol>

/// 代理对象
@property (nonatomic, weak) id<DNSplashAdDelegate> delegate;

/// 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

@property (nonatomic, copy, readonly) NSString *placeId;

@property (nonatomic, strong, readonly) UIView *bottomView;

/// 背景色//默认为白色
@property (nonatomic, strong) UIColor *backgroundColor;

/// 是否在开屏时隐藏状态栏，默认是YES
@property (nonatomic, class, getter=isHiddenStatusBar) BOOL hiddenStatusBar;

/// 初始化方法
/// @param placeId 广告位置id
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 同下
- (void)loadAdAndShowWithController:(UIViewController *)controller;

/// 在开屏页面底部设置应用自身的Logo页面或是自定义View
/// 详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
/// 请注意
///     1.bottomView需设置高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%。必须设置height，如果height=0，将使用默认值200
///     2.Splash广告只支持竖屏
///     3.除广点通外，其余开屏均支持了safeArea
/// @param controller 广告被点击时push内容的控制器
/// @param bottomView 自定义底部View，可以在此View中设置应用Logo
- (void)loadAdAndShowWithController:(UIViewController *)controller bottomView:(UIView *_Nullable)bottomView;


- (void)loadAdAndShowInWindow:(UIWindow *_Nullable)window __attribute__((deprecated("该接口已经废弃，请使用 -loadAdAndShowWithController:")));
- (void)loadAdAndShowInWindow:(UIWindow *_Nullable)window withBottomView:(UIView *_Nullable)bottomView __attribute__((deprecated("该接口已经废弃，请使用 -loadAdAndShowWithController:bottomView:")));

@end

NS_ASSUME_NONNULL_END
