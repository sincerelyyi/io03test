#pragma once
#include <stdint.h>

#ifdef DLLLIBRARY_EXPORTS  
#define LIBRARY_API extern "C" __declspec(dllexport)  
#elif  DLLLIBRARY_INPORTS
#define LIBRARY_API extern "C" __declspec(dllimport)
#else
#define LIBRARY_API extern	
#endif  



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

LIBRARY_API char* get_hardware(void);
LIBRARY_API char* get_software(void);
LIBRARY_API char* get_production_date(void);
LIBRARY_API char* get_uid(void);
LIBRARY_API uint16_t get_counter(uint8_t counter_id);
LIBRARY_API void set_counter(uint8_t counter_id, uint16_t counter_num);
LIBRARY_API uint16_t get_coin();
LIBRARY_API uint16_t decrease_coins(uint16_t coins); //返回实际扣币数。

LIBRARY_API uint8_t get_mcu_temperature(void);
LIBRARY_API uint8_t get_mcu_voltage(void);
LIBRARY_API uint8_t get_battery_voltage(void);
LIBRARY_API bool get_key(uint8_t key_id);
LIBRARY_API uint8_t get_adc(uint8_t adc_id);

LIBRARY_API void set_pwm(uint8_t pwm_id, uint8_t type, uint8_t interval, uint8_t bright);
LIBRARY_API void set_outPin(uint8_t out_id, bool level);
LIBRARY_API bool stop_monitoring();

