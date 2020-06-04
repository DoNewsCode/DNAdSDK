//
//  ZKAdMacros.h
//  DNAdSDKLib
//
//  Created by donews on 2019/12/12.
//  Copyright © 2019 donews. All rights reserved.
//

#ifndef ZKAdMacros_h
#define ZKAdMacros_h
#import <Foundation/Foundation.h>

#import <Foundation/Foundation.h>
/// 广告展示样式类型
typedef NS_ENUM(NSInteger, ZKAdInformationStyle) {
    ZKAdInformationStyleUnknow  = 0,    /// 未知类型
    ZKAdInformationStyleSmall   = 1,    /// 小图
    ZKAdInformationStyleGroup   = 2,    /// 组图
    ZKAdInformationStyleBig     = 3     /// 大图
};

/// 广告资源类型
typedef NS_ENUM(NSInteger, ZKAdCreativeType) { ///< 交互类型
    ZKAdCreativeTypeUnknow  = 0,    /// 0 未知
    ZKAdCreativeTypeImage   = 1,    /// 1 图片
    ZKAdCreativeTypeVideo   = 2,    /// 2 视频
//    ZKAdCreativeTypeImageAndText ,  /// 3 图文
//    ZKAdCreativeTypeText ,          /// 4 文本
//    ZKAdCreativeTypeHtml5 ,         /// 5 html5
//    ZKAdCreativeTypeHtmlUrl ,       /// 6 html5 url 即一个指向 html5 素材页面的 url
};

#endif /* ZKAdMacros_h */
