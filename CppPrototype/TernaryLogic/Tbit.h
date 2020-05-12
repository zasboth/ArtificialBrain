#ifndef TBIT_H
#define TBIT_H

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
	Tbit(const Tbit &b);
	Tbit(Tbit &&b);
	Tbit(double a);
	Tbit(double a, double treshold);
	Tbit(TernaryBit bit_);
	~Tbit();

	TernaryBit compare(const Tbit &val);
	TernaryBit getBit();
	double getTreshold();
	void setTreshold(double value);

	Tbit &operator=(const double &a);
	Tbit &operator=(const Tbit &a);
	Tbit &operator=(const TernaryBit &a);
	operator TernaryBit();
	bool operator==(const Tbit &operand);
	bool operator!=(const Tbit &operand);
	bool operator==(const TernaryBit &operand);
	bool operator!=(const TernaryBit &operand);
	Tbit operator!();
};

#endif
