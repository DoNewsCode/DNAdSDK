//
//  _DNAdIMPModel.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/29.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface _DNAdIMPModel : NSObject

/// 广告位 id
@property (nonatomic, copy, nullable) NSString *position;
/// 请求广告的数量 （不传或者0都默认为1处理 最大值5 超过当5处理)
@property (nonatomic, assign) NSInteger ads_count;
/// 0冷启动 1 热启动 (自有媒体估计才用的，外部的媒体估计自己控制会请求)
@property (nonatomic, assign) NSUInteger open_type;
/// 请求开屏广告的宽高 （全屏广告、半屏广告）
@property (nonatomic, assign) NSInteger w;
@property (nonatomic, assign) NSInteger h;

@property (readonly) NSDictionary <NSString *, id> *toDictionaryValue;

@end

NS_ASSUME_NONNULL_END
