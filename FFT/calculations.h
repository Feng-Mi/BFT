#pragma once
#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_
#include <complex>// библиотека комплексных чисел
#include <vector> // библиотека для подключения динамических массивов,находящихся в пространстве std
#include "etype.h"

typedef f64_t complex_inner_t;//объявим псевдоним типа 64_t именнованный как complex_inner_t
typedef std::complex<complex_inner_t> complex_t;//создадим псевдоним для стандартного класса complex,указав в качестве параметра шаблона complex_inner_t

using std::vector;

vector<complex_t> GetComplexFromF64(const vector<f64_t>&);//функция ДПФ
vector<complex_t> GetComplexFromF64Fast(const vector<f64_t>&);//функция БПФ


#endif // !_CALCULATIONS_H_
