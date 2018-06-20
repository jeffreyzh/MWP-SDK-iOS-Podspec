//


#import "MWPAbstractValve.h"

/**
 *  @author kongkong
 *
 *  @brief 重试阀门，现阶段给Https请求重试使用，但是否使用https由外部context指定，此阀门只做清除信息和重试
 */
@interface MWPResponseRetryValve : MWPAbstractValve

@end
