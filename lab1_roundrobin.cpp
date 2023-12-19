//round robin->scheduling algorithm
//preemptive scheduling
//according to the time quant
#include<bits/stdc++.h>
using namespace std;
struct process{
     int at;
     int bt;
     int ct;
     int tat;
     int wt;
};
int main(){
     int n,c=0,l=0,i,index=-1;
     bool flag;
     int temp[20];//for gant chat 
     cout<<"Enter number of processes:";
     cin>>n;
     int quant;
     cout<<"Enter quant value:";
     cin>>quant;
     struct process p[n];
     float time=0,a[n],b[n],mini,awt=0,atat=0;
     cout<<"Enter at and bt values:";
     for(i=0;i<n;i++){
        cin>>p[i].at>>p[i].bt;
        a[i]=p[i].at;
        b[i]=p[i].bt;
     }
     while(c<n){
        mini=INT_MAX;
        flag=false;
        for(i=0;i<n;i++){
           float p=time+0.1;
           if(a[i]<=p && a[i]<mini && b[i]>0){//taking lesser at valued processor
              mini=a[i];
              index=i;
              flag=true;
            }
         }
         if(!flag){
           time++;
           continue;
         }
         if(b[index]<=quant){//bt<quant
              time=time+b[index];
              temp[l++]=index+1;
              b[index]=0;
         }
         else{//bt >quant
              time=time+quant;
              temp[l++]=index+1;
              b[index]=b[index]-quant;
         }
         if(b[index]>0){//ready queue lo unna processes ni execute cheyadaaniki
            a[index]=time+0.1;
         }
         if(b[index]==0){
            p[index].ct=time;
            p[index].wt=p[index].ct-p[index].at-p[index].bt;
            p[index].tat=p[index].wt+p[index].bt;
            awt=awt+p[index].wt;
            atat=p[index].tat;
            c++;
         }
      }
      //printing
      cout<<"Ready queue:";
      for(i=0;i<l;i++){
         cout<<"P"<<temp[i]<<"|";
      }
      cout<<"\nprocess\tAT\tBT\tCT\tWt\tTAT\n";
      for(i=0;i<n;i++){
          cout<<i+1<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
      }
      cout<<"Average waiting time:"<<awt/n<<endl;
      cout<<"Average turn around time:"<<atat/n;
 }
      
/* output
Enter number of processes:6
Enter quant value:3
Enter at and bt values:7
3
4
7
6
5
2
4
5
6
3
8
Ready queue:P4|P6|P2|P5|P4|P3|P1|P6|P2|P5|P3|P6|P2|
process	AT	BT	CT	Wt	TAT
1	7	3	21	14	11
2	4	7	35	31	24
3	6	5	32	26	21
4	2	4	15	13	9
5	5	6	30	25	19
6	3	8	34	31	23
Average waiting time:17.8333
Average turn around time:5.16667
*/     
       
     
