#include <iostream>
using namespace std;

int main() {
    int cnt, sum;
    int list[100];
    cin >> cnt >> sum;
    int result = 0;
    for (int i = 0; i < cnt; i++)
        cin >> list[i];

    for (int i = 0; i < cnt - 2; i++) {
        for (int j = i + 1; j < cnt - 1; j++) {
            for (int k = j + 1; k < cnt; k++) {
                if (list[i] + list[j] + list[k] <= sum && list[i] + list[j] + list[k] > result) {       // 넘지않는다 && 최대한 가까우면서
                    result = list[i] + list[j] + list[k];
                }
            }
        }
    }
    cout << result;
}