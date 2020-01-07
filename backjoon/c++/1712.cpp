#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int cost;
    cost = C - B;               // 순수익
    if (cost <= 0) {
        cout << "-1" << endl;
    } else {
        cout << A / cost + 1;   // 순수익으로 고정비용 처리단계
    }

    return 0;
}
