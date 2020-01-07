#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    vector<string> v = {{"-1"},{"-1"},{"-1"},{"ABC"},{"DEF"},{"GHI"},{"JKL"},{"MNO"},{"PQRS"},{"TUV"},{"WXYZ"}};
    int sum = 0;    
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if(v[j].find(str[i]) != string::npos) {
                sum += j;
            }
        }
    }

    cout << sum << '\n';
    return 0;
}