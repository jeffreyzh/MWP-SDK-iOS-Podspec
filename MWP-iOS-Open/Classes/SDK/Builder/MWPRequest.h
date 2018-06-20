//
// Created by Zephyrleaves on 16/3/15.
//

#import <Foundation/Foundation.h>
#import "RemoteCallBack.h"
#import "RemoteBuild.h"

@class RemoteBizDomain;


@interface MWPRequest : NSObject

@property(nonatomic, copy) NSString *api;
@property(nonatomic, copy) NSString *version;
@property(nonatomic, strong) id <NSObject> parameter;
@property(nonatomic, assign) BOOL useSecurity;
@property(nonatomic, copy) NSString *bizNameSpace;
@property(nonatomic) Class returnClass;
@property(nonatomic, assign) RemoteMethod method;
@property(nonatomic, copy) RemoteCallback callback;
@property(nonatomic, copy) RemoteCacheCallback cacheCallback;
@property(nonatomic, assign) BOOL useCache;
@property(nonatomic, strong) RemoteBizDomain *bizDomain;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *debugIP;
@end
