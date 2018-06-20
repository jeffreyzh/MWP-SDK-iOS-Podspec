
#import <Foundation/Foundation.h>

#import "RemoteCallBack.h"

@protocol RemoteCall <NSObject>

@property(nonatomic, copy, readonly) id <RemoteCall> (^onCached)(RemoteCacheCallback cacheCallback);

@property(nonatomic, copy, readonly) void (^async)(RemoteCallback remoteCallback);

@property(nonatomic, copy, readonly) void (^cancel)();

@end
