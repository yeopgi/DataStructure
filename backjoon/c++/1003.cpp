#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int dp[41][2] = {0};
    dp[0][0] = 1;
    dp[0][1] = 0;
    int caseCnt;
    cin >> caseCnt;
    while (caseCnt--) {
        int inputNum;
        cin >> inputNum;
        if (inputNum == 0) {
            cout << dp[0][0] << " " << dp[0][1] << '\n';
            continue;
        }

        for (int i = 1; i < 41; i++) {
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] = dp[i - 1][1];
        }

        cout << dp[inputNum][0] << " " << dp[inputNum][1] << '\n';
    }

    return 0;
}