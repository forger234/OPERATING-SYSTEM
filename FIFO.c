#include<stdio.h>
int main(){
int reference[50],frame[50],fsize,i,j,c=0,n,fault=0;
float miss,hit;
printf("Enter the no of refrence: ");
scanf("%d",&n);
printf("Enter the reference: ");
for(i=0;i<n;i++)
scanf("%d",&reference[i]);
printf("Enter the frame size: ");
scanf("%d",&fsize);
for(i=0;i<fsize;i++)
frame[i]=-1;
printf("\nPage reference  Page frames\n");
for(i=0;i<n;i++){
    int flag=0;
    printf("\n   For page %d -> ",reference[i]);
for(j=0;j<fsize;j++){
if(frame[j]==reference[i])
flag=1;
}
if(flag!=1){
fault++;
frame[c]=reference[i];
c=(c+1)%fsize;
}
for(j=0;j<fsize;j++)
{
    if(frame[j]!=-1)
    printf("%d",frame[j]);
    printf(" ");
}
printf("\t%s\n",(flag?"HIT":"MISS"));
}
printf("\nTotal number of faults= %d\n",fault);
miss=((float)fault/n)*100;
hit=((float)(n-fault)/n)*100;
printf("Total no of references= %d\n",n);
printf("Miss ratio= %.2f% \n",miss);
printf("Hit ratio= %.2f% \n",hit);
return 0;
}
