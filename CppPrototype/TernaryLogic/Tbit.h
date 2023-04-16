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
	explicit Tbit(double a);
	Tbit(double a, double treshold);
	explicit Tbit(TernaryBit bit_);
	virtual ~Tbit();

	TernaryBit compare(const Tbit &val);
	TernaryBit compare(const TernaryBit &val);
	TernaryBit getBit();
	double getTreshold();
	void setTreshold(double value);
	char to_char();
	void from_char(char c);

	operator double();
	Tbit& operator=(double a);
	Tbit& operator=(const TernaryBit &a);
	bool operator==(const Tbit &operand);
	bool operator!=(const Tbit &operand);
	bool operator==(const TernaryBit &operand);
	bool operator!=(const TernaryBit &operand);
	Tbit operator!();
};

typedef std::vector<Tbit> TernaryBitArray;

#endif
