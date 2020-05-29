//
//  _DNNetworking.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/27.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "_DNResponseModel.h"
#import "_DNNetworkTask.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^_DNNetworkingDownloadCallback)(NSURL *_Nullable, NSError *_Nullable);

@class _DNRequestModel;
@interface _DNNetworking <__covariant DataType> : NSObject

typedef void(^_DNNetworkingCallback)(_DNResponseModel<DataType> *_Nullable, NSError *_Nullable);

/// 请求的超时时间，默认3秒
@property (nonatomic, class) NSTimeInterval timeoutInterval;

+ (_DNNetworkDataTask *)requestWithModel:(_DNRequestModel *)model callback:(_DNNetworkingCallback _Nullable)callback;

+ (_DNNetworkDataTask *)requestWithModel:(_DNRequestModel *)model params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingCallback _Nullable)callback;

+ (_DNNetworkDataTask *)requestWithURLString:(NSString *)urlString method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingCallback _Nullable)callback;

+ (_DNNetworkDataTask *)requestWithURL:(NSURL *)url method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingCallback _Nullable)callback;


+ (_DNNetworkDownloadTask *)downloadWithURLString:(NSString *)urlString  callback:(_DNNetworkingDownloadCallback _Nullable)callback;

+ (_DNNetworkDownloadTask *)downloadWithURL:(NSURL *)url callback:(_DNNetworkingDownloadCallback _Nullable)callback;

@end

NS_ASSUME_NONNULL_END
