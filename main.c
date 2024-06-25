#include "TCircList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int result = findSafePosition(N, M);
    printf("%d\n", result);
    return 0;
}
