//
//  ZKSplashAd.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/5/6.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZKSplashAdDelegate;

@interface ZKSplashAd : NSObject

@property (nonatomic, weak) id<ZKSplashAdDelegate> delegate;

@property (nonatomic, strong) NSDictionary *adMaterial;

@property (nonatomic, weak) UIViewController *controller;

@property (nonatomic, strong, readonly) UIView *adView;

- (void)loadAD;

@end

@protocol ZKSplashAdDelegate <NSObject>

@optional;
/**
 开屏广告加载成功的回调
 @param splashAd 产生该事件的 ZKSplashAd 对象
 */
- (void)splashAdDidLoadSuccess:(ZKSplashAd *)splashAd;

/**
 开屏广告加载失败的回调
 @param splashAd 产生该事件的 ZKSplashAd 对象
 @param error Error对象
 */
- (void)splashAdDidLoadFaild:(ZKSplashAd *)splashAd withError:(NSError *)error;

/**
 开屏广告点击的回调
 @param splashAd 产生该事件的 ZKSplashAd 对象
 */
- (void)splashAdClicked:(ZKSplashAd *)splashAd;

/**
 开屏广告点击关闭按钮的回调
 @param splashAd ZKSplashAd 对象
 */
- (void)splashAdDidClickCloseButton:(ZKSplashAd *)splashAd;

/**
 关闭开屏广告的回调
 @param splashAd ZKSplashAd 对象
 */
- (void)splashAdDidClose:(ZKSplashAd *)splashAd;

/**
 广告将要消失的回调
 @param splashAd 产生该事件的 ZKSplashAd 对象
 */
- (void)splashAdWillClose:(ZKSplashAd *)splashAd;

/**
 开屏广告完成曝光的回调
 @param splashAd ZKSplashAd 对象
 */
- (void)splashAdExposured:(ZKSplashAd *)splashAd;

/**
 开屏视频广告准备播放回调
 @param splashAd ZKSplashAd 对象
 @param isLoadInCache 视频资源是不是从缓存加载的，YES从缓存加载，NO当前直接加载全部后播放
 */
- (void)splashAdVideoWillPlay:(ZKSplashAd *)splashAd isLoadInCache:(BOOL)isLoadInCache;

@end

@class _DNAdIMPModel, ZKAdVideoFileModel;
@interface ZKSplashAd (_ZKVideoAd)

+ (void)requstVideoCacheWithIMP:(_DNAdIMPModel *)imp callback:(void (^_Nullable)(NSArray <ZKAdVideoFileModel *> *_Nullable, NSError *_Nullable))callback;

/// 获得所有开屏视频缓存的资源组
+ (NSArray <ZKAdVideoFileModel *> *)allVideoAdCatalog;

/// 清除旧的开屏视频缓存
+ (void)clearVideoCache;

/// 清除全部开屏视频缓存
+ (void)clearAllVideoCache;

@end

NS_ASSUME_NONNULL_END
