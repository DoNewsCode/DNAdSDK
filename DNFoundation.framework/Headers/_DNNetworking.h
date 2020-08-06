//
//  _DNNetworking.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/27.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "_DNResponseModel.h"

typedef NS_ENUM(NSInteger, _DNRequestMethod) {
    DNRequestMethodUnknown  = 0,
    DNRequestMethodGET      = 1,
    DNRequestMethodPOST     = 2
};

typedef NS_ENUM(NSInteger, _DNRequestContentType) {
    DNRequestContentTypeJSON            = 0, /// Content-Type =  application/json;
    DNRequestContentTypeFormUrlencoded  = 1 /// Content-Type = application/x-www-form-urlencoded
};

NS_ASSUME_NONNULL_BEGIN

typedef void(^_DNNetworkingDownloadCallback)(NSURL *_Nullable, NSError *_Nullable);

@class _DNRequestModel;
@interface _DNNetworking <__covariant DataType> : NSObject

typedef void(^_DNNetworkingCallback)(DataType _Nullable, NSError *_Nullable);

@property (nonatomic, readonly) NSURLSessionConfiguration *configuration;
@property (nonatomic, assign, readonly) _DNRequestContentType contentType;
@property (nonatomic, readonly) NSOperationQueue *queue;

@property (nonatomic, strong, nullable) NSData *certificateData;
@property (nonatomic, copy, nullable) NSString *certificatePassword;

@property (nonatomic, assign, getter=isNeedServerTrust) BOOL needServerTrust;
@property (nonatomic, strong, nullable) NSData *serverTrustData;
@property (nonatomic, copy, nullable) NSString *serverTrustPassword;

- (instancetype)initWithConfiguration:(NSURLSessionConfiguration *)configuration queue:(NSOperationQueue *_Nullable)queue;
- (instancetype)initWithConfiguration:(NSURLSessionConfiguration *)configuration contentType:(_DNRequestContentType)contentType queue:(NSOperationQueue *_Nullable)queue;

/// 请求的超时时间，默认3秒
@property (nonatomic, class) NSTimeInterval timeoutInterval;

+ (NSURLSessionDataTask *)requestWithModel:(_DNRequestModel *)model callback:(_DNNetworkingCallback _Nullable)callback;

+ (NSURLSessionDataTask *)requestWithModel:(_DNRequestModel *)model params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingCallback _Nullable)callback;

+ (NSURLSessionDataTask *)requestWithURLString:(NSString *)urlString method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingCallback _Nullable)callback;

+ (NSURLSessionDataTask *)requestWithURL:(NSURL *)url method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingCallback _Nullable)callback;

- (NSURLSessionDataTask *)requestWithURL:(NSURL *)url method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingCallback _Nullable)callback;


+ (NSURLSessionDownloadTask *)downloadWithURLString:(NSString *)urlString  callback:(_DNNetworkingDownloadCallback _Nullable)callback;

+ (NSURLSessionDownloadTask *)downloadWithURL:(NSURL *)url callback:(_DNNetworkingDownloadCallback _Nullable)callback;

@end

@interface _DNNetworking <__covariant DataType> (_DNResponseModelNetworking)

typedef void(^_DNNetworkingModelCallback)(_DNResponseModel<DataType> *_Nullable, NSError *_Nullable);

+ (NSURLSessionDataTask *)requestForResponseModelWithModel:(_DNRequestModel *)model callback:(_DNNetworkingModelCallback _Nullable)callback;

+ (NSURLSessionDataTask *)requestForResponseModelWithModel:(_DNRequestModel *)model params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingModelCallback _Nullable)callback;

+ (NSURLSessionDataTask *)requestForResponseModelWithURLString:(NSString *)urlString method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingModelCallback _Nullable)callback;

+ (NSURLSessionDataTask *)requestForResponseModelWithURL:(NSURL *)url method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingModelCallback _Nullable)callback;

- (NSURLSessionDataTask *)requestForResponseModelWithURL:(NSURL *)url method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params callback:(_DNNetworkingModelCallback _Nullable)callback;

@end

NS_ASSUME_NONNULL_END
