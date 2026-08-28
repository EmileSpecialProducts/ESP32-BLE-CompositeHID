#if !defined ESP32_ARDUINO_MATH_H
#define ESP32_ARDUINO_MATH_H

#ifndef LED_BUILTIN
#define LED_BUILTIN 2    
#endif

#define abs(x) ((x)>0?(x):-(x))
#if !defined constrain
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#endif
#if !defined round
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#endif
#if !defined radians
#define radians(deg) ((deg)*DEG_TO_RAD)
#endif
#if !defined degrees
#define degrees(rad) ((rad)*RAD_TO_DEG)
#endif
#if !defined sq
#define sq(x) ((x)*(x))
#endif

#if !defined lowByte
#define lowByte(w) ((uint8_t) ((w) & 0xff))
#endif
#if !defined highByte
#define highByte(w) ((uint8_t) ((w) >> 8))
#endif
#if !defined bitRead
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#endif
#if !defined bitSet
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#endif
#if !defined bitClear
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#endif
#if !defined bitToggle
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#endif
#if !defined bitWrite   
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))
#endif
#endif