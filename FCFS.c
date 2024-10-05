#include<stdio.h>
#include<string.h>
int main() {
    int i, n, j, at[20], bt[20], temp, sum = 0, ct[30], tt[30], wt[20], ss = 0;
    float avgtt, avgwt;
    char pname[20][20];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("PROCESS NAME: ");
        scanf("%s", pname[i]);
        printf("\nARRIVAL TIME: ");
        scanf("%d", &at[i]);
        printf("\nBURST TIME: ");
        scanf("%d", &bt[i]);
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                char tempstr[20];
                strcpy(tempstr, pname[i]);
                strcpy(pname[i], pname[j]);
                strcpy(pname[j], tempstr);
            }
        }
    }
    ct[0] = bt[0];
    tt[0] = ct[0] - at[0];
    wt[0] = tt[0] - bt[0];
    sum += wt[0];
    ss += tt[0];
    for(i = 1; i < n; i++) {
       ct[i] = ct[i - 1] + bt[i];
       tt[i] = ct[i] - at[i];
       wt[i] = tt[i] - bt[i];
       sum += wt[i];
       ss += tt[i];
    }
    avgwt = (float)sum / n;
    avgtt = (float)ss / n;
    printf("\nPROCESS\t\tARRIVAL TIME\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", pname[i], at[i], bt[i], wt[i], tt[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtt);
    printf("\nGantt Chart\n");
    printf("|");
    for(i = 0; i < n; i++) {
        printf("\t%s\t|", pname[i]);
    }
    printf("\n0");
    for(i = 0; i < n; i++) {
        printf("\t\t%d", ct[i]);
    }
    printf("\n");
    return 0;
}
