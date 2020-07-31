//
//  _DNModelsProtocol.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/26.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#ifndef _DNModelsProtocol_h
#define _DNModelsProtocol_h

#import <Foundation/Foundation.h>

@protocol _DNEnModelsProtocol <NSObject>

@required
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@protocol _DNDeModelsProtocol <NSObject>

@required
@property (nonatomic, readonly) NSDictionary *toDictionaryValue;

@end

#endif /* _DNModelsProtocol_h */
