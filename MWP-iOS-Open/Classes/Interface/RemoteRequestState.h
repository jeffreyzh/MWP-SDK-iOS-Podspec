//
// Created by gairui on 16/5/17.
//

#import <Foundation/Foundation.h>

@interface RemoteRequestState : NSObject
/**
 * mwp appKey
 */
@property(nonatomic, copy, readonly) NSString *appKey;
@property(nonatomic, copy, readonly) NSString *appSecret;
@property(nonatomic, copy, readonly) NSString *userAgent;
@property(nonatomic, copy, readonly) NSString *ttid;
@property(nonatomic, copy, readonly) NSString *language;
@property(nonatomic, copy, readonly) NSString *deviceInfo;
@property(nonatomic, copy, readonly) NSString *deviceId;

/**
 * 客户端纠偏后的时间,单位毫秒
 */
@property(nonatomic, readonly, assign) double correctTime;
/**
 * 客户端和服务端时间偏移,单位毫秒
 */
@property(nonatomic, assign) double timeOffset;
/**
 * 客户端时间是否已经纠偏过了
 */
@property(nonatomic, readonly, assign) BOOL isTimeCorrected;

/**
 * user id
 */
@property(nonatomic, copy, readonly) NSString *uid;
/**
 * user session id
 */
@property(nonatomic, copy, readonly) NSString *sid;

/**
 * mwp协议版本号
 */
@property(nonatomic, copy, readonly) NSString *pv;

- (void)registerLoginInfoWithUid:(NSString *)uid sid:(NSString *)sid;

- (void)cleanLoginInfo;

- (instancetype)initWithAppKey:(NSString *)appKey appSecret:(NSString *)appSecret userAgent:(NSString *)userAgent ttid:(NSString *)ttid;

+ (RemoteRequestState *)instance;
@end
