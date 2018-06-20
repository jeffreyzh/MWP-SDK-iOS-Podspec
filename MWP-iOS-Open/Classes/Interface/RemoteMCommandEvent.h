//
// Created by gairui on 16/7/20.
//

#import <Foundation/Foundation.h>


@interface RemoteMCommandEvent : NSObject

@property(nonatomic, copy) NSString *value;

- (instancetype)initWithValue:(NSString *)value;

@end