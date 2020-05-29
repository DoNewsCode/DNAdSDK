//
//  _DNDeviceTools.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/28.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#ifndef _DNDeviceTools_h
#define _DNDeviceTools_h

#import <Foundation/Foundation.h>

FOUNDATION_EXTERN NSString * _dn_getIMSI(void);
FOUNDATION_EXTERN NSString * _dn_getIDFA(void);
FOUNDATION_EXTERN NSString * _dn_getMacAddress(void);
FOUNDATION_EXTERN NSString * _dn_getUserAgent(void);
FOUNDATION_EXTERN NSString * _dn_getDeviceModel(void);
/// 0:无网络，1:联通，2:移动，3:电信，4:其他
FOUNDATION_EXTERN NSInteger _dn_getCarrier(void);
FOUNDATION_EXTERN NSString * _dn_getIDFA(void);
FOUNDATION_EXTERN NSString * _dn_getDeviceIPAddress(void);
FOUNDATION_EXTERN NSString * _dn_getNetworkIPAddress(bool isIPv4);
/// 0:无网络，1:wifi，2:4G，3:3G，4:2G，5:5G
FOUNDATION_EXTERN NSInteger _dn_GetNetworkType(void);

FOUNDATION_EXTERN float _dn_device_battery(void);
FOUNDATION_EXTERN double _dn_availableMemory(void);
FOUNDATION_EXTERN unsigned long long _dn_totalMemory(void);
FOUNDATION_EXTERN unsigned long long _dn_totalDiskSize(void);
FOUNDATION_EXTERN unsigned long long _dn_availableDiskSize(void);

FOUNDATION_EXTERN NSTimeInterval _dn_timeStampForNow(void);

FOUNDATION_EXTERN NSString * _dn_md5(NSString *string);

#endif /* _DNDeviceTools_h */
