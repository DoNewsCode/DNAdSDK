//
//  ZKAdVideoModel.h
//  ZhiKeAdSDK
//
//  Created by Kinsun on 2020/5/9.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZKAdVideoFileModel : NSObject

@property (nonatomic, copy, readonly) NSString *video_id;
@property (nonatomic, assign, readonly) NSTimeInterval timestamp;
@property (nonatomic, copy, readonly) NSString *path;
@property (nonatomic, copy, readonly) NSString *fileName;

@end

NS_ASSUME_NONNULL_END
