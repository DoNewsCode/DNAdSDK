//
//  DNFeedAdVideoView.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/7/7.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DNFeedAdVideoView : UIView

/// 是否开启静音模式，默认=YES
@property (nonatomic, assign, getter=isQuietMode) BOOL quietMode;
/// 播放是否已完成
@property (nonatomic, assign, readonly, getter=isPlayFinished) BOOL playFinished;

@end

NS_ASSUME_NONNULL_END
