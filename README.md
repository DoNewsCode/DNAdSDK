## **iOS集成指南**

## 步骤1：工程设置(必要)

### 平台创建应用和代码位
> **请在聚合广告平台上创建好应用ID和广告位ID。**

### 集成SDK
#### 方式一：手动集成framework
> **下载**[聚合广告SDK](download/iOS_sdk)**将ZIP解压，将内容拖放到项目中。**
**5.3版本之后可以选择集成想要的联盟SDK，不需要的可以不引入**

#### 方式二：pod集成framework

> **支持pod方式接入，只需配置pod环境，在podfile文件中加入以下代码即可接入成功。 pod 'DNAdSDK'**
**请在pod或手动引入第三方联盟的SDK， 集成哪几个请与后台配置广告保持一致。**
* GDTMobSDK // 广点通 （建议使用pod）
* Bytedance-UnionAD //穿山甲 （建议使用pod）
* BaiduAdSDK //百度
* KSAdSDK //快手 （建议使用pod）(5.5版本及以后版本开始支持)
* SigmobAd-iOS //Sigmob （建议使用pod）(5.5版本及以后版本开始支持)
* MintegralAdSDK //Mintegral （建议使用pod）(5.5版本及以后版本开始支持)

**特别注意⚠️！！因为百度AdSDK已经停止在pod更新，所以请手动下载并引入其SDK**
**下载地址：[百度广告SDK](download/other_sdk)**

##   步骤2：全局配置(必要)

### XCode编译选项设置
#### 配置info.plist
> **在info.plist中添加 App Transport Security Settings 设定，由于苹果默认限制HTTP请求，需手动配置才可正常访问HTTP请求，SDK的API均已使用HTTPS但部分媒体资源需要使用HTTP**
> **TIPS：可以右击info.plist文件，选择Open As -> Source Code，然后将下列代码粘贴进去**
```
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

> **iOS14之后获得IDFA需要申请，所以请在info.plist中添加 Privacy - Tracking Usage Description 描述**
> **TIPS：可以右击info.plist文件，选择Open As -> Source Code，然后将下列代码粘贴进去**
```
<key>NSUserTrackingUsageDescription</key>
<string>只有您使用‘允许跟踪’才能为您推荐个性化内容与活动,关闭跟踪并不会减少内容的推荐,只是可能会降低对您的个性化推荐.</string>
```

### 配置项目三方库的编译选项
> **点击主工程 -> Build Settings -> 搜索Other Linker Flags -> 在列表中找到Other Linker Flags -> 添加参数`-ObjC`**
> **点击主工程 -> Build Settings -> 搜索Enable Bitcode -> 在列表中找到Enable Bitcode -> 修改参数为`NO`**

### 运行环境配置
* 支持系统 iOS 9.0 及以上
* SDK编译环境 Xcode 12.1 (12A7403)
* 支持架构： x86-64, armv7, armv7s, arm64

### 添加依赖库（pod 接入方式可以略过此步）
* libc++.tbd
* libsqlite3.0.tbd
* libz.tbd
* libxml2.tbd
* libresolv.9.tdb
* AVFoundation.framework
* AdSupport.framework
* CoreMotion.framework
* CoreMedia.framework
* CoreLocation.framework
* CoreGraphics.framework
* CoreTelephony.framework
* CoreServices.framework
* MediaPlayer.framework
* MessageUI.framework 
* StoreKit.framework
* SystemConfiguration.framework
* SafariServices.framework
* Security.framework
* WebKit.framework
* Photos.framework
* IOKit.framework
> **IOKit.framework 特别说明，如果在依赖库列表中找不到IOKit.framework 请右击"访达(Finder)"-"前往文件夹"-"输入下列路径，找到IOKit.framework拖入到引用库列表即可"
/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/System/Library/Frameworks/IOKit.framework

##  步骤3：开始代码接入

### 全局设置(DNAdKitManager)
> **DNAdKitManager 类是整个 SDK 设置的入口，是一个单例对象，通过DNAdKitManager 来进行SDK的一些全局信息配置。**

### 接口说明
```
//  当前测试通过的SDK版本
//  --百度 = 4.67
//  --穿山甲 = 3.3.0.5
//  --广点通 = 4.11.12
//  --快手 = 3.3.5
//  --Sigmob = 2.22.0
//  --Mintegral = 6.6.8
//  请尽量使用上述版本，其他版本未经过测试

/// 获取SDK版本
@property (nonatomic, strong, readonly) NSString *SDKVersion;
/// 网络请求超时时间，默认为3
@property (nonatomic) NSTimeInterval timeoutInterval;
/// 是否现实DebugLog
@property (nonatomic, assign, getter=isShowDebugLog) BOOL showDebugLog;

/// 媒体控制回调（需在startService前调用），该方法会回调控制的需求，每当SDK设定背景音乐需要关闭或恢复时都会回调此方法。
/// 如果此回调为空SDK将会在内部控制AVAudioSession，从而达到控制背景音乐的要求。
/// 如果您的应用对于声音控制比较严格请使用此回调以禁用SDK对AVAudioSession的控制
/// 注：文档中已开源此项内部实现，可供您参考。此方法对于某些供应商的SDK可能无效，烦请自测。
@property (nonatomic, copy, nullable) void (^AVAudioSessionControlCallback)(BOOL isNeedStopBackgroundSound);
/// 当上面的回调没有被实现，SDK需要暂停或恢复背景音乐的时候会设置下面的值，入无特殊需求请不要更改。
/// 如果您希望应用在播放广告的时候视频媒体是不随静音按钮状态而静音的请设置suspendBackgroundSoundAudioSessionCategory = AVAudioSessionCategoryPlayback
/// 当SDK需要暂停背景音乐的时候，会将`AVAudioSession setCategory`设置下面的值默认=AVAudioSessionCategorySoloAmbient
@property (nonatomic) AVAudioSessionCategory suspendBackgroundSoundAudioSessionCategory;
/// 当SDK需要恢复背景音乐的时候，会将`AVAudioSession setCategory`设置下面的值默认=AVAudioSessionCategoryAmbient
@property (nonatomic) AVAudioSessionCategory resumeBackgroundSoundAudioSessionCategory;

/// 单利对象
+ (instancetype)sharedManager;
/// 启动初始化服务，可在非主线程中执行
- (void)startService;
/// 打印所有SDK版本信息
- (NSString *)printAllSDKVersionInfo;
```

### App启动时SDK初始化
> **可以在在 AppDelegate 的方法` - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions` 中配置初始化设定**
```
DNAdKitManager *mgr = DNAdKitManager.sharedManager;
mgr.showDebugLog = YES;
/// 调用这句可检测联盟SDK引用状况，可用来判断大部分不走代理，无回调问题
[mgr printAllSDKVersionInfo];
[mgr startService];
```

### 跳转须知
> **广告接口中的所有controller均为必传项，用来处理广告跳转。SDK里所有的跳转均采用present的方式，请确保传入的controller不能为空且没有present其他的控制器，否则会出现presentedViewController已经存在而导致present失败**

### 开屏广告(DNSplashAd)
> **开屏广告主要是 APP 启动时展示的广告视图，开发只要按照接入标准就能够展示设计好的视图,根据是否传入bottomView来决定展示全屏、半屏广告**

#### DNSplashAd接口说明
```
//************** 以下是类属性 **************//
/// 是否在开屏时隐藏状态栏，默认是YES !!!!  
@property (nonatomic, class, getter=isHiddenStatusBar) BOOL hiddenStatusBar;
//************** 类属性  end **************//

@property (nonatomic, copy, readonly) NSString *placeId;
/// 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak, readonly) UIViewController *controller;
/// 默认=NO。
/// 此方法如果设置为YES则将会在聚合SDK最后一个可控Controller时自动查找传入控制器的栈顶控制器，以避免广告无法正常弹出的问题。
@property (nonatomic, assign, getter=isAdShowCompatibilityMode) BOOL adShowCompatibilityMode;

@property (nonatomic, strong, readonly, nullable) UIView *bottomView;
/// 背景色//默认为白色
@property (nonatomic, strong) UIColor *backgroundColor;
/// 代理对象
@property (nonatomic, weak) id<DNSplashAdDelegate> delegate;

/// 初始化方法
/// @param placeId 广告位置id
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 同下
- (void)loadAdAndShowWithController:(UIViewController *)controller;

/// 在开屏页面底部设置应用自身的Logo页面或是自定义View
/// 详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
/// 请注意
///     1.bottomView需设置高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%。必须设置height，如果height=0，将使用默认值200
///     2.Splash广告只支持竖屏
///     3.除广点通外，其余开屏均支持了safeArea
/// @param controller 广告被点击时push内容的控制器
/// @param bottomView 自定义底部View，可以在此View中设置应用Logo
- (void)loadAdAndShowWithController:(UIViewController *)controller bottomView:(UIView *_Nullable)bottomView;
```

#### 创建DNSplashAd接口实例
```
DNSplashAd.hiddenStatusBar = isHiddenStatusBar;
DNSplashAd *splash = [DNSplashAd.alloc initWithPlaceId:placeID];
splash.delegate = self;
// splash.backgroundColor = UIColor.redColor;
_splash = splash; //需要全局持有实例否则实例被销毁将无法正常展示广告
CGRect frame = bottomView.frame;
frame.size = (CGSize){UIScreen.mainScreen.bounds.size.width, 100.0}; /// 在frame中设置好bottomView的高就可以使用自定义高度，否则将使用默认100
bottomView.frame = frame;
[splash loadAdAndShowWithController:controller bottomView:bottomView];
```

#### DNSplashAdDelegate回调说明
```
/**
 开屏广告加载成功的回调
 @param splashAd 产生该事件的 DNSplashAd 对象
 */
- (void)splashAdDidLoadSuccess:(DNSplashAd *)splashAd;

/**
 开屏广告加载失败的回调
 @param splashAd 产生该事件的 DNSplashAd 对象
 @param error Error对象
 */
- (void)splashAdDidLoadFaild:(DNSplashAd *)splashAd withError:(NSError *)error;

/**
 开屏广告点击的回调
 @param splashAd 产生该事件的 DNSplashAd 对象
 */
- (void)splashAdClicked:(DNSplashAd *)splashAd;

/**
 开屏广告点击关闭按钮的回调
 @param splashAd 产生该事件的 DNSplashAd 对象
 */
- (void)splashAdDidClickCloseButton:(DNSplashAd *)splashAd;

/**
 关闭开屏广告的回调
 @param splashAd DNSplashAd 对象
 */
- (void)splashAdDidClose:(DNSplashAd *)splashAd;

/**
 广告将要消失的回调
 @param splashAd 产生该事件的 DNSplashAd 对象
 */
- (void)splashAdWillClose:(DNSplashAd *)splashAd;

/**
 开屏广告完成曝光的回调
 @param splashAd splashAd 对象
 */
- (void)splashAdExposured:(DNSplashAd *)splashAd;

/**
 直客开屏视频广告准备播放回调！！！！！！！仅仅用于直客视频类型开屏，其他无效！！！！！
 @param splashAd splashAd 对象
 @param isLoadInCache 视频资源是不是从缓存加载的，YES从缓存加载，NO当前直接加载全部后播放
 */
- (void)splashAdVideoWillPlay:(DNSplashAd *)splashAd isLoadInCache:(BOOL)isLoadInCache;
```


### Banner广告(DNBannerAdView)
> ** banner广告可通过DNBannerAdView配置广告基本信息。例如期望尺寸，为避免渲染过程产生广告视图形变，务必和媒体平台配置相同尺寸。通过设置DNBannerAdViewDelegate代理，获取广告、展示、点击、关闭等回调。值得注意的是一定要设置controller，即跳转落地页需要的viewController。**

#### DNBannerAdView接口说明
```
/// 代理对象
@property (nonatomic, weak) id<DNBannerAdViewDelegate> delegate;
/// 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

@property (nonatomic, copy, readonly) NSString *placeId;

/// 指定构造器
/// @param frame adview的大小，如您设置了其size会将以更优的方式返回接近设置尺寸的图像。
/// tips！想要显示适应控件尺寸清晰度的图像必须在此初始化方法传入的frame.size中才能生效，使用view.frame不会影响图像质量
/// @param placeId 广告位id
- (instancetype)initWithFrame:(CGRect)frame placeId:(NSString *)placeId;

/// 拉取并展示广告
- (void)loadAdAndShow;
```

#### DNBannerAdView接口实例
```
DNBannerAdView *bannerView = [DNBannerAdView.alloc initWithFrame:(CGRect){CGPointZero, adSize} placeId:placeID];
bannerView.controller = controller;
bannerView.delegate = self;
[bannerView loadAdAndShow];
```

#### DNBannerAdViewDelegate回调说明
```

/// bannerAdView加载成功时的回调
/// banner是可能有多条广告轮流展示的，所以banner每次展示了新的广告都会回调此方法
/// @param bannerView bannerView对象本身
- (void)bannerAdDidLoadSuccessForBannerView:(DNBannerAdView *)bannerView;

/// bannerAdView加载失败时的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidLoadFaildForBannerView:(DNBannerAdView *)bannerView error:(NSError *)error;

/// bannerAdView发生轮换时的回调，不会轮换的供应商将不会回调此方法
/// @param bannerView bannerView对象本身
- (void)bannerAdDidRotationForBannerView:(DNBannerAdView *)bannerView;

/// bannerAdView曝光的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidExposureForBannerView:(DNBannerAdView *)bannerView;

/// 点击banner广告的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidClickForBannerView:(DNBannerAdView *)bannerView;

/// 落地页显示完成
/// @param bannerView bannerView对象本身
- (void)bannerAdDidShowDetailsForBannerView:(DNBannerAdView *)bannerView;

/// 落地页内点击返回
/// @param bannerView bannerView对象本身
- (void)bannerAdDetailsDidCloseForBannerView:(DNBannerAdView *)bannerView;

/// 点击广告上的❌关闭广告(没有关闭按钮的不回调此方法)
/// @param bannerView bannerView对象本身
- (void)bannerAdDidClickCloseForBannerView:(DNBannerAdView *)bannerView;
```

### 自渲染信息流(DNFeedAd) 
> **自渲染信息流广告即普通 feed 流广告，是在feed流场景下的原生广告**
> **使用说明：
在SDK里只需要使用 DNFeedAd 就可以获取信息流广告。SDK 提供信息流广告的数据绑定、点击事件的上报，用户可自行定义信息流广告展示形态与布局，自渲染中由于关闭按钮是由开发者布局的所以请务必在用户点击关闭钮时调用（- (*void*)registClickClose;）否则将会导致刷新后广告还会显示的问题，详情可以参考Demo**

#### DNFeedAd接口说明
```
@property (nonatomic, copy, readonly) NSString *placeId;
/// 信息流数据结果状态的 代理对象
@property (nonatomic, weak) id<DNFeedAdDelegate> delegate;
/// 开发者需传入用来弹出目标页的ViewController，一般为显示广告的ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 指定构造器
/// @param placeId 广告位id
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 请求信息流广告
/// @param count 请求广告的数量
- (void)loadAdWithCount:(NSInteger)count;

/// 注册元素广告关闭操作
- (void)registClickCloseWithAdMaterial:(DNAdMaterial *)adMaterial;
```

####  DNFeedAd接口实例
> **在初始化 DNFeedAd 对象之前，要先设置好 DNAdSlot，通过loadAdWithSlot: 方法来获取广告数据，其中DNAdSlot中的adCount方法能够根据 count 设置返回广告数据的个数，同样通过 delegate 来处理回调。**

> **参见下面代码示例：**
    
```
DNFeedAd *feedAd = [[DNFeedAd alloc] initWithPlaceId:placeID];
feedAd.controller = controller;
feedAd.delegate = self;
_nativeFeed = feedAd; //需要全局持有实例否则实例被销毁将无法正常展示广告
[feedAd loadAdWithCount:adCount];
```


#### DNFeedAdDelegate回调说明
```
/**
 自渲染广告加载数据成功回调
 @param materialArray 广告模型数组
 */
- (void)feedAdDidLoadSuccess:(DNFeedAd *)feedAd materialArray:(NSArray<DNAdMaterial *> *)materialArray;

/**
  自渲染广告加载数据失败回调
 @param error 错误对象
 */
- (void)feedAdDidLoadFaild:(DNFeedAd *)feedAd error:(NSError *)error;

/// 广告曝光回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewWillExpose:(DNFeedAdContentView *)view;

/// 广告点击回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewDidClick:(DNFeedAdContentView *)view;

/// 广告详情页关闭回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewAdDetailViewClosed:(DNFeedAdContentView *)view;

/// 当点击应用下载或者广告调用系统程序打开时调用
//- (void)feedAdContentViewApplicationWillEnterBackground:(DNFeedAdContentView *)view;

/// 广告详情页面即将展示回调
- (void)feedAd:(DNFeedAd *)feedAd contentViewWillPresentScreen:(DNFeedAdContentView *)view;
```

> **TIPS1⚠️！广告请求成功后会在`- (void*)feedAdDidLoadSuccess:(DNFeedAd *)feedAd materialArray:(NSArray<DNAdMaterial *> *)materialArray`代理方法中回调回来一个DNAdMaterial数组，是用于展示在自己的列表中的数据源，自行创建DNFeedAdContentView，并分发到DNFeedAdContentView中，才可以正常使用自渲染信息流**
> **TIPS2⚠️！在广告位id（placeID）不变的情况下可以重复调用-loadAdWithCount：方法，就可以获取更多条目，但是注意，因为DNFeedAd对象内部会一直持有各供应商的广告实例，不是必要的情况下不建议这么做。举个例子，比如需求是在tableview中插入几条广告，那么当tableview滑动到加载更多时可能需要更多的广告，这时候就可以使用同一个DNFeedAd实例去调用-loadAdWithCount：，在下拉刷新时重新创建DNFeedAd实例，让其内部持有各供应商的广告实例得以释放已减少内存压力。ps，如果发现点击某一条feed广告不能跳转极有可能就是您因为重新生成了DNFeedAd实例并全局引用了新的实例，而让之前的DNFeedAd释放了，但是您的Cell还在持有DNAdMaterial对象的原因。**

#### DNFeedAdContentView
> **DNFeedAdContentView是自定义信息流的基类视图，将DNFeedAdContentView作为父视图，将自定义的控件摆放在其上，才能正常使用自渲染信息流**
> **TIPS！cell也可讲DNFeedAdContentView放在视图最底部，最佳方式是继承后重写，再通过-layoutSubview布局，一定要设置DNFeedAdContentView的frame！！**
> **DNFeedAdContentView接口**

```
/// 是否开启点击兼容性模式，默认NO， 请在构造实例完成后尽早设置此项否则可能失效。
/// 如果发现自渲染集成后无法正常点击打开落地页，请优先检查您是否使用了手势，如果使用了手势，请将手势的cancelsTouchesInView设置为NO。
/// 如还是没有响应，可以尝试打开此开关。(此方法对广点通无效)
/// 注意！打开此开关可能会影响布局在DNFeedAdContentView上的按钮点击后仍会触发DNFeedAdContentView的点击从而打开落地页。
@property (nonatomic, getter=isClickCompatibilityMode) BOOL clickCompatibilityMode;

/// 原生自渲染物料模型
@property (nonatomic, strong, nullable) DNAdMaterial *adMaterial;

/// 当adMaterial.creative_type == DNAdCreativeTypeVideo时才有效果
/// 视频播放器视图，默认没有加到任何视图上面，也没有布局，请自行添加和布局
@property (nonatomic, readonly, strong) DNFeedAdVideoView *videoView;
```

### 模版信息流(DNExpressFeedAd) 
> **模板信息流广告是一种具备动态渲染能力的一种原生广告。即通过开发者在媒体平台编辑渲染模板，SDK支持实时更新广告布局，SDK进行渲染并为开发者提供渲染视图**

> **使用说明：**

> ** 模板信息流广告可通过DNAdSlot配置广告基本信息。目前模板信息流广告的尺寸只支持自适应大小。通过设置DNExpressFeedAdDelegate代理，获取广告、展示、点击、关闭等回调。开发者可以通过nativeExpressAdSuccessToLoad回调中的views数组获取到展示的广告视图，详情参考demo。值得注意的是一定要设置controller，即跳转落地页需要的viewController。**

> **接入影响：**

> ** 模板为了优化展示速度,会使用本地模板,请求时会拦截相关数据.如果接入方正在使用H5的页面发送请求,会造成请求body清空,其他逻辑不变.如果使用body传参请更换其他方式.例如:jsBridge方式.**

> **TIPS⚠️！在广告位id（placeID）不变的情况下可以重复调用-loadAdWithCount：方法，就可以获取更多条目，但是注意，因为DNExpressFeedAd对象内部会一直持有各供应商的广告实例，不是必要的情况下不建议这么做。举个例子，比如需求是在tableview中插入几条广告，那么当tableview滑动到加载更多时可能需要更多的广告，这时候就可以使用同一个DNFeedAd实例去调用-loadAdWithCount：，在下拉刷新时重新创建DNExpressFeedAd实例，让其内部持有各供应商的广告实例得以释放已减少内存压力。ps，如果发现点击某一条feed广告不能跳转极有可能就是您因为重新生成了DNExpressFeedAd实例并全局引用了新的实例，而让之前的DNExpressFeedAd释放了，但是您的Cell还在持有DNExpressFeedAdView对象的原因。**

#### DNExpressFeedAd接口说明
```
@property (nonatomic, copy, readonly) NSString *placeId;
@property (nonatomic, assign, readonly) CGSize adSize;
/// 信息流数据结果状态的 代理对象
@property (nonatomic, weak) id<DNExpressFeedAdDelegate> delegate;
/// [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 指定构造器
/// @param placeId 广告位id
/// @param adSize 广告尺寸
- (instancetype)initWithPlaceId:(NSString *)placeId adSize:(CGSize)adSize;

/// 请求信息流广告
/// @param count 请求广告的数量
- (void)loadAdWithCount:(NSInteger)count;
```

#### DNExpressFeedAd接口实例
```
DNExpressFeedAd *expressAd = [DNExpressFeedAd.alloc initWithPlaceId:placeID adSize:adSize];
expressAd.controller = controller;
expressAd.delegate = self;
_expressFeed = expressAd; //需要全局持有实例否则实例被销毁将无法正常展示广告
[expressAd loadAdWithCount:adCount];
```


#### DNExpressFeedAdDelegate回调说明
```
/// 拉取原生模板广告成功
/// @param expressFeedAd expressFeedAd对象本身
/// @param views 模版广告视图数组
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd loadSuccessWithViews:(NSArray<DNExpressFeedAdView *> *)views;

/// 拉取原生模板广告失败
/// @param expressFeedAd expressFeedAd对象本身
/// @param error 错误信息
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd loadFailureWithError:(NSError *)error;

/// 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd renderSuccessForView:(DNExpressFeedAdView *)view;

/// 原生模板广告渲染失败
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd renderFailureForView:(DNExpressFeedAdView *)view;

/// 原生模板广告曝光回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd exposureForView:(DNExpressFeedAdView *)view;

/// 原生模板广告点击回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd didClickedForView:(DNExpressFeedAdView *)view;

/// 原生模板广告被关闭
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd didClosedForView:(DNExpressFeedAdView *)view;

/// 即将打开广告落地页
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd willShowDetailsForView:(DNExpressFeedAdView *)view;

/// 关闭广告落地页
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd didCloseDetailsForView:(DNExpressFeedAdView *)view;

/// 播放器状态发生变化时回调
/// @param expressFeedAd expressFeedAd对象本身
/// @param status 当前播放器状态
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd playerDidChangedStatus:(DNExpressPlayerStatus)status forView:(DNExpressFeedAdView *)view;

/// 视频广告播放完毕
/// @param expressFeedAd expressFeedAd对象本身
/// @param view 模板View
- (void)expressFeedAd:(DNExpressFeedAd *)expressFeedAd playerDidPlayFinishForView:(DNExpressFeedAdView *)view;
```

#### DNExpressFeedAdView说明
> **广告请求成功后会操作一组DNExpressFeedAdView类型的view，这些便是模版广告的view，请将view添加之想展示的地方，注意⚠️！一定要调用view 的`- (void)render;` 方法不然会是空白的，此操作是为了避免视图过多时内存溢出，请务必懒加载使用。**

```
/// 是否渲染完毕
@property (nonatomic, readonly, getter=isReady) BOOL ready;
/// 是否是视频模板广告
@property (nonatomic, readonly, getter=isVideoAd) BOOL videoAd;
/// 视频模板广告时长，单位 ms
@property (nonatomic, readonly) NSTimeInterval videoDuration;
/// 视频模板广告已播放时长，单位 ms
@property (nonatomic, readonly) NSTimeInterval videoPlayTime;
/// 自定义标识对象，此字段是为了开发者方便，开发者可在此字段传入分辨view的标识符，在代理返回View中以分辨DNExpressFeedAdView的身份。
/// 此字段对于DNExpressFeedAdView内部没有任何作用
@property (nonatomic, strong, nullable) id customIdentity;

///在显示view之前必须调用此方法不然会什么也没有！！
- (void)render;
```

###  插屏(DNExpressInterstitialAd) 
> **插屏广告主要是用户暂停某个操作时展示的全屏广告视图，开发只要按照接入标准就能够展示设计好的视图。**

#### DNInterstitialAd
```
/// 代理对象
@property (nonatomic, weak) id <DNInterstitialAdDelegate> delegate;

@property (nonatomic, copy, readonly) NSString *placeId;

/// 构造方法
/// @param placeId placeId - 广告位 ID
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 加载广告方法
- (void)loadAD;
 
/// 展示插屏广告
/// @param controller 用于展示插屏的控制器
- (void)interstitialAdShowInController:(UIViewController *)controller;
```

#### DNInterstitialAd接口实例
```
DNInterstitialAd *interstitial = [DNInterstitialAd.alloc initWithPlaceId:placeID];
interstitial.delegate = self;
_interstitial = interstitial; //需要全局持有实例否则实例被销毁将无法正常展示广告
[interstitial loadAD];
```

#### DNInterstitialAd Delegate
```
/// 当接收服务器返回的广告数据成功且预加载后调用该函数
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDidLoadSuccessForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 当接收服务器返回的广告数据失败后调用该函数
/// @param interstitialAd interstitialAd对象本身
/// @param error 错误信息
- (void)interstitialAdDidLoadFaildForInterstitialAd:(DNInterstitialAd *)interstitialAd error:(NSError *)error;

/// 插屏广告即将展示回调该函数
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdWillVisibleForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 插屏广告展示结束回调该函数
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDidClosedForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 插屏广告曝光回调
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDidExposureForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 插屏广告点击回调
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDidClickForInterstitialAd:(DNInterstitialAd *)interstitialAd;

/// 全屏广告页将要关闭
/// @param interstitialAd interstitialAd对象本身
- (void)interstitialAdDetailsDidClosedForInterstitialAd:(DNInterstitialAd *)interstitialAd;
```

### 激励视频(DNRewardedVideoAd)
> **激励视频广告是一种全新的广告形式，用户可选择观看视频广告以换取有价物，例如虚拟货币、应用内物品和独家内容等等；这类广告的长度为 15-30 秒，不可跳过，且广告的结束画面会显示结束页面，引导用户进行后续动作。**

#### DNRewardedVideoAd接口说明
> **TIPS！ 每次需要生成新的DNRewardedVideoAd对象调用loadAd方法请求最新激励视频，请勿重复使用本地缓存激励视频多次展示**

```
/// 代理对象
@property (nonatomic, weak) id <DNRewardedVideoAdDelegate> delegate;

@property (nonatomic, copy, readonly) NSString *placeId;

/// 构造方法
/// @param placeId placeId - 广告位 ID
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 加载广告方法 支持 iOS9.0 及以上系统
- (void)loadAD;
 
/// 展示激励视频
/// @param controller 用于展示激励视频的控制器
- (void)rewardedVideoShowInController:(UIViewController *)controller;
```

#### DNRewardedVideoAd接口实例
```
DNRewardedVideoAd *rewardedVideo = [DNRewardedVideoAd.alloc initWithPlaceId:placeID];
rewardedVideo.delegate = self;
_rewardedVideo = rewardedVideo; //需要全局持有实例否则实例被销毁将无法正常展示广告
[rewardedVideo loadAD];
```

#### DNRewardedVideoAdDelegate回调说明
```
/// 广告数据加载成功回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidLoad:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告各种错误信息回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
/// @param error 错误信息
- (void)rewardVideoAd:(DNRewardedVideoAd *)rewardedVideoAd didFaildWithError:(NSError *)error;
 
/// 视频数据下载成功回调，已经下载过的视频会直接回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdVideoDidLoad:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频播放页即将展示回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdWillVisible:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告曝光回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidExposed:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频播放页关闭回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidClose:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告信息点击回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidClicked:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告播放达到激励条件回调
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidRewardEffective:(DNRewardedVideoAd *)rewardedVideoAd;

/// 视频广告视频播放完成
/// @param rewardedVideoAd rewardedVideoAd对象本身
- (void)rewardVideoAdDidPlayFinish:(DNRewardedVideoAd *)rewardedVideoAd;

```


## 扩展：各个供应商提供的个性回调(Beta 1.1)
> **在之前的开发过程中您可能已经介入过【广点通】【穿山甲】【百度】或更多聚合支持的AdSDK，因为聚合SDK统一了它们的共性，因此有些厂商的非共性代理回调就没有办法在聚合广告的代理中体现，没关系，有了`DNAdDelegateCallbackProtocol`就能完美解决这个问题**

> **只要遵守了`DNAdDelegateCallbackProtocol`这个协议（现全部广告都支持此协议），就可以在开发过程中使用“adDelegateCallback”**

### DNAdDelegateCallback
> ** DNAdDelegateCallback的参数详解**

```
为兼容各种代理回调方式，所以DNAdDelegateCallback有两个参数一个返回值。
第一个是该回调的广告类型，是为了区分相同名字的不同供应商代理会被覆盖的问题。
第二个是参数，这个参数并不是供应商广告回调的AD类，而是其之后的参数，比如视频回调的时候的类型，详见下面的表，基本数据类型会包装成NSNumber，超过两个参数会包装成字典，key就是原形参名称。

返回值亦是一样，如果该代理方法有要返回值，请直接returen值，如果是基本数据类型，也是包装成NSNumber再返回，结构体装成NSValue再返回，没有返回值的return nil。

typedef id _Nullable (^DNAdDelegateCallback)(DNAdProvider, id _Nullable);
```

> **详细用法**

```
/// 设定一个回调，必须是DNAdDelegateCallback类型的block
DNAdDelegateCallback splashAdCountdownToZero = ^id (DNAdProvider adType, id obj){
    NSLog(@"回调啦  splashAdCountdownToZero:");
    return nil;
};
    
DNSplashAd.hiddenStatusBar = isHiddenStatusBar;
DNSplashAd *splash = [DNSplashAd.alloc initWithPlaceId:placeID];

/// 然后以其方法名的方式（注意带冒号）作为KEY将CALLBACK block作为VALUE放进去，注意！一定要  copy   一下，否则可能会崩溃。
splash.callbackPool = @{@"splashAdCountdownToZero:": [splashAdCountdownToZero copy]};

splash.delegate = self;
_splash = splash; //需要全局持有实例否则实例被销毁将无法正常展示广告
CGRect frame = bottomView.frame;
frame.size = (CGSize){UIScreen.mainScreen.bounds.size.width, 100.0};
bottomView.frame = frame;
[splash loadAdAndShowWithController:controller bottomView:bottomView];
```


### 现支持参数对照表

> **Splash开屏**

Key | 供应商 | 参数解释| 备注
:-: | :-: | :-: | :-:
splashAdSuccessPresentScreen: | 广点通 | - | 开屏广告成功展示
splashAdApplicationWillEnterBackground: | 广点通 | - | 当点击下载应用时会调用系统程序打开，应用切换到后台
splashAdWillPresentFullScreenModal: | 广点通 | - | 开屏广告点击以后即将弹出全屏广告页
splashAdDidPresentFullScreenModal: | 广点通 | - | 开屏广告点击以后弹出全屏广告页
splashAdWillDismissFullScreenModal: | 广点通 | - | 点击以后全屏广告页将要关闭
splashAdLifeTime: | 广点通 | NSNumber包裹的NSUInteger | 开屏广告剩余时间回调
splashAdCountdownToZero: | 穿山甲 | - | 当开屏广告倒计时等于零时调用此方法
splashDidReady:AndAdType:VideoDuration: | 百度 | NSDictionary参数集合 | 广告加载完成
ksad_splashAdVideoDidSkipped: | 快手 | - | 视频闪屏广告跳过
splashADLoadSuccess: | Mintegral | - | 加载广告成功时调用。
splashADShowSuccess: | Mintegral | - | 成功显示广告时调用。
splashADDidLeaveApplication: | Mintegral | - | 当应用程序因tap事件即将离开时调用。调用此方法后不久，应用程序将被移到后台。
splashAD:timeLeft: | Mintegral | NSNumber包裹的NSUInteger | 在剩余倒计时更新时调用。。

> **Interstitial插屏**

Key | 供应商 | 参数解释| 备注
:-: | :-: | :-: | :-:
unifiedInterstitialDidPresentScreen: | 广点通 | - | 插屏2.0广告展示成功回调该函数
unifiedInterstitialWillLeaveApplication: | 广点通 | - | 当点击下载应用时会调用系统程序打开其它App或者Appstore时回调
unifiedInterstitialAdWillPresentFullScreenModal: | 广点通 | - | 点击插屏2.0广告以后即将弹出全屏广告页
unifiedInterstitialAdDidPresentFullScreenModal: | 广点通 | - | 点击插屏2.0广告以后弹出全屏广告页
unifiedInterstitialAdDidDismissFullScreenModal: | 广点通 | - | 全屏广告页被关闭
unifiedInterstitialAd:playerStatusChanged: | 广点通 | NSNumber包裹的GDTMediaPlayerStatus | 插屏2.0视频广告 player 播放状态更新回调
unifiedInterstitialAdViewWillPresentVideoVC | 广点通 | - | 插屏2.0视频广告详情页 WillPresent 回调
unifiedInterstitialAdViewDidPresentVideoVC: | 广点通 | - | 插屏2.0视频广告详情页 DidPresent 回调
unifiedInterstitialAdViewWillDismissVideoVC: | 广点通 | - | 插屏2.0视频广告详情页 WillDismiss 回调
unifiedInterstitialAdViewDidDismissVideoVC: | 广点通 | - | 插屏2.0视频广告详情页 DidDismiss 回调
nativeExpresInterstitialAdWillClose: | 穿山甲 | - | 当InterstitialAd即将关闭时调用此方法。

> **Rewarded激励视频**

Key | 供应商 | 参数解释| 备注
:-: | :-: | :-: | :-:
nativeExpressRewardedVideoAdDidDownLoadVideo: | 穿山甲 | - | 成功缓存时调用此方法。
nativeExpressRewardedVideoAdViewRenderSuccess: | 穿山甲 | - | 在成功呈现nativeExpressAdView时调用此方法。
nativeExpressRewardedVideoAdWillClose: | 穿山甲 | - | 此方法在视频广告即将关闭时调用。
nativeExpressRewardedVideoAdDidClickSkip: | 穿山甲 | - | 当用户单击跳过按钮时调用此方法。
nativeExpressRewardedVideoAdServerRewardDidFail: | 穿山甲 | - | 异步请求的服务器验证失败。 返回值不是2000。
nativeExpressRewardedVideoAdDidCloseOtherController:interactionType: | 穿山甲 | NSNumber包裹的BUInteractionType | 当另一个控制器关闭时调用此方法。
rewardedVideoAdWillClose: | 快手 | - | 此方法在视频广告即将关闭时调用。
rewardedVideoAdDidClickSkip: | 快手 | - | 此方法在用户单击“跳过”按钮时调用。
rewardedVideoAdStartPlay: | 快手 | - | 此方法在视频开始播放时调用。
rewardedVideoAd:hasReward: | 快手 | - | 此方法在用户关闭视频广告时调用。
onVideoEndCardShowSuccess:unitId: | Mintegral | - | 仅当广告有endcard内容时调用，当endcard显示时调用。

> **ExpressFeed模版信息流**

Key | 供应商 | 参数解释| 备注
:-: | :-: | :-: | :-:
nativeExpressAdViewDidPresentScreen: | 广点通 | DNExpressFeedAdView对象 | 点击原生模板广告以后弹出全屏广告页
nativeExpressAdViewWillDissmissScreen: | 广点通 | 同上 | 全屏广告页将要关闭
nativeExpressAdViewApplicationWillEnterBackground: | 广点通 | 同上 | 详解:当点击应用下载或者广告调用系统程序打开时调用
nativeExpressAdViewWillPresentVideoVC: | 广点通 | 同上 | 原生视频模板详情页 WillPresent 回调
nativeExpressAdViewDidPresentVideoVC: | 广点通 | 同上 | 原生视频模板详情页 DidPresent 回调
nativeExpressAdViewWillDismissVideoVC: | 广点通 | 同上 | 原生视频模板详情页 WillDismiss 回调
nativeExpressAdViewDidDismissVideoVC: | 广点通 | 同上 | 原生视频模板详情页 DidDismiss 回调

> **Feed自渲染信息流**

Key | 供应商 | 参数解释| 备注
:-: | :-: | :-: | :-:
gdt_unifiedNativeAdViewApplicationWillEnterBackground: | 广点通 | DNFeedAdContentView对象 | 当点击应用下载或者广告调用系统程序打开时调用
gdt_unifiedNativeAdView:playerStatusChanged:userInfo: | 广点通 | NSDictionary参数集合 | 当点击应用下载或者广告调用系统程序打开时调用
nativeAdDidLoad: | 快手 | DNFeedAdContentView对象 | 当本地广告材料成功加载时，将调用此方法
nativeAd:didFailWithError: | 快手 | DNFeedAdContentView对象 | 当本机ad materiala加载失败时调用此方法


## AVAudioSessionControl 内部实现

```

- (instancetype)init {
    if (self = [super init]) {
        _suspendBackgroundSoundAudioSessionCategory = AVAudioSessionCategorySoloAmbient;
        _resumeBackgroundSoundAudioSessionCategory = AVAudioSessionCategoryAmbient;
    }
    return self;
}

- (void)setNeedStopBackgroundSound:(BOOL)isNeedStopBackgroundSound {
    _isNeedStopBackgroundSound = isNeedStopBackgroundSound;
    if (_AVAudioSessionControlCallback != nil) {
        _AVAudioSessionControlCallback(isNeedStopBackgroundSound);
    } else {
        AVAudioSession *audioSession = AVAudioSession.sharedInstance;
        if (isNeedStopBackgroundSound) {
            if (audioSession.category != _suspendBackgroundSoundAudioSessionCategory) {
                [audioSession setCategory:_suspendBackgroundSoundAudioSessionCategory withOptions:AVAudioSessionCategoryOptionMixWithOthers|AVAudioSessionCategoryOptionDefaultToSpeaker error:nil];
            }
            if (audioSession.isOtherAudioPlaying) {
                [audioSession setActive:YES withOptions:AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation error:nil];
            }
        } else {
            if (audioSession.category != _resumeBackgroundSoundAudioSessionCategory) {
                [audioSession setCategory:_resumeBackgroundSoundAudioSessionCategory withOptions:AVAudioSessionCategoryOptionMixWithOthers|AVAudioSessionCategoryOptionDefaultToSpeaker error:nil];
            }
            if (!audioSession.isOtherAudioPlaying) {
                [audioSession setActive:NO withOptions:AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation error:nil];
            }
        }
    }
}
```
