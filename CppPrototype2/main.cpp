#include "Ternary/TernaryBit.hpp"
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    TernaryBit::Digits d{TernaryBit::FALSE};

    TernaryBit::BIT b = d;

    TernaryBit tb{b};

    cout << "high: " << d.HighBit << " low: " << d.LowBit << endl;
    cout << "Bit: " << static_cast<int>(b) << endl;
    cout << tb << endl;

    bitset<8> bs;
    bs[0] = tb.low();
    bs[1] = tb.high();

    cout << bs << endl;
}