#include <bits/stdc++.h>
using namespace std;

int main() {

    int x = 10;   // Binary: 1010
    int k = 2;    // We will operate on bit index k=2

    cout << "=== LEFT SHIFT (<<) ===\n";
    cout << "x = " << x << "  (binary 1010)\n";
    cout << "x << 1 = " << (x << 1) << "   --> multiplies by 2 (shifts bits left)\n";
    cout << "x << 2 = " << (x << 2) << "   --> multiplies by 4 (shifts bits left twice)\n\n";

    cout << "=== RIGHT SHIFT (>>) ===\n";
    cout << "x >> 1 = " << (x >> 1) << "   --> divides by 2 (shifts bits right)\n";
    cout << "x >> 2 = " << (x >> 2) << "   --> divides by 4 (shifts bits right twice)\n\n";

    cout << "=== BIT MASK USING (1 << k) ===\n";
    cout << "(1 << k) where k=2 = " << (1 << k)
         << "   --> creates a mask with only bit 2 set (binary 100)\n\n";

    cout << "=== CHECKING IF BIT k IS ON ===\n";
    cout << "Expression: x & (1 << k)\n";
    if(x & (1 << k))
        cout << "Bit " << k << " is ON\n";
    else
        cout << "Bit " << k << " is OFF\n";
    cout << "--> This checks if bit k contains a 1.\n\n";

    cout << "=== SETTING BIT k ===\n";
    int a = x | (1 << k);   // force bit k to become 1
    cout << "x | (1 << k) = " << a
         << "   --> turns bit " << k << " ON\n\n";

    cout << "=== CLEARING BIT k ===\n";
    int b = x & ~(1 << k);  // force bit k to become 0
    cout << "x & ~(1 << k) = " << b
         << "   --> turns bit " << k << " OFF\n";
    cout << "--> ~(1 << k) creates a mask where only bit k is 0, all others are 1.\n\n";

    cout << "=== TOGGLING BIT k ===\n";
    int c = x ^ (1 << k);   // flip bit k
    cout << "x ^ (1 << k) = " << c
         << "   --> flips bit " << k << " (0->1 or 1->0)\n\n";

    cout << "=== COUNTING SET BITS ===\n";
    cout << "__builtin_popcount(x) = " << __builtin_popcount(x)
         << "   --> number of 1-bits in x\n\n";

    cout << "=== LAST BIT OF x ===\n";
    cout << "x & 1 = " << (x & 1)
         << "   --> extracts last (least significant) bit\n\n";

    cout << "=== MULTIPLY & DIVIDE USING SHIFTS ===\n";
    cout << "x << 3 = " << (x << 3) << "   --> x * 8 (fast multiply)\n";
    cout << "x >> 2 = " << (x >> 2) << "   --> x / 4 (fast divide)\n\n";

    return 0;
}
