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
    vector<string> v = {{"c="}, {"c-"}, {"dz="}, {"d-"}, {"lj"}, {"nj"}, {"s="}, {"z="}};
    int alphabetCnt = 0;
    int wordIdx = 0;
    while (wordIdx < str.size()) {
        for (int i = 0; i < v.size(); i++) {
            if (str.substr(wordIdx, v[i].size()) == v[i]) {
                alphabetCnt++;
                wordIdx += v[i].size();
                break;
            }

            if (i == v.size() - 1) {
                wordIdx++;
                alphabetCnt++;
            }
        }
    }

    cout << alphabetCnt << '\n';
    return 0;
}
