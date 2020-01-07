#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int wordCnt = 0;
    int testWord;
    cin >> testWord;
    cin.ignore();

    while (testWord--) {
        bool flag = true;
        string str;
        cin >> str;
        for (int i = 1; i < str.size(); i++) {
            if (str[i - 1] != str[i]) {
                for (int j = 0; j < i; j++) {
                    if(str[i] == str[j]) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag == false) {
                break;
            }
        }

        if (flag == true) {
            wordCnt++;
        }
    }

    cout << wordCnt << '\n';
    return 0;
}