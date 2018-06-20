//
//  RemotePlayLoad.h
//  Pods
//
//  Created by kongkong on 15/12/21.
//
//

#import <Foundation/Foundation.h>

@protocol RemotePlayLoad <NSObject>

@property(nonatomic, strong) NSString *api;    /// API名称
@property(nonatomic, strong) NSString *version;    /// api版本
/**
 *  @brief 获取状态信息
 *
*  @return 对应状态信息
            SUCCESS = 0,    ///< 成功

            **系统错误
            FAIL_SYS_SIGN_ERROR, ///< 签名失败
            FAIL_SYS_REQUEST_EXPIRED,   ///< 请求失败

            **业务错误
            FAIL_BIZ_SESSION_INVALID,   ///< Session失效

            **SDK内部错误
            FAIL_SDK_NO_NETWORK,    ///< 无网络
            FAIL_SDK_NETWORK_ERROR, ///< 网络错误
            FAIL_SDK_JSON_PARSE_ERROR,  ///< 解析JSON数据错误
            FAIL_SDK_BUILD_REQUEST_ERROR,   ///< 构建请求参数失败
            FAIL_SDK_BUILD_NETWORK_ERROR,   ///< 构建网路请求实例失败
            FAIL_SDK_GENERATE_SIGN_ERROR,   ///< 生成请求签名失败
 */
@property(nonatomic, strong) NSString *ret;        /// status
@property(nonatomic, strong) NSString *msg;        /// 信息
@property(nonatomic, strong) id data;       /// 对应data

@end
