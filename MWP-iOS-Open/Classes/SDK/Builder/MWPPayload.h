
#import <Foundation/Foundation.h>
#import "RemotePlayLoad.h"

@interface MWPPayload : NSObject <RemotePlayLoad>

@property(nonatomic, strong) NSString *api;    /// API名称
@property(nonatomic, strong) NSString *version;    /// api版本
@property(nonatomic, strong) NSString *ret;        /// status
@property(nonatomic, strong) NSString *msg;        /// 信息
@property(nonatomic, strong) id data;       /// 对应data

@end
