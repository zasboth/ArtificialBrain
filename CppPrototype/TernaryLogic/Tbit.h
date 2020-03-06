 
enum TernaryBit : signed char{
    TRUE = 1,
    MAIBY = 0,
    FALSE = -1
};

struct Tbit
{
    private: 
        TernaryBit bit;

    public:
        Tbit();
        Tbit( int a);
        Tbit(TernaryBit bit_);

        Tbit& operator= (const int& a);
        Tbit& operator= (const Tbit& a);
        Tbit& operator== (const Tbit& operand);
        Tbit& operator!= (const Tbit& operand); 
        Tbit& operator! ();
};
