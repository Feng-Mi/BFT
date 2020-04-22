#pragma once
#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_
#include <complex>
#include <vector>
#include "etype.h"

typedef f64_t complex_inner_t;
typedef std::complex<complex_inner_t> complex_t;

using std::vector;

vector<complex_t> GetComplexFromF64(const vector<f64_t>&);
vector<complex_t> GetComplexFromF64Fast(const vector<f64_t>&);


#endif // !_CALCULATIONS_H_
