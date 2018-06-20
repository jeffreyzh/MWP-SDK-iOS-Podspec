//
// Created by gairui on 2017/2/15.
// Copyright (c) 2017 kongkong. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MWPCompositeNetworkManager;
@class MWPNetworkDataTask;
@class MWPNetAnalytics;
@class MWPCompositeNetworkTransactionMetrics;
@class MGJNetworkTransactionMetrics;
@class MWCSChannelTransactionMetrics;
@class MGJNetworkTransaction;
//@class MWCSChannelRequestMetrics;

extern NSString *const MWP_NETWORK_VALUE_MWCS_DEGRADE_REASON;
extern NSString *const MWP_NETWORK_VALUE_MEC_DEGRADE_REASON;
extern NSString *const MWP_NETWORK_VALUE_MWCS_DEGRADE_REASON_MESSAGE;

@protocol MWPNetworkTaskDelegate <NSObject>
- (void)MWPNetwork:(MWPCompositeNetworkManager *)session task:(MWPNetworkDataTask *)dataTask prepareStart:(nullable void *)pVoid;

- (void)MWPNetwork:(nonnull MWPCompositeNetworkManager *)session task:(nonnull MWPNetworkDataTask *)dataTask didCompleteWithError:(nullable NSError *)error;

- (void)MWPNetwork:(nonnull MWPCompositeNetworkManager *)session task:(nonnull MWPNetworkDataTask *)dataTask didReceiveResponseObject:(nullable id)responseObject;

@end

@interface MWPNetworkDataTask : NSObject <NSCopying>
@property(nonnull, readonly) NSString *taskIdentifier;
@property(nullable, nonatomic, readonly, copy) NSURLRequest *originalRequest;
/**
 * 经过处理的request,和originalRequest不同。比如URL的NDS处理
 */
@property(nullable, nonatomic, readonly, copy) NSURLRequest *currentRequest;
@property(nullable, nonatomic, readonly, copy) NSURLResponse *response;
@property(nullable, readonly, copy) MWPCompositeNetworkTransactionMetrics *metrics;
@property(nullable, readonly, copy) NSError *error;
@property(nullable, nonatomic, readonly, weak) MWPCompositeNetworkManager *session;
@property(nullable, readonly, copy) id responseObject;
@property(nullable, strong) id delegate;
@property(nullable, strong) id userInfo;

- (void)start;

- (void)cancel;

- (id)copyWithZone:(NSZone *)zone;

@end

@interface MWPNetworkInternalDataTask : MWPNetworkDataTask

- (void)startWithConnType:(NSString *)connType;

/**
 * 以成功结束
 * @param response
 * @param responseObject
 * @param request
 * @param metrics
 */
- (void)successWithResponse:(nonnull NSURLResponse *)response
             responseObject:(nullable id)responseObject
             currentRequest:(nonnull NSURLRequest *)request;

/**
 * 以失败结束
 * @param error
 * @param metrics
 */
- (void)failWithError:(nonnull NSError *)error
       currentRequest:(NSURLRequest *)request;
@end

@interface MWPCompositeNetworkManager : NSObject <MWPNetworkTaskDelegate>
+ (nonnull instancetype)manager;

- (nonnull MWPNetworkDataTask *)dataTaskWithRequest:(nonnull NSURLRequest *)request
                                  completionHandler:(void (^)(MWPNetworkDataTask *dataTask, NSURLResponse *response, id responseObject, NSError *error))completionHandler;

@end


#pragma mark - MWPCompositeNetwork

typedef void(^MWPCompositeNetworkCompleteHandler)(__nonnull id context, __nullable id response, NSError *error);

@protocol MWPCompositeNetworkCall <NSObject>
- (void)enqueueWithBlock:(nullable MWPCompositeNetworkCompleteHandler)callback;

- (void)cancel;
@end

@protocol MWPCompositeNetwork <NSObject>

- (nonnull id <MWPCompositeNetworkCall>)newCall:(nonnull NSURLRequest *)request withContext:(nonnull MWPNetworkDataTask *)task;

@end

//TODO persistentExtra不重置移到task中，改成多个Metrics，一个connType对于一个connType
@interface MWPCompositeNetworkTransactionMetrics : NSObject <NSCopying>

@property(nullable, strong) NSMutableDictionary *persistentExtra;

/**
 * 以下属性需要重置
 */
@property(nonatomic, copy) NSString *connType;
@property(copy) NSURLRequest *request;
@property(nullable, copy) NSURLResponse *response;
@property(nullable, copy) NSError *error;

@property(nullable, copy) NSDate *fetchStartDate;
@property(nullable, copy) NSDate *fetchEndDate;

@property(nullable, copy) NSDate *domainLookupStartDate;

@property(nullable, copy) NSDate *domainLookupEndDate;

@property(nullable, copy) NSDate *connectStartDate;

@property(nullable, copy) NSDate *secureConnectionStartDate;

@property(nullable, copy) NSDate *secureConnectionEndDate;

@property(nullable, copy) NSDate *connectEndDate;

@property(nullable, copy) NSDate *requestStartDate;

@property(nullable, copy) NSDate *requestEndDate;

@property(nullable, copy) NSDate *responseStartDate;

@property(nullable, copy) NSDate *responseEndDate;

@property(nullable, copy) NSString *networkProtocolName;

@property(assign) BOOL proxyConnection;

@property(assign) BOOL reusedConnection;

@property(nonatomic) int64_t receivedDataLength;

- (instancetype)copyPersistentExtraWithConnType:(NSString *)connType;

- (NSDictionary *)extraInfoForNetworkRecorder;

- (MGJNetworkTransaction *)convertToMGJNetworkTransaction;

//- (instancetype)setMWCSTransactionMetrics:(MWCSChannelRequestMetrics *)mwcsMetrics error:(NSError *)error;

- (id)copyWithZone:(NSZone *)zone;


@end
