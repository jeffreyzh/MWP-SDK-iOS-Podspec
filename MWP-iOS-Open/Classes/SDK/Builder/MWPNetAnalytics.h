//
// Created by gairui on 16/5/31.
//

#import <Foundation/Foundation.h>
#import "RemoteBuild.h"

@class MWPCompositeNetworkTransactionMetrics;

@interface MWPNetAnalytics : NSObject

@property(nonatomic, copy) MWPCompositeNetworkTransactionMetrics *metrics;

- (NSDictionary *)commit;


@end
