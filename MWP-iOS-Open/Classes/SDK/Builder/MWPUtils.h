//
//  MWPUtils.m
//  MWP-SDK-iOS
//
//  Created by gairui on 2018/5/22.
//

#import <Foundation/Foundation.h>

static inline BOOL MWP_IS_EMPTY(id thing) {
    return thing == nil ||
    ([thing isEqual:[NSNull null]]) ||
    ([thing respondsToSelector:@selector(length)] && [(NSData *)thing length] == 0) ||
    ([thing respondsToSelector:@selector(count)]  && [(NSArray *)thing count] == 0);
}
