//
// Created by gairui on 16/5/5.
//

#import <Foundation/Foundation.h>
#import "RemoteSwitch.h"

@interface MWPSwitchConfig : NSObject <RemoteSwitch>

+ (instancetype)instance;

- (BOOL)isGlobalCacheSwitchOpen;


@end
