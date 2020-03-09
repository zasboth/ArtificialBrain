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
        void calcBit(int a, unsigned int treshold);

    public:
        Tbit();
        Tbit( int a);
        Tbit( int a, unsigned int treshold);
        Tbit(TernaryBit bit_): bit(bit_){};
        ~Tbit();

        Tbit compare(const Tbit val);
        TernaryBit getBit() {return bit;}

        Tbit operator= (const int& a);
        Tbit operator= (const Tbit& a);
        Tbit operator= (const TernaryBit& a);
        bool operator== (const Tbit& operand);
        bool operator!= (const Tbit& operand); 
        Tbit operator! ();
};

#endif