//
// Created by gairui on 16/6/15.
//

#import <Foundation/Foundation.h>

@protocol RemoteSwitch <NSObject>

typedef NS_ENUM(NSUInteger, SocketForcedMode) {
    DEBUG_FORCED_RELEASE = 0,        //线上模式
    DEBUG_FORCED_ON = 1, //强制走长链
    DEBUG_FORCED_OFF = 2 //强制不走长链
};

/**
 * MGC 非安全长链的开关,后面会废弃
 */
@property(nonatomic, assign, readonly, getter=isGlobalSocketSwitchOpen) BOOL globalSocketSwitchOpen;

/**
 * MEC 安全长链的开关
 */
@property(nonatomic, assign, readonly, getter=isGlobalMecSwitchOpen) BOOL globalMecSwitchOpen;

/**
 * MWCS 安全长链的开关
 */
@property(nonatomic, assign, readonly, getter=isGlobalMWCSSwitchOpen) BOOL globalMWCSSwitchOpen;

/**
 * 长链 强制打开或者关闭
 */
@property(nonatomic, assign) SocketForcedMode socketForcedMode;

/**
 * HTTP2的流量开关
 */
@property(nonatomic, assign, readonly, getter=isGlobalH2ApiOpen) BOOL globalH2ApiOpen;

/**
 * App Transport Security
 */
@property(nonatomic, assign, getter=isGlobalATSOpen) BOOL globalATSOpen;

/**
 * cookie
 */
@property(nonatomic, assign, getter=isGlobalCookieOpen) BOOL globalCookieOpen;


/**
 * mars 安全长链的开关
 */
@property(nonatomic, assign, readonly, getter=isGlobalMarsSwitchOpen) BOOL globalMarsSwitchOpen;


@end