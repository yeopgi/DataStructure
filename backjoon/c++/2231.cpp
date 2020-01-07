#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int inputNum;
    cin >> inputNum;
    int num = 1;
    while(true) {
        int min = num;    
        int quotient = num;                           // 몫
        while(quotient) {
            min += quotient % 10;
            quotient = quotient / 10;
        }

        if(num == inputNum || min == inputNum) {
            break;
        }

        num++;
    }

    if(num == inputNum) {
        cout << 0 << '\n';
    } else {
        cout << num << '\n';
    }

    return 0;
}