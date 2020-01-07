#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int sequenceCnt = 0;
    int sumList[s.size()/2 + 1] = {0};
    for(int i = 1 ; i < s.size() / 2; i++) {
        string prev = s.substr(0,i);
        cout << "prev prev : " << prev << endl;
        int length = 0;
        for(int j = i; j <= s.size(); j += i) {
            cout << "substr : " << s.substr(j, i) << endl;
			if (s.substr(j, i) == prev) {
                sequenceCnt++;
            } else {
                if(sequenceCnt > 1) {
                    length += 2;
                } else {
                    length += 1;
                }
                
                sequenceCnt = 0;
            }    
            prev = s.substr(j,i);
        	cout << "post prev : " << prev << endl;
        }
        sumList[i] = length;
    }
    
    sort(sumList, sumList + s.size());
    return sumList[1];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    cout << solution(str) << '\n';

    return 0;
}