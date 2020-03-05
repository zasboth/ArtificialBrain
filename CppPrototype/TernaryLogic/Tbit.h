 
enum TernaryBit : signed char{
    TRUE = 1,
    MAIBY = 0,
    FALSE = -1
};

struct Tbit
{
    TernaryBit bit;

    Tbit( int a);
    
    Tbit& operator= (const int& a);

    bool& operator== (const Tbit& operand);

    bool& operator!= (const Tbit& operand);

    Tbit& operator! ();
};
