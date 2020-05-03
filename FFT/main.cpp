#include <iostream> // файл с классами, функциями и переменными для организации ввода-вывода
#include <conio.h> // файл,для создания текстового интерфейса пользователя
#include <vector>

#define _USE_MATH_DEFINES //vатематические константы не определены в стандартных библиотеках
#include <math.h>

#include "etype.h"
#include "calculations.h"

using namespace std; // использовать пространство имен std

#define FS (14000)
#define TS (1.0 / FS)
#define SZ (1400)

typedef f64_t(*_base)(const u64_t&);

vector<f64_t> feed(const size_t& n, _base base);
void out(std::ostream& out, const vector<complex_t>& vec);


f64_t fbase(const u64_t& arg) { //внесение параметров гармоник сигналов в соответствующие функции 
	return 5 * cos(2 * M_PI * 1200 * arg * TS + M_PI_2) +
		2.5 * cos(2 * M_PI * 4000 * arg * TS + M_PI_2) +
		cos(2 * M_PI * 11000 * arg * TS + M_PI_4);
}

f64_t fbase2(const u64_t& arg) {
	return 5 * cos(2 * M_PI * 1200 * arg * TS + M_PI_2) +
		3 * cos(2 * M_PI * 4995 * arg * TS + M_PI_2) +
		cos(2 * M_PI * 11985 * arg * TS + M_PI_4);
}

int main() {

	auto src = feed(SZ, fbase);//заполянем вектор дискретными значениями функции fbase
	auto fftresult = GetComplexFromF64Fast(src);//вызываем функцию для получения комплексных значений БПФ

	cout << "fbase 1:" << endl; //вывода данных в консольное окно,каждый раз с новой строки
	out(cout, fftresult);//вызываем функцию out,передавая в качестве первого параметра стандартный поток вывода,а в качестве второго вектор модифицированных значений

	src = feed(SZ, fbase2);//заполянем вектор дискретными значениями функции fbase2
	fftresult = GetComplexFromF64Fast(src);//вызываем функцию для получения комплексных значений БПФ
	cout << endl;
	cout << "fbase 2:" << endl;
	out(cout, fftresult);//вызываем функцию out,передавая в качестве первого параметра стандартный поток вывода,а в качестве второго вектор модифицированных значений

	_getch(); // возвращает один символ, прочитанный с клавиатуры,без его отображения
	return 0;
}


vector<f64_t> feed(const size_t& n, _base base) {//заполняет вектор данных

	vector<f64_t> out;

	for (register size_t t = 0; t < n; t++)
		out.push_back(base(t));

	return out;
}

void out(std::ostream& out, const vector<complex_t>& vec) { //данные будут выведены в консоль через эту функцию, вначале как комплексные отсчеты, а затем, как амплитуды и фазы

	cout << "Complex values output:\n\n";

	for (auto c : vec)
		cout << c << endl;

	cout << "\n\nAmplitudes:\n\n";

	for (auto c : vec) {
		cout << 2.0 * std::abs(c) / (vec.size()) << endl;
	}

	cout << "\n\nPhases:\n\n";

	for (auto c : vec) {
		cout << std::arg(c) / M_PI * 180.0 << endl;
	}

	cout << endl;
}