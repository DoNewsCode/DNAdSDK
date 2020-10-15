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

/// 广告展示样式类型
typedef NS_ENUM(NSInteger, ZKAdInformationStyle) {
    ZKAdInformationStyleUnknow          = 0, // 未知
    ZKAdInformationStyleSmallImage      = 1, // 信息流小图
    ZKAdInformationStyleGroupImage      = 2, // 信息流组图
    ZKAdInformationStyleBigImage        = 3, // 信息流大图
    ZKAdInformationStyleRewardedVideo   = 4, // 激励视频
    ZKAdInformationStyleBannerIcon      = 5, // banner icon
    ZKAdInformationStyleBanner          = 6, // banner(纯图)
    ZKAdInformationStyleSplash          = 7, // 开屏 图
    ZKAdInformationStyleSplashIcon      = 8, // 开屏 图带 icon
    ZKAdInformationStyleInterstitialAd  = 9, // 插屏
    ZKAdInformationStyleSplashVideo     = 12,// 视频开屏
    ZKAdInformationStyleDrawFeed        = 13,// draw流
    ZKAdInformationStyleFeedVideo       = 14,// 信息流视频
    ZKAdInformationStyleExpressSmallImage   = 15, // 信息流小图(模板)
    ZKAdInformationStyleExpressGroupImage   = 16, // 信息流组图(模板)
    ZKAdInformationStyleExpressBigImage     = 17, // 信息流大图(模板)
    ZKAdInformationStyleExpressFeedVideo    = 18, // 信息流视频(模板)
};

/// 广告资源类型
typedef NS_ENUM(NSInteger, ZKAdCreativeType) {
    ZKAdCreativeTypeUnknow  = 0,    // 0 未知
    ZKAdCreativeTypeImage   = 1,    // 1 图片
    ZKAdCreativeTypeVideo   = 2,    // 2 视频
//    ZKAdCreativeTypeImageAndText ,  // 3 图文
//    ZKAdCreativeTypeText ,          // 4 文本
//    ZKAdCreativeTypeHtml5 ,         // 5 html5
//    ZKAdCreativeTypeHtmlUrl ,       // 6 html5 url 即一个指向 html5 素材页面的 url
};

//typedef NS_ENUM(NSUInteger, ZKExpressPlayerStatus) {
//    ZKExpressPlayerStatusInitial    = 0,    // 初始状态
//    ZKExpressPlayerStatusLoading    = 1,    // 加载中
//    ZKExpressPlayerStatusStarted    = 2,    // 开始播放
//    ZKExpressPlayerStatusPaused     = 3,    // 用户行为导致暂停
//    ZKExpressPlayerStatusStoped     = 4,    // 播放停止
//    ZKExpressPlayerStatusError      = 5     // 播放出错
//};

#endif /* ZKAdMacros_h */
