#pragma once
#include <stdint.h>

#ifdef DLLLIBRARY_EXPORTS  
#define LIBRARY_API extern "C" __declspec(dllexport)  
#elif  DLLLIBRARY_INPORTS
#define LIBRARY_API extern "C" __declspec(dllimport)
#else
#define LIBRARY_API extern	
#endif  
#define LIB_VERSION "lib_V1.9"
/*   �汾��¼
*  lib_V1.0����ʼ�汾
*  lib_V1.1��������������ʱ����һ���ܶ�ȡ������������
*  lib_v1.2: ����ĳЩusbת���ڣ�����ܾõ�����
*  lib_v1.3: ��������ʱ����ȷ��ȡkeys������
*  lib_v1.4:
*		1�����ֵ��Ͷ��ֵ����λ32λ
		2��Pwm���Ʋ��Ϊ3������
		3,ʵ�ֶϿ����ͶϿ���������
*lib_v1.5:
	1������һ��Ͷ����
	2��set_counter()��Ϊadd_counter()
	3������clean_counter()
	4,����adcֵ��uint16_t���ݴ洢
lib_v1.6
	1,�ӿ��ȡ���ڵ��ٶ�
lib_v1.7
	1,���ӷ����̹���
lib_v1.8
	1,��ȷ֧��windows7��windows10��Windows11.
	2,���ڸ���Ϊͬ��ģʽ
	3������ע���ö�ٴ���
	4,�Ż����ͺͽ��ܣ�ʹ�����������ݺ�������
lib_v1.9
	1,֧��CANת������
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

//error��mask
#define NO_FM               0x0001      ///< û�м�⵽����洢�� 
#define NO_LKT              0x0100      ///< û�м�⵽����оƬ 
#define LKT_ILLEGAL         0x0200      ///< ����оƬû����Ȩ
#define CODE_NOSIGN         0x0400      ///< �̼�û��ǩ�������ǩ�� 
#define UID_NOSIGN          0x0800      ///< UIDû��ǩ�������ǩ�� 
#define NO_RDP              0x1000      ///< mcu���ڶ�����״̬�� 
//�����̶�������
#define     STEERING_ERROR      -1  ///< �����̴���(Steering wheel error)
#define     STEERING_AUTO_TEST  0   ///< �������������Զ�����ָ��(The steering wheel is currently executing an automatic test command)
#define     STEERING_STOP       1   ///< ������������ָֹͣ��(The steering wheel is currently executing a stop command)
#define     STEERING_LEFT       2   ///< ��������������תָ��(The steering wheel is currently executing a left turn command.)
#define     STEERING_RIGHT      3   ///< ��������������תָ��(The steering wheel is currently executing a right turn command.)
#define     STEERING_POSITION   4   ///< ������������ָ��λ��ָ��(The steering wheel is currently executing a command to move to a specified position)
#define     STEERING_SHAKE      5   ///<��������������ָ��(The steering wheel is currently executing a vibration command)

//CAN ��ʼ��ֵ�ṹ��
typedef struct _can_init
{
	uint32_t baud;//������
	uint8_t bs1;// BS1
	uint8_t bs2;//BS2
	uint8_t sjw;//SJW
}CAN_initType;

//CAN ���ݽṹ��
typedef struct _can_data
{
	uint32_t id;//ID
	uint8_t len;// ���ݳ���
	uint8_t data[8];//����
}CAN_dataType;

/*
* ����io��
* ���� �Ѿ��ɹ����ӷ���com�ţ�ʧ�ܷ���-1,���������з���0��
*/
LIBRARY_API int connect_state(void);

/*
* ����io��
* ���� �Ѿ��ɹ����ӷ���com�ţ�ʧ�ܷ���-1�����������з���0��
*/
LIBRARY_API int reconnect(void);


/*
* ��ȡio���Ӳ���汾��
* ���� io���Ӳ���汾�ŵ��ַ���
*/
LIBRARY_API uint16_t get_error(void);


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
* counter_id��0-1������0����Ͷ�Ҷ�Ӧ�����
* ����32λ���޷�������ֵ
*/
LIBRARY_API uint32_t get_counter(uint8_t counter_id);


/*
* �趨io�����û�������������
* counter_id��0-1������0����Ͷ�Ҷ�Ӧ�����
* counter_num: 0 - 0xfffffff
*/
LIBRARY_API void add_counter(uint8_t counter_id, uint32_t counter_num);

/*
* ���io�����û�������������
* counter_id��0-1������0����Ͷ�Ҷ�Ӧ�����
*/
LIBRARY_API void clean_counter(uint8_t counter_id);


/*
* ��ȡio�廹û���õ��ı���
* uint8_t coin_id:0-1
* coin_id��
#define COIN1            0
#define COIN2            1
* ����32λ���޷�������ֵ
*/
LIBRARY_API uint32_t get_coin(uint8_t coin_id);


/*
* Ҫ�õ��ı���������Ҫ�۳��ı���
* uint8_t coin_id:0-1
* coin_id��
#define COIN1            0
#define COIN2            1
* uint32_t coins: Ҫ�۳��ı��� 0-0xffffffff
* ����32λ���޷�������ֵ��ʵ�ʿ۳��������磬���ڻ�û���õ��ı�����1��Ҫ�۳�2����ô�ͷ���ʵ���ܿ۳���1
*/
LIBRARY_API uint32_t decrease_coin(uint8_t coin_id,uint32_t coins); //����ʵ�ʿ۱�����

/*
* ���IO�����Ͷ����
* uint8_t coin_id:0-1
* coin_id��
#define COIN1            0
#define COIN2            1
* ����32λ���޷�������ֵ��ʵ������˵ı�����
*/
LIBRARY_API uint32_t clear_coin(uint8_t coin_id); //����ʵ�����������


/*
* ��ȡio��mcu���ڲ��¶�
* ����16λ���޷�������ֵ��ֵ����1���϶�
*/
LIBRARY_API uint16_t get_mcu_temperature(void);


/*
* ��ȡio��mcu�Ĺ����ѹ
* ����16λ���޷�������ֵ��ֵ����1mv
*/
LIBRARY_API uint16_t get_mcu_voltage(void);


/*
* ��ȡio���ص�ѹ
* ����16λ���޷�������ֵ��ֵ����1mv
*/
LIBRARY_API uint16_t get_battery_voltage(void);


/*
* ��ȡio��24����������ֵ
* key_id��0-23���ļ���ͷ�и����������Ƶĺ궨�壬��INPUT_UP
* true����ʾ�������¡�false����ʾ�ɿ�
*/
LIBRARY_API bool get_key(uint8_t key_id);


/*
* ��ȡio��8��adcֵ
*  adc_id��0-7
* ����һ��0-0xffff��adcֵ
*/
LIBRARY_API uint16_t get_adc(uint8_t adc_id);


/*
* ����io��18��pwm��rgb��ͨ���ĳ���ģʽ
* pwm_id��0-17��0����R0��1��G0��2��B0��3��R1.������ƣ���pwm_id�ĺ궨��
*  bright��0-255����ֵ.0Ϊ������255Ϊ����
*/
LIBRARY_API void set_pwm_normal(uint8_t pwm_id,uint8_t bright);


/*
* ����io��18��pwm��rgb��ͨ��������ģʽ
* pwm_id��0-17��0����R0��1��G0��2��B0��3��R1.������ƣ���pwm_id�ĺ궨��
* interval��0-100 �����ļ��ʱ�䡣����0Ϊ��������1����죬100��������ֵ���� * 0.1S
*  bright��0-255����ֵ.0Ϊ������255Ϊ����
*/
LIBRARY_API void set_pwm_blink(uint8_t pwm_id, uint8_t interval, uint8_t bright);


/*
* ����io��18��pwm��rgb��ͨ���ĺ�����ģʽ
* pwm_id��0-17��0����R0��1��G0��2��B0��3��R1.������ƣ���pwm_id�ĺ궨��
* interval��0-100 �����ļ��ʱ�䡣����0Ϊ��������1����죬100��������ֵ���� * 0.1S
*  bright��0-255����ֵ.0Ϊ������255Ϊ����
*/
LIBRARY_API void set_pwm_breathe(uint8_t pwm_id, uint8_t interval, uint8_t bright);


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

/*
* �رշ������������
* uint8_t sternum��������ID
* 0��������1
* 1��������2
*/
LIBRARY_API void steering_stop(uint8_t steernum);

/*
* �������Զ��ⶨ����߽�����ұ߽�
* uint8_t sternum��������ID
* 0��������1
* 1��������2
*/
LIBRARY_API void steering_auto_test(uint8_t steernum);

/*
* ������һֱ����ת
* uint8_t sternum��������ID
* 0��������1
* 1��������2
* uint8_t strength�������̵����ȣ���Ҫ����������ץס�����̣���ֹ���˶�ʱ�����ܵ������ȡ�ȡֵ��ΧΪ0��100.����100��ֵ���ᵱ����100.
* uint8_t speed���������ƶ����ٶȡ���Ҫ����Ϊ������û���谭ʱ�ƶ����ٶȡ�ȡֵ��ΧΪ0��100������100��ֵ���ᵱ��100��
*/
LIBRARY_API void steering_left(uint8_t steernum,uint8_t strength, uint8_t speed);

/*
* ������һֱ����ת
* uint8_t sternum��������ID
* 0��������1
* 1��������2
* uint8_t strength�������̵����ȣ���Ҫ����������ץס�����̣���ֹ���˶�ʱ�����ܵ������ȡ�ȡֵ��ΧΪ0��100.����100��ֵ���ᵱ����100.
* uint8_t speed���������ƶ����ٶȡ���Ҫ����Ϊ������û���谭ʱ�ƶ����ٶȡ�ȡֵ��ΧΪ0��100������100��ֵ���ᵱ��100��
*/
LIBRARY_API void steering_right(uint8_t steernum,uint8_t strength, uint8_t speed);

/*
* ������ת����ָ��λ��
* uint8_t sternum��������ID
* 0��������1
* 1��������2
* uint8_t strength�������̵����ȣ���Ҫ����������ץס�����̣���ֹ���˶�ʱ�����ܵ������ȡ�ȡֵ��ΧΪ0��100.����100��ֵ���ᵱ����100.
* uint8_t speed���������ƶ����ٶȡ���Ҫ����Ϊ������û���谭ʱ�ƶ����ٶȡ�ȡֵ��ΧΪ0��100������100��ֵ���ᵱ��100��
* int8_t pos: ���λ��ֵ,-100��ʾ�����,+100��ʾ���ұߡ�С��-100�Ķ��ᵱ��-100������+100���ᵱ��+100��0��ʾ����λ�á�
*/
LIBRARY_API void steering_position(uint8_t steernum,uint8_t strength,uint8_t speed,int8_t pos);

/*
* ��������ָ��λ��Ϊ�������Ұڶ�
* uint8_t sternum��������ID
* 0��������1
* 1��������2
* uint8_t strength�������̵����ȣ���Ҫ����������ץס�����̣���ֹ���˶�ʱ�����ܵ������ȡ�ȡֵ��ΧΪ0��100.����100��ֵ���ᵱ����100.
* uint8_t speed���������ƶ����ٶȡ���Ҫ����Ϊ������û���谭ʱ�ƶ����ٶȡ�ȡֵ��ΧΪ0��100������100��ֵ���ᵱ��100��
* int8_t pos: ���λ��ֵ,-100��ʾ�����,+100��ʾ���ұߡ�С��-100�Ķ��ᵱ��-100������+100���ᵱ��+100��0��ʾ����λ�á�
* uint8_t amp�����������Ұڶ��������ȣ�0-100��
*/
LIBRARY_API void steering_shake(uint8_t steernum,uint8_t strength,uint8_t speed,int8_t pos,uint8_t amp);

/*
* ��ȡ�����̵�����״̬�����Ƿ��������к���ָ��
* uint8_t sternum��������ID
* 0��������1
* 1��������2
* ��������¶���
#define     STEERING_ERROR      -1  ///< �����̴���(Steering wheel error)
#define     STEERING_AUTO_TEST  0   ///< �������������Զ�����ָ��(The steering wheel is currently executing an automatic test command)
#define     STEERING_STOP       1   ///< ������������ָֹͣ��(The steering wheel is currently executing a stop command)
#define     STEERING_LEFT       2   ///< ��������������תָ��(The steering wheel is currently executing a left turn command.)
#define     STEERING_RIGHT      3   ///< ��������������תָ��(The steering wheel is currently executing a right turn command.)
#define     STEERING_POSITION   4   ///< ������������ָ��λ��ָ��(The steering wheel is currently executing a command to move to a specified position)
#define     STEERING_SHAKE      5   ///<��������������ָ��(The steering wheel is currently executing a vibration command)
*/
LIBRARY_API int8_t get_steering_state(uint8_t steernum);

/*
* ��ȡ����������߽߱��ADCԭʼֵ
* uint8_t sternum��������ID
* 0��������1
* 1��������2
* �����������߽��ADCֵ0~4095
*/
LIBRARY_API uint16_t get_steering_left_limit(uint8_t steernum);

/*
* ��ȡ�������ұ߽��ADCԭʼֵ
* uint8_t sternum��������ID
* 0��������1
* 1��������2
* ����������ұ߽��ADCֵ0~4095
*/
LIBRARY_API uint16_t get_steering_right_limit(uint8_t steernum);

/*
* ��ⷽ���̵�ʵʱλ��
* uint8_t sternum��������ID
* 0��������1
* 1��������2
* ��������ط����̵����λ�á�-100~-1Ϊ���λ�ã�0Ϊ�м�λ�ã�1��100Ϊ�ұ�λ�á�
*/
LIBRARY_API int8_t get_steering_position(uint8_t steernum);

/*
* ����CAN��ʱ��Ƭ�εĳ�ʼ��ֵ
* baud�� ������,��ʼֵΪ500K��������=42MHz/((1+BS1+BS2)*n),n����������
			���Ҫ���õĲ����ʵ�ֵ���ڹ�ʽ�У�����ֵ��ʵ��ֵ������ƫ�
			�����ʱ���С��1M��1000000��
*		
* BS1�� λ��1��ֵ����ʼֵΪ8 
* BS2�� λ��2��ֵ����ʼֵΪ3
* SJW�� ��ͬ����ת��ȵ�ֵ����ʼֵΪ1��SJW<= BS1,SJW<= BS2
* ����в�������������Ҫ�󣬸ú�����ִ�У�������0
* ������ɹ�ִ�У�����ʵ�ʲ����ʡ�ʧ�ܷ���0
*/
LIBRARY_API uint32_t set_can_init(uint32_t baud,uint8_t BS1,uint8_t BS2,uint8_t SJW);

/*
* ��ȡCAN��ʱ��Ƭ�εĳ�ʼ��ֵ
*init�� �����ʼ��ֵ��CAN_initType ָ��
*/
LIBRARY_API void get_can_init(CAN_initType* init);

/*
* �������ݵ�CAN����
* id�� ��Ϣid������ʹ�ñ�׼ID��CAN 2.0A����11λ����
* len�� Ҫ���͵����ݳ��ȣ�ȡֵ��Χ0-8
* data�� Ҫ���͵����ݵ�ָ��
*/
LIBRARY_API void can_send(uint32_t id, uint8_t len, uint8_t* data);

/*
* ��ȡCAN���ݣ�CAN���ݴ洢��CAN_dataType���͵�FIFO�У�ÿ�ε��ô˺�����ȡһ��FIFO���ݡ�
*data�� ������ݵ�CAN_dataType ָ��
* ������ɹ���ȡ�����ݣ�����1��FIFO�գ�û�ж�ȡ�����ݷ���0
*/
LIBRARY_API int can_receive(CAN_dataType* data);


