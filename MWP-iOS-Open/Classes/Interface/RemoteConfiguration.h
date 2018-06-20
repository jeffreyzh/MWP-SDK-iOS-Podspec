
#import <Foundation/Foundation.h>
#import "RemoteBuild.h"

@interface RemoteConfiguration : NSObject <NSCopying>

/**
 * ttid表示渠道、平台、版本等信息, 格式需要符合：channel@appName_appType_version_build
 * 必填
 */
@property(nonatomic, copy) NSString *ttid;

/**
 * userAgent
 * 可选
 */
@property(nonatomic, copy) NSString *userAgent;

/**
 * 应用的id号, mwp平台自己维护的6位数字
 * 必填
 */
@property(nonatomic, copy) NSString *appKey;     ///< 应用id【MWP平台分配值】（需要外部设置）

/**
 * 应用的密钥,生成签名时使用
 * 必填
 */
@property(nonatomic, copy) NSString *appSecret;     ///< 应用id【MWP平台分配值】（需要外部设置）

/**
 * 全局的网络环境，默认为线上
 */
@property(nonatomic, assign) MWPENV env;

/**
 * 是否打印日志
 */
@property(nonatomic, assign) BOOL writeLogs;

/**
 * ttid表示渠道、平台、版本等信息, 格式需要符合：channel@appName_appType_version_build
 * @param channel 渠道
 * @param appName 应用名
 * @param version 版本号
 * @param buildVersion 构建版本号
 */
- (void)setTtidWithChannel:(NSString *)channel appName:(NSString *)appName version:(NSString *)version buildVersion:(NSString *)buildVersion;

@end
