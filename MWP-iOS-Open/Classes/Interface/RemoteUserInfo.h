//
// Created by Zephyrleaves on 16/3/18.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MWPLoginStatus) {
    MWP_LOGIN_SUCCESS = 1,
    MWP_LOGIN_FAILED,
    MWP_LOGIN_CANCEL,
    MWP_LOGOUT
};

@interface RemoteUserInfo : NSObject
@property(nonatomic, copy) NSString *uid;
@property(nonatomic, copy) NSString *sessionID;
@property(nonatomic, assign) MWPLoginStatus loginStatus;
@end