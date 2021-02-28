#include<iostream>
using namespace std;

int n;
class process
{
	public:
		int pid;										//process_id
		int at;											//Arrival Time
		int bt;											//Burst Time or Execution Time
		int tt;											//Turn aroundtime
		int wt;											//Waiting time
}*proc;

void input()
{
	cout<<"\nEnter the total no. of Processes : ";
	cin>>n;
	proc=new process[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nFor Process "<<i+1<<" : ";
		cout<<"\nEnter Process_id : "; 
		cin>>proc[i].pid;
		cout<<"Enter arrival time : ";
		cin>>proc[i].at;
		cout<<"Enter burst time : ";
		cin>>proc[i].bt;
		cout<<"";
	}
	cout<<"\n\n";
	cout<<"\nGiven set of Processes is as follows: \n";
	cout<<"\n\t\tProcess_id\tArrival Time\tBurst Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t\tP"<<proc[i].pid<<"\t\t"<<proc[i].at<<"\t\t"<<proc[i].bt<<"\n";		
	}
}

void sort_at()		//Sort processes according to their Arrival Time
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(proc[j].at>proc[j+1].at)
			{
				process temp=proc[j];			//process --> struct
				proc[j]=proc[j+1];
				proc[j+1]=temp;
			}
		}
	}
}

void ganttchart()
{
    int i,j;
    cout<<"\n\nGantt chart\n\n";
    for(i=0; i<n; i++)
	{
        for(j=0; j<proc[i].bt; j++) cout<<"--";
        cout<<" ";
    }
    cout<<"\n|";
    for(i=0; i<n; i++)
	{
        for(j=0; j<proc[i].bt - 1; j++)
			cout<<" ";
        cout<<"P"<< proc[i].pid;
        for(j=0; j<proc[i].bt - 1; j++) 
			cout<<" ";
        cout<<"|";
    }
    cout<<endl;
    // printing bottom bar
    for(i=0; i<n; i++)
	{
        for(j=0; j<proc[i].bt; j++) 
			cout<<"--";
        cout<<" ";
    }
    cout<<"\n";
	cout<<"0";  
    for(i=0;i<n; i++)
	{
        for(j=0; j<proc[i].bt; j++)
			cout<<"  ";
        if(proc[i].tt > 9) 						//if it is two digit number remove one space 
			cout<<"\b"; 						// backspace : remove 1 space
        cout<< proc[i].tt;
    }  
}

void fcfs()									//FCFS (First Come First Serve) Scheduling (Based on Arrival Time)
{
	sort_at();								//Sort processes according to their Arrival Time
	int st;									//Starting Time or Service Time (i.e. when a process starts its execution) 
	int ct;									//Finishing or Completion Time (i.e. a process completes its execution)
	st=proc[0].at;
	float avgwaittime=0,avgturntime=0,totalwaittime=0,totalturntime=0;
	
	cout<<"\n\n";
	cout<<"\nExecution sequence of Processes is as follows : ";
	cout<<"\nSelected Process info : \n";
	cout<<"\nProcess_id\tS Time\t\tC Time\t\tT time\t\tW time\n";
	
	for(int i=0;i<n;i++)
	{
		ct=st+proc[i].bt;
		proc[i].tt=ct-proc[i].at;
		proc[i].wt=proc[i].tt-proc[i].bt;
		cout<<"P"<<proc[i].pid<<"\t\t"<<st<<"\t\t"<<ct<<"\t\t"<<proc[i].tt<<"\t\t"<<proc[i].wt<<endl;
		st=ct;
		totalwaittime+=proc[i].wt;
		totalturntime+=proc[i].tt;
	}
	
	avgwaittime=totalwaittime/n;
	avgturntime=totalturntime/n;
	cout<<"\nAverage waiting time: "<<avgwaittime<<"\n";
	cout<<"Average turn aroundtime: "<<avgturntime;
	ganttchart();
}

int main()
{
	input();
	fcfs();
	return 0;
}
