//
//  RemoteResponse.h
//  Pods
//
//  Created by kongkong on 15/12/21.
//
//

#import <Foundation/Foundation.h>
#import "RemotePlayLoad.h"

@protocol RemoteResponse <NSObject>

@property(nonatomic, assign) NSInteger statusCode; ///< http状态码,成功200之类
@property(nonatomic, strong) NSDictionary<NSString *, NSString *> *headerFiled;    ///< http头
@property(nonatomic, strong) NSData *rawData;    ///< 原始数据
@property(nonatomic, strong) id <RemotePlayLoad> playLoad;   ///< 返回数据结构
@property(nonatomic, strong) NSError *error;  ///< 网络层报告的NSError

/**
 * 此方法过期不再使用
 * @return
 */
- (NSString *)statusMsg DEPRECATED_ATTRIBUTE;

/**
 *  @author kongkong
 *
 *  @brief 请求成功前提下，API调用是否成功
 *
 *  @return api调用状态
 */

- (BOOL)isApiSuccess;

/**
 *  @author kongkong
 *
 *  @brief 请求是否失效
 *
 *  @return 请求是否失效
 */
- (BOOL)isExpiredRequest;

/**
 *  @author kongkong
 *
 *  @brief 无网络状态
 *
 *  @return 是否无网络
 */
- (BOOL)isNoNetwork;

/**
 *  @author kongkong
 *
 *  @brief 网络异常判断
 *
 *  @return 网络是否异常
 */
- (BOOL)isNetworkError;

/**
 *  @author kongkong
 *
 *  @brief 判断SDK内部错误
 *
 *  @return 错误是否SDK内部
 */
- (BOOL)isSDKError;

/**
 * 判断是服务端返回的系统错误
 * @return
 */
- (BOOL)isSystemError;

/**
 *  @author kongkong
 *
 *  @brief 判断是否业务错误
 *
 *  @return 是否业务错误
 */
- (BOOL)isBusError DEPRECATED_ATTRIBUTE;

- (BOOL)isBizError ;

/**
 *  @author kongkong
 *
 *  @brief 判断数据是否缓存数据
 *
 *  @return 是否缓存数据
 */
- (BOOL)isCacheData;


/**
 * 缓存数据回来后,判断是否还需要请求网络,适用在offline的场景下
 */
- (BOOL)isRequireRemote;
@end
