#
#  Be sure to run `pod spec lint DNAdSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|
  spec.name         = "DNAdSDK"
  spec.version      = "5.6.1"
  spec.summary      = "多牛聚合广告SDK"
  spec.description  = "多牛聚合广告SDK"

  spec.homepage     = "http://ad.infinities.com.cn/advertiser/"
  spec.author       = { "Donews" => "kinsunlu@sina.com" }
  
  spec.ios.deployment_target = "9.0"

  spec.source       = { :git => "https://github.com/DoNewsCode/DNAdSDK.git", :tag => "v5.6.1" }

  spec.resources    = "DNAdSDK.bundle"
  spec.frameworks   = "AVFoundation", "AdSupport", "CoreMotion", "CoreMedia", "CoreLocation", "CoreGraphics", "CoreTelephony", "CoreServices", "MediaPlayer", "MessageUI", "StoreKit", "SystemConfiguration", "SafariServices", "Security", "WebKit", "Photos"
  spec.libraries    = "c++", "sqlite3.0", "z", "xml2", "resolv.9"
  
  spec.requires_arc = true

  spec.vendored_frameworks  = '*.framework'

end
