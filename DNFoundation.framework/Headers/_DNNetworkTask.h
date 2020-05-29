//
//  _DNNetworkTask.h
//  DNFoundation
//
//  Created by Kinsun on 2020/5/9.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, _DNRequestMethod) {
    DNRequestMethodUnknown  = 0,
    DNRequestMethodGET      = 1,
    DNRequestMethodPOST     = 2
};

NS_ASSUME_NONNULL_BEGIN

@interface _DNNetworkTask : NSObject

@property (nonatomic, weak, readonly) NSURLSession *session;
@property (nonatomic, strong, readonly) NSURLRequest *request;

- (instancetype)initWithURL:(NSURL *)url method:(_DNRequestMethod)method params:(NSDictionary <NSString *, id> *_Nullable)params session:(NSURLSession *)session callback:(void(^_Nullable)(__kindof _DNNetworkTask *, id _Nullable, NSError *_Nullable))callback;

- (void)fire;
- (void)cancel;

@end

@interface _DNNetworkDataTask : _DNNetworkTask

@end

@interface _DNNetworkDownloadTask : _DNNetworkTask

- (instancetype)initWithURL:(NSURL *)url session:(NSURLSession *)session callback:(void(^_Nullable)(_DNNetworkDownloadTask *, NSURL *_Nullable, NSError *_Nullable))callback;

@end

NS_ASSUME_NONNULL_END
