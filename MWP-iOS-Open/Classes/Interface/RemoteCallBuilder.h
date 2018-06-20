//
// Created by gairui on 16/8/3.
//

#import <Foundation/Foundation.h>

@class RemoteBizDomain;
@protocol RemoteCall;

@protocol RemoteCallBuilder <NSObject>
@property(nonatomic, copy, readonly) id <RemoteCallBuilder> (^apiAndVersion)(NSString *api, NSString *v);
@property(nonatomic, copy, readonly) id <RemoteCallBuilder> (^parameter)(id <NSObject> parameter);
@property(nonatomic, copy, readonly) id <RemoteCallBuilder> (^useSecurity)(BOOL useSecurity);
@property(nonatomic, copy, readonly) id <RemoteCallBuilder> (^returnClass)(Class returnClass);
@property(nonatomic, copy, readonly) id <RemoteCallBuilder> (^useCache)(BOOL useCache);
@property(nonatomic, copy, readonly) id <RemoteCallBuilder> (^bizDomain)(RemoteBizDomain *bizDomain);
@property(nonatomic, copy, readonly) id <RemoteCallBuilder> (^debugIP)(NSString *debugIP);
@property(nonatomic, copy, readonly) id <RemoteCall> (^newCall)();

@end