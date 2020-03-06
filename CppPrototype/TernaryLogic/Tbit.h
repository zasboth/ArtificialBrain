 
enum TernaryBit : signed char{
    TRUE = 1,
    MAIBY = 0,
    FALSE = -1
};

struct Tbit
{
    private TernaryBit bit;

    public Tbit( int a);

    public Tbit(TernaryBit bit_);
    
    public Tbit& operator= (const int& a);

    public Tbit& operator= (const Tbit& a);

    public bool& operator== (const Tbit& operand);

    public bool& operator!= (const Tbit& operand);

    public Tbit& operator! ();
};
