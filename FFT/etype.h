#pragma once // препроцессорна€ директива, разработанна€ дл€ контрол€ за тем, чтобы конкретный исходный файл при компил€ции подключалс€ строго один раз
#ifndef ETYPE_H // библиотечный файл,содержащий объ€влени€ типов //конструкци€ #ifndef/#endif тоже самое,что pragma once,но добавлено дл€ совместимости с различными верси€ми разничных компил€торов
#define ETYPE_H

typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;
typedef unsigned long long u64_t;

typedef signed char s8_t;
typedef signed short s16_t;
typedef signed int s32_t;
typedef signed long long s64_t;

typedef float f32_t;
typedef double f64_t;

#define EPS (.0000000001) // определ€ем машинный эпсилон

#endif // !ETYPE_H 
