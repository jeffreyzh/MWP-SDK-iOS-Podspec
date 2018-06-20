//
//  MWPConstant.h
//  Pods
//
//  Created by kongkong on 15/12/29.
//
//

#ifndef MWPConstant_h
#define MWPConstant_h

#define PREFIX @"mw-"

#define KEY_API @"mw-api"
#define KEY_VERSION @"mw-v"

/**
 * 设备信息
 */
#define KEY_UA @"User-Agent"
/**
 * 渠道信息 ，例：`NWxiaomi@mogujie_android_7.5.2_build``
 */
#define KEY_TTID @"mw-ttid"
/**
 * 当前设备GMT时间 long型
 */
#define KEY_TIME @"mw-t"
/**
 * 当前client时间和服务端时间的偏移量
 */
#define KEY_TIME_OFFSET @"t_offset"
/**
 * 业务请求参数
 */
#define KEY_DATA @"data"
/**
 * 设备id
 */
#define KEY_DEVICEID @"mw-did"


/**
 * 表明App的id号
 */
#define KEY_APPKEY @"mw-appkey"

/**
 * 表明App的SECRET.  只用在签名,不需要加到head协议中
 */
#define KEY_SECRET @"mw-secret"
/**
 * 请求签名
 */
#define KEY_SIGN @"mw-sign"
/**
 * 用户的session id
 */
#define KEY_SID @"mw-sid"
/**
 * 协议版本号,用于后面拓展协议用
 */
#define KEY_PV @"mw-pv"
/**
 * network type 网络类型
 * 如GPRS、EDGE、CDMA、EVDO、LTE等
 */
#define KEY_NET_TYPE @"mw-net"
/**
 * network quality 网络质量
 * 如2G、3G、4G、WIFI
 */
#define KEY_NET_QUALITY @"mw-nq"
/**
 * 当前语言 zh_CN
 */
#define KEY_LANGUAGE @"mw-lang"

/**
 * 第一次安装的渠道名
 */
#define KEY_FIRST_SOURCE @"mw-fs"

/**
 * 手机型号@操作系统型号@屏幕宽度，minfo@_sdklevel@_swidth，例：iphone7@9.2@1242
 */
#define KEY_DEVICE_INFO @"mw-dinfo"


/**
 * 用户id，登录成功的时候才有
 */
#define KEY_UID @"mw-uid"

/**
 * debug某台机器
 */
#define KEY_DEBUG_IP @"mw-debug"

//============返回数据字段==============
/**
 * 服务端时间戳（毫秒）
 */
#define KEY_SERVER_TIME     @"mw-st"

/**
 * MWP 返回码
 */
#define KEY_MWP_RET         @"mw-ret"

/**
 * c-command
 */
#define KEY_CMD_V   @"mw-cmd-v"

#define KEY_OPEN   @"mw-open"
/**
 * 业务方错误码定义
 */

//======错误号对应=【mwp_info.plist中对应】========
#define MWP_SUCCESS @"SUCCESS" ///< 成功
#define FAIL_SYS_SIGN_ERROR @"FAIL_SYS_SIGN_ERROR" ///< 签名失败
#define FAIL_SYS_REQUEST_EXPIRED @"FAIL_SYS_REQUEST_EXPIRED" ///< 请求过期
#define FAIL_BIZ_SESSION_INVALID @"FAIL_BIZ_SESSION_INVALID"///< Session失效
#define FAIL_SDK_NO_NETWORK @"FAIL_SDK_NO_NETWORK"///< 无网络
#define FAIL_SDK_NETWORK_ERROR @"FAIL_SDK_NETWORK_ERROR"///< 网络错误
#define FAIL_SDK_JSON_PARSE_ERROR @"FAIL_SDK_JSON_PARSE_ERROR"///< 解析JSON错误
#define FAIL_SDK_TIMEOUT_ERROR @"FAIL_SDK_TIMEOUT_ERROR"    ///< 超时
#define FAIL_SDK_BUILD_REQUEST_ERROR @"FAIL_SDK_BUILD_REQUEST_ERROR"///< 构建请求参数失败
#define FAIL_SDK_GENERATE_SIGN_ERROR @"FAIL_SDK_GENERATE_SIGN_ERROR" ///< 生成请求签名失败
#define FAIL_SYS_NEED_HTTPS @"FAIL_SYS_NEED_HTTPS"///< 重新请求，并走Https
#define FAIL_SDK_REQUEST_CANCEL_ERROR @"FAIL_SDK_REQUEST_CANCEL_ERROR"///请求取消
/**
 * 异步请求数据解析失败
 */
#define FAIL_SDK_POOLING_PARSE_ERROR @"FAIL_SDK_POOLING_PARSE_ERROR"
/**
 * 异步请求超时
 */
#define FAIL_SDK_POOLING_TIMEOUT_ERROR @"FAIL_SDK_POOLING_TIMEOUT_ERROR"

/**
 * 快速故障转移
 */
#define FAIL_SYS_FAST_FAIL_OVER @"FAIL_SYS_FAST_FAIL_OVER"

#define FAIL_RETRY_PREFIX @"FAIL_RETRY_" ///< 重试超出次数(3)仍失败
#define FAIL_SDK_PREFIX @"FAIL_SDK_"    ///< sdk前缀
#define FAIL_BIZ_PREFIX @"FAIL_BIZ_"    ///< biz前缀
#define FAIL_SYS_PREFIX @"FAIL_SYS_"    ///< sys前缀
//==================================

//======缓存相关的字段======
#define CACHE_CONTROL @"Cache-Control"
#define LAST_MODIFIED @"Last-Modified"
#define NO_CACHE @"no-cache"
#define MAX_AGE_FLAG  @"max-age="
#define OFFLINE_FLAG_ON  @"of=on"
#define ISCACHED @"isCached"
#define TRUE_STRING @"true"
#define FALSE_STRING @"false"
//========================

#define MWPErrorDomain @"MWPErrorDomain"  //网络异常
#define MWPBizErrorDomain @"MWPBizErrorDomain" //网络正常,但业务错误


#endif /* MWPConstant_h */
