//
//  ZKNativeFeedAdVideoView.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/8/12.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZKAdMaterialModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZKNativeFeedAdVideoViewDelegate;
@interface ZKNativeFeedAdVideoView : UIView

@property (nonatomic, strong, nullable) ZKAdMaterialModel *material;
@property (nonatomic, weak) id <ZKNativeFeedAdVideoViewDelegate> delegate;
@property (nonatomic) float volume;
@property (nonatomic, readonly, getter=isPlaying) BOOL playing;
@property (nonatomic, getter=isShowProgressBar) BOOL showProgressBar;

- (void)play;
- (void)pause;
- (void)stop;

@end

@protocol ZKNativeFeedAdVideoViewDelegate <NSObject>

- (void)playerReadyToPlay:(ZKNativeFeedAdVideoView *)videoView;
- (void)playerPlayFinished:(ZKNativeFeedAdVideoView *)videoView;

@end

NS_ASSUME_NONNULL_END
