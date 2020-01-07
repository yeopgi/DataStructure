#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sequence;
    cin >> sequence;
    int dp[1000000 + 1];
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= sequence; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] = dp[i] % 15746;
    }

    cout << dp[sequence] % 15746 << '\n';
}