#pragma once
#include <stdint.h>

#ifdef DLLLIBRARY_EXPORTS  
#define LIBRARY_API extern "C" __declspec(dllexport)  
#elif  DLLLIBRARY_INPORTS
#define LIBRARY_API extern "C" __declspec(dllimport)
#else
#define LIBRARY_API extern	
#endif  
#define LIB_VERSION "lib_V1.3"
/*   版本记录
*  lib_V1.0：初始版本
*  lib_V1.1：修正程序启动时，不一定能读取到币数的问题
*  lib_v1.2: 修正某些usb转串口，缓冲很久的问题
*  lib_v1.3: 修正启动时不正确读取keys的问题
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
//counter id 
#define COUNTER_COIN            0
#define COUNTER_1               1
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
* counter_id：0-1，其中0，位投币对应的码表
* 返回16位的无符合整数值
*/
LIBRARY_API uint16_t get_counter(uint8_t counter_id);
/*
* 设定io板码表还没有跳动完的数字
* counter_id：0-1，其中0，位投币对应的码表
* counter_num: 0 - 0xffe,0xffff,表示不变动的意思
*/
LIBRARY_API void set_counter(uint8_t counter_id, uint16_t counter_num);
/*
* 获取io板还没有用掉的币数
* 返回16位的无符合整数值
*/
LIBRARY_API uint16_t get_coin();
/*
* 要用掉的币数，即想要扣除的币数
* 返回16位的无符合整数值的实际扣除币是。如现在还没有用掉的币数位1，要扣除2，那么就返回实际能扣除的1
*/
LIBRARY_API uint16_t decrease_coins(uint16_t coins); //返回实际扣币数。
/*
* 获取io板mcu的内部温度
* 返回8位的无符合整数值，值代表1摄氏度
*/
LIBRARY_API uint8_t get_mcu_temperature(void);
/*
* 获取io板mcu的供电电压
* 返回8位的无符合整数值，值代表0.1v
*/
LIBRARY_API uint8_t get_mcu_voltage(void);
/*
* 获取io板电池电压
* 返回8位的无符合整数值，值代表0.1v
*/
LIBRARY_API uint8_t get_battery_voltage(void);
/*
* 获取io板24个按键输入值
* key_id：0-23。文件开头有各个按键名称的宏定义，如INPUT_UP
* true：表示按键按下。false：表示松开
*/
LIBRARY_API bool get_key(uint8_t key_id);
/*
* 获取io板8个adc值
*  adc_id：0-7
* 返回一个0-255的adc值
*/
LIBRARY_API uint8_t get_adc(uint8_t adc_id);
/*
* 设置io板18个pwm（rgb）通道的闪动方式
* pwm_id：0-17，0代表R0，1：G0；2：B0，3：R1.如此类推
* type：0-1；0为呼吸灯模式，1为on/off模式
* interval：0-7 闪动的间隔时间。其中0为常亮。1，最快，7最慢
*  bright：0-15亮度值.0为不亮，15为最亮
*/
LIBRARY_API void set_pwm(uint8_t pwm_id, uint8_t type, uint8_t interval, uint8_t bright);
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

