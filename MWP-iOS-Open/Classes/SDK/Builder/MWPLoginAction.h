//
// Created by Zephyrleaves on 16/3/16.
//

#import <Foundation/Foundation.h>

@protocol MWPLoginAction <NSObject>

- (void)onSuccess;

- (void)onFailed;

- (void)onLogout;

- (void)onCancel;

@end