#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    for(int i = 'a'; i <= 'z'; ++i) 
    {
            int idx = 0;
            for(char c : str) 
            {
                if(c == i)
                {
                    cout << idx << ' ';
                    break;
                }
                
                ++idx;
            }

            if(idx == str.size()) 
            {
                cout << -1 << ' ';
            }
    }

    return 0;
}