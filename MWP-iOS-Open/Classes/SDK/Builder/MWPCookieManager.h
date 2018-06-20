//
// Created by gairui on 2017/4/10.
// Copyright (c) 2017 kongkong. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSHTTPCookiePropertyKey const MWPCookieShared;

@interface MWPCookie : NSHTTPCookie
/**
 * 共享给谁
 */
@property(nullable, readonly, copy) NSArray<NSString *> *shared;

@property(nonnull, readonly, copy) NSString *pathService;

+ (NSArray<MWPCookie *> *)mwpCookiesWithResponseHeaderFields:(NSDictionary<NSString *, NSString *> *)headerFields forURL:(NSURL *)URL api:(NSString *)api v:(NSString *)v;

- (BOOL)matches:(NSURL *)URL;

- (BOOL)isExpired:(NSDate *)date;
@end


@protocol MWPCookieJar <NSObject>
- (void)saveFromResponse:(NSURL *)URL cookies:(NSArray<MWPCookie *> *)cookies;

- (NSArray<MWPCookie *> *)loadForRequest:(NSURL *)URL;
@end

@interface MWPPersistentCookieStore :NSObject <MWPCookieJar>
- (NSString *)description;

@end

@interface MWPCookieManager : NSObject

+ (NSString *)cookieRequestHeaderNameWithApi:(NSString *)api v:(NSString *)v;

+ (NSString *)cookieResponseHeaderNameWithApi:(NSString *)api v:(NSString *)v;

+ (NSString *)cookieRequestHeaderValue:(NSArray<MWPCookie *> *)cookies;

@end

@interface MWPSerializableCookie : NSObject <NSCoding>

@property(readonly, strong) MWPCookie *cookie;

- (instancetype)initWithCookie:(MWPCookie *)cookie;

@end


