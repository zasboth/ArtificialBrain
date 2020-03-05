#include "Tbit.h"

Tbit::Tbit(int a)
{
    switch (a)
    {
    case 1:
        bit = TRUE;
        break;
    case 0:
        bit = MAIBY;
        break;
    case -1:
        bit = FALSE;
        break;
    default:
        throw "Not a valid walue for ternary bit!!!";
    }
}

Tbit &Tbit::operator=(const int &a)
{
    return Tbit(a);
}
