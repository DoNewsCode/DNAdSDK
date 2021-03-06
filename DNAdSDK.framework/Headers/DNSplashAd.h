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
/// 开屏广告的windowLevel = UIWindowLevelStatusBar-1.0;
@interface DNSplashAd : NSObject <DNAdDelegateCallbackProtocol>

//************** 以下是类属性 **************//
/// 是否在开屏时隐藏状态栏，默认是YES !!!!  
@property (nonatomic, class, getter=isHiddenStatusBar) BOOL hiddenStatusBar;
/// 实现该回调以禁用SDK内部对于UIApplication.sharedApplication.statusBarHidden的控制，
/// 每当sdk想要控制隐藏状态栏的时候都会调用该回调。
@property (nonatomic, class, nullable) void (^needHiddenStatusBarCallback)(BOOL isNeedHiddenStatusBar);
//************** 类属性  end **************//

@property (nonatomic, copy, readonly) NSString *placeId;
/// 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak, readonly) UIViewController *controller;
/// 默认=NO。
/// 此方法如果设置为YES则将会在聚合SDK最后一个可控Controller时自动查找传入控制器的栈顶控制器，以避免广告无法正常弹出的问题。
@property (nonatomic, assign, getter=isAdShowCompatibilityMode) BOOL adShowCompatibilityMode;
/// 自定义底部View，可以在此View中设置应用Logo
/// 在开屏页面底部设置应用自身的Logo页面或是自定义View
/// 详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
/// 请注意
///     1.bottomView需设置高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%。必须设置height，如果height=0，将使用默认值200
///     2.Splash广告只支持竖屏
///     3.除广点通外，其余开屏均支持了safeArea
@property (nonatomic, strong, nullable) UIView *bottomView;
/// 背景色//默认为白色
@property (nonatomic, strong) UIColor *backgroundColor;
/// 代理对象
@property (nonatomic, weak) id<DNSplashAdDelegate> delegate;

/// 初始化方法
/// @param placeId 广告位置id
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 请求并展示开屏
/// @param controller 当前最顶部的控制器，用于弹出落地页
- (void)loadAdAndShowWithController:(UIViewController *)controller;

@end

@interface DNSplashAd (Deprecated)

- (void)loadAdAndShowWithController:(UIViewController *)controller bottomView:(UIView *_Nullable)bottomView API_DEPRECATED("请使用DNSplashAd.bottomView设置应用logo", ios(1.0, 1.0));

@end

NS_ASSUME_NONNULL_END
