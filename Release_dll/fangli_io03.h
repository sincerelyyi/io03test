#pragma once
#include <stdint.h>

#ifdef DLLLIBRARY_EXPORTS  
#define LIBRARY_API extern "C" __declspec(dllexport)  
#elif  DLLLIBRARY_INPORTS
#define LIBRARY_API extern "C" __declspec(dllimport)
#else
#define LIBRARY_API extern	
#endif  
#define LIB_VERSION "lib_V1.6"
/*   版本记录
*  lib_V1.0：初始版本
*  lib_V1.1：修正程序启动时，不一定能读取到币数的问题
*  lib_v1.2: 修正某些usb转串口，缓冲很久的问题
*  lib_v1.3: 修正启动时不正确读取keys的问题
*  lib_v1.4:
*		1，码表值，投币值更改位32位
		2，Pwm控制拆分为3个函数
		3,实现断开检测和断开重连功能
*lib_v1.5:
	1，增加一个投币器
	2，set_counter()改为add_counter()
	3，增加clean_counter()
	4,所有adc值用uint16_t数据存储
lib_v1.6
	1,加快读取串口的速度
*/

// base input key_id
#define INPUT_UP                0
#define INPUT_DOWN              1
#define INPUT_LEFT              2
#define INPUT_RIGHT             3
#define INPUT_START             4
#define INPUT_STOP              5
#define INPUT_VIEW              6
#define INPUT_SERVICE           7

#define INPUT_TEST              8
#define INPUT_SAFE              9
#define INPUT_COIN              10
#define INPUT_GEAR0             11
#define INPUT_GEAR1             12
#define INPUT_GEAR2             13
#define INPUT_GEAR3             14
#define INPUT_RESERVE0          15

#define INPUT_RESERVE1          16
#define INPUT_RESERVE2          17
#define INPUT_RESERVE3          18
#define INPUT_RESERVE4          19
#define INPUT_RESERVE5          20
#define INPUT_RESERVE6          21
#define INPUT_RESERVE7          22
#define INPUT_RESERVE8          23

//base out pin pin_id
#define OUTPUT_KEYLED0          0
#define OUTPUT_KEYLED1          1
#define OUTPUT_KEYLED2          2
#define OUTPUT_KEYLED3          3
#define OUTPUT_KEYLED4          4
#define OUTPUT_KEYLED5          5
#define OUTPUT_KEYLED6          6
#define OUTPUT_KEYLED7          7

#define OUTPUT_KEYLED8          8
#define OUTPUT_KEYLED9          9
#define OUTPUT_KEYLED10         10
#define OUTPUT_KEYLED11         11
#define OUTPUT_KEYLED12         12
#define OUTPUT_KEYLED13         13
#define OUTPUT_COUNTER0         14
#define OUTPUT_COUNTER1         15

#define OUTPUT3                 16
#define OUTPUT2                 17
#define OUTPUT1                 18
#define OUTPUT0                 19
#define OUTPUT7                 20
#define OUTPUT6                 21
#define OUTPUT5                 22
#define OUTPUT4                 23
//coin id 
#define COIN1					0
#define COIN2					1
//counter id 
#define COUNTER_COIN1           0
#define COUNTER_COIN2           1
//pwm_id
#define R0                      0
#define G0                      1
#define B0                      2
#define R1                      3
#define G1                      4
#define B1                      5
#define R2                      6
#define G2                      7
#define B2                      8
#define R3                      9
#define G3                      10
#define B3                      11
#define R4                      12
#define G4                      13
#define B4                      14
#define R5                      15
#define G5                      16
#define B5                      17

//error的mask
#define NO_FM               0x0001      ///< 没有检测到铁电存储器 
#define NO_LKT              0x0100      ///< 没有检测到加密芯片 
#define LKT_ILLEGAL         0x0200      ///< 加密芯片没有授权
#define CODE_NOSIGN         0x0400      ///< 固件没有签名或错误签名 
#define UID_NOSIGN          0x0800      ///< UID没有签名或错误签名 
#define NO_RDP              0x1000      ///< mcu不在读保护状态下 

/*
* 连接io板
* 返回 已经成功连接返回com号，失败返回-1,正在连接中返回0；
*/
LIBRARY_API int connect_state(void);

/*
* 连接io板
* 返回 已经成功连接返回com号，失败返回-1，正在连接中返回0；
*/
LIBRARY_API int reconnect(void);


/*
* 获取io板的硬件版本号
* 返回 io板的硬件版本号的字符串
*/
LIBRARY_API uint16_t get_error(void);


/*
* 获取io板的硬件版本号
* 返回 io板的硬件版本号的字符串
*/
LIBRARY_API char* get_hardware(void);

/*
* 获取io板的软件版本号
* 返回 io板的软件版本号的字符串
*/
LIBRARY_API char* get_software(void);


/*
* 获取io板的api库版本号
* 返回 io板的api库的字符串
*/
LIBRARY_API char* get_lib(void);


/*
* 获取io板的生产日期
* 返回日期的字符串
*/
LIBRARY_API char* get_production_date(void);


/*
* 获取io板uid
* 返回uid的字符串
*/
LIBRARY_API char* get_uid(void);


/*
* 获取io板码表还没有跳动完的数字
* counter_id：0-1，其中0，是投币对应的码表
* 返回32位的无符合整数值
*/
LIBRARY_API uint32_t get_counter(uint8_t counter_id);


/*
* 设定io板码表还没有跳动完的数字
* counter_id：0-1，其中0，是投币对应的码表
* counter_num: 0 - 0xfffffff
*/
LIBRARY_API void add_counter(uint8_t counter_id, uint32_t counter_num);

/*
* 清除io板码表还没有跳动完的数字
* counter_id：0-1，其中0，是投币对应的码表
*/
LIBRARY_API void clean_counter(uint8_t counter_id);


/*
* 获取io板还没有用掉的币数
* uint8_t coin_id:0-1
* coin_id：
#define COIN1            0
#define COIN2            1
* 返回32位的无符合整数值
*/
LIBRARY_API uint32_t get_coin(uint8_t coin_id);


/*
* 要用掉的币数，即想要扣除的币数
* uint8_t coin_id:0-1
* coin_id：
#define COIN1            0
#define COIN2            1
* uint32_t coins: 要扣除的币数 0-0xffffffff
* 返回32位的无符合整数值的实际扣除币数。如，现在还没有用掉的币数是1，要扣除2，那么就返回实际能扣除的1
*/
LIBRARY_API uint32_t decrease_coin(uint8_t coin_id,uint32_t coins); //返回实际扣币数。

/*
* 清除IO储存的投币数
* uint8_t coin_id:0-1
* coin_id：
#define COIN1            0
#define COIN2            1
* 返回32位的无符合整数值的实际清除了的币数字
*/
LIBRARY_API uint32_t clear_coin(uint8_t coin_id); //返回实际清除币数。


/*
* 获取io板mcu的内部温度
* 返回16位的无符合整数值，值代表1摄氏度
*/
LIBRARY_API uint16_t get_mcu_temperature(void);


/*
* 获取io板mcu的供电电压
* 返回16位的无符合整数值，值代表1mv
*/
LIBRARY_API uint16_t get_mcu_voltage(void);


/*
* 获取io板电池电压
* 返回16位的无符合整数值，值代表1mv
*/
LIBRARY_API uint16_t get_battery_voltage(void);


/*
* 获取io板24个按键输入值
* key_id：0-23。文件开头有各个按键名称的宏定义，如INPUT_UP
* true：表示按键按下。false：表示松开
*/
LIBRARY_API bool get_key(uint8_t key_id);


/*
* 获取io板8个adc值
*  adc_id：0-7
* 返回一个0-0xffff的adc值
*/
LIBRARY_API uint16_t get_adc(uint8_t adc_id);


/*
* 设置io板18个pwm（rgb）通道的常亮模式
* pwm_id：0-17，0代表R0，1：G0；2：B0，3：R1.如此类推，见pwm_id的宏定义
*  bright：0-255亮度值.0为不亮，255为最亮
*/
LIBRARY_API void set_pwm_normal(uint8_t pwm_id,uint8_t bright);


/*
* 设置io板18个pwm（rgb）通道的闪动模式
* pwm_id：0-17，0代表R0，1：G0；2：B0，3：R1.如此类推，见pwm_id的宏定义
* interval：0-100 闪动的间隔时间。其中0为不闪动。1，最快，100最慢，此值代表 * 0.1S
*  bright：0-255亮度值.0为不亮，255为最亮
*/
LIBRARY_API void set_pwm_blink(uint8_t pwm_id, uint8_t interval, uint8_t bright);


/*
* 设置io板18个pwm（rgb）通道的呼吸灯模式
* pwm_id：0-17，0代表R0，1：G0；2：B0，3：R1.如此类推，见pwm_id的宏定义
* interval：0-100 闪动的间隔时间。其中0为不呼吸。1，最快，100最慢，此值代表 * 0.1S
*  bright：0-255亮度值.0为不亮，255为最亮
*/
LIBRARY_API void set_pwm_breathe(uint8_t pwm_id, uint8_t interval, uint8_t bright);


/*
* 设置io板24个基本io输出电平
* out_id：0-23。文件开头有各个按键名称的宏定义，如OUTPUT_KEYLED0
* level：引脚电平 false：输出电平为高，对应的灯不亮。false：输出电平为低，对应的灯亮
*/
LIBRARY_API void set_outPin(uint8_t out_id, bool level);
/*
* 停止监控io板串口的线程，使用动态库时，应用结束前使用此函数。不如线程可能不能退出
*/
LIBRARY_API bool stop_monitoring();

