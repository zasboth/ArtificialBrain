#ifndef TBIT_H
#define TBIT_H

enum TernaryBit : signed char{
    TRUE = 1,
    MAIBY = 0,
    FALSE = -1
};

struct Tbit
{
    private: 
        TernaryBit bit;
        double treshold = 0;
        void calcBit(double a);

    public:
        Tbit();
        Tbit( double a);
        Tbit( double a, double treshold);
        Tbit(TernaryBit bit_): bit(bit_){};
        ~Tbit();

        TernaryBit compare(const Tbit val);
        TernaryBit getBit() {return bit;}
        double getTreshold() {return treshold;}
        void setTreshold(double value);

        Tbit operator= (const double& a);
        Tbit operator= (const Tbit& a);
        Tbit operator= (const TernaryBit& a);
        bool operator== (const Tbit& operand);
        bool operator!= (const Tbit& operand);
        bool operator== (const TernaryBit& operand);
        bool operator!= (const TernaryBit& operand);
        Tbit operator! ();
};

#endif
