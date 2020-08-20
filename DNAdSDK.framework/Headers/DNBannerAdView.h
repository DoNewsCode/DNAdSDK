//
//  DNBannerAdView.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/14.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNAdDelegateCallbackProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class DNBannerAdView;
@protocol DNBannerAdViewDelegate <NSObject>

@optional
/// 即将开始加载banner广告
/// @param bannerView bannerView对象本身
- (void)bannerAdWillLoadForBannerView:(DNBannerAdView *)bannerView;

/// bannerAdView加载成功时的回调
/// banner是可能有多条广告轮流展示的，所以banner每次展示了新的广告都会回调此方法
/// @param bannerView bannerView对象本身
- (void)bannerAdDidLoadSuccessForBannerView:(DNBannerAdView *)bannerView;

/// bannerAdView加载失败时的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidLoadFaildForBannerView:(DNBannerAdView *)bannerView error:(NSError *)error;

/// bannerAdView曝光的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidExposureForBannerView:(DNBannerAdView *)bannerView;

/// 点击banner广告的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidClickForBannerView:(DNBannerAdView *)bannerView;

/// 落地页显示完成
/// @param bannerView bannerView对象本身
- (void)bannerAdDidShowDetailsForBannerView:(DNBannerAdView *)bannerView;

/// 落地页内点击返回
/// @param bannerView bannerView对象本身
- (void)bannerAdDetailsDidCloseForBannerView:(DNBannerAdView *)bannerView;

/// 点击广告上的❌关闭广告(没有关闭按钮的不回调此方法)
/// @param bannerView bannerView对象本身
- (void)bannerAdDidClickCloseForBannerView:(DNBannerAdView *)bannerView;

@end

@interface DNBannerAdView : UIView <DNAdDelegateCallbackProtocol>

/// 代理对象
@property (nonatomic, weak) id<DNBannerAdViewDelegate> delegate;
/// 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

@property (nonatomic, copy, readonly) NSString *placeId;
/// 默认=NO。
/// 此方法如果设置为YES则将会在聚合SDK最后一个可控Controller时自动查找传入控制器的栈顶控制器，以避免广告无法正常弹出的问题。
@property (nonatomic, assign, getter=isAdShowCompatibilityMode) BOOL adShowCompatibilityMode;

/// 指定构造器
/// @param frame adview的大小，如您设置了其size会将以更优的方式返回接近设置尺寸的图像。
/// tips！想要显示适应控件尺寸清晰度的图像必须在此初始化方法传入的frame.size中才能生效，使用view.frame不会影响图像质量
/// @param placeId 广告位id
- (instancetype)initWithFrame:(CGRect)frame placeId:(NSString *)placeId;

/// 拉取并展示广告
- (void)loadAdAndShow;

@end

NS_ASSUME_NONNULL_END
