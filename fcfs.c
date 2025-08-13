#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], ct[n], tat[n], wt[n];
    float total_tat = 0, total_wt = 0;

    // Input burst times
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate Completion Time
    ct[0] = bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    // Calculate TAT & WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];           // Since AT = 0
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Throughput calculation
    float throughput = (float)n / ct[n - 1];

    // Output
    printf("\nP#\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nThroughput = %.2f processes/unit time\n", throughput);

    return 0;
}
