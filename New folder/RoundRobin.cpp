#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,sum = 0,y,AT[100],BT[100],temp[100],wt=0,tat=0,quant;
    float avg_wt=0,avg_tat=0;
    bool isProcessing = true;
    cout<<"Total number of process in system: ";
    cin>>n;
    y = n;

    for(i=0;i<n;i++){
        cout<<"\nEnter arrival time for P"<<i+1<<" : ";
        cin>>AT[i];
        cout<<"\nEnter Burst time for P"<<i+1<<" : ";
        cin>>BT[i];
        temp[i] = BT[i];
    }
    cout<<"\nEnter the time Quantum for process: ";
    cin>>quant;
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
            tat = sum-AT[i];
            wt = tat-BT[i];
            cout<<"P "<<i+1<<"\t\t"<<BT[i]<<"\t\t"<<wt<<"\t\t"<<tat<<endl;
            avg_wt+=wt;
            avg_tat+=tat;
            isProcessing = true;
        }
        if(i == n-1){
            i = 0;
        }else if(AT[i]<= sum){
            i++;
        }else{
            i = 0;
        }
    }
}
