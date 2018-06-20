//
// Created by gairui on 16/7/20.
//

#import <Foundation/Foundation.h>

@class RemoteMCommandEvent;

#pragma mark -

@protocol RemoteMCommandListener <NSObject>
@required
- (void)onEvent:(RemoteMCommandEvent *)event;
- (NSString*)version;
@end


#pragma mark -

@protocol RemoteMCommand <NSObject>

- (void)addListener:(id <RemoteMCommandListener>)listener;

- (void)removeListener:(id <RemoteMCommandListener>)listener;

@end
