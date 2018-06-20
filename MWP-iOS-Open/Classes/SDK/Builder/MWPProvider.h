//
// Created by Zephyrleaves on 16/3/16.
//

#import <Foundation/Foundation.h>
#import "RemoteBuild.h"

@protocol MWPLoginAction;

@protocol MWPProvider <RemoteBuild>
- (void)addLoginAction:(id <MWPLoginAction>)action;
@end