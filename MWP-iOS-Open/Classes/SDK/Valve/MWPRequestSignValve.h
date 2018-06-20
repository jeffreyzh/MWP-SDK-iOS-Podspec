
#import "MWPAbstractValve.h"

@interface MWPRequestSignValve : MWPAbstractValve

+ (NSString *)generateSignWith:(NSDictionary *)headers api:(NSString *)api version:(NSString *)version data:(NSString *)data appSecret:(NSString *)appSecret;
@end
