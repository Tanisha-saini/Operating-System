#include<iostream>
using namespace std;

int n;
class process
{
	public:
		int pid;										//process_id
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
		cout<<"Enter burst time : ";
		cin>>proc[i].bt;
		cout<<"";
	}
	cout<<"\n\n";
	cout<<"\nGiven set of Processes is as follows: \n";
	cout<<"\n\t\tProcess_id\tBurst Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t\tP"<<proc[i].pid<<"\t\t"<<proc[i].bt<<"\n";		
	}
}

void sort_bt()		//Sort processes according to their burst Time
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(proc[j].bt>proc[j+1].bt)
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

void sjf()									
{
	sort_bt();																
	float avgwaittime=0,avgturntime=0,totalwaittime=0,totalturntime=0;
	
	cout<<"\n\n";
	cout<<"\nExecution sequence of Processes is as follows : ";
	cout<<"\nSelected Process info : \n";
	cout<<"\nProcess_id\t\tW time\t\tT time\n";
	
	proc[0].wt=0;																	//waiting time for the 1st process is 0
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
			proc[i].wt+=proc[j].bt;													//now waiting for the next process will be the burst time of the previous process
		totalwaittime+=proc[i].wt;
	}
	for(int i=0;i<n;i++)															//turnaround time for any process will be its burst time + its waiting time
	{
		proc[i].tt=proc[i].wt+proc[i].bt;
		totalturntime+=proc[i].tt;
		cout<<"P"<<proc[i].pid<<"\t\t"<<proc[i].wt<<"\t\t"<<proc[i].tt<<endl;
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
	sjf();
	return 0;
}
