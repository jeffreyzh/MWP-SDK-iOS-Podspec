

#import <Foundation/Foundation.h>
#import "RemoteBuild.h"
#import "RemoteCallBuilder.h"
#import "RemoteDslCallBuilder.h"
#import "RemoteBizDomain.h"
#import "RemoteDslParam.h"
#import "RemoteSwitch.h"
#import "RemoteConstant.h"
#import "RemoteConfiguration.h"
#import "RemoteMCommand.h"
#import "RemoteMCommandEvent.h"
#import "RemoteResponse.h"
#import "RemoteCallBack.h"
#import "RemoteRequestState.h"
#import "RemoteUserInfo.h"

#define EasyRemote ([MWPRemote defaultRemote])

@interface MWPRemote : NSObject <RemoteBuild, EasyRemoteBuild>

+ (MWPRemote *)defaultRemote;

@end
