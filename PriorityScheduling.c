#include <stdio.h>
#include <string.h>
void ganttchart(int n, int bt[], int ct[], char pname[][10]) {
    printf("\nGANTT CHART\n");
    for (int i = 0; i < n; i++) {
        printf("|\t%s\t", pname[i]);
    }
    printf("|\n");
    printf("0\t\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t", ct[i]);
    }
    printf("\n");
}
int main() {
    int n, bt[10], pri[10], wt[10], tat[10];
    char pname[10][10];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and priority of p %d and process name ", i + 1);
        scanf("%d %d %s", &bt[i], &pri[i],&pname[i]);

    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pri[j] > pri[j + 1]) {
                int temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                char tempStr[10];
                strcpy(tempStr, pname[j]);
                strcpy(pname[j], pname[j + 1]);
                strcpy(pname[j + 1], tempStr);
            }
        }
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
    printf("Process\tBt\tPrio\tWait\tTT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", pname[i], bt[i], pri[i], wt[i], tat[i]);
    }
    ganttchart(n, bt, tat, pname);
return 0;
}
