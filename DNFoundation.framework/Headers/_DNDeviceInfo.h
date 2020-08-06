//
//  _DNDeviceInfo.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/28.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import "DNModelsProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface _DNInfoBase : NSObject <_DNDeModelsProtocol>

/// 注意！toDictionaryValue是懒加载生成值的，并且生成后会缓存值，如果中途值属性的值发生了变化一定要及时调用-resetToDictionaryValueCache，否则返回的字典值是不会更新的。
@property (nonatomic, strong, readonly) NSMutableDictionary <NSString *, id> *toDictionaryValue;

- (void)resetToDictionaryValueCache;

@end

@interface _DNDeviceInfo : _DNInfoBase

@property (nonatomic, class, readonly) _DNDeviceInfo *sharedDeviceInfo;

/// 经纬度
@property (nonatomic, strong, readonly) NSDictionary *geo; //{float lat, float lon}
///
@property (nonatomic, copy, readonly) NSString *imsi;
/// 设备的IMEI
@property (nonatomic, copy, readonly) NSString *imei;
/// 设备浏览器的User-Agent字符串
@property (nonatomic, copy, readonly) NSString *ua;
/// 手机制造商
@property (nonatomic, copy, readonly) NSString *make;
/// 设备型号
@property (nonatomic, copy, readonly) NSString *model;
/// 设备操作系统 (1:ios,2:android)
@property (nonatomic, assign, readonly) NSInteger os;
/// 设备操作系统版本号
@property (nonatomic, copy, readonly) NSString *osv;
///  苹果广告标识 id
@property (nonatomic, copy, readonly) NSString *idfa;
/// IDFV -> 设备的UUID
@property (nonatomic, copy, readonly) NSString *idfv;
/// openudid ->设备的UUID
@property (nonatomic, copy, readonly) NSString *openudid;
/// 设备的IP地址
@property (nonatomic, copy, readonly) NSString *ip;
/// ipv6
@property (nonatomic, copy, readonly) NSString *ipv6;
/// 设备惟一标示符-》 对应IDFV  自有媒体生成的唯一 id
@property (nonatomic, copy, readonly) NSString *suuid;
/// MAC地址原
@property (nonatomic, copy, readonly) NSString *mac;
/// 运营商  0未知 1移动 2联通 3电信
@property (nonatomic, assign, readonly) NSInteger carrier;
/// 设备联网方式 0:未知  1:Wifi  2:4G 3:3G 4:2G 6:5G
@property (nonatomic, assign, readonly) NSInteger connectiontype;
/// 1:竖屏 2:横屏
@property (nonatomic, assign, readonly) NSInteger orientation;
/// 设备屏幕分辨率宽高素数 （iPhone设备的宽高）
@property (nonatomic, assign, readonly) NSInteger w;
@property (nonatomic, assign, readonly) NSInteger h;
/// 设备屏幕每英寸像素数 ppi
@property (nonatomic, assign, readonly) NSInteger ppi;
/// iOS系统屏幕密度 1 为标清,大于等于 2 为高清
@property (nonatomic, assign, readonly) NSInteger pxratio;
/// SDK的版本号 例如 2.x 不要语义化 就是纯小数 eg: 5.0
@property (nonatomic, copy) NSString *dn_ad_sdkver;

@end

@interface _DNApplicationInfo : _DNInfoBase

@property (nonatomic, class, readonly) _DNApplicationInfo *sharedApplicationInfo;

///  app 名称
@property (nonatomic, copy, readonly) NSString *name;
/// app_bundle_id(App 包名)
@property (nonatomic, copy, readonly) NSString *bundle;
/// app 版本号
@property (nonatomic, copy, readonly) NSString *ver;
/// app长版本号
@property (nonatomic, copy, readonly) NSString *build;

@end

NS_ASSUME_NONNULL_END
