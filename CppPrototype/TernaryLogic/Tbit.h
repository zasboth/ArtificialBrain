#ifndef TBIT_H
#define TBIT_H

#include <vector>

enum TernaryBit : signed char {
	TRUE = 1, MAIBY = 0, FALSE = -1
};

union uTernaryBit {
	TernaryBit tb;
	signed char numeric;
};

struct Tbit {
private:
	TernaryBit bit;
	double treshold = 0;
	void calcBit(double a);

public:
	Tbit();
	Tbit(double a);
	Tbit(double a, double treshold);
	Tbit(TernaryBit bit_);
	~Tbit();

	TernaryBit compare(const Tbit &val);
	TernaryBit getBit();
	double getTreshold();
	void setTreshold(double value);
	char to_char();
	void from_char(char c);

	Tbit& operator=(const double &a);
	Tbit& operator=(const TernaryBit &a);
	operator TernaryBit();
	bool operator==(const Tbit &operand);
	bool operator!=(const Tbit &operand);
	bool operator==(const TernaryBit &operand);
	bool operator!=(const TernaryBit &operand);
	Tbit operator!();
};

typedef std::vector<Tbit> TernaryBitArray;

#endif
