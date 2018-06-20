//
// Created by gairui on 16/7/20.
//

#import <Foundation/Foundation.h>
#import "RemoteMCommand.h"


@protocol RemoteMCommandHandle <RemoteMCommand, RemoteMCommandListener>
@end

@interface MWPMCommand : NSObject <RemoteMCommandHandle>
@end
