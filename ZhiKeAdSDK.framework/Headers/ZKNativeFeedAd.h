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

@property (nonatomic, weak) id<ZKNativeFeedAdDelegate> delegate;

@property (nonatomic, strong) NSArray<NSDictionary *> *materialArray;

- (void)loadAD;

+ (void)handleClick:(ZKAdMaterialModel *)model controller:(UIViewController *)controller completion:(void (^ __nullable)(void))completion;

+ (void)trackImpression:(ZKAdMaterialModel *)model;

@end

@protocol ZKNativeFeedAdDelegate <NSObject>
@optional;

/**
 自渲染广告加载数据成功回调
 @param materialArray 广告模型数组
 */
- (void)feedAdDidLoadSuccess:(ZKNativeFeedAd *)feedAd materialArray:(NSArray<ZKAdMaterialModel *> *)materialArray;

/**
  自渲染广告加载数据失败回调
 @param error 错误对象
 */
- (void)feedAdDidLoadFaild:(ZKNativeFeedAd *)feedAd error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
