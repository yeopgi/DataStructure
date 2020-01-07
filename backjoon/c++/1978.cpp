#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCnt;
    cin >> testCnt;
    int primeCnt = testCnt;
    int test[100] = {0};
    for (int i = 0; i < testCnt; i++) {
        cin >> test[i];
        if(test[i] <= 1) {
            primeCnt--;
            continue;
        }

        for (int j = 2; j * j<= test[i]; j++) {
            if(test[i] % j == 0) {
                primeCnt--;
                break;
            }
        }
    }

    cout << primeCnt;
    return 0;
}