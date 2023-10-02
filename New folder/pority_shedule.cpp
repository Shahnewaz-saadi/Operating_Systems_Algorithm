#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void NonPreemetive(){
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    // b is array for burst time, p for priority and index for process id
    int b[n],p[n],index[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
        scanf("%d %d",&b[i],&p[i]);
        index[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        int a=p[i],m=i;

        //Finding out highest priority element and placing it at its desired position
        for(int j=i;j<n;j++)
        {
            if(p[j] > a)
            {
                a=p[j];
                m=j;
            }
        }

        //Swapping processes
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i],&index[m]);
    }
    printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
    int wait_time=0;
    for(int i=0;i<n;i++)
    {
        printf("P%d             %d              %d              %d\n",index[i],b[i],wait_time,wait_time + b[i]);
        wait_time += b[i];
    }
}

void Preemetive(){
    int i,sum = 0,temp[100],wt=0,tat=0,quant;
    float avg_wt=0,avg_tat=0;
    bool isProcessing = true;
    int n,y;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    cin>>quant;
    y = n;
    // b is array for burst time, p for priority and index for process id
    int b[n],p[n],index[n];
    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
        scanf("%d %d",&b[i],&p[i]);
        index[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        int a=p[i],m=i;

        //Finding out highest priority element and placing it at its desired position
        for(int j=i;j<n;j++)
        {
            if(p[j] > a)
            {
                a=p[j];
                m=j;
            }
        }

        //Swapping processes
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i],&index[m]);
        temp[i] = b[i];
    }
    cout<<endl<<"Process\tBurst Time\tWaiting Time\tTurnaround Time \n";
    i = 0;
    while(y!=0){
        if(temp[i]<=quant && temp[i]>0){
            sum += temp[i];
            temp[i] = 0;
            isProcessing = false;
        }else if(temp[i]>0)
        {
            temp[i] -= quant;
            sum += quant;
            isProcessing = true;
        }
        if(temp[i] == 0 && !isProcessing){
            y--;
            tat = sum;
            wt = tat-b[i];
            cout<<"P "<<i+1<<"\t\t"<<b[i]<<"\t\t"<<wt<<"\t\t"<<tat<<endl;
            avg_wt+=wt;
            avg_tat+=tat;
            isProcessing = true;
        }
        if(i == n-1){
            i = 0;
        }else{
            i++;
        }
    }
}
int main()
{
    Preemetive();
    return 0;
}
