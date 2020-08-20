//
//  ZKNativeFeedAd.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/5/7.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZKAdMaterialModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZKNativeFeedAdDelegate;
@interface ZKNativeFeedAd : NSObject

@property (nonatomic, copy, readonly) NSString *positionid;

@property (nonatomic, weak) id<ZKNativeFeedAdDelegate> delegate;

/// 跳转到落地页的控制器（一定要是最顶部的控制器不然将无法正常打开落地页从而影响收益）
@property (nonatomic, weak) UIViewController *controller;

- (instancetype)initWithPositionid:(NSString *)positionid;

- (void)loadADWithCount:(NSInteger)count adSize:(CGSize)adSize;

@end

@protocol ZKNativeFeedAdDelegate <NSObject>
@optional;

/// 自渲染广告即将加载数据回调
/// @param feedAd feedAd ZKNativeFeedAd本身
- (void)feedAdWillLoad:(ZKNativeFeedAd *)feedAd;

/// 自渲染广告加载数据成功回调
/// @param feedAd feedAd ZKNativeFeedAd本身
/// @param materialArray 广告物料模型数组
- (void)feedAdDidLoadSuccess:(ZKNativeFeedAd *)feedAd materialArray:(NSArray<ZKAdMaterialModel *> *)materialArray;

/// 自渲染广告加载数据失败回调
/// @param feedAd ZKNativeFeedAd本身
/// @param error 错误对象
- (void)feedAdDidLoadFaild:(ZKNativeFeedAd *)feedAd error:(NSError *)error;

/// 自渲染广告关闭详情页回调
/// @param feedAd ZKNativeFeedAd本身
/// @param material 单个广告物料
- (void)feedAdDidCloseDetailsController:(ZKNativeFeedAd *)feedAd material:(ZKAdMaterialModel *)material;

/// 自渲染广告已经打开详情页回调
/// @param feedAd ZKNativeFeedAd本身
/// @param material 单个广告物料
- (void)feedAdDidEnterDetailsController:(ZKNativeFeedAd *)feedAd material:(ZKAdMaterialModel *)material;

/// 自渲染广告点击回调
/// @param feedAd ZKNativeFeedAd本身
/// @param material 单个广告物料
- (void)feedAdDidClick:(ZKNativeFeedAd *)feedAd material:(ZKAdMaterialModel *)material;

/// 自渲染广告曝光回调
/// @param feedAd ZKNativeFeedAd本身
/// @param material 单个广告物料
- (void)feedAdDidExposure:(ZKNativeFeedAd *)feedAd material:(ZKAdMaterialModel *)material;


@end

NS_ASSUME_NONNULL_END
