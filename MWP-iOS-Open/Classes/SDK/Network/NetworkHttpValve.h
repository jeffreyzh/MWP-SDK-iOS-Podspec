//
// Created by gairui on 16/5/29.
//

#import <Foundation/Foundation.h>
#import "MWPAbstractValve.h"
#import "MWPCompositeNetworkManager.h"

@protocol MWPCompositeNetworkCall;
@class MWPNetworkDataTask;

@interface NetworkHttpValve : MWPAbstractValve

+ (NSString *)getLabel;

@end

