#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    cin.ignore();
    while(testCase--)
    {
        string str;
        getline(cin, str);
        int repeat = static_cast<int>(str[0] - '0');
        for(int i = 2; i < str.size(); i++)
        {
            while(repeat--)
            {
                cout << str[i];
            }

            repeat = static_cast<int>(str[0] - '0');
        }
        cout << '\n';
    }

    return 0;
}
