

#import <Foundation/Foundation.h>
#import "MGJWTValve.h"
#import "RemoteContext.h"
#import "RemoteConstant.h"

/**
 *  @author kongkong
 *
 *  @brief MWP基础阀门，基本操作封装（预留基类，方便扩展）
 */
@interface MWPAbstractValve : NSObject <MGJWTValve>

- (id <RemoteContext>)contextWithPipeLine:(id <MGJWTPipelineContext>)pipelineContext;

@end
