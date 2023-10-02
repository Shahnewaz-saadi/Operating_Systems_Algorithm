#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,bt[100],wt[100],tat[100],i,j;
    double avwt=0,avtat=0;
    cout<<"Enter total number of processes: ";
    cin>>n;

    cout<<endl<<"Enter Process Burst Time: ";
    for(i=0;i<n;i++)
    {
        cout<<"\nProcess "<<i+1<<": ";
        cin>>bt[i];
    }

    wt[0] = 0;
    for(i=1;i<n;i++)
    {
        wt[i] = 0;
        for(j=0;j<i;j++)
        {
            wt[i]+=bt[j];
        }
    }

    cout<<endl<<"Process\tBurst Time\tWaiting Time\tTurnaround Time \n";

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }

    avwt/=(n+0.0);
    avtat/=(n+0.0);
    cout<<endl<<"Average Waiting Time: "<<avwt;
    cout<<endl<<"Average Turnaround Time: "<<avtat<<endl;
    return 0;
}
