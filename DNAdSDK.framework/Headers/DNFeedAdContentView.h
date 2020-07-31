//
//  DNFeedAdContentView.h
//  DNAdSDK
//
//  Created by Kinsun on 2020/5/7.
//  Copyright © 2020 Kinsun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNAdMaterial.h"

NS_ASSUME_NONNULL_BEGIN

/// 信息流自渲染视图基类，请将原生控件放在这个view上，如果是cell也可以将view摆放在所有视图的最底下。最佳方式是继承后重写，再通过-layoutSubview布局，一定要设置DNFeedAdContentView的frame！！！
@interface DNFeedAdContentView : UIView

/// 是否开启点击兼容性模式，默认NO， 请在构造实例完成后尽早设置此项否则可能失效。
/// 如果发现自渲染集成后无法正常点击打开落地页，请优先检查您是否使用了手势，如果使用了手势，请将手势的cancelsTouchesInView设置为NO。
/// 如还是没有响应，可以尝试打开此开关。(此方法对广点通无效)
/// 注意！打开此开关可能会影响布局在DNFeedAdContentView上的按钮点击后仍会触发DNFeedAdContentView的点击从而打开落地页。
@property (nonatomic, getter=isClickCompatibilityMode) BOOL clickCompatibilityMode;

/// 原生自渲染物料模型
@property (nonatomic, strong, nullable) DNAdMaterial *adMaterial;

@end

NS_ASSUME_NONNULL_END
