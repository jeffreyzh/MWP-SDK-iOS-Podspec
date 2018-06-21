
Pod::Spec.new do |s|

  s.name         = "MWP-iOS-Open"
  s.version      = "0.0.6.1"
  s.summary      = "MWP SDK for iOS."

  s.description  = <<-DESC
  meili wireless platform SDK for iOS.
                   DESC

  s.homepage     = "http://github.com/meili/MWP-SDK-iOS-Podspec"

  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author             = { "mogujie" => "mopen@meili-inc.com" }

   s.platform     = :ios
   s.platform     = :ios, "8.0"

  #  When using multiple platforms
   s.ios.deployment_target = "8.0"
  # s.osx.deployment_target = "10.7"
  # s.watchos.deployment_target = "2.0"
  # s.tvos.deployment_target = "9.0"

  s.source       = { :git => "http://github.com/meili/MWP-SDK-iOS-Podspec.git", :tag => "#{s.version}" }

  s.requires_arc = true

  s.default_subspecs = 'SDK', 'Interface'

  s.subspec '__default__' do |ss|
     ss.vendored_libraries = 'libMWP-iOS-Open.a'
  end

  s.subspec 'SDK' do |ss|
    # ss.private_header_files = 'MWP-iOS-Open/Classes/SDK/**/*.h'
    # ss.source_files = 'MWP-iOS-Open/Classes/SDK/**/*'
    ss.dependency 'MWP-iOS-Open/__default__'
    ss.dependency 'MLComm-Open'
    ss.dependency 'AFNetworking'
  end

  s.subspec 'Interface' do |ss|
    ss.public_header_files = 'MWP-iOS-Open/Classes/Interface/*.h'
    ss.source_files = 'MWP-iOS-Open/Classes/Interface/*'
    ss.dependency 'MWP-iOS-Open/__default__'
  end


end
