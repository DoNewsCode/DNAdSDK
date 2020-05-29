//
//  _DNAdFileTool.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/7.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface _DNAdFileTool : NSObject

@property (nonatomic, copy, readonly) NSString *identifier;

- (instancetype)initWithIdentifier:(NSString *)identifier;

- (void)setSerialization:(id)map forKey:(NSString *)key;
- (id _Nullable)serializationForKey:(NSString *)key;
- (void)removeMapForKey:(NSString *)key;

- (void)reinit;

@property (nonatomic, class, readonly) _DNAdFileTool *shared;

@end

NS_ASSUME_NONNULL_END
