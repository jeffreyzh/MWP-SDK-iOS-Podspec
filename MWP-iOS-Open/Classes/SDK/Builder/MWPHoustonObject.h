//
// Created by gairui on 2017/2/6.
// Copyright (c) 2017 kongkong. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HoustonForwardingObject<__covariant T> : NSObject

/**
 *  key
 */
@property(nonatomic, copy, readonly) NSString *key;


/**
 *  group
 */
@property(nonatomic, copy, readonly) NSString *group;


/**
 *  当前值，在 HoustonObject 的生命周期内，该值永远是最新的
 */
@property(nonatomic, strong, readonly) T value;

/**
 *  创建 HoustonObject 对象
 *
 *  @param key          对应的 Key
 *  @param group        对应的 Group
 *  @param class        value 的类型，内部会使用 MGJEntity 来转换
 *  @param defaultValue 默认值，类型必须与传入的 class 一致
 *  @param block        回调
 *
 *  @return HoustonObject 对象
 */
- (instancetype)initWithKey:(NSString *__nonnull)key inGroup:(NSString *__nonnull)group withValueClass:(Class __nonnull)class defaultValue:(T __nullable)defaultValue observer:(void (^)(NSString *groupName, NSString *key, T oldValue, T newValue))block;
@end


@interface MWPHoustonObject <__covariant T> : NSObject

/**
 *  key
 */
@property(nonatomic, copy, readonly) NSString *key;


/**
 *  group
 */
@property(nonatomic, copy, readonly) NSString *group;


/**
 *  当前值，在 HoustonObject 的生命周期内，该值永远是最新的
 */
@property(nonatomic, strong, readonly) T value;

/**
 * 先判断本地持久化的配置，再获取线上配置
 */
@property(nonatomic, strong) T valueWithLocalValue;

/**
 * 清除本地配置
 */
- (void)clearLocalValue;

/**
 * 本地配置是否设置
 */
- (BOOL)localValueEnable;

- (NSString *)description;

- (instancetype)initWithKey:(NSString *__nonnull)key inGroup:(NSString *__nonnull)group withValueClass:(Class __nonnull)class defaultValue:(T __nullable)defaultValue observer:(void (^)(NSString *groupName, NSString *key, T oldValue, T newValue))block;
@end
