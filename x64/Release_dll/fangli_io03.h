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
lib_v2.0
	1�����Ӵ���ת����uart5�Ĺ��ܡ�
	2��������չ�ư�Ŀ��ƹ���
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


/*
* ��ȡIO��͵��Ե�����״̬
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



//�����̶�������
#define     STEERING_ERROR      -1  ///< �����̴���(Steering wheel error)
#define     STEERING_AUTO_TEST  0   ///< �������������Զ�����ָ��(The steering wheel is currently executing an automatic test command)
#define     STEERING_STOP       1   ///< ������������ָֹͣ��(The steering wheel is currently executing a stop command)
#define     STEERING_LEFT       2   ///< ��������������תָ��(The steering wheel is currently executing a left turn command.)
#define     STEERING_RIGHT      3   ///< ��������������תָ��(The steering wheel is currently executing a right turn command.)
#define     STEERING_POSITION   4   ///< ������������ָ��λ��ָ��(The steering wheel is currently executing a command to move to a specified position)
#define     STEERING_SHAKE      5   ///<��������������ָ��(The steering wheel is currently executing a vibration command)

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

//uart parity ����
#define		NONE		0
#define		EVEN		1
#define		ODD			2

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



//ת������ͨ�Ų����ṹ��
typedef struct _uartForward_init
{
	uint32_t baud;	//������
	uint8_t bits;	//��λ��
	uint8_t parity;	//��żУ��λ
	uint8_t stop;	//ֹͣλ
}uartForward_initType;

/*
* ����ת������uart5��ͨ�Ų���
* baud��		������,��ʼֵΪ115200
* bits��		��λ��ȣ�ֻ��8��9
* parity��		��żУ�飬0:NONE��1:EVEN; 2:ODD
* stop��		ֹͣλ��ֻ��1��2
*				����в�������������Ҫ�󣬸ú�����ִ�У�������0
* �����		�ɹ�ִ�У�����1,ʧ�ܷ���0��
*/
LIBRARY_API int set_uartForward_init(uint32_t baud, uint8_t bits, uint8_t parity, uint8_t stop);

/*
* ��ȡת������uart5��ͨ�Ų���
*init�� ���ת������ͨ�Ų����ṹ��uartForward_initTypeָ��
*/
LIBRARY_API void get_uartForward_init(uartForward_initType* init);

/*
* �������ݵ�����ת����uart5
* len��			Ҫ���͵����ݳ���
* data��		Ҫ���͵����ݵ�ָ��
* �����		�ɹ�ִ�У�����1,ʧ�ܷ���0
*/
LIBRARY_API int uartForward_send(uint16_t len, uint8_t* data);

/*
* ��ȡת���������ݣ����յ��Ĵ���ת�����ݴ洢��FIFO�У���ָ���ǽ�FIFO���ݶ�����
* len��			Ҫ��ȡ�����ݳ���
* data��		Ҫ�洢��ȡ�����ݵ�ָ��
* �����		���سɹ���ȡ�������ֽ���
*/
LIBRARY_API int uartForward_receive(uint16_t len, uint8_t* data);



//�����ư�extLight�Ķ���

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


//��������ѡ��
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

// FixedColor_bufһЩ��������ɫ
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

//ģʽѡ��
#define FX_MODE_STATIC                   0   //��̬ģʽ���ƹⱣ�̶ֹ���ɫ����
#define FX_MODE_BLINK                    1   //��˸ģʽ���ƹ���һ��Ƶ����˸
#define FX_MODE_BREATH                   2   //����ģʽ���ƹ����������һ���𽥱����ٱ䰵
#define FX_MODE_COLOR_WIPE               3   //��ɫ����ģʽ��һ����ɫ��һ���𽥲�������һ��
#define FX_MODE_COLOR_WIPE_INV           4   //����ɫ����ģʽ����ɫ����������COLOR_WIPE�෴
#define FX_MODE_COLOR_WIPE_REV           5   //��ת��ɫ����ģʽ����ɫ˳��ת�ĵ�ɫ����
#define FX_MODE_COLOR_WIPE_REV_INV       6   //��ת����ɫ����ģʽ������˷�ת�ͷ���ĵ�ɫ����
#define FX_MODE_COLOR_WIPE_RANDOM        7   //�����ɫ����ģʽ�������ɫ���в���
#define FX_MODE_RANDOM_COLOR             8   //�����ɫģʽ���ƹ�����任��ɫ
#define FX_MODE_SINGLE_DYNAMIC           9   //����̬ģʽ�������ƹ⶯̬�仯
#define FX_MODE_MULTI_DYNAMIC           10   //�ද̬ģʽ������ƹ�ͬʱ��̬�仯
#define FX_MODE_RAINBOW                 11   //�ʺ�ģʽ���ƹ���ֲʺ���ɫ�ʽ���Ч��
#define FX_MODE_RAINBOW_CYCLE           12   //�ʺ�ѭ��ģʽ���ʺ�Ч��ѭ������
#define FX_MODE_SCAN                    13   //ɨ��ģʽ���ƹ���ɨ����һ������ɨ��
#define FX_MODE_DUAL_SCAN               14   //˫��ɨ��ģʽ������ɨ�����ͬʱ����ɨ��
#define FX_MODE_FADE                    15   //����ģʽ���ƹ���ɫ�������𽥱仯(��2���)
#define FX_MODE_THEATER_CHASE           16   //��Ժ׷��ģʽ���ƹ����Ժ�ƹ�һ��׷����˸
#define FX_MODE_THEATER_CHASE_RAINBOW   17   //��Ժ׷��ʺ�ģʽ������˾�Ժ׷��Ͳʺ�Ч��
#define FX_MODE_RUNNING_LIGHTS          18   //�����ƹ�ģʽ���ƹ�����ˮһ����ǰ����
#define FX_MODE_TWINKLE                 19   //��˸ģʽ���ƹ�������һ����˸
#define FX_MODE_TWINKLE_RANDOM          20   //�����˸ģʽ���ƹ����λ�������˸
#define FX_MODE_TWINKLE_FADE            21   //������˸ģʽ����˸ʱ���н���Ч��
#define FX_MODE_TWINKLE_FADE_RANDOM     22   //���������˸ģʽ�����λ�ý�����˸
#define FX_MODE_SPARKLE                 23   //��˸ģʽ���ƹ����һ����˸
#define FX_MODE_FLASH_SPARKLE           24   //������˸ģʽ����˸ʱ��������Ч��
#define FX_MODE_HYPER_SPARKLE           25   //������˸ģʽ����ǿ�ҵ���˸Ч��
#define FX_MODE_STROBE                  26   //Ƶ��ģʽ���ƹ������˸����Ƶ��Ч��
#define FX_MODE_STROBE_RAINBOW          27   //�ʺ�Ƶ��ģʽ��Ƶ��ʱ���ֲʺ���ɫ
#define FX_MODE_MULTI_STROBE            28   //����Ƶ��ģʽ�����Ƶ������ͬʱ����
#define FX_MODE_BLINK_RAINBOW           29   //�ʺ���˸ģʽ����˸ʱ���ֲʺ���ɫ
#define FX_MODE_CHASE_WHITE             30   //��ɫ׷��ģʽ����ɫ�ƹ����׷��Ч��
#define FX_MODE_CHASE_COLOR             31   //��ɫ׷��ģʽ����ɫ�ƹ����׷��Ч��
#define FX_MODE_CHASE_RANDOM            32   //���׷��ģʽ�������ɫ�ƹ����׷��
#define FX_MODE_CHASE_RAINBOW           33   //�ʺ�׷��ģʽ���ʺ���ɫ�ƹ����׷��
#define FX_MODE_CHASE_FLASH             34   //׷������ģʽ��׷��ʱ��������Ч��
#define FX_MODE_CHASE_FLASH_RANDOM      35   //���׷������ģʽ�������ɫ׷��ʱ����
#define FX_MODE_CHASE_RAINBOW_WHITE     36   //�ʺ��׷��ģʽ���ʺ����ɫ�ƹ���׷��
#define FX_MODE_CHASE_BLACKOUT          37   //Ϩ��׷��ģʽ���ƹ���׷���������Ϩ��Ч��
#define FX_MODE_CHASE_BLACKOUT_RAINBOW  38   //�ʺ�Ϩ��׷��ģʽ���ʺ�ƹ���׷��ʱ��Ϩ��Ч��
#define FX_MODE_COLOR_SWEEP_RANDOM      39   //�����ɫɨ��ģʽ�������ɫ��ɨ��һ��ɨ���ƹ�
#define FX_MODE_RUNNING_COLOR           40   //������ɫģʽ����ɫ��ˮ��һ���ڵƹ�������
#define FX_MODE_RUNNING_RED_BLUE        41   //��������ģʽ��������ɫ�ƹ���������
#define FX_MODE_RUNNING_RANDOM          42   //�������ģʽ�������ɫ�ƹ���������
#define FX_MODE_LARSON_SCANNER          43   //����ɭɨ��ģʽ���ƹ���ɨ����һ������ɨ�裬�����ڿƻ�Ч��
#define FX_MODE_COMET                   44   //����ģʽ���ƹ�������β��һ������
#define FX_MODE_FIREWORKS               45   //�̻�ģʽ���ƹ����̻�һ������
#define FX_MODE_FIREWORKS_RANDOM        46   //����̻�ģʽ���̻����ŵ�λ�ú���ɫ���
#define FX_MODE_MERRY_CHRISTMAS         47   //ʥ��ģʽ������ʥ������ĵƹ�Ч��������˸�ĲʵƵ�
#define FX_MODE_FIRE_FLICKER            48   //������˸ģʽ���ƹ������һ����˸
#define FX_MODE_FIRE_FLICKER_SOFT       49   //��ͻ�����˸ģʽ��������˸Ч�������
#define FX_MODE_FIRE_FLICKER_INTENSE    50   //ǿ�һ�����˸ģʽ��������˸Ч����ǿ��
#define FX_MODE_CIRCUS_COMBUSTUS        51   //��Ϸ�Ż���ģʽ��������Ϸ�ű����еĻ���Ч��
#define FX_MODE_HALLOWEEN               52   //��ʥ��ģʽ��������ʥ������ĵƹ�Ч���������顢�ϹϵƵ�
#define FX_MODE_BICOLOR_CHASE           53   //˫ɫ׷��ģʽ��������ɫ�ĵƹ����׷��
#define FX_MODE_TRICOLOR_CHASE          54   //��ɫ׷��ģʽ��������ɫ�ĵƹ����׷��
#define FX_MODE_TWINKLEFOX              55   //��˸��ģʽ���ƹ�������۾�һ����˸
#define FX_MODE_BLOCK_DISSOLVE          56   //�����ܽ�ģʽ���ƹ��񷽿�һ�����ܽ���ʧ
#define FX_MODE_ICU                     57   //��֢�໤ģʽ����������ҽԺ��֢�໤�ҵĵƹ�Ч��
#define FX_MODE_DUAL_LARSON             58   //˫������ɭģʽ����������ɭɨ�����ͬʱ����
#define FX_MODE_RUNNING_RANDOM2         59   //��һ���������ģʽ����RUNNING_RANDOM������ͬ
#define FX_MODE_FILLER_UP               60   //�������ģʽ���ƹ�ӵײ����������
#define FX_MODE_RAINBOW_LARSON          61   //�ʺ�����ɭģʽ������ɭɨ��������ֲʺ���ɫ
#define FX_MODE_TRIFADE                 62   //��ɫ����ģʽ��������ɫ֮���໥����
#define FX_MODE_HEARTBEAT               63   //����ģʽ���ƹ�������һ���н������˸
#define FX_MODE_VU_METER                64   //������ģʽ���ƹ����������С�仯�������������豸
#define FX_MODE_BITS                    65   //����ģʽ���ƹ�������Ʊ���һ����˸
#define FX_MODE_MULTI_COMET             66   //������ģʽ���������β��Ч��ͬʱ����
#define FX_MODE_FLIPBOOK                67   //��ҳ��ģʽ���ƹ���ҳ��һ�������л�Ч��
#define FX_MODE_POPCORN                 68   //���׻�ģʽ���ƹ����׻�һ���������
#define FX_MODE_OSCILLATOR              69   //����ģʽ���ƹ�������һ���й�
#define UFX_MODE_COMET1                 70   //��ɫ������ɨ��ɨȥ
#define UFX_MODE_COMET2                 71   //��ɫ������ɨ��ɨȥ
#define UFX_MODE_COMET3                 72   //��ɫ������ɨ��ɨȥ
#define MODE_MAX						73

//ѡ��Ķ���
#define NO_OPTIONS   (uint8_t)0x00   //û���κ�ѡ����á�
#define REVERSE      (uint8_t)0x80   //������תѡ�������������λ�����������򲥷�
#define FADE_XFAST   (uint8_t)0x10  //��Щ�궨���˲�ͬ����ɫ���ʣ�fade rate�����Ӽ��죨FAST����������GLACIAL����ÿ���궨���˲�ͬ��λģʽ���������� LED �ε���ɫ���ʡ�
#define FADE_FAST    (uint8_t)0x20
#define FADE_MEDIUM  (uint8_t)0x30
#define FADE_SLOW    (uint8_t)0x40
#define FADE_XSLOW   (uint8_t)0x50
#define FADE_XXSLOW  (uint8_t)0x60
#define FADE_GLACIAL (uint8_t)0x70
#define GAMMA        (uint8_t)0x08   //����٤��У��ѡ�������������λ��LED ����ɫ��Ӧ��٤��У����
#define SIZE_SMALL   (uint8_t)0x01  //��Щ�궨���˶εĴ�Сѡ���С�ͣ�SMALL���������ͣ�XLARGE����ÿ���궨���˲�ͬ��λģʽ���������� LED �εĴ�С��
#define SIZE_MEDIUM  (uint8_t)0x02
#define SIZE_LARGE   (uint8_t)0x04
#define SIZE_XLARGE  (uint8_t)0x06


/*
* ��ȡ�����ư������״̬��
* �����		�Ѿ����ӷ���1��û�����ӷ���0��
*/
LIBRARY_API int extLight_connect_state(void);

/*
* ��ʼ�������ư�Ķ˿ڡ�
* port��		exLight�Ķ˿ڣ�0-6��Port1-Port7
* lednum��		led����������
* ledtype:		led����:NEO_RGB - NEO_BGRW
* segmentnum:		��������0-255
* �����		�ɹ�����1��ʧ�ܷ���0
*/
LIBRARY_API int exLight_port_init(extLight_portEnum port,uint8_t lednum, uint8_t ledtype, uint8_t segmentnum, uint8_t bright);

/*
* ��ֹextLight �˿� ���¡�
* port��		exLight�Ķ˿ڣ�0-6��Port1-Port7
* �����		�ɹ�����1��ʧ�ܷ���0
*/
LIBRARY_API int exLight_port_disable(extLight_portEnum port);

/*
* ʹ��extLight �˿� ���¡�
* port��		exLight�Ķ˿ڣ�0-6��Port1-Port7
* �����		�ɹ�����1��ʧ�ܷ���0
*/
LIBRARY_API int exLight_port_enable(extLight_portEnum port);

/*
*  ���ù̶���ɫ��,�����þ���Ĭ�ϵ�
*  ��ɫ���� RED -  GRAY �� FixedColor_Max����ɫ��ɣ�ÿ����ɫ��4��������B��G��R��W
* colorTable:	extLight_colorTableType���͵���ɫ��ָ�롣
* �����		�ɹ�����1��ʧ�ܷ���0
*/
LIBRARY_API int extLight_colorTab_set(extLight_colorTableType* colorTable);

/*
*  ���õƹ�ģʽ
* port��		exLight�Ķ˿ڣ�0-6��Port1-Port7
* segment:		�κ�
* ledstart:     led��ʼ���0-255
* ledstart:     led�������0-255
* mode:			�ƹ�ģʽ NEO_RGB - NEO_BGRW
* color1:		0-11��RED - GRAY
* color2:		0-11��RED - GRAY
* color3:		0-11��RED - GRAY
* speed:		�ٶ�0-255
* �����		�ɹ�����1��ʧ�ܷ���0
*/
LIBRARY_API int extLight_mode_set(extLight_portEnum port,uint8_t segment,uint8_t ledstart,uint8_t ledend,uint8_t mode,
	uint8_t color1, uint8_t color2, uint8_t color3,uint8_t speed,uint8_t option);

/*
*  �������ݵ�flash
* block��		Ҫ�洢����flash�Ŀ����ţ�0-255
* flame			�ж���֡���棺0-255
* line:			�ж����У�0-255
* column:		�ж����У�0-255
* color:		ָ����ɫ�����ָ�롣��ɫ����Ĵ�СΪflame * line * column * 4
* �����		�ɹ�����1��ʧ�ܷ���0
*/
LIBRARY_API int extLight_flash_save(uint8_t block,uint8_t flame, uint8_t line, uint8_t column, extLight_colorType* colorbuff);

/*
*  ��ȡflash���ݵ�ָ���˿�
* port��		exLight�Ķ˿ڣ�0-6��Port1-Port7
* sector��		flash�������ţ�0-4095
* line:			�ж����У�0-255
* column:		�ж����У�0-255
* color:		ָ����ɫ�����ָ��
* �����		�ɹ�����1��ʧ�ܷ���0
*/
LIBRARY_API int extLight_flash_read(uint8_t port, uint8_t block);

/*
*��ȡextLight �̼��汾��
* �����char�ַ�����ʼ��ַ
*/
LIBRARY_API char* exLight_software_version(void);


/*
*��ȡextLight Ӳ����PCB���汾��
* �����char�ַ�����ʼ��ַ
* 
*/
LIBRARY_API char* exLight_hardware_version(void);



