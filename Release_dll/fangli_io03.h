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
/*   �汾��¼
*  lib_V1.0����ʼ�汾
*  lib_V1.1��������������ʱ����һ���ܶ�ȡ������������
*  lib_v1.2: ����ĳЩusbת���ڣ�����ܾõ�����
*  lib_v1.3: ��������ʱ����ȷ��ȡkeys������
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
* ��ȡio���Ӳ���汾��
* ���� io���Ӳ���汾�ŵ��ַ���
*/
LIBRARY_API char* get_hardware(void);
/*
* ��ȡio�������汾��
* ���� io�������汾�ŵ��ַ���
*/
LIBRARY_API char* get_software(void);
/*
* ��ȡio���api��汾��
* ���� io���api����ַ���
*/
LIBRARY_API char* get_lib(void);
/*
* ��ȡio�����������
* �������ڵ��ַ���
*/
LIBRARY_API char* get_production_date(void);
/*
* ��ȡio��uid
* ����uid���ַ���
*/
LIBRARY_API char* get_uid(void);
/*
* ��ȡio�����û�������������
* counter_id��0-1������0��λͶ�Ҷ�Ӧ�����
* ����16λ���޷�������ֵ
*/
LIBRARY_API uint16_t get_counter(uint8_t counter_id);
/*
* �趨io�����û�������������
* counter_id��0-1������0��λͶ�Ҷ�Ӧ�����
* counter_num: 0 - 0xffe,0xffff,��ʾ���䶯����˼
*/
LIBRARY_API void set_counter(uint8_t counter_id, uint16_t counter_num);
/*
* ��ȡio�廹û���õ��ı���
* ����16λ���޷�������ֵ
*/
LIBRARY_API uint16_t get_coin();
/*
* Ҫ�õ��ı���������Ҫ�۳��ı���
* ����16λ���޷�������ֵ��ʵ�ʿ۳����ǡ������ڻ�û���õ��ı���λ1��Ҫ�۳�2����ô�ͷ���ʵ���ܿ۳���1
*/
LIBRARY_API uint16_t decrease_coins(uint16_t coins); //����ʵ�ʿ۱�����
/*
* ��ȡio��mcu���ڲ��¶�
* ����8λ���޷�������ֵ��ֵ����1���϶�
*/
LIBRARY_API uint8_t get_mcu_temperature(void);
/*
* ��ȡio��mcu�Ĺ����ѹ
* ����8λ���޷�������ֵ��ֵ����0.1v
*/
LIBRARY_API uint8_t get_mcu_voltage(void);
/*
* ��ȡio���ص�ѹ
* ����8λ���޷�������ֵ��ֵ����0.1v
*/
LIBRARY_API uint8_t get_battery_voltage(void);
/*
* ��ȡio��24����������ֵ
* key_id��0-23���ļ���ͷ�и����������Ƶĺ궨�壬��INPUT_UP
* true����ʾ�������¡�false����ʾ�ɿ�
*/
LIBRARY_API bool get_key(uint8_t key_id);
/*
* ��ȡio��8��adcֵ
*  adc_id��0-7
* ����һ��0-255��adcֵ
*/
LIBRARY_API uint8_t get_adc(uint8_t adc_id);
/*
* ����io��18��pwm��rgb��ͨ����������ʽ
* pwm_id��0-17��0����R0��1��G0��2��B0��3��R1.�������
* type��0-1��0Ϊ������ģʽ��1Ϊon/offģʽ
* interval��0-7 �����ļ��ʱ�䡣����0Ϊ������1����죬7����
*  bright��0-15����ֵ.0Ϊ������15Ϊ����
*/
LIBRARY_API void set_pwm(uint8_t pwm_id, uint8_t type, uint8_t interval, uint8_t bright);
/*
* ����io��24������io�����ƽ
* out_id��0-23���ļ���ͷ�и����������Ƶĺ궨�壬��OUTPUT_KEYLED0
* level�����ŵ�ƽ false�������ƽΪ�ߣ���Ӧ�ĵƲ�����false�������ƽΪ�ͣ���Ӧ�ĵ���
*/
LIBRARY_API void set_outPin(uint8_t out_id, bool level);
/*
* ֹͣ���io�崮�ڵ��̣߳�ʹ�ö�̬��ʱ��Ӧ�ý���ǰʹ�ô˺����������߳̿��ܲ����˳�
*/
LIBRARY_API bool stop_monitoring();

