#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);

    // Allocate memory for the 2D DP table: (m+1) x (n+1)
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc((n + 1), sizeof(int));
    }

    // Build the DP table bottom-up
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // Length of LCS is at dp[m][n]
    int lcs_len = dp[m][n];

    // Allocate memory for the resulting LCS string (+1 for null-terminator)
    char *lcsStr = (char *)malloc((lcs_len + 1) * sizeof(char));
    lcsStr[lcs_len] = '\0';

    // Backtrack through the DP table to reconstruct the string
    int i = m, j = n, index = lcs_len;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Output results
    printf("LCS Length: %d\n", lcs_len);
    printf("LCS String: %s\n", lcsStr);

    // Free dynamically allocated memory to prevent leaks
    free(lcsStr);
    for (int k = 0; k <= m; k++) {
        free(dp[k]);
    }
    free(dp);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    printf("String 1: %s\n", X);
    printf("String 2: %s\n", Y);
    
    findLCS(X, Y);

    return 0;
}
