#include<iostream>
#include<iomanip>
using namespace std;

class Process_Info
{
	public:
		int pid;						// Process ID
		int pr;							// Priority
		int at;							// Arrival Time 
		int bt;							// Burst Time
		int rt;							// Response time
		int tt;							// Turn Around Time
};

class Helper
{
	public:
	int n;				// No. of process	
	int cursor;
	Process_Info *process;
	Helper(){
		cout<<"\nEnter the number of processes : ";
		cin>>n;
		cout<<"Higher number represents higher priority";
		cursor = 0;
		process = new Process_Info[n];
		get_processes();
	}
	void get_processes();
	void sort_processes_at();
	void sort_processes_pr(int t);
	void print_Gantt_Chart();
	void print_Process_Table();
	void priority_based();
	
};

void Helper::get_processes(){
	for(int i=0; i<n; i++){
		cout<<"\nEnter the pID for process "<<i+1<<" : ";
		cin>>process[i].pid;
		cout<<"Enter the Arrival Time of this process : ";
		cin>>process[i].at;
		cout<<"Enter the Burst Time of this process : ";
		cin>>process[i].bt;
		cout<<"Enter the Priority of the process : ";
		cin>>process[i].pr;
	}
	
	cout<<"\nEntered set of processes : \n";
	cout<<"\tProcessID\tArrival Time\tBurst Time\tPriority";
	for(int i = 0; i<n; i++){
		cout<<"\n\t  P"<<process[i].pid<<"\t\t   "<<process[i].at<<"\t\t   "<<process[i].bt<<"\t\t   "<<process[i].pr;
	}
}

void Helper::sort_processes_at(){
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(process[j+1].at < process[j].at)
			{
				Process_Info temp = process[j];			
				process[j] = process[j+1];
				process[j+1] = temp;
			}
		}
	}	
}

void Helper::sort_processes_pr(int t){
	if (cursor == n)return;
	for(int i=cursor;i<n && process[i].at<=t;i++)
	{
		for(int j=cursor; j<n-1 && process[j].at<=t;j++)
		{
			if(process[j+1].at<=t && process[j+1].pr > process[j].pr)
			{
				Process_Info temp = process[j];			
				process[j] = process[j+1];
				process[j+1] = temp;
			}
		}
	}
}

void Helper::print_Gantt_Chart(){
	cout<<"\n\nGantt Chart for the given set of processes : \n";
	cout<<"-";
	for(int i=0; i<n; i++){
		cout<<setfill('-')<<setw(process[i].bt*2 +1);
		cout<<"-";
	}
	
	int st;					
	int ct;	
	
	cout<<"\n|";				
	st = process[0].at;
	cursor = 0;
	for(int i = 0; i<n; i++){
		sort_processes_pr(st);
		ct = st + process[i].bt;
		cout<<setfill(' ')<<setw(process[i].bt)<<"P"<<process[i].pid<<setw(process[i].bt)<<"|";	
		st = ct;
		cursor++;
	}
	
	cout<<"\n";
	cout<<"-";
	for(int i=0; i<n; i++){
		cout<<setfill('-')<<setw(process[i].bt*2 +1);
		cout<<"-";
	}
	
	st = process[0].at;
	cursor = 0;
	cout<<"\n"<<st;
	for(int i = 0; i<n; i++){
		sort_processes_pr(st);
		ct = st + process[i].bt;
		cout<<setfill(' ')<<setw((process[i].bt*2)+1)<<ct;
		st = ct;
		cursor++;
	}
}

void Helper::print_Process_Table(){
	int avg_rt=0;				// Average Response Time
	int avg_tt=0;
	cout<<"\n\nComplete Process Table of the given set of processes : \n";
	cout<<"\tProcessID\tArrival Time\tBurst Time\tPriority\tResponse Time\tTurn Around Time";
	for(int i = 0; i<n; i++){
		cout<<"\n\t  P"<<process[i].pid<<"\t\t   "<<process[i].at<<"\t\t   "<<process[i].bt<<"\t\t   "<<process[i].pr<<"\t\t   "<<process[i].rt<<"\t\t   "<<process[i].tt;
		avg_rt += process[i].rt;
		avg_tt += process[i].tt;
	}
	avg_rt = avg_rt/n;
	avg_tt = avg_tt/n;
	cout<<"\n\nAverage Response Time is : "<<avg_rt;
	cout<<"\nAverage Turn Around Time is : "<<avg_tt;
}

void Helper::priority_based(){
	sort_processes_at();		// to sort process according to their arrival time then by their priority
	
	int st;					// Service Time
	int ct;					// Completion Time
	st = process[0].at;
	cout<<"\n\nSequence in which processes will execute according to SJF Scheduling Algo: \n";
	cout<<"\tProcessID\tService Time\tCompletion Time";
	for(int i = 0; i<n; i++){
		sort_processes_pr(st);
		ct = st + process[i].bt;
		cout<<"\n\t  P"<<process[i].pid<<"\t\t   "<<st<<"\t\t   "<<ct;
		process[i].rt = st-process[i].at;
		process[i].tt = ct-process[i].at;
		st = ct;
		cursor++;
	}
	
	print_Gantt_Chart();
	
	print_Process_Table();
}

int main(){
	cout<<"\n	______PRIORITY BASED (NON-PREEMPTIVE)______	  \n";
	Helper process_set1;
	process_set1.priority_based();
}
