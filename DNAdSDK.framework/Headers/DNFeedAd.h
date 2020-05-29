//
//  DNNativeFeedAd.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/6.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DNAdMaterial.h"
#import "DNAdSlot.h"

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

/// 当点击应用下载或者广告调用系统程序打开时调用
//- (void)feedAdContentViewApplicationWillEnterBackground:(DNFeedAdContentView *)view;

/// 广告详情页面即将展示回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewWillPresentScreen:(DNFeedAdContentView *)view;

@end

@interface DNFeedAd : NSObject

/**
*  信息流数据结果状态的 代理对象
*/
@property (nonatomic, weak) id<DNFeedAdDelegate> delegate;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;


/**
 广告位置相关信息
 */
@property (nonatomic, readonly, strong) DNAdSlot *slot;


/**
 请求信息流广告
 */
- (void)loadAdWithSlot:(DNAdSlot *)slot;

/**
 注册元素广告关闭操作
 */
- (void)registClickCloseWithAdMaterial:(DNAdMaterial *)adMaterial;

@end

NS_ASSUME_NONNULL_END
