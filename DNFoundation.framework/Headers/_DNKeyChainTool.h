//
//  _DNKeyChainTool.h
//  DNFoundation
//
//  Created by Kinsun on 2020/6/23.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface _DNKeyChainTool : NSObject

+ (NSMutableDictionary *)getKeychainQuery:(NSString *)key forAccessGroup:(NSString *_Nullable)accessGroup;
+ (NSString *_Nullable)getFullAccessGroup:(NSString *)accessGroup;
+ (NSString *_Nullable)getBundleSeedIdentifier;

+ (BOOL)setValue:(id)value forKey:(NSString *)key;
+ (BOOL)setValue:(id)value forKey:(NSString *)key forAccessGroup:(NSString *_Nullable)accessGroup;

+ (BOOL)deleteValueForKey:(NSString *)key;
+ (BOOL)deleteValueForKey:(NSString *)key forAccessGroup:(NSString *_Nullable)accessGroup;

+ (id _Nullable)valueForKey:(NSString *)key;
+ (id _Nullable)valueForKey:(NSString *)key forAccessGroup:(NSString *_Nullable)accessGroup;

@end

NS_ASSUME_NONNULL_END
