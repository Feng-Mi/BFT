#pragma once // препроцессорная директива, разработанная для контроля за тем, чтобы конкретный исходный файл при компиляции подключался строго один раз
#ifndef ETYPE_H // библиотечный файл,содержащий объявления типов //#ifndef если определено
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

#define EPS (.0000000001) // присваеваем константе точность и формат с плавающей точкой

#endif // !ETYPE_H //если не определено
