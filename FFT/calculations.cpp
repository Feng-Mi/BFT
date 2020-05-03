#include "calculations.h"

#define _USE_MATH_DEFINES
#include <math.h> //файл библиотеки,разработанный для выполнения простых математических операций,в большинстве своем над числами с плавающей точкой

using namespace std::complex_literals;

vector<complex_t> GetComplexFromF64(const vector<f64_t>& src) { //Функция ДПФ

	complex_inner_t carg;
	complex_t acc;
	vector<complex_t> out;

	auto s_size = src.size();

	for (size_t m = 0; m < s_size; m++) {
		for (register size_t n = 0; n < s_size; n++) {
			carg = 2.0 * M_PI * n * m / s_size; // непосредственно алгоритм ДПФ
			acc += src[n] * (cos(carg) - 1i * sin(carg));
		}

		out.push_back(acc);
		acc = 0;
	}

	return out;
}


static inline void TransformFast(vector<complex_t>& src) {//функция помечена как static inline,потому что ее область видимости ограничена файлом calculations.cpp

	size_t sz, hsz;
	sz = src.size();

	if (sz == 1) {
		return;
	}

	if (sz & 1) { // если число точек стало отличным от 2^n,то функция передает данные в функцию ДПФ,т.к передается малое количество отсчетов,то на скорость преобразоания это влияет незначительно

		vector<f64_t> dft;
		dft.resize(sz);

		for (register size_t t = 0; t < sz; t++) {
			dft[t] = src[t].real();
		}

		src = GetComplexFromF64(dft);

		return;
	}

	hsz = sz >> 1;

	vector<complex_t> even(hsz), odd(hsz);

	for (size_t i = 0,
		j = 0; i < sz; i += 2, j++) {

		even[j] = src[i];
		odd[j] = src[i + 1];
	}

	TransformFast(odd); //функция рекурсивно вызвает себя,пока число точек соответствует 2^n
	TransformFast(even);

	f64_t arg = 2 * M_PI / sz;
	complex_t w(1), wn(cos(arg), -sin(arg));

	for (size_t i = 0; i < hsz; i++) {
		src[i] = even[i] + w * odd[i];// непосредственно алгоритм БПФ
		src[i + hsz] = even[i] - w * odd[i];

		w *= wn;
	}

}

vector<complex_t> GetComplexFromF64Fast(const vector<f64_t>& src) {//для совместимости типов входных данных,функция преобразует формат dooble в формат с плавающей точкой

	vector<complex_t> out;

	for (auto f : src) {
		out.push_back(f);
	}

	TransformFast(out);

	return out;
}