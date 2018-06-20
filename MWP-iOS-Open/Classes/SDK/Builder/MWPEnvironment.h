////
////  MWPEnvironment.h
////  Pods
////
////  Created by kongkong on 15/12/18.
////
////
//
//#import <Foundation/Foundation.h>
//
//@protocol RemoteContext;
//
//typedef enum : NSUInteger {
//    MWP_RELEASE = 1,    ///< 线上环境
//    MWP_PRE_RELEASE,     ///< 预发环境
//    MWP_DAILY,           ///< 发布环境
//} MWPENV;
//
//extern NSString *MWPEnvEnumName(MWPENV env);
//
//extern MWPENV MWPEnvEnumForName(NSString *envName);
//
//extern MWPENV MWPEnvEnumForIndex(NSUInteger envIndex);
//
///**
// *  @author kongkong
// *
// *  @brief 环境配置：线上，日常，发布等，在配置文件中直接读取
// */
//@interface MWPEnvironment : NSObject
///**
// *  @author kongkong
// *
// *  @brief 获取对应的环境值 格式 ip(or host):port
// *
// *  @param key 定义字符串值
// *
// *  @return 返回对应的环境值
// */
//
//+ (NSString *)getEnvForKeyStr:(NSString *)keyStr;
//
///**
// *  @author kongkong
// *
// *  @brief 获取对应的环境值 格式 ip(or host):port
// *
// *  @param key 定义的枚举值
// *
// *  @return 返回对应的环境值
// */
//+ (NSString *)getEnvForKey:(MWPENV)key;
//
///**
// *  @author kongkong
// *
// *  @brief 获取域名或ip
// *
// *  @param key 定义的枚举值
// *
// *  @return 返回对应的域名
// */
//+ (NSString *)hostForKey:(MWPENV)key;
//
///**
// *  @author kongkong
// *
// *  @brief 获取端口
// *
// *  @param key 定义的枚举值
// *
// *  @return 返回对应的端口
// */
//+ (NSInteger)portForKey:(MWPENV)key;
//
///**
// *  获取当前的 MWP 环境
// *
// *  @return
// */
//+ (MWPENV)currentEnvironmentForContext:(id <RemoteContext>)context;
//
////+ (MWPENV)EnvEnumForKey:(NSString *)key;
//
////+ (MWPENV)EnvEnumForIndex:(NSUInteger)index;
//@end
