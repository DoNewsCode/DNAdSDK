//
//  DNExpressFeedAdView.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/15.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DNExpressFeedAdView : UIView

/// 是否渲染完毕
@property (nonatomic, readonly, getter=isReady) BOOL ready;
/// 是否是视频模板广告
@property (nonatomic, readonly, getter=isVideoAd) BOOL videoAd;
/// 视频模板广告时长，单位 ms
@property (nonatomic, readonly) NSTimeInterval videoDuration;
/// 视频模板广告已播放时长，单位 ms
@property (nonatomic, readonly) NSTimeInterval videoPlayTime;
/// 自定义标识对象，此字段是为了开发者方便，开发者可在此字段传入分辨view的标识符，在代理返回View中以分辨DNExpressFeedAdView的身份。
/// 此字段对于DNExpressFeedAdView内部没有任何作用
@property (nonatomic, strong, nullable) id customIdentity;

/// 渲染ADView，请务必在View显示前调用，否则会什么也不显示。
/// 延迟渲染是为了避免view过多时内存溢出的问题。
- (void)render;

/// 在加载广告时传入的大致尺寸
@property (nonatomic, assign, readonly) CGSize roughlySize;
/// 广告实图更新了推荐使用的尺寸回调（广点通，穿山甲会动态更新高度所以会使用这个回调更新）
@property (nonatomic, copy, nullable) void (^adViewUpdateSizeCallback)(DNExpressFeedAdView *view, CGSize adSize);

- (instancetype)initWithFrame:(CGRect)frame API_DEPRECATED("请勿主动构造DNExpressFeedAdView", ios(9.0,13.0));

@end

NS_ASSUME_NONNULL_END
