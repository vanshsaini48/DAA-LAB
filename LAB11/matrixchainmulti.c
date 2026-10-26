#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 100

int memo[MAX][MAX];
int s[MAX][MAX];      

int mcm(int p[], int i, int j) {
    if (i == j)
        return 0;

    if (memo[i][j] != -1)          
        return memo[i][j];

    int best = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = mcm(p, i, k) + mcm(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (cost < best) {
            best = cost;
            s[i][j] = k;
        }
    }
    return memo[i][j] = best;
}

void printOptimalParens(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the dimensions array (%d values):\n", n + 1);
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    memset(memo, -1, sizeof(memo));

    int result = mcm(p, 1, n);

    printf("Minimum number of multiplications: %d\n", result);
    printf("Optimal Parenthesization: ");
    printOptimalParens(1, n);
    printf("\n");

    return 0;