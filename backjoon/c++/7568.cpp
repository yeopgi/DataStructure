#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int manCnt;
    cin >> manCnt;
    vector<pair<int, int>> manData(manCnt);
    int rank[manData.size()];
    for (int i = 0; i < manCnt; i++) {
        cin >> manData[i].first >> manData[i].second;
        rank[i] = 1;
    }

    for (int i = 0; i < manCnt; i++) {
        for (int j = 0; j < manCnt; j++) {
            if (manData[i].first < manData[j].first && manData[i].second < manData[j].second) {
                rank[i]++;
            }
        }
    }

    for (int i = 0; i < manCnt; i++) {
        cout << rank[i] << ' ';
    }

    return 0;
}