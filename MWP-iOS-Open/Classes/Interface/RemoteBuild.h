#import <Foundation/Foundation.h>
#import "RemoteCallBack.h"
#import "RemoteUser.h"
#import "RemoteCall.h"

@protocol RemoteMCommand;
@protocol RemoteCallBuilder;
@protocol RemoteDslCallBuilder;
@protocol MWPCookieJar;
@protocol RemoteSwitch;
@class RemoteConfiguration;

extern NSString *const MWPFastFailoverNotification;
extern NSString *const MWPFastFailoverNotificationResponseItem;

typedef NS_ENUM(NSUInteger, MWPNetStack) {
    MWPNetStackLegacy = 0,
    MWPNetStackMec = 1,
    MWPNetStackMWCS = 2
};

extern NSString *const MWPNetStackName[];

typedef NS_ENUM(NSUInteger, RemoteMethod) {
    R_METHOD_GET,
    R_METHOD_POST,
};

typedef NS_OPTIONS(NSUInteger, MWPENV) {
    MWP_RELEASE = 1,    ///< 线上环境
    MWP_PRE_RELEASE,     ///< 预发环境
    MWP_DAILY,           ///< 发布环境
};

extern NSString *MWPEnvHostName(MWPENV env);

extern NSString *MWPErrorCodeMessageName(NSString *ret);


@protocol EasyRemoteBuild

@property(nonatomic, copy, readonly) id <RemoteCallBuilder> (^apiAndVersion)(NSString *api, NSString *v);

@property(nonatomic, copy, readonly) id <RemoteDslCallBuilder> (^getDSL)(void);

@end

@protocol RemoteBuild <RemoteUser>

@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSString *> *customQuery;

@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSString *> *customHeader;

@property(nonatomic, assign) MWPENV env;

@property(nonatomic, strong, readonly) id <RemoteSwitch> remoteSwitch;

@property(nonatomic, strong, readonly) id <RemoteMCommand> remoteMCommand;

- (instancetype)initWithConfiguration:(RemoteConfiguration *)configuration;

- (void)startWithConfiguration:(RemoteConfiguration *)configuration;

@required
/**
 * 用这个方法开启EasyRemote方式调用
 */
//- (id <RemoteCall>)asyncCall:(MWPRequest *)request;

@end
