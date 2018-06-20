//
// Created by gairui on 16/9/12.
//

#import <Foundation/Foundation.h>
#import "RemoteDslCallBuilder.h"


@interface RemoteDslParamBuilder : NSObject
@property(nonatomic, strong) NSMutableDictionary *body;

- (instancetype)setParameter:(id <NSObject>)parameter forApi:(NSString *)api AndVersion:(NSString *)version;

- (instancetype)setParameter:(id <NSObject>)parameter forKey:(NSString *)key;

@end

@interface RemoteDslParam : NSObject <DslParameter>
@property(nonatomic, strong, readonly) NSMutableDictionary *body;

- (instancetype)init;

- (instancetype)initWithBuilder:(RemoteDslParamBuilder *)builder;

+ (instancetype)makeWithBuilder:(void (^)(RemoteDslParamBuilder *))updateBlock;

- (instancetype)update:(void (^)(RemoteDslParamBuilder *))updateBlock;
@end



