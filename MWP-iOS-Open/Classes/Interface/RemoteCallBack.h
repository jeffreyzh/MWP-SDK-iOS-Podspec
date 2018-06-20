
#import <Foundation/Foundation.h>
#import "RemoteResponse.h"

typedef void (^RemoteCallback)(id <RemoteResponse> response);

typedef void (^RemoteCacheCallback)(id <RemoteResponse> response);
