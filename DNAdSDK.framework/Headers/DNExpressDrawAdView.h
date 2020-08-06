//
//  DNExpressDrawAdView.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/8/6.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DNExpressDrawAdView : UIView

/// 是否渲染完毕
@property (nonatomic, readonly, getter=isReady) BOOL ready;
/// 视频模板广告时长，单位 ms
@property (nonatomic, readonly) NSTimeInterval videoDuration;
/// 视频模板广告已播放时长，单位 ms
@property (nonatomic, readonly) NSTimeInterval videoPlayTime;
/// 自定义标识对象，此字段是为了开发者方便，开发者可在此字段传入分辨view的标识符，在代理返回View中以分辨DNExpressDrawAdView的身份。
/// 此字段对于DNExpressDrawAdView内部没有任何作用
@property (nonatomic, strong, nullable) id customIdentity;

/// 渲染ADView，请务必在View显示前调用，否则会什么也不显示。延迟渲染是为了避免view过多时内存溢出的问题。
- (void)render;

- (instancetype)initWithFrame:(CGRect)frame API_DEPRECATED("请勿主动构造DNExpressDrawAdView", ios(9.0,13.0));

@end

NS_ASSUME_NONNULL_END
