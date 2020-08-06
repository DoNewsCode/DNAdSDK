//
//  _DNResponseModel.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/30.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DNModelsProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface _DNResponseModel <__covariant DataType> : NSObject <_DNEnModelsProtocol>

/// 提示
@property (nonatomic, copy, readonly, nullable) NSString *message;
/// 响应结果的code码
@property (nonatomic, assign, readonly) NSInteger code;
/// 响应结果的结果
@property (nonatomic, assign, readonly) NSInteger result;
/// 响应数据
@property (nonatomic, strong, readonly, nullable) DataType data;

@end

NS_ASSUME_NONNULL_END
