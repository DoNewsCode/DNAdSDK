//
//  DNNativeFeedAd.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/6.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DNAdMaterial.h"
#import "DNAdDelegateCallbackProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class DNFeedAd, DNFeedAdContentView;
@protocol DNFeedAdDelegate <NSObject>
@optional;

/**
 自渲染广告加载数据成功回调
 @param materialArray 广告模型数组
 */
- (void)feedAdDidLoadSuccess:(DNFeedAd *)feedAd materialArray:(NSArray<DNAdMaterial *> *)materialArray;

/**
 自渲染广告加载数据失败回调
 @param error 错误对象
 */
- (void)feedAdDidLoadFaild:(DNFeedAd *)feedAd error:(NSError *)error;

/// 广告曝光回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewWillExpose:(DNFeedAdContentView *)view;

/// 广告点击回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewDidClick:(DNFeedAdContentView *)view;

/// 广告详情页关闭回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewAdDetailViewClosed:(DNFeedAdContentView *)view;

/// 广告详情页面即将展示回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewWillPresentScreen:(DNFeedAdContentView *)view;

@end

@interface DNFeedAd : NSObject <DNAdDelegateCallbackProtocol>

@property (nonatomic, copy, readonly) NSString *placeId;
/// 信息流数据结果状态的 代理对象
@property (nonatomic, weak) id<DNFeedAdDelegate> delegate;
/// 开发者需传入用来弹出目标页的ViewController，一般为显示广告的ViewController
@property (nonatomic, weak) UIViewController *controller;
/// 默认=NO。
/// 此方法如果设置为YES则将会在聚合SDK最后一个可控Controller时自动查找传入控制器的栈顶控制器，以避免广告无法正常弹出的问题。
@property (nonatomic, assign, getter=isAdShowCompatibilityMode) BOOL adShowCompatibilityMode;

/// 指定构造器
/// @param placeId 广告位id
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 请求信息流广告
/// @param count 请求广告的数量
- (void)loadAdWithCount:(NSInteger)count;

/// 注册元素广告关闭操作
- (void)registClickCloseWithAdMaterial:(DNAdMaterial *)adMaterial;

@end

NS_ASSUME_NONNULL_END
