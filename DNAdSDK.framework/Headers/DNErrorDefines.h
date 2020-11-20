//
//  DNErrorDefines.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/4/27.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT const NSUInteger DNAdNoNetworkErrorCode; //设备无网络导致的请求错误
FOUNDATION_EXPORT const NSUInteger DNAdTimeOutErrorCode; //设备无网络导致的请求错误
FOUNDATION_EXPORT const NSUInteger DNAdServerErrorCode; //服务端导致的错误
FOUNDATION_EXPORT const NSUInteger DNAdClientErrorCode; //设备端导致的错误

FOUNDATION_EXPORT NSErrorDomain const DNBaiduErrorDomain;///百度广告错误
FOUNDATION_EXPORT const NSInteger DNBaiduErrorCode;
FOUNDATION_EXPORT NSErrorDomain const DNGDTErrorDomain;///广点通广告错误
FOUNDATION_EXPORT NSErrorDomain const DNKuaiShouErrorDomain;///快手广告错误
FOUNDATION_EXPORT const NSInteger DNKuaiShouErrorCode;
FOUNDATION_EXPORT NSErrorDomain const DNSigmobErrorDomain;///Sigmob广告错误
FOUNDATION_EXPORT const NSInteger DNSigmobErrorCode;
FOUNDATION_EXPORT NSErrorDomain const DNMintegralErrorDomain;///Mintegral广告错误
FOUNDATION_EXPORT const NSInteger DNMintegralErrorCode;

FOUNDATION_EXPORT NSErrorDomain const DNADListEmptyErrorDomain;///广告列表为空
FOUNDATION_EXPORT const NSInteger DNADListEmptyErrorCode;

FOUNDATION_EXPORT NSErrorDomain const DNGetAdErrorDomain; ///获取广告错误
FOUNDATION_EXPORT NSErrorDomain const DNStrategyErrorDomain; ///获取广告时策略错误

FOUNDATION_EXPORT NSErrorDomain const DNAdSDKVersionTooOldErrorDomain; /// SDK版本过旧
FOUNDATION_EXPORT const NSInteger DNAdSDKVersionTooOldErrorCode;

FOUNDATION_EXPORT NSErrorDomain const DNSupplierErrorDomain;
FOUNDATION_EXPORT const NSUInteger DNSupplierErrorCode;

FOUNDATION_EXPORT NSErrorDomain const DNSplashGetTooFrequentlynErrorDomain; ///获取开屏广告过于频繁
FOUNDATION_EXPORT const NSInteger DNSplashGetTooFrequentlynErrorCode;
FOUNDATION_EXPORT NSErrorDomain const DNSplashADIsShowingErrorDomain; ///已经有开屏广告正在展示
FOUNDATION_EXPORT const NSInteger DNSplashADIsShowingErrorCode;
