//
//  DNFeedAdSlot.h
//  DoNews
//
//  Created by donews on 2018/10/31.
//  Copyright © 2018年 donews. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DNAdSlot : NSObject

/// 请求广告的数量 默认是1 (⚠️最大是3,推荐一次请求一个 作用于信息流)
@property (nonatomic, assign) NSInteger adCount;

/// 广告位置id
@property (nonatomic, copy) NSString *positionId;

/// 指定广告整体的size (⚠️一般用于联盟的模板广告 height传0表示自适应)
@property (nonatomic, assign) CGSize adSize;

@end
