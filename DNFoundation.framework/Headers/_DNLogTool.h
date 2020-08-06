//
//  _DNLogTool.h
//  DNOPTAdSDK
//
//  Created by Kinsun on 2020/6/15.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface _DNLogTool : NSObject

@property (nonatomic, class, getter=isLogEnable) BOOL logEnable;

@property (nonatomic, class, getter=isShowDebugLog) BOOL showDebugLog;

@end

FOUNDATION_EXPORT void _DNLog(NSString *format, ...);

NS_ASSUME_NONNULL_END
