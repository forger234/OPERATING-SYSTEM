#include <stdio.h>
#include <string.h>
float avgwt, avgtt;
char pname[10][10];
int wt[10], tt[10], bt[10], at[10], ct[10], n;
int sum_wt = 0, sum_tt = 0;
void gantt_chart() {
    printf("\nGANTT CHART\n");
    for (int i = 0; i < n; i++) {
        printf("|\t%s\t", pname[i]);
    }
    printf("|\n");
    printf("0\t\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t", ct[i]);
    }
}
int main()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the NAME, ARRIVAL TIME, BURST TIME of each process\n");
    for (int i = 0; i < n; i++) {
        printf("\nPROCESS NAME: ");
        scanf("%s", pname[i]);

        printf("ARRIVAL TIME: ");
        scanf("%d", &at[i]);

        printf("BURST TIME: ");
        scanf("%d", &bt[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j])) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                char tempStr[10];
                strcpy(tempStr, pname[i]);
                strcpy(pname[i], pname[j]);
                strcpy(pname[j], tempStr);
            }
        }
    }
    int currentTime = 0;

    for (int i = 0; i < n; i++) 
   {
        if (currentTime < at[i])
       {
            currentTime = at[i];  
        }
        
        wt[i] = currentTime - at[i]; 
        ct[i] = currentTime + bt[i];  
        tt[i] = ct[i] - at[i];        

        sum_wt += wt[i];
        sum_tt += tt[i];

        currentTime = ct[i];  
    }

    avgwt = (float)sum_wt / n;
    avgtt = (float)sum_tt / n;
    printf("\nAVG WAITING TIME = %f", avgwt);
    printf("\nAVG TURNAROUND TIME = %f", avgtt);
    printf("\n\nPROCESS\t\tAT\t\tBT\t\tWT\t\tTT\t");
    for (int i = 0; i < n; i++) {
        printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d\t", pname[i], at[i], bt[i], wt[i], tt[i]);
    }
    gantt_chart();
    return 0;
}
