
#import <Foundation/Foundation.h>

@protocol RemoteContext;
@protocol RemoteCall;
@class MWPRequest;
@class MWPContext;
@protocol DslCall;

@interface MWPCall : NSObject <RemoteCall, DslCall>
@property(nonatomic, strong, readonly) MWPRequest *request;
@property(nonatomic, strong, readonly) id <RemoteBuild> client;
@property(nonatomic, strong, readonly) id <RemoteContext> context;

+ (MWPCall *)newCallWithRequest:(MWPRequest *)request remoteBuild:(id <RemoteBuild>)remoteBuild;

@end
