//
//  RemoteContext.h
//  Pods
//
//  Created by kongkong on 15/12/30.
//
//

#import <Foundation/Foundation.h>
#import "RemoteCallBack.h"
#import "RemoteResponse.h"

@protocol RemoteBuild;
@protocol MWPProvider;
@class RemoteBizDomain;
@class MWPNetAnalytics;
@class MWPRequest;
@class RemoteConfiguration;


/**
 *  @author kongkong
 *
 *  @brief 请求上下文
 *  这边的所有上下文参数都是 readonly，只有head和params可以由运行时的阀门动态添加修改参数
 *  设计初衷是：其他参数，在整个请求建立之前就已经决定了，不能在操作过程中被修改
 *            防止后续开放『阀门接口』给外部之后，被意外操作引发请求异常
 */
@protocol RemoteContext <NSObject>

@property(nonatomic, strong, readonly) RemoteConfiguration *remoteConfig;

@property(nonatomic, strong, readonly) MWPRequest *request;
///< 请求头
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSString *> *heads;
///< 请求参数，参数的正确性验证需要在某个阀门中处理，例如 RequestValidateValve
//@property(nonatomic, strong, readonly) id <NSObject> params;
///< 请求方式
//@property(nonatomic, copy, readonly) NSString *method;
///< 请求接口
@property(nonatomic, copy, readonly) NSString *api;
///< 请求接口版本
@property(nonatomic, copy, readonly) NSString *version;
///< 当前基本URL
@property(nonatomic, copy, readonly) NSString *host;
///< gw
@property(nonatomic, copy, readonly) NSString *pathPrefix;
///< 需要在response阀门中，解析数据成对应实例，则注册cls
@property(nonatomic, readonly) Class responseCls;
///< 请求回调
@property(nonatomic, copy, readonly) RemoteCallback callback;
///< 是否使用Https
@property(nonatomic, assign) BOOL useSecurity;

///< 返回数据对象
@property(nonatomic, strong) id <RemoteResponse> response;
///< 重试次数
@property(atomic, assign) NSUInteger retryCount;

@property(atomic, assign) NSUInteger maxRetryCount;

- (BOOL)isExceedRetryCount;

@property(nonatomic, assign) NSTimeInterval sendTime;

///< 额外信息，例如用户信息等
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, id> *extra;

@property(nonatomic, strong) id <MWPProvider> provider;

/**
 * 缓存的回调
 */
@property(nonatomic, copy, readonly) RemoteCacheCallback cacheCallback;

/**
 * 是否使用缓存
 */
@property(nonatomic) BOOL useCache;

/**
 * 业务域
 */
@property(nonatomic, strong, readonly) RemoteBizDomain *bizDomain;

/**
 * http://api.mogueji.com/gw/api/v
 */
@property(nonatomic, copy, readonly) NSURL *baseUrlWithApi;

/**
 * 网络栈的埋点数据
 */
@property(nonatomic, strong) MWPNetAnalytics *statsNetEvent;


/**
 *  @author kongkong
 *
 *  @brief 某个context完成操作，推送消息给上下文
 *
 *  @param context 请求句柄
 */
- (void)cancel;

@end

/**
 *  @author kongkong
 *
 *  @brief Extra 字段信息中保留字段
 */
#define EXTRA_JSON_PARAM    @"_context_json_param"  ///< param转化成json

