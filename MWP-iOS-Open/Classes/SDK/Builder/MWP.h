
#import <Foundation/Foundation.h>
#import "RemoteBuild.h"
#import "MWPProvider.h"
#import <WTPipelineForOC/MGJWTCancelable.h>

@class MGJWTDefaultPipeline;
@class MWPPipelineCancelableDelegate;
@protocol MWPCookieJar;

@interface MWP : NSObject <MWPProvider>

- (instancetype)initWithConfiguration:(RemoteConfiguration *)configuration;

@property(nonatomic, strong, readonly) RemoteConfiguration *config;

@property(nonatomic, strong, readonly) MGJWTDefaultPipeline *pipeline;

@property(nonatomic, strong, readonly) id <MWPCookieJar> cookieJar;

@end

static dispatch_queue_t mwp_processing_queue() {
    static dispatch_queue_t mwp_processing_queue;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        mwp_processing_queue = dispatch_queue_create("com.mogujie.mwp.processing.queue", DISPATCH_QUEUE_CONCURRENT);
    });

    return mwp_processing_queue;
}


typedef void(^MWPPipelineCancelableHandler)(MWPPipelineCancelableDelegate *delegate);

@interface MWPPipelineCancelableDelegate : NSObject <MGJWTCancelable>

@property(nonatomic, copy) MWPPipelineCancelableHandler cancelableHandler;

- (instancetype)initWithCancelableHandler:(MWPPipelineCancelableHandler)cancelableHandler;

+ (instancetype)delegateWithCancelableHandler:(MWPPipelineCancelableHandler)cancelableHandler;

@end
