#pragma once
#include <stdint.h>

#ifdef DLLLIBRARY_EXPORTS  
#define LIBRARY_API extern "C" __declspec(dllexport)  
#elif  DLLLIBRARY_INPORTS
#define LIBRARY_API extern "C" __declspec(dllimport)
#else
#define LIBRARY_API extern	
#endif  
#define LIB_VERSION "lib_V2.0"
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
lib_v1.7
	1,增加方向盘功能
lib_v1.8
	1,明确支持windows7，windows10，Windows11.
	2,串口更改为同步模式
	3，利用注册表枚举串口
	4,优化发送和接受，使得整个软件快捷和轻量化
lib_v1.9
	1,支持CAN转发功能
lib_v2.0
	1，增加串口转发到uart5的功能。
	2，增加扩展灯板的控制功能
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
* 获取IO板和电脑的连接状态
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
* 停止监控io板串口的线程，使用动态库时，应用结束前使用此函数。否则线程可能不能退出
*/
LIBRARY_API bool stop_monitoring();



//方向盘动作定义
#define     STEERING_ERROR      -1  ///< 方向盘错误(Steering wheel error)
#define     STEERING_AUTO_TEST  0   ///< 方向盘正运行自动测试指令(The steering wheel is currently executing an automatic test command)
#define     STEERING_STOP       1   ///< 方向盘正运行停止指令(The steering wheel is currently executing a stop command)
#define     STEERING_LEFT       2   ///< 方向盘正运行左转指令(The steering wheel is currently executing a left turn command.)
#define     STEERING_RIGHT      3   ///< 方向盘正运行右转指令(The steering wheel is currently executing a right turn command.)
#define     STEERING_POSITION   4   ///< 方向盘正运行指定位置指令(The steering wheel is currently executing a command to move to a specified position)
#define     STEERING_SHAKE      5   ///<方向盘正运行振动指令(The steering wheel is currently executing a vibration command)

/*
* 关闭方向盘马达驱动
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
*/
LIBRARY_API void steering_stop(uint8_t steernum);

/*
* 方向盘自动测定最左边界和最右边界
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
*/
LIBRARY_API void steering_auto_test(uint8_t steernum);

/*
* 方向盘一直向左转
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
* uint8_t strength：方向盘的力度，主要体现在用手抓住方向盘，阻止它运动时所感受到的力度。取值范围为0到100.大于100的值都会当作是100.
* uint8_t speed：方向盘移动的速度。主要体现为方向盘没有阻碍时移动的速度。取值范围为0到100。大于100的值都会当作100。
*/
LIBRARY_API void steering_left(uint8_t steernum,uint8_t strength, uint8_t speed);

/*
* 方向盘一直向右转
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
* uint8_t strength：方向盘的力度，主要体现在用手抓住方向盘，阻止它运动时所感受到的力度。取值范围为0到100.大于100的值都会当作是100.
* uint8_t speed：方向盘移动的速度。主要体现为方向盘没有阻碍时移动的速度。取值范围为0到100。大于100的值都会当作100。
*/
LIBRARY_API void steering_right(uint8_t steernum,uint8_t strength, uint8_t speed);

/*
* 方向盘转动到指定位置
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
* uint8_t strength：方向盘的力度，主要体现在用手抓住方向盘，阻止它运动时所感受到的力度。取值范围为0到100.大于100的值都会当作是100.
* uint8_t speed：方向盘移动的速度。主要体现为方向盘没有阻碍时移动的速度。取值范围为0到100。大于100的值都会当作100。
* int8_t pos: 相对位置值,-100表示最左边,+100表示最右边。小于-100的都会当作-100，大于+100都会当作+100。0表示居中位置。
*/
LIBRARY_API void steering_position(uint8_t steernum,uint8_t strength,uint8_t speed,int8_t pos);

/*
* 方向盘以指定位置为中心左右摆动
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
* uint8_t strength：方向盘的力度，主要体现在用手抓住方向盘，阻止它运动时所感受到的力度。取值范围为0到100.大于100的值都会当作是100.
* uint8_t speed：方向盘移动的速度。主要体现为方向盘没有阻碍时移动的速度。取值范围为0到100。大于100的值都会当作100。
* int8_t pos: 相对位置值,-100表示最左边,+100表示最右边。小于-100的都会当作-100，大于+100都会当作+100。0表示居中位置。
* uint8_t amp：方向盘左右摆动的最大幅度，0-100。
*/
LIBRARY_API void steering_shake(uint8_t steernum,uint8_t strength,uint8_t speed,int8_t pos,uint8_t amp);

/*
* 获取方向盘的运行状态包括是否错误和运行何种指令
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
* 输出：如下定义
#define     STEERING_ERROR      -1  ///< 方向盘错误(Steering wheel error)
#define     STEERING_AUTO_TEST  0   ///< 方向盘正运行自动测试指令(The steering wheel is currently executing an automatic test command)
#define     STEERING_STOP       1   ///< 方向盘正运行停止指令(The steering wheel is currently executing a stop command)
#define     STEERING_LEFT       2   ///< 方向盘正运行左转指令(The steering wheel is currently executing a left turn command.)
#define     STEERING_RIGHT      3   ///< 方向盘正运行右转指令(The steering wheel is currently executing a right turn command.)
#define     STEERING_POSITION   4   ///< 方向盘正运行指定位置指令(The steering wheel is currently executing a command to move to a specified position)
#define     STEERING_SHAKE      5   ///<方向盘正运行振动指令(The steering wheel is currently executing a vibration command)
*/
LIBRARY_API int8_t get_steering_state(uint8_t steernum);

/*
* 获取方向盘最左边边界的ADC原始值
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
* 输出：返回左边界的ADC值0~4095
*/
LIBRARY_API uint16_t get_steering_left_limit(uint8_t steernum);

/*
* 获取方向盘右边界的ADC原始值
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
* 输出：返回右边界的ADC值0~4095
*/
LIBRARY_API uint16_t get_steering_right_limit(uint8_t steernum);

/*
* 监测方向盘的实时位置
* uint8_t sternum：方向盘ID
* 0：方向盘1
* 1：方向盘2
* 输出：返回方向盘的相对位置。-100~-1为左边位置，0为中间位置，1～100为右边位置。
*/
LIBRARY_API int8_t get_steering_position(uint8_t steernum);




//CAN 初始化值结构体
typedef struct _can_init
{
	uint32_t baud;//波特率
	uint8_t bs1;// BS1
	uint8_t bs2;//BS2
	uint8_t sjw;//SJW
}CAN_initType;

//CAN 数据结构体
typedef struct _can_data
{
	uint32_t id;//ID
	uint8_t len;// 数据长度
	uint8_t data[8];//数据
}CAN_dataType;

//uart parity 定义
#define		NONE		0
#define		EVEN		1
#define		ODD			2

/*
* 设置CAN的时间片段的初始化值
* baud： 波特率,初始值为500K，波特率=42MHz/((1+BS1+BS2)*n),n是正整数，
			如果要设置的波特率的值不在公式中，设置值和实际值将会有偏差。
			波特率必须小于1M（1000000）
*		
* BS1： 位段1的值，初始值为8 
* BS2： 位段2的值，初始值为3
* SJW： 再同步跳转宽度的值，初始值为1，SJW<= BS1,SJW<= BS2
* 如果有参数不满足上面要求，该函数不执行，并返回0
* 输出：成功执行，返回实际波特率。失败返回0
*/
LIBRARY_API uint32_t set_can_init(uint32_t baud,uint8_t BS1,uint8_t BS2,uint8_t SJW);

/*
* 获取CAN的时间片段的初始化值
*init： 输出初始化值的CAN_initType 指针
*/
LIBRARY_API void get_can_init(CAN_initType* init);

/*
* 发送数据到CAN总线
* id： 消息id，这里使用标准ID（CAN 2.0A）（11位），
* len： 要发送的数据长度，取值范围0-8
* data： 要发送的数据的指针
*/
LIBRARY_API void can_send(uint32_t id, uint8_t len, uint8_t* data);

/*
* 获取CAN数据，CAN数据存储在CAN_dataType类型的FIFO中，每次调用此函数读取一个FIFO数据。
*data： 输出数据的CAN_dataType 指针
* 输出：成功读取到数据，返回1；FIFO空，没有读取到数据返回0
*/
LIBRARY_API int can_receive(CAN_dataType* data);



//转发串口通信参数结构体
typedef struct _uartForward_init
{
	uint32_t baud;	//波特率
	uint8_t bits;	//字位宽
	uint8_t parity;	//奇偶校验位
	uint8_t stop;	//停止位
}uartForward_initType;

/*
* 设置转发串口uart5的通信参数
* baud：		波特率,初始值为115200
* bits：		字位宽度，只能8，9
* parity：		奇偶校验，0:NONE；1:EVEN; 2:ODD
* stop：		停止位，只能1，2
*				如果有参数不满足上面要求，该函数不执行，并返回0
* 输出：		成功执行，返回1,失败返回0。
*/
LIBRARY_API int set_uartForward_init(uint32_t baud, uint8_t bits, uint8_t parity, uint8_t stop);

/*
* 获取转发串口uart5的通信参数
*init： 输出转发串口通信参数结构体uartForward_initType指针
*/
LIBRARY_API void get_uartForward_init(uartForward_initType* init);

/*
* 发送数据到串口转发口uart5
* len：			要发送的数据长度
* data：		要发送的数据的指针
* 输出：		成功执行，返回1,失败返回0
*/
LIBRARY_API int uartForward_send(uint16_t len, uint8_t* data);

/*
* 获取转发串口数据，接收到的串口转发数据存储在FIFO中，该指令是将FIFO数据读出。
* len：			要读取的数据长度
* data：		要存储读取到数据的指针
* 输出：		返回成功读取到数据字节数
*/
LIBRARY_API int uartForward_receive(uint16_t len, uint8_t* data);



//外扩灯板extLight的定义

typedef enum _extLight_port{
	Port1,
	Port2,
	Port3,
	Port4,
	Port5,
	Port6,
	Port7,
	Port_MAX				//!< MaxProt
}extLight_portEnum;


//灯珠类型选择：
// RGB:             W        R        G       B
#define NEO_RGB  (uint8_t)((0<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B
#define NEO_RBG  (uint8_t)((0<<6) | (0<<4) | (2<<2) | (1)) ///< Transmit as R,B,G
#define NEO_GRB  (uint8_t)((1<<6) | (1<<4) | (0<<2) | (2)) ///< Transmit as G,R,B
#define NEO_GBR  (uint8_t)((2<<6) | (2<<4) | (0<<2) | (1)) ///< Transmit as G,B,R
#define NEO_BRG  (uint8_t)((1<<6) | (1<<4) | (2<<2) | (0)) ///< Transmit as B,R,G
#define NEO_BGR  (uint8_t)((2<<6) | (2<<4) | (1<<2) | (0)) ///< Transmit as B,G,R

// RGBW NeoPixel permutations; all 4 offsets are distinct
// RGBW :           W         R       G       B
#define NEO_WRGB (uint8_t)((0<<6) | (1<<4) | (2<<2) | (3)) ///< Transmit as W,R,G,B
#define NEO_WRBG (uint8_t)((0<<6) | (1<<4) | (3<<2) | (2)) ///< Transmit as W,R,B,G
#define NEO_WGRB (uint8_t)((0<<6) | (2<<4) | (1<<2) | (3)) ///< Transmit as W,G,R,B
#define NEO_WGBR (uint8_t)((0<<6) | (3<<4) | (1<<2) | (2)) ///< Transmit as W,G,B,R
#define NEO_WBRG (uint8_t)((0<<6) | (2<<4) | (3<<2) | (1)) ///< Transmit as W,B,R,G
#define NEO_WBGR (uint8_t)((0<<6) | (3<<4) | (2<<2) | (1)) ///< Transmit as W,B,G,R

#define NEO_RWGB (uint8_t)((1<<6) | (0<<4) | (2<<2) | (3)) ///< Transmit as R,W,G,B
#define NEO_RWBG (uint8_t)((1<<6) | (0<<4) | (3<<2) | (2)) ///< Transmit as R,W,B,G
#define NEO_RGWB (uint8_t)((2<<6) | (0<<4) | (1<<2) | (3)) ///< Transmit as R,G,W,B
#define NEO_RGBW (uint8_t)((3<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B,W
#define NEO_RBWG (uint8_t)((2<<6) | (0<<4) | (3<<2) | (1)) ///< Transmit as R,B,W,G
#define NEO_RBGW (uint8_t)((3<<6) | (0<<4) | (2<<2) | (1)) ///< Transmit as R,B,G,W
#define NEO_GWRB (uint8_t)((1<<6) | (2<<4) | (0<<2) | (3)) ///< Transmit as G,W,R,B
#define NEO_GWBR (uint8_t)((1<<6) | (3<<4) | (0<<2) | (2)) ///< Transmit as G,W,B,R
#define NEO_GRWB (uint8_t)((2<<6) | (1<<4) | (0<<2) | (3)) ///< Transmit as G,R,W,B
#define NEO_GRBW (uint8_t)((3<<6) | (1<<4) | (0<<2) | (2)) ///< Transmit as G,R,B,W
#define NEO_GBWR (uint8_t)((2<<6) | (3<<4) | (0<<2) | (1)) ///< Transmit as G,B,W,R
#define NEO_GBRW (uint8_t)((3<<6) | (2<<4) | (0<<2) | (1)) ///< Transmit as G,B,R,W
#define NEO_BWRG (uint8_t)((1<<6) | (2<<4) | (3<<2) | (0)) ///< Transmit as B,W,R,G
#define NEO_BWGR (uint8_t)((1<<6) | (3<<4) | (2<<2) | (0)) ///< Transmit as B,W,G,R
#define NEO_BRWG (uint8_t)((2<<6) | (1<<4) | (3<<2) | (0)) ///< Transmit as B,R,W,G
#define NEO_BRGW (uint8_t)((3<<6) | (1<<4) | (2<<2) | (0)) ///< Transmit as B,R,G,W
#define NEO_BGWR (uint8_t)((2<<6) | (3<<4) | (1<<2) | (0)) ///< Transmit as B,G,W,R
#define NEO_BGRW (uint8_t)((3<<6) | (2<<4) | (1<<2) | (0)) ///< Transmit as B,G,R,W

// FixedColor_buf一些常见的颜色
#define RED        0
#define GREEN      1
#define BLUE       2
#define WHITE      3
#define BLACK      4
#define YELLOW     5
#define CYAN       6
#define MAGENTA    7
#define PURPLE     8
#define ORANGE     9
#define PINK       10
#define GRAY       11
#define FixedColor_Max       12

typedef struct _extLight_color
{
	uint8_t blue;
	uint8_t green;
	uint8_t red;
	uint8_t write;
}extLight_colorType;
typedef struct _extLight_colorTable
{
	extLight_colorType color[FixedColor_Max];
}extLight_colorTableType;

//模式选择
#define FX_MODE_STATIC                   0   //静态模式，灯光保持固定颜色不变
#define FX_MODE_BLINK                    1   //闪烁模式，灯光以一定频率闪烁
#define FX_MODE_BREATH                   2   //呼吸模式，灯光亮度像呼吸一样逐渐变亮再变暗
#define FX_MODE_COLOR_WIPE               3   //单色擦除模式，一种颜色从一端逐渐擦除到另一端
#define FX_MODE_COLOR_WIPE_INV           4   //反向单色擦除模式，单色擦除方向与COLOR_WIPE相反
#define FX_MODE_COLOR_WIPE_REV           5   //反转单色擦除模式，颜色顺序反转的单色擦除
#define FX_MODE_COLOR_WIPE_REV_INV       6   //反转反向单色擦除模式，结合了反转和反向的单色擦除
#define FX_MODE_COLOR_WIPE_RANDOM        7   //随机单色擦除模式，随机颜色进行擦除
#define FX_MODE_RANDOM_COLOR             8   //随机颜色模式，灯光随机变换颜色
#define FX_MODE_SINGLE_DYNAMIC           9   //单动态模式，单个灯光动态变化
#define FX_MODE_MULTI_DYNAMIC           10   //多动态模式，多个灯光同时动态变化
#define FX_MODE_RAINBOW                 11   //彩虹模式，灯光呈现彩虹般的色彩渐变效果
#define FX_MODE_RAINBOW_CYCLE           12   //彩虹循环模式，彩虹效果循环滚动
#define FX_MODE_SCAN                    13   //扫描模式，灯光像扫描仪一样来回扫描
#define FX_MODE_DUAL_SCAN               14   //双重扫描模式，两个扫描光束同时进行扫描
#define FX_MODE_FADE                    15   //渐变模式，灯光颜色或亮度逐渐变化(跟2差不多)
#define FX_MODE_THEATER_CHASE           16   //剧院追逐模式，灯光像剧院灯光一样追逐闪烁
#define FX_MODE_THEATER_CHASE_RAINBOW   17   //剧院追逐彩虹模式，结合了剧院追逐和彩虹效果
#define FX_MODE_RUNNING_LIGHTS          18   //流动灯光模式，灯光像流水一样向前流动
#define FX_MODE_TWINKLE                 19   //闪烁模式，灯光像星星一样闪烁
#define FX_MODE_TWINKLE_RANDOM          20   //随机闪烁模式，灯光随机位置随机闪烁
#define FX_MODE_TWINKLE_FADE            21   //渐变闪烁模式，闪烁时带有渐变效果
#define FX_MODE_TWINKLE_FADE_RANDOM     22   //随机渐变闪烁模式，随机位置渐变闪烁
#define FX_MODE_SPARKLE                 23   //闪烁模式，灯光像火花一样闪烁
#define FX_MODE_FLASH_SPARKLE           24   //闪光闪烁模式，闪烁时带有闪光效果
#define FX_MODE_HYPER_SPARKLE           25   //超级闪烁模式，更强烈的闪烁效果
#define FX_MODE_STROBE                  26   //频闪模式，灯光快速闪烁产生频闪效果
#define FX_MODE_STROBE_RAINBOW          27   //彩虹频闪模式，频闪时呈现彩虹颜色
#define FX_MODE_MULTI_STROBE            28   //多重频闪模式，多个频闪光束同时出现
#define FX_MODE_BLINK_RAINBOW           29   //彩虹闪烁模式，闪烁时呈现彩虹颜色
#define FX_MODE_CHASE_WHITE             30   //白色追逐模式，白色灯光进行追逐效果
#define FX_MODE_CHASE_COLOR             31   //彩色追逐模式，彩色灯光进行追逐效果
#define FX_MODE_CHASE_RANDOM            32   //随机追逐模式，随机颜色灯光进行追逐
#define FX_MODE_CHASE_RAINBOW           33   //彩虹追逐模式，彩虹颜色灯光进行追逐
#define FX_MODE_CHASE_FLASH             34   //追逐闪光模式，追逐时带有闪光效果
#define FX_MODE_CHASE_FLASH_RANDOM      35   //随机追逐闪光模式，随机颜色追逐时闪光
#define FX_MODE_CHASE_RAINBOW_WHITE     36   //彩虹白追逐模式，彩虹与白色灯光结合追逐
#define FX_MODE_CHASE_BLACKOUT          37   //熄灭追逐模式，灯光在追逐过程中有熄灭效果
#define FX_MODE_CHASE_BLACKOUT_RAINBOW  38   //彩虹熄灭追逐模式，彩虹灯光在追逐时有熄灭效果
#define FX_MODE_COLOR_SWEEP_RANDOM      39   //随机颜色扫过模式，随机颜色像扫帚一样扫过灯光
#define FX_MODE_RUNNING_COLOR           40   //流动颜色模式，颜色像水流一样在灯光上流动
#define FX_MODE_RUNNING_RED_BLUE        41   //红蓝流动模式，红蓝两色灯光依次流动
#define FX_MODE_RUNNING_RANDOM          42   //随机流动模式，随机颜色灯光依次流动
#define FX_MODE_LARSON_SCANNER          43   //拉尔森扫描模式，灯光像扫描仪一样来回扫描，常用于科幻效果
#define FX_MODE_COMET                   44   //彗星模式，灯光像彗星尾巴一样流动
#define FX_MODE_FIREWORKS               45   //烟花模式，灯光像烟花一样绽放
#define FX_MODE_FIREWORKS_RANDOM        46   //随机烟花模式，烟花绽放的位置和颜色随机
#define FX_MODE_MERRY_CHRISTMAS         47   //圣诞模式，呈现圣诞主题的灯光效果，如闪烁的彩灯等
#define FX_MODE_FIRE_FLICKER            48   //火焰闪烁模式，灯光像火焰一样闪烁
#define FX_MODE_FIRE_FLICKER_SOFT       49   //柔和火焰闪烁模式，火焰闪烁效果更柔和
#define FX_MODE_FIRE_FLICKER_INTENSE    50   //强烈火焰闪烁模式，火焰闪烁效果更强烈
#define FX_MODE_CIRCUS_COMBUSTUS        51   //马戏团火焰模式，呈现马戏团表演中的火焰效果
#define FX_MODE_HALLOWEEN               52   //万圣节模式，呈现万圣节主题的灯光效果，如幽灵、南瓜灯等
#define FX_MODE_BICOLOR_CHASE           53   //双色追逐模式，两种颜色的灯光进行追逐
#define FX_MODE_TRICOLOR_CHASE          54   //三色追逐模式，三种颜色的灯光进行追逐
#define FX_MODE_TWINKLEFOX              55   //闪烁狐模式，灯光像狐狸眼睛一样闪烁
#define FX_MODE_BLOCK_DISSOLVE          56   //方块溶解模式，灯光像方块一样逐渐溶解消失
#define FX_MODE_ICU                     57   //重症监护模式，呈现类似医院重症监护室的灯光效果
#define FX_MODE_DUAL_LARSON             58   //双重拉尔森模式，两个拉尔森扫描光束同时出现
#define FX_MODE_RUNNING_RANDOM2         59   //另一种随机流动模式，与RUNNING_RANDOM有所不同
#define FX_MODE_FILLER_UP               60   //填充上升模式，灯光从底部向上逐渐填充
#define FX_MODE_RAINBOW_LARSON          61   //彩虹拉尔森模式，拉尔森扫描光束呈现彩虹颜色
#define FX_MODE_TRIFADE                 62   //三色渐变模式，三种颜色之间相互渐变
#define FX_MODE_HEARTBEAT               63   //心跳模式，灯光像心跳一样有节奏地闪烁
#define FX_MODE_VU_METER                64   //音量表模式，灯光根据音量大小变化，常用于音响设备
#define FX_MODE_BITS                    65   //比特模式，灯光像二进制比特一样闪烁
#define FX_MODE_MULTI_COMET             66   //多彗星模式，多个彗星尾巴效果同时出现
#define FX_MODE_FLIPBOOK                67   //翻页书模式，灯光像翻页书一样快速切换效果
#define FX_MODE_POPCORN                 68   //爆米花模式，灯光像爆米花一样随机爆开
#define FX_MODE_OSCILLATOR              69   //振荡器模式，灯光像振荡器一样有规
#define UFX_MODE_COMET1                 70   //彩色流星雨扫来扫去
#define UFX_MODE_COMET2                 71   //彩色流星雨扫来扫去
#define UFX_MODE_COMET3                 72   //彩色流星雨扫来扫去
#define MODE_MAX						73

//选项的定义
#define NO_OPTIONS   (uint8_t)0x00   //没有任何选项被设置。
#define REVERSE      (uint8_t)0x80   //动画反转选项。如果设置了这个位，动画将反向播放
#define FADE_XFAST   (uint8_t)0x10  //这些宏定义了不同的褪色速率（fade rate），从极快（FAST）到极慢（GLACIAL）。每个宏定义了不同的位模式，用于设置 LED 段的褪色速率。
#define FADE_FAST    (uint8_t)0x20
#define FADE_MEDIUM  (uint8_t)0x30
#define FADE_SLOW    (uint8_t)0x40
#define FADE_XSLOW   (uint8_t)0x50
#define FADE_XXSLOW  (uint8_t)0x60
#define FADE_GLACIAL (uint8_t)0x70
#define GAMMA        (uint8_t)0x08   //开启伽马校正选项。如果设置了这个位，LED 的颜色将应用伽马校正。
#define SIZE_SMALL   (uint8_t)0x01  //这些宏定义了段的大小选项，从小型（SMALL）到超大型（XLARGE）。每个宏定义了不同的位模式，用于设置 LED 段的大小。
#define SIZE_MEDIUM  (uint8_t)0x02
#define SIZE_LARGE   (uint8_t)0x04
#define SIZE_XLARGE  (uint8_t)0x06


/*
* 获取外扩灯板的连接状态。
* 输出：		已经连接返回1，没有连接返回0；
*/
LIBRARY_API int extLight_connect_state(void);

/*
* 初始化外扩灯板的端口。
* port：		exLight的端口：0-6或Port1-Port7
* lednum：		led灯珠数量。
* ledtype:		led类型:NEO_RGB - NEO_BGRW
* segmentnum:		段数量：0-255
* 输出：		成功返回1，失败返回0
*/
LIBRARY_API int exLight_port_init(extLight_portEnum port,uint8_t lednum, uint8_t ledtype, uint8_t segmentnum, uint8_t bright);

/*
* 禁止extLight 端口 更新。
* port：		exLight的端口：0-6或Port1-Port7
* 输出：		成功返回1，失败返回0
*/
LIBRARY_API int exLight_port_disable(extLight_portEnum port);

/*
* 使能extLight 端口 更新。
* port：		exLight的端口：0-6或Port1-Port7
* 输出：		成功返回1，失败返回0
*/
LIBRARY_API int exLight_port_enable(extLight_portEnum port);

/*
*  设置固定颜色表,不配置就用默认的
*  颜色表由 RED -  GRAY 共 FixedColor_Max个颜色组成，每个颜色由4个分量：B，G，R，W
* colorTable:	extLight_colorTableType类型的颜色表指针。
* 输出：		成功返回1，失败返回0
*/
LIBRARY_API int extLight_colorTab_set(extLight_colorTableType* colorTable);

/*
*  设置灯光模式
* port：		exLight的端口：0-6或Port1-Port7
* segment:		段号
* ledstart:     led开始序号0-255
* ledstart:     led结束序号0-255
* mode:			灯光模式 NEO_RGB - NEO_BGRW
* color1:		0-11或RED - GRAY
* color2:		0-11或RED - GRAY
* color3:		0-11或RED - GRAY
* speed:		速度0-255
* 输出：		成功返回1，失败返回0
*/
LIBRARY_API int extLight_mode_set(extLight_portEnum port,uint8_t segment,uint8_t ledstart,uint8_t ledend,uint8_t mode,
	uint8_t color1, uint8_t color2, uint8_t color3,uint8_t speed,uint8_t option);

/*
*  保存数据到flash
* block：		要存储到的flash的块区号：0-255
* flame			有多少帧画面：0-255
* line:			有多少行：0-255
* column:		有多少列：0-255
* color:		指向颜色数组的指针。颜色数组的大小为flame * line * column * 4
* 输出：		成功返回1，失败返回0
*/
LIBRARY_API int extLight_flash_save(uint8_t block,uint8_t flame, uint8_t line, uint8_t column, extLight_colorType* colorbuff);

/*
*  读取flash数据到指定端口
* port：		exLight的端口：0-6或Port1-Port7
* sector：		flash的扇区号：0-4095
* line:			有多少行：0-255
* column:		有多少列：0-255
* color:		指向颜色数组的指针
* 输出：		成功返回1，失败返回0
*/
LIBRARY_API int extLight_flash_read(uint8_t port, uint8_t block);

/*
*获取extLight 固件版本号
* 输出：char字符穿开始地址
*/
LIBRARY_API char* exLight_software_version(void);


/*
*获取extLight 硬件（PCB）版本号
* 输出：char字符穿开始地址
* 
*/
LIBRARY_API char* exLight_hardware_version(void);



