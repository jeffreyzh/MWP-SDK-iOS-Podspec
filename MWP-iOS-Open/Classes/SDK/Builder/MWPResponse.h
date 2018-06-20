//
//  MWPResponse.h
//  Pods
//
//  Created by kongkong on 15/12/31.
//
//

#import <Foundation/Foundation.h>
#import "RemoteResponse.h"

@class CacheInfo;

@interface MWPResponse : NSObject <RemoteResponse>

@property(nonatomic, assign) NSInteger statusCode; ///< http状态码,成功200之类
@property(nonatomic, strong) NSDictionary<NSString *, NSString *> *headerFiled;    ///< http头
@property(nonatomic, strong) NSData *rawData;    ///< 原始数据
@property(nonatomic, strong) id <RemotePlayLoad> playLoad;   ///< 返回数据结构
@property(nonatomic, strong) NSError *error;  ///< 网络层报告的NSError
@property(nonatomic, strong) CacheInfo *cacheInfo;///< 缓存信息

- (NSString *)description;

@end
