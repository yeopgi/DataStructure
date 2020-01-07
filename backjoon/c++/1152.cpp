#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    if (str == " " || str == "") {
        cout << 0 << endl;
        return 0;
    }
    
    int wordCnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            if (i == 0 || i == str.size() - 1) {
                continue;
            }
            wordCnt++;
        }
    }

    cout << wordCnt + 1 << endl;
    return 0;
}