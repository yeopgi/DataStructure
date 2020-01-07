#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string testStr;
    cin >> testStr;
    int alphabetCnt[26] = {0};
    int max = 0,
        maxIdx = 0;

    for (int i = 0; i < testStr.size(); i++) {
        if (testStr[i] > 90) {
            testStr[i] = toupper(testStr[i]);
        }

        alphabetCnt[testStr[i] - 65]++;
        if (max < alphabetCnt[testStr[i] - 65]) {
            max = alphabetCnt[testStr[i] - 65];
            maxIdx = testStr[i] - 65;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alphabetCnt[i] == alphabetCnt[maxIdx] && maxIdx != i) {
            cout << '?' << '\n';
            return 0;
        }
    }

    cout << (char)(maxIdx + 65) << '\n';
    return 0;
}