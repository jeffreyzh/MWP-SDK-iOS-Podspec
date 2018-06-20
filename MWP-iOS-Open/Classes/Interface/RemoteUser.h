//
//  RemoteUser.h
//  Pods
//
//  Created by kongkong on 16/1/7.
//
//

#import <Foundation/Foundation.h>

@class RemoteUserInfo;


typedef void(^RefreshToken)(void);

@protocol RemoteUser <NSObject>

@property(readonly, copy) NSString *uid;
@property(readonly, copy) NSString *sessionID;

/**
 *  @author kongkong
 *
 *  @brief
 *
 *  @param uid
 *  @param sessionID
 */
- (void)setUserId:(NSString *)uid sessionID:(NSString *)sessionID;

/**
 *  @author kongkong
 *
 *  @brief
 */
@property(nonatomic, copy) RefreshToken refreshBlock;

/**
 * 这个方法有点难用废弃吧
 *  @author kongkong
 *
 *  @brief 用户信息回调包含操作信息
 *  @params info    status: @"success",@"failur,@"cancel",@"logout"   标识登陆是否成功
 *                  uid：用户id
 *                  sid：sid
 */
- (void)updateUserInfo:(NSDictionary *)info DEPRECATED_ATTRIBUTE;


- (void)refreshUserInfo:(RemoteUserInfo *)userInfo;

@end
