//
//  ZKExpressFeedAdView.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/10/9.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZKExpressFeedAdView : UIView

@property (nonatomic, getter=isRendered, readonly) BOOL rendered;
- (void)render;
- (void)derender;

@end

NS_ASSUME_NONNULL_END
