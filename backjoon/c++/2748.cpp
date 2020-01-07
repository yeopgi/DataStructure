#include <iostream>
using namespace std;

int main(void)
{
    int idx;
    cin >> idx;
    long long fibo[91] = {0};
    fibo[0] = 0, fibo[1] = 1;
    for (int i = 2; i <= idx; i++) {
        fibo[i] = fibo[i -1] + fibo[i - 2];
    }

    cout << fibo[idx];
    return 0;
}