//
//  ZKNativeFeedAdContentView.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/7/23.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZKNativeFeedAdVideoView.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZKNativeFeedAdContentView : UIControl

@property (nonatomic, strong, nullable) ZKAdMaterialModel *material;

@property (nonatomic, strong) ZKNativeFeedAdVideoView *videoView;

@end

NS_ASSUME_NONNULL_END
