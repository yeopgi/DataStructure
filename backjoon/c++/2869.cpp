#include <cstdio>
#include <iostream>
using namespace std;

int main(void)
{
    int ladderMeter, risingMeter, fallingMeter;
    scanf("%d %d %d", &risingMeter, &fallingMeter, &ladderMeter);

    printf("%d", (ladderMeter - fallingMeter - 1) / (risingMeter - fallingMeter) + 1);

    return 0;
}