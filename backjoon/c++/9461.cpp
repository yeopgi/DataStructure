#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    while (test--) {
        long long d[101] = {0};
        d[0] = 1, d[1] = 1, d[2] = 1, d[3] = 1;
        int input;
        cin >> input;
        for (int i = 4; i <= input; i++) {
            d[i] = d[i - 2] + d[i - 3];
        }

        cout << d[input] << '\n';
    }

    return 0;
}