#include <stdio.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

void sortJobs(struct Job jobs[], int n) {
    // Sort jobs by profit in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

void jobSequencing(struct Job jobs[], int n) {
    sortJobs(jobs, n);

    int maxDeadline = 0;

    // Find maximum deadline
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[maxDeadline + 1];

    // Initialize slots
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        // Find latest available slot before deadline
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nJob Sequence: ");

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            printf("%c ", jobs[slot[i]].id);
    }

    printf("\nMaximum Profit = %d\n", totalProfit);
}

int main() {
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    printf("Enter Job ID, Deadline and Profit:\n");

    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d",
              &jobs[i].id,
              &jobs[i].deadline,
              &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}