//
//  DNAdDelegateCallbackProtocol.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/27.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#ifndef DNAdDelegateCallbackProtocol_h
#define DNAdDelegateCallbackProtocol_h

#import <Foundation/Foundation.h>
#import "DNAdMacros.h"

typedef id _Nullable (^DNAdDelegateCallback)(DNAdProvider, id _Nullable);

/// 此协议是用来回调一些多牛聚合SDK没有回调的广告供应商的代理放的工具，只要是遵循了此协议的类，都可以使用。
/// 详见：
@protocol DNAdDelegateCallbackProtocol <NSObject>

@required
@property (nonatomic, strong, nullable) NSDictionary <NSString *, DNAdDelegateCallback> *callbackPool;

@end

#endif /* DNAdDelegateCallbackProtocol_h */
