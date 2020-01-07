#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    while (testCase--) {
        int apt[15][15] = {0};
        for (int i = 1; i < 15; i++) {
            apt[0][i] = i;
        }
        int height, room;
        cin >> height;
        cin >> room;

        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= room; j++) {
                for (int k = 1; k <= j; k++) {
                    apt[i][j] += apt[i - 1][k];
                }
            }
        }

        cout << apt[height][room] << '\n';
    }

    return 0;
}