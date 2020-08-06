//
//  _DNRequestModel.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/28.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "_DNNetworking.h"

//formart is '(path)***(1 or 2)'. 1 = GET Method, 2 = POST Method.
typedef NSString * _DNRequestKey;

NS_ASSUME_NONNULL_BEGIN

@interface _DNRequestModel : NSObject

@property (nonatomic, assign, readonly) _DNRequestMethod method;
@property (nonatomic, copy, readonly) NSString *url;
@property (nonatomic, weak) NSURLSessionTask *task;

@property (nonatomic, strong, readonly) NSString *host;
@property (nonatomic, copy, readonly) _DNRequestKey key;

- (instancetype)initWithKey:(_DNRequestKey)key host:(NSString *)host;

@end

NS_ASSUME_NONNULL_END
