//
// Created by gairui on 16/9/11.
//

#import <Foundation/Foundation.h>
#import "RemoteCallBack.h"

@class RemoteBizDomain;
@class RemoteDslParam;

@protocol DslParameter <NSObject>

@property(nonatomic, strong, readonly) NSMutableDictionary *body;

@end

@protocol DslCall <NSObject>
@property(nonatomic, copy, readonly) void (^async)(RemoteCallback remoteCallback);
@property(nonatomic, copy, readonly) id <DslCall> (^addObserver)(NSString *key, Class returnClass, RemoteCallback remoteCallback);
@property(nonatomic, copy, readonly) void (^removeObserver)(NSString *key);

@end

@protocol RemoteDslCallBuilder <NSObject>
@property(nonatomic, copy, readonly) id <RemoteDslCallBuilder> (^apiAndVersion)(NSString *api, NSString *v);
@property(nonatomic, copy, readonly) id <RemoteDslCallBuilder> (^parameter)(id <DslParameter> parameter);
@property(nonatomic, copy, readonly) id <RemoteDslCallBuilder> (^useSecurity)(BOOL useSecurity);
@property(nonatomic, copy, readonly) id <RemoteDslCallBuilder> (^useCache)(BOOL useCache);
@property(nonatomic, copy, readonly) id <RemoteDslCallBuilder> (^bizDomain)(RemoteBizDomain *bizDomain);
@property(nonatomic, copy, readonly) id <DslCall> (^newCall)();
@end