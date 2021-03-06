//
//  ZKAdMaterialModel.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/5/6.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZKAdMacros.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZKAdMaterialModel : NSObject

/// 广告标题，图文广告时需要
@property (nonatomic, copy, readonly, nullable) NSString *title;
/// 广告描述 (⚠️也是推⼴名称)
@property (nonatomic, copy, readonly, nullable) NSString *desc;
/// icon图标地址
@property (nonatomic, copy, readonly, nullable) NSString *icon_url;
/// 直客广告logo
@property (nonatomic, copy, readonly, nullable) NSString *logo_url;
///  广告尺寸
@property (nonatomic, assign, readonly) CGSize adSize;

/// 图片地址数组
@property (nonatomic, copy, readonly, nullable) NSArray<NSString *> *image_urls;

/// 广告资源类型(附录 4)
@property (nonatomic, assign, readonly) ZKAdCreativeType creative_type;
/// 广告 信息流 图片资源展示形式 (1单图文，2多图，组图，3大图)
@property (nonatomic, assign, readonly) ZKAdInformationStyle information;

/// 自定义标识对象，此字段是为了开发者方便，开发者可在此字段传入分辨Material的标识符，在代理返回Material中以分辨ZKAdMaterialModel的身份。
/// 此字段对于ZKAdMaterialModel内部没有任何作用
@property (nonatomic, strong, nullable) id customIdentity;

@end

NS_ASSUME_NONNULL_END
