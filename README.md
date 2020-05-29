## **iOS集成指南**

## 步骤1：工程设置(必要)

### 平台创建应用和代码位
> **请在多牛聚合广告平台上创建好应用ID和广告位ID。**

### 集成SDK
#### 方式一：手动集成framework
> **下载**[多牛聚合广告SDK](download/other_sdk)**将ZIP解压，将内容拖放到项目中。**

#### 方式二：pod集成framework
> **支持pod方式接入，只需配置pod环境，在podfile文件中加入以下代码即可接入成功。 pod 'DNAdSDK'**

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

### 配置项目三方库的编译选项
> **点击主工程 -> Build Settings -> 搜索Other Linker Flags -> 在列表中找到Other Linker Flags -> 添加参数`-ObjC`**
> **点击主工程 -> Build Settings -> 搜索Enable Bitcode -> 在列表中找到Enable Bitcode -> 修改参数为`NO`**

### 运行环境配置
* 支持系统 iOS 9.0 及以上
* SDK编译环境 Xcode 10.0
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

##  步骤3：开始代码接入

### 全局设置(DNAdKitManager)
> **DNAdKitManager 类是整个 SDK 设置的入口，是一个单例对象，通过DNAdKitManager 来进行SDK的一些全局信息配置。**

### 接口说明
```
//  当前测试通过的SDK版本
//  --百度 = 4.67
//  --穿山甲 = 2.9.5.6
//  --广点通 = 4.11.5/4.11.7/4.11.8
//  其他烦请自测，如有问题请及时联系我们

/// 服务器环境 (默认是测试环境)
@property (nonatomic, assign) DNAdAPIType apiType;
/// 网络请求超时时间，默认为3
@property (nonatomic) NSTimeInterval timeoutInterval;
/// 获取SDK版本
@property (nonatomic, strong, readonly) NSString *SDKVersion;

/// 单利对象
+ (instancetype)sharedManager;
/// 启动初始化服务，可在非主线程中执行
- (void)startService;
/// 打印所有SDK版本信息
- (void)printAllSDKVersionInfo;
```

### App启动时SDK初始化
> **可以在在 AppDelegate 的方法` - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions` 中配置初始化设定**
```
    DNAdKitManager *mgr = DNAdKitManager.sharedManager;
#ifdef DEBUG
    mgr.apiType = DNAdSDKApiTypeDebug;
#else
    mgr.apiType = DNAdSDKApiTypeRelease;
#endif
//    mgr.isLogger = YES;
    [mgr startService];
```

### 跳转须知
> **广告接口中的所有controller均为必传项，用来处理广告跳转。SDK里所有的跳转均采用present的方式，请确保传入的controller不能为空且没有present其他的控制器，否则会出现presentedViewController已经存在而导致present失败**

### 开屏广告(DNSplashAd)
> **开屏广告主要是 APP 启动时展示的广告视图，开发只要按照接入标准就能够展示设计好的视图,根据是否传入bottomView来决定展示全屏、半屏广告**

#### DNSplashAd接口说明
```
/// 代理对象
@property (nonatomic, weak) id<DNSplashAdDelegate> delegate;

/// 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

@property (nonatomic, copy, readonly) NSString *placeId;

@property (nonatomic, strong, readonly) UIView *bottomView;

/**
 初始化方法
 @param placeId 广告位置id 
 @return SplashAd实例
 */
- (instancetype)initWithPlaceId:(NSString *)placeId;

/// 同下
- (void)loadAdAndShowWithController:(UIViewController *)controller;

/**
 *  在开屏页面底部设置应用自身的Logo页面或是自定义View
 *  详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
 *  请注意
 *       1.bottomView需设置高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%。必须设置height，如果height=0，将使用默认值200
 *       2.Splash广告只支持竖屏
 *       3.除广点通外，其余开屏均支持了safeArea
 @param controller 广告被点击时push内容的控制器
 @param bottomView 自定义底部View，可以在此View中设置应用Logo
 */
- (void)loadAdAndShowWithController:(UIViewController *)controller bottomView:(UIView *_Nullable)bottomView;
```

#### 创建DNSplashAd接口实例
```
DNSplashAd *splash = [DNSplashAd.alloc initWithPlaceId:placeID];
splash.delegate = self;
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
 开屏广告即将分配供应商
 @param splashAd splashAd 对象
 @param type 即将加载的广告提供商类型
 */
- (void)splashAd:(DNSplashAd *)splashAd willDispenseAdOfType:(DNAdProvider)type;

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
/// 即将开始加载banner广告
/// @param bannerView bannerView对象本身
- (void)bannerAdWillLoadForBannerView:(DNBannerAdView *)bannerView;

/// bannerAdView加载成功时的回调
/// banner是可能有多条广告轮流展示的，所以banner每次展示了新的广告都会回调此方法
/// @param bannerView bannerView对象本身
- (void)bannerAdDidLoadSuccessForBannerView:(DNBannerAdView *)bannerView;

/// bannerAdView加载失败时的回调
/// @param bannerView bannerView对象本身
- (void)bannerAdDidLoadFaildForBannerView:(DNBannerAdView *)bannerView error:(NSError *)error;

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

/**
 banner广告即将分配供应商
 @param bannerView bannerView对象本身
 @param type 即将加载的广告提供商类型
 */
- (void)bannerView:(DNBannerAdView *)bannerView willDispenseAdOfType:(DNAdProvider)type;
```

### 广告位类(DNAdSlot)
> **在使用Feed流类型的广告之前我们先要看看 广告位类(DNAdSlot)这个对象，这个对象是用来设置Feed流拉取的一些配置**

#### DNAdSlot接口说明
```
/// 请求广告的数量 默认是1 (⚠️最大是3,推荐一次请求一个 作用于信息流)
@property (nonatomic, assign) NSInteger adCount;

/// 广告位置id
@property (nonatomic, copy) NSString *positionId;

/// 指定广告整体的size (⚠️一般用于联盟的模板广告 height传0表示自适应)
@property (nonatomic, assign) CGSize adSize;
```

#### DNAdSlot接口实例
```
DNAdSlot *slot = [[DNAdSlot alloc] init];
slot.positionId = @“000”;
slot.adCount = 1;
```

### 自渲染信息流(DNFeedAd) 
> **自渲染信息流广告即普通 feed 流广告，是在feed流场景下的原生广告**
> **使用说明：
在SDK里只需要使用 DNFeedAd 就可以获取信息流广告。SDK 提供信息流广告的数据绑定、点击事件的上报，用户可自行定义信息流广告展示形态与布局，自渲染中由于关闭按钮是由开发者布局的所以请务必在用户点击关闭钮时调用（- (*void*)registClickClose;）否则将会导致刷新后广告还会显示的问题，详情可以参考Demo**

#### DNFeedAd接口说明
```
/**
*  信息流数据结果状态的 代理对象
*/
@property (nonatomic, weak) id<DNFeedAdDelegate> delegate;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 广告位置相关信息
 */
@property (nonatomic, readonly, strong) DNAdSlot *slot;

/**
 请求信息流广告
 */
- (void)loadAdWithSlot:(DNAdSlot *)slot;

/**
 注册元素广告关闭操作
 */
- (void)registClickClose;
```

####  DNFeedAd接口实例
> **在初始化 DNFeedAd 对象之前，要先设置好 DNAdSlot，通过loadAdWithSlot: 方法来获取广告数据，其中DNAdSlot中的adCount方法能够根据 count 设置返回广告数据的个数，同样通过 delegate 来处理回调。**

> **参见下面代码示例：**
    
```
DNAdSlot *slot = DNAdSlot.alloc.init;
slot.positionId = placeID;
slot.adCount = 3;

DNFeedAd *feedAd = [[DNFeedAd alloc] init];
feedAd.controller = controller;
feedAd.delegate = self;
_nativeFeed = feedAd; //需要全局持有实例否则实例被销毁将无法正常展示广告
[feedAd loadAdWithSlot:slot];
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

> **TIPS！广告请求成功后会在`- (void*)feedAdDidLoadSuccess:(DNFeedAd *)feedAd materialArray:(NSArray<DNAdMaterial *> *)materialArray`代理方法中回调回来一个DNAdMaterial数组，是用于展示在自己的列表中的数据源，自行创建DNFeedAdContentView，并分发到DNFeedAdContentView中，才可以正常使用自渲染信息流**

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
```

### 模版信息流(DNExpressFeedAd) 
> **模板信息流广告是一种具备动态渲染能力的一种原生广告。即通过开发者在媒体平台编辑渲染模板，SDK支持实时更新广告布局，SDK进行渲染并为开发者提供渲染视图**

> **使用说明：**

> ** 模板信息流广告可通过DNAdSlot配置广告基本信息。目前模板信息流广告的尺寸只支持自适应大小。通过设置DNExpressFeedAdDelegate代理，获取广告、展示、点击、关闭等回调。开发者可以通过nativeExpressAdSuccessToLoad回调中的views数组获取到展示的广告视图，详情参考demo。值得注意的是一定要设置controller，即跳转落地页需要的viewController。**

> **接入影响：**

> ** 模板为了优化展示速度,会使用本地模板,请求时会拦截相关数据.如果接入方正在使用H5的页面发送请求,会造成请求body清空,其他逻辑不变.如果使用body传参请更换其他方式.例如:jsBridge方式.**

#### DNExpressFeedAd接口说明
```
/// 信息流数据结果状态的 代理对象
@property (nonatomic, weak) id<DNExpressFeedAdDelegate> delegate;

/// [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 广告位
@property (nonatomic, readonly, strong) DNAdSlot *slot;


/// 请求广告
- (void)loadAdWithSlot:(DNAdSlot *)slot;
```

#### DNExpressFeedAd接口实例
```
DNAdSlot *slot = DNAdSlot.alloc.init;
slot.positionId = placeID;
slot.adCount = 1;

DNExpressFeedAd *expressAd = DNExpressFeedAd.alloc.init;
expressAd.controller = controller;
expressAd.delegate = self;
_expressFeed = expressAd; //需要全局持有实例否则实例被销毁将无法正常展示广告
[expressAd loadAdWithSlot:slot];
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

/// 插屏广告即将分配供应商
/// @param interstitialAd interstitialAd对象本身
/// @param type 即将加载的广告提供商类型
- (void)interstitialAd:(DNInterstitialAd *)interstitialAd willDispenseAdOfType:(DNAdProvider)type;
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

/**
 激励视频广告即将分配供应商
 @param rewardedVideoAd rewardedVideoAd对象本身
 @param type 即将加载的广告提供商类型
 */
- (void)rewardVideoAd:(DNRewardedVideoAd *)rewardedVideoAd willDispenseAdOfType:(DNAdProvider)type;
```

