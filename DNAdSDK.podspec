#
#  Be sure to run `pod spec lint DNAdSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|
  spec.name         = "DNAdSDK"
  spec.version      = "5.1"
  spec.summary      = "多牛聚合广告SDK"
  spec.description  = <<-DESC
                   DESC

  spec.homepage     = "http://ad.infinities.com.cn/advertiser/"
  spec.author       = { "Donews" => "kinsunlu@sina.com" }
  
  spec.platform     = :ios
  spec.platform     = :ios, "9.0"

  spec.source       = { :git => "git@github.com:DoNewsCode/DNAdSDK.git", :tag => "5.1" }

  # spec.resources    = "Resources/*.bundle"
  spec.frameworks   = "AVFoundation", "AdSupport", "CoreMotion", "CoreMedia", "CoreLocation", "CoreGraphics", "CoreTelephony", "CoreServices", "MediaPlayer", "MessageUI", "StoreKit", "SystemConfiguration", "SafariServices", "Security", "WebKit", "Photos"
  spec.libraries    = "libc++", "libsqlite3.0", "libz", "libxml2", "libresolv.9"
  
  spec.requires_arc = true

  spec.vendored_frameworks  = '*.framework'
  # spec.vendored_libraries = 'Framewroks/*.a'
  spec.resource_bundles = {
        'DNAdSDK' => ['DNAdSDK.bundle']
    }
  spec.dependency "Bytedance-UnionAD", "~> 2.9.5.6"
  spec.dependency "GDTMobSDK", "~> 4.11.8"


end
