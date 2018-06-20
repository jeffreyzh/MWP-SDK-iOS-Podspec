//
// Created by Zephyrleaves on 16/3/15.
//

#import <Foundation/Foundation.h>
#import "MWPAbstractValve.h"


@interface MWPNetworkValve : MWPAbstractValve

+ (id <RemoteResponse>)responseWithData:(id)responseObject
                                context:(id <RemoteContext>)rContext
                             statusCode:(NSInteger)statusCode
                                  heads:(NSDictionary *)heads
                                rawData:(NSData *)rawData
                                  error:(NSError *)error;
@end