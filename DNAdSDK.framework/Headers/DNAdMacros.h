//
//  DNAdMacros.h
//  DNAdSDKLib
//
//  Created by donews on 2019/12/12.
//  Copyright © 2019 donews. All rights reserved.
//

#ifndef DNAdMacros_h
#define DNAdMacros_h

#import <Foundation/Foundation.h>

/// 广告来源类型
typedef NS_ENUM(NSInteger, DNAdProvider) {
    DNAdProviderNormal      = 0, // 直客广告（默认）
    DNAdProviderBaidu       = 1, // 百度
    DNAdProviderGoogle      = 2, // 谷歌 (暂未支持预留位置)
    DNAdProviderToutiao     = 3, // 穿山甲
    DNAdProviderYWN         = 4, // 英威诺 (暂未支持预留位置)
    DNAdProviderGDT         = 5, // 广点通
    DNAdProviderBaiduHybrid = 6, // 百度hybrid (暂未支持预留位置)
    DNAdProviderIflytek     = 7, // 科大讯飞 (暂未支持预留位置)
    DNAdProviderInmobi      = 8, // inmobi (暂未支持预留位置)
    DNAdProviderSougou      = 9, // 搜狗 (暂未支持预留位置)
    DNAdProviderJiuxin      = 10 // 久鑫 (暂未支持预留位置)
};

/// 广告展示样式类型
typedef NS_ENUM(NSInteger, DNAdInformationStyle) {
    DNAdInformationStyleUnknow  = 0,    /// 未知类型
    DNAdInformationStyleSmall   = 1,    /// 小图
    DNAdInformationStyleGroup   = 2,    /// 组图
    DNAdInformationStyleBig     = 3     /// 大图
};

/// 广告资源类型
typedef NS_ENUM(NSInteger, DNAdCreativeType) {
    DNAdCreativeTypeUnknow  = 0,    // 0 未知
    DNAdCreativeTypeImage   = 1,    // 1 图片
    DNAdCreativeTypeVideo   = 2,    // 2 视频
//    DNAdCreativeTypeImageAndText ,  // 3 图文
//    DNAdCreativeTypeText ,          // 4 文本
//    DNAdCreativeTypeHtml5 ,         // 5 html5
//    DNAdCreativeTypeHtmlUrl ,       // 6 html5 url 即一个指向 html5 素材页面的 url
};

/// 播放器播放状态
typedef NS_ENUM(NSUInteger, DNExpressPlayerStatus) {
    DNExpressPlayerStatusInitial    = 0,    // 初始状态
    DNExpressPlayerStatusLoading    = 1,    // 加载中
    DNExpressPlayerStatusStarted    = 2,    // 开始播放
    DNExpressPlayerStatusPaused     = 3,    // 用户行为导致暂停
    DNExpressPlayerStatusStoped     = 4,    // 播放停止
    DNExpressPlayerStatusError      = 5     // 播放出错
};

#endif /* DNAdMacros_h */
