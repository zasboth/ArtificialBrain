#include "Ternary/TernaryBit.hpp"
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    TernaryBit::Digits d{TernaryBit::FALSE};

    TernaryBit::BIT b = d;

    TernaryBit tb{b};
    

    std::cout << "high: " << d.HighBit << " low: " << d.LowBit << endl;
    std::cout << "Bit: " << static_cast<int>(b) << endl;
    std::cout << tb << endl;
    
    double d2 = -12;
    TernaryBit tb2(d2);
    std::cout << tb2 << endl;

    bitset<8> bs;
    bs[0] = tb.low();
    bs[1] = tb.high();

    cout << bs << endl;
}