//
//  ZKBannerAdView.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/5/14.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZKBannerAdViewDelegate;
@interface ZKBannerAdView : UIView

@property (nonatomic, copy, readonly) NSString *positionid;

@property (nonatomic, weak) id<ZKBannerAdViewDelegate> delegate;

@property (nonatomic, weak) UIViewController *controller;

- (instancetype)initWithFrame:(CGRect)frame positionid:(NSString *)positionid;

- (void)loadAdAndShow;

@end

@protocol ZKBannerAdViewDelegate <NSObject>

/// 即将开始加载banner广告
/// @param bannerView bannerView对象本身
- (void)bannerAdWillLoadForBannerView:(ZKBannerAdView *)bannerView;

/// bannerAdView加载成功时的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidLoadSuccessForBannerView:(ZKBannerAdView *)bannerView;

/// bannerAdView加载失败时的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidLoadFaildForBannerView:(ZKBannerAdView *)bannerView error:(NSError *)error;

/// bannerAdView曝光的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidExposureForBannerView:(ZKBannerAdView *)bannerView;

/// 点击banner广告的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidClickForBannerView:(ZKBannerAdView *)bannerView;

/// 落地页显示完成
/// @param bannerView bannerView对象本身
- (void)bannerAdDidShowDetailsForBannerView:(ZKBannerAdView *)bannerView;

/// 落地页内点击返回
/// @param bannerView bannerView对象本身
- (void)bannerAdDetailsDidCloseForBannerView:(ZKBannerAdView *)bannerView;

/// 点击广告上的❌关闭广告(暂时没有关闭按钮)
/// @param bannerView bannerView对象本身
//- (void)bannerAdDidClickCloseForBannerView:(ZKBannerAdView *)bannerView;

@end

NS_ASSUME_NONNULL_END
