#include<iostream>
using namespace std;
                                               
class sched
{
public:
    int n,bt[10],at[10],tat[10],wt[10],rt[10],finish[10],twt,ttat,total;
    void readData();
    void Init();
    void dispTime();
    void computeRR();
};

void sched::readData()
{
    cout<<"Enter no. of processes\n";
    cin>>n;
    cout<<"Enter the burst times in order :\n";
    for(int i=0;i<n;i++)
    cin>>bt[i];
    cout<<"Enter the arrival times in order:\n";
    for(int i=0;i<n;i++)
    cin>>at[i];
}

void sched::Init()
{
    total=0;
    twt=0;
    ttat=0;
    for(int i=0; i<n; i++)
 {
        rt[i]=bt[i];
        finish[i]=0;
        wt[i]=0;
        tat[i]=0;
        total+=bt[i];
        }
}

void sched::dispTime()
{
    for(int i=0;i<n;i++)
    {

        twt+=wt[i];
        tat[i]=wt[i]+bt[i];
        ttat+=tat[i];
        cout<<"Waiting time for P"<<(i+1)<<" = "<<wt[i]<<", Turnaround time = "<<tat[i]<<endl;

    }

    cout<<"Avg Waiting time = "<<(double)twt/n<<" and Avg Turnaround time = "<<(double)ttat/n<<endl;
    cout<<"Scheduling complete\n";
}

void sched::computeRR(){

    readData();
    Init();
    int time,j,q,i,dec=0;
    cout<<"Enter the time quantum:\n";
    cin>>q;
    cout<<"Gantt Chart\n ";
    for(time=0;time<total;)
    {
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && finish[i]==0)
            {

                cout<<"("<<time<<")|==P"<<(i+1)<<"==|";
                if(rt[i]<q)  {
                    dec=rt[i];
                }
                else {dec=q;}

                rt[i]=rt[i]-dec;
                if(rt[i]==0) 
                  finish[i]=1;
                for(j=0;j<n;j++)
                    if(j!=i && finish[j]==0 && at[j]<=time)
                        wt[j]+=dec;
                  time=time+dec;

            }

        }

    }                                                        

    cout<<"("<<total<<")"<<endl;
    dispTime();
}
int main()
{
    sched s;
    int ch;
    s.computeRR();
}
