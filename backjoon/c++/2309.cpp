#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    int dwarf[9] = {0};
    int dwarfSum = 0;
    for(int i = 0; i < 9; i++) {
        scanf("%d", &dwarf[i]);
        dwarfSum += dwarf[i];
    }

    sort(dwarf, dwarf + 9);

    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 9; j++) {
            if(dwarfSum - dwarf[i] - dwarf[j] == 100) {
                for(int k = 0; k < 9; k++) {
                    if(k == i || k == j) {
                        continue;
                    }

                    printf("%d\n", dwarf[k]);
                }

                return 0;
            }
        }
    }

    return 0;
}