#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;
    if (num == 1) {
        cout << 1 << '\n';
        return 0;
    }

    int sum = 0;
    for (int i = 1; ; i++) {
        sum += 6 * i;
        if (num <= sum + 1) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    return 0;
}