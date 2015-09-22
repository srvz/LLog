
/* 0 TURN OFF; 1 TURN ON */

#define _LLog_SWITCH 1

#if _LLog_SWITCH

#define XCODE_COLORS_ESCAPE_MAC @"\033["
#define XCODE_COLORS_ESCAPE_IOS @"\033["
//#define XCODE_COLORS_ESCAPE_IOS @"\xC2\xA0["

#if TARGET_OS_IPHONE
#define XCODE_COLORS_ESCAPE         XCODE_COLORS_ESCAPE_IOS
#else
#define XCODE_COLORS_ESCAPE         XCODE_COLORS_ESCAPE_MAC
#endif

#define XCODE_COLORS_RESET          XCODE_COLORS_ESCAPE ";"

#define _LLog_INFO_FG               "fg255,255,255;"
#define _LLog_INFO_BG               "bg0,0,0;"
#define _LLog_INFO_COLOR_SCHEME     XCODE_COLORS_ESCAPE _LLog_INFO_FG XCODE_COLORS_ESCAPE _LLog_INFO_BG

#define _LLog_WARN_FG               "fg255,255,0;"
#define _LLog_WARN_BG               "bg0,0,0;"
#define _LLog_WARN_COLOR_SCHEME     XCODE_COLORS_ESCAPE _LLog_WARN_FG XCODE_COLORS_ESCAPE _LLog_WARN_BG

#define _LLog_ERROR_FG              "fg255,0,0;"
#define _LLog_ERROR_BG              "bg255,255,255;"
#define _LLog_ERROR_COLOR_SCHEME    XCODE_COLORS_ESCAPE _LLog_ERROR_FG XCODE_COLORS_ESCAPE _LLog_ERROR_BG


#define _LVarName(varName) (#varName)

//Replace NSLog
#define LLog(fmt, ...)  \
{ \
    NSString *_LLog_FILENAME = [[NSString stringWithCString:__FILE__ \
                                                   encoding:NSUTF8StringEncoding] \
                                                   lastPathComponent]; \
    NSLog((@ \
    "\n" \
    _LLog_INFO_COLOR_SCHEME \
    "\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n" \
    "FILE:%@\n" \
    "FUNC:%s\n" \
    "LINE:%d\n" \
    "INFO:" fmt \
    "\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" \
    XCODE_COLORS_RESET), \
    _LLog_FILENAME, \
    __PRETTY_FUNCTION__, \
    __LINE__, \
    ##__VA_ARGS__); \
} \


//Log Warning
#define LLogw(fmt, ...)  \
{ \
    NSString *_LLog_FILENAME = [[NSString stringWithCString:__FILE__ \
                                                   encoding:NSUTF8StringEncoding] \
                                                   lastPathComponent]; \
    NSLog((@ \
    "\n" \
    _LLog_WARN_COLOR_SCHEME \
    "\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n" \
    "FILE:%@\n" \
    "FUNC:%s\n" \
    "LINE:%d\n" \
    "WARNING:" fmt \
    "\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" \
    XCODE_COLORS_RESET), \
    _LLog_FILENAME, \
    __PRETTY_FUNCTION__, \
    __LINE__, \
    ##__VA_ARGS__); \
} \


//Log Error Or Exception
#define LLoge(fmt, ...)  \
{ \
    NSString *_LLog_FILENAME = [[NSString stringWithCString:__FILE__ \
                                                   encoding:NSUTF8StringEncoding] \
                                                   lastPathComponent]; \
    NSLog((@ \
    "\n" \
    _LLog_ERROR_COLOR_SCHEME \
    "\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n" \
    "FILE:%@\n" \
    "FUNC:%s\n" \
    "LINE:%d\n" \
    "ERROR:" fmt \
    "\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" \
    XCODE_COLORS_RESET), \
    _LLog_FILENAME, \
    __PRETTY_FUNCTION__, \
    __LINE__, \
    ##__VA_ARGS__); \
} \


#define LOLog(info)                          LLog(@"%s = %@", _LVarName(info), info)
#define LOLog2(info, var1, var2)             LLog(@"%@ \n[1] %s = %@ \n[2] %s = %@", info, _LVarName(var1), var1, _LVarName(var2), var2)
#define LOLog3(info, var1, var2, var3)       LLog(@"%@ \n[1] %s = %@ \n[2] %s = %@ \n[3] %s = %@", info, _LVarName(var1), var1, _LVarName(var2), var2, _LVarName(var3), var3)
#define LOLog4(info, var1, var2, var3, var4) LLog(@"%@ \n[1] %s = %@ \n[2] %s = %@ \n[3] %s = %@ \n[4] %s = %@", info, _LVarName(var1), var1, _LVarName(var2), var2, _LVarName(var3), var3, _LVarName(var4), var4)

#define LWLog(warning)                       LLogw(@"%@", warning)

#define LELog(error)                         LLoge(@"%@", error)

#define METHOD_LOG                           LLog(@"***Method Running***")

#else

#define LLog(...)
#define LLogw(...)
#define LLoge(...)
#define LOLog(...)
#define LOLog2(...)
#define LOLog3(...)
#define LOLog4(...)
#define LWLog(...)
#define LELog(...)

#define METHOD_LOG

#endif

