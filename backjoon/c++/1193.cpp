#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int inputIdx;
    cin >> inputIdx;
    if (inputIdx == 1) {
        cout << "1/1" << 'n';
        return 0;
    }

    int fractionIdx = 1, denominator = 0, numerator = 0; // denominator -> 분모, numerator -> 분자
    for (int i = 2;; i++) {
        if (i % 2 == 0) {
            denominator = i;
            numerator = 1;
            for (int j = 0; j < i; j++) {
                fractionIdx++;
                if (fractionIdx == inputIdx) {
                    cout << numerator << "/" << denominator;
                    return 0;
                }

                denominator--;
                numerator++;
            }
        } else {
            denominator = 1;
            numerator = i;
            for (int j = 0; j < i; j++) {
                fractionIdx++;
                if (fractionIdx == inputIdx) {
                    cout << numerator << "/" << denominator;
                    return 0;
                }

                denominator++;
                numerator--;
            }
        }
    }
    return 0;
}