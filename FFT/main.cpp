#include <iostream>
#include <conio.h>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

#include "etype.h"
#include "calculations.h"

using namespace std;

#define FS (14000)
#define TS (1.0 / FS)
#define SZ (1400)

typedef f64_t(*_base)(const u64_t&);

vector<f64_t> feed(const size_t& n, _base base);
void out(std::ostream& out, const vector<complex_t>& vec);


f64_t fbase(const u64_t& arg) {
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

	auto src = feed(SZ, fbase);
	auto fftresult = GetComplexFromF64Fast(src);

	cout << "fbase 1:" << endl;
	out(cout, fftresult);

	src = feed(SZ, fbase2);
	fftresult = GetComplexFromF64Fast(src);
	cout << endl;
	cout << "fbase 2:" << endl;
	out(cout, fftresult);

	_getch();
	return 0;
}


vector<f64_t> feed(const size_t& n, _base base) {

	vector<f64_t> out;

	for (register size_t t = 0; t < n; t++)
		out.push_back(base(t));

	return out;
}

void out(std::ostream& out, const vector<complex_t>& vec) {

	cout << "Complex value output:\n\n";

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