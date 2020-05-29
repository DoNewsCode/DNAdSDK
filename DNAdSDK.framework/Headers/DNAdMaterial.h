//
//  DNAdMaterial.h
//  DNAdSDKLib
//
//  Created by donews on 2020/1/19.
//  Copyright © 2020 donews. All rights reserved.
//  信息流自渲染的物料模型

#import <UIKit/UIKit.h>
#import "DNAdMacros.h"

NS_ASSUME_NONNULL_BEGIN

@interface DNAdMaterial : NSObject

/// 广告标题，图文广告时需要
@property (nonatomic, copy, readonly, nullable) NSString *title;
/// 广告描述 (⚠️也是推⼴名称)
@property (nonatomic, copy, readonly, nullable) NSString *desc;
/// 图片地址数组
@property (nonatomic, copy, readonly, nullable) NSArray<NSString *> *image_urls;
/// icon图标数组 （可能多个）
@property (nonatomic, copy, readonly, nullable) NSArray<NSString *> *icon_url;
/// 联盟平台的logo（⚠️⚠️用于自渲染）
@property (nonatomic, strong, readonly, nullable) UIImage *adlogoImage;
/// 广告媒体来源  0直客 1百度 2google 3今⽇日头条 4英威诺 5⼴点通
@property (nonatomic, assign, readonly) DNAdProvider ad_from;
/// 广告资源类型(附录 4)
@property (nonatomic, assign, readonly) DNAdCreativeType creative_type;
/// 广告 信息流 图片资源展示形式 (1单图文，2多图，组图，3大图)
@property (nonatomic, assign, readonly) DNAdInformationStyle information;

@end

NS_ASSUME_NONNULL_END

