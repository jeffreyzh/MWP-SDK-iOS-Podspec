//
//  MWPContext.h
//  Pods
//
//  Created by kongkong on 15/12/30.
//
//

#import <Foundation/Foundation.h>
#import "RemoteContext.h"
#import <WTPipelineForOC/MGJWTPipelineInvocationHandle.h>
#import "RemoteBizDomain.h"


@protocol MWPProvider;
@class MWPNetAnalytics;
@class MWPRequest;
@class RemoteConfiguration;

/**
 *  @author kongkong
 *
 *  @brief 请求上下文的impl，实例对象中存放 http Head，params，api，version和sign
 */
@interface MWPContext : NSObject <RemoteContext>

@property(nonatomic, strong) RemoteConfiguration *remoteConfig; /// 配置信息
@property(nonatomic, assign) NSTimeInterval invokeTime; /// 运行时间记录
@property(nonatomic, weak) id <MGJWTPipelineInvocationHandle> handle; ///pipeline句柄
@property(nonatomic, strong) id <MWPProvider> provider; /// 额外操作

@property(nonatomic, strong) MWPRequest *request;
@property(nonatomic, strong) NSMutableDictionary<NSString *, NSString *> *heads;
//@property(nonatomic, strong) id <NSObject> params;
//@property(nonatomic, copy) NSString *method;
//@property(nonatomic, copy) NSString *api;
//@property(nonatomic, copy) NSString *version;
@property(nonatomic, copy) NSString *host;
@property(nonatomic, copy) NSString *pathPrefix;

/**
 * http://api.mogueji.com/gw/api/v
 */
@property(nonatomic, copy) NSURL *baseUrlWithApi;

///< 需要在response阀门中，解析数据成对应实例，则注册cls
@property(nonatomic) Class responseCls;
///< 请求回调
@property(nonatomic, copy) RemoteCallback callback;
///< 是否使用Https
@property(nonatomic, assign) BOOL useSecurity;

///< 重试次数
@property(atomic, assign) NSUInteger retryCount;

@property(atomic, assign) NSUInteger maxRetryCount;

- (BOOL)isExceedRetryCount;

@property(nonatomic, assign) NSTimeInterval sendTime;

///< 额外信息，例如用户信息等
@property(nonatomic, strong) NSMutableDictionary<NSString *, id> *extra;

/**
 * 缓存的回调
 */
@property(nonatomic, copy) RemoteCacheCallback cacheCallback;

/**
 * 是否使用缓存
 */
@property(nonatomic, assign) BOOL useCache;

/**
 * 业务域
 */
@property(nonatomic, strong) RemoteBizDomain *bizDomain;

/**
 * 埋点数据
 */
@property(nonatomic, strong) MWPNetAnalytics *statsNetEvent;


@end
