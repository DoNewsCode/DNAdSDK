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

@property (nonatomic, copy, readonly) NSString *positionid;

/// 代理对象
@property (nonatomic, weak) id<ZKSplashAdDelegate> delegate;

/// 打开落地页的控制器，请务必测试可以正常弹出
@property (nonatomic, weak) UIViewController *controller;

/// 广告视图，请自行处理，默认没有设置frame
@property (nonatomic, readonly) UIView *adView;

/// 指定构造器
/// @param positionid 广告位ID
- (instancetype)initWithPositionid:(NSString *)positionid;

/// 加载并展示开屏广告
/// @param size 加载广告的素材大小（一定要是展示广告的大小，否则图像质量/清晰度将降低）
- (void)loadADWithSize:(CGSize)size;

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

/// 清除旧的开屏视频缓存（剩余最新10个缓存项目，总缓存数据不足十个将不删除任何缓存）
+ (void)clearVideoCache;

/// 清除全部开屏视频缓存
+ (void)clearAllVideoCache;

@end

NS_ASSUME_NONNULL_END
