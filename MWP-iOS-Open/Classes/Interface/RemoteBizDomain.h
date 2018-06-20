//
// Created by gairui on 16/4/24.
//

#import <Foundation/Foundation.h>


@interface RemoteBizDomainBuilder : NSObject
@property(nonatomic, strong) NSMutableDictionary *header;
@property(nonatomic, strong) NSMutableDictionary *query;
@property(nonatomic, copy) NSString *host;

- (instancetype)setHeader:(NSString *)aHeader forKey:(NSString *)aKey;

- (instancetype)setQuery:(NSString *)aQuery forKey:(NSString *)aKey;

@end

@interface RemoteBizDomain : NSObject
@property(nonatomic, strong, readonly) NSMutableDictionary *header;
@property(nonatomic, strong, readonly) NSMutableDictionary *query;
@property(nonatomic, copy, readonly) NSString *host;

- (instancetype)init;

- (instancetype)initWithBuilder:(RemoteBizDomainBuilder *)builder;

+ (instancetype)makeWithBuilder:(void (^)(RemoteBizDomainBuilder *))updateBlock;

- (instancetype)update:(void (^)(RemoteBizDomainBuilder *))updateBlock;
@end





