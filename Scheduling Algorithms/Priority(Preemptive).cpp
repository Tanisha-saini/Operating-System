#include<iostream>
#include<iomanip>
using namespace std;

class process
{
	public:
		int pid;						// Process ID
		int pr;							// Priority
		int at;							// Arrival Time 
		int bt;							// Burst Time
		int rt;							// Response time
		int tt;							// Turn Around Time
		int t_bt;
};

class Helper
{
	public:
	int n;								// No. of process	
	bool ch;
	process *process;
	Helper()
	{
		cout<<"\n Higher number represents higher priority \n";
		cout<<"\nEnter the number of processes : ";
		cin>>n;
		process = new process[n];
		input();
	}
	void input();
	void sort_processes();
	void print_ganttchart();
	void print_processtable();
	void priority_based();
	
};

void Helper::input(){
	for(int i=0; i<n; i++)
	{
		cout<<"\nEnter the pid for process "<<i+1<<" : ";
		cin>>process[i].pid;
		cout<<"Enter the Arrival Time of this process : ";
		cin>>process[i].at;
		cout<<"Enter the Burst Time of this process : ";
		cin>>process[i].bt;
		cout<<"Enter the Priority of the process : ";
		cin>>process[i].pr;
		process[i].t_bt=process[i].bt;
	}
	
	cout<<"\nEntered set of processes : \n";
	cout<<"\tProcessID\tArrival Time\tBurst Time\tPriority";
	for(int i = 0; i<n; i++)
	{
		cout<<"\n\t  P"<<process[i].pid<<"\t\t   "<<process[i].at<<"\t\t   "<<process[i].bt<<"\t\t   "<<process[i].pr;
	}
}

void Helper::sort_processes()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(process[j+1].at < process[j].at)
			{
				process temp = process[j];			
				process[j] = process[j+1];
				process[j+1] = temp;
			}
		}
	}
	
}

void Helper::print_ganttchart()
{
	cout<<"\n\nGantt Chart for the given set of processes : \n";
	
	int st;					// Service Time
	int ct;					// Completion Time
	
	sort_processes();
	st = process[0].at;
	ct = process[0].at;
	cout<<"-";
	while(1)
	{
		for(int i=0; process[i].at <= ct; i++)
		{
			for(int j=0; process[j].at <= ct ; j++)
			{
				if(process[j+1].t_bt != 0  && process[j].t_bt == 0) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}
		
		int t_n = 0;
		for(int i=0; process[i].at <= ct && process[i].t_bt > 0 ; i++)
		{
			t_n++;
			for(int j=0;process[i].at <= ct && process[j].t_bt > 0 ; j++)
			{
				
				if(process[j+1].at<=ct && process[j+1].pr > process[j].pr) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}	
		bool set = 0;
		for(int k =0; k<t_n; k++){
			for(int l = 0; l<process[k].bt; l++){
				if(t_n!=n && ct == process[t_n].at){
					set = 1;
					break;
				}
				ct++;
				process[k].t_bt--;
				if(process[k].t_bt==0){
					break;
				}
			}	
			for(int c=0; c<(ct-st)*2 +1;c++){
				cout<<"-";
			}
			st = ct;
			if(set == 1){
				break;
			}		
		}
		if(t_n==n){
			break;
		}	
	}
	
	for(int i = 0; i<n; i++){
		process[i].t_bt = process[i].bt;
	}
	
	cout<<"\n|";
	sort_processes();
	st = process[0].at;
	ct = process[0].at;
	while(1)
	{
		for(int i=0; process[i].at <= ct; i++)
		{
			for(int j=0; process[j].at <= ct ; j++)
			{
				if(process[j+1].t_bt != 0  && process[j].t_bt == 0) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}
		
		int t_n = 0;
		for(int i=0; process[i].at <= ct && process[i].t_bt > 0 ; i++)
		{
			t_n++;
			for(int j=0;process[i].at <= ct && process[j].t_bt > 0 ; j++)
			{
				
				if(process[j+1].at<=ct && process[j+1].pr > process[j].pr) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}	
		bool set = 0;
		for(int k =0; k<t_n; k++){
			for(int l = 0; l<process[k].bt; l++){
				if(t_n!=n && ct == process[t_n].at){
					set = 1;
					break;
				}
				ct++;
				process[k].t_bt--;
				if(process[k].t_bt==0){
					process[k].tt = ct-process[k].at;
					break;
				}
			}
			cout<<setfill(' ')<<setw(ct-st)<<"P"<<process[k].pid<<setw(ct-st)<<"|";
			st = ct;
			if(set == 1){
				break;
			}		
		}
		if(t_n==n){
			break;
		}	
	}
	for(int i = 0; i<n; i++){
		process[i].t_bt = process[i].bt;
	}
	
	cout<<"\n";
	cout<<"-";
	sort_processes();
	st = process[0].at;
	ct = process[0].at;
	while(1)
	{
		for(int i=0; process[i].at <= ct; i++)
		{
			for(int j=0; process[j].at <= ct ; j++)
			{
				if(process[j+1].t_bt != 0  && process[j].t_bt == 0) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}
		
		int t_n = 0;
		for(int i=0; process[i].at <= ct && process[i].t_bt > 0 ; i++)
		{
			t_n++;
			for(int j=0;process[i].at <= ct && process[j].t_bt > 0 ; j++)
			{
				
				if(process[j+1].at<=ct && process[j+1].pr > process[j].pr) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}	
		bool set = 0;
		for(int k =0; k<t_n; k++){
			for(int l = 0; l<process[k].bt; l++){
				if(t_n!=n && ct == process[t_n].at){
					set = 1;
					break;
				}
				ct++;
				process[k].t_bt--;
				if(process[k].t_bt==0){
					process[k].tt = ct-process[k].at;
					break;
				}
			}	
			for(int c=0; c<(ct-st)*2 +1;c++){
				cout<<"-";
			}
			st = ct;
			if(set == 1){
				break;
			}		
		}
		if(t_n==n){
			break;
		}	
	}
	for(int i = 0; i<n; i++){
		process[i].t_bt = process[i].bt;
	}
	
	sort_processes();
	st = process[0].at;
	ct = process[0].at;	
	cout<<"\n"<<st;
	while(1){
		for(int i=0; process[i].at <= ct; i++)
		{
			for(int j=0; process[j].at <= ct ; j++)
			{
				if(process[j+1].t_bt != 0  && process[j].t_bt == 0) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}
		
		int t_n = 0;
		for(int i=0; process[i].at <= ct && process[i].t_bt > 0 ; i++)
		{
			t_n++;
			for(int j=0;process[i].at <= ct && process[j].t_bt > 0 ; j++)
			{
				
				if(process[j+1].at<=ct && process[j+1].pr > process[j].pr) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}	
		bool set = 0;
		for(int k =0; k<t_n; k++){
			for(int l = 0; l<process[k].bt; l++){
				if(t_n!=n && ct == process[t_n].at){
					set = 1;
					break;
				}
				ct++;
				process[k].t_bt--;
				if(process[k].t_bt==0){
					process[k].tt = ct-process[k].at;
					break;
				}
			}	
			cout<<setfill(' ')<<setw((ct-st)*2 +1)<<ct;
			st = ct;
			if(set == 1){
				break;
			}		
		}
		if(t_n==n){
			break;
		}	
	}
	for(int i = 0; i<n; i++)
	{
		process[i].t_bt = process[i].bt;
	}
}

void Helper::print_processtable()
{
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

void Helper::priority_based()
{
	sort_processes();		// to sort process according to their arrival time then by their priority
	
	int st;					// Service Time
	int ct;					// Completion Time
	
	st = process[0].at;
	ct = process[0].at;
	
	cout<<"\n\nSequence in which processes will execute according to SJF Scheduling Algo: \n";
	cout<<"\tProcessID\tService Time\tCompletion Time";
	
	while(1){
		for(int i=0; process[i].at <= ct; i++)
		{
			for(int j=0; process[j].at <= ct ; j++)
			{
				if(process[j+1].t_bt != 0  && process[j].t_bt == 0) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}
		
		int t_n = 0;
		for(int i=0; process[i].at <= ct && process[i].t_bt > 0 ; i++)
		{
			t_n++;
			for(int j=0;process[i].at <= ct && process[j].t_bt > 0 ; j++)
			{
				
				if(process[j+1].at<=ct && process[j+1].pr > process[j].pr) 
				{
					process temp = process[j];			
					process[j] = process[j+1];
					process[j+1] = temp;
				}
			}
		}	
		bool set = 0;
		for(int k =0; k<t_n; k++){
			for(int l = 0; l<process[k].bt; l++){
				if(t_n!=n && ct == process[t_n].at){
					set = 1;
					break;
				}
				if(process[k].t_bt==process[k].bt){
					process[k].rt = st-process[k].at;
				}
				ct++;
				process[k].t_bt--;
				if(process[k].t_bt==0){
					process[k].tt = ct-process[k].at;
					break;
				}
			}	
			cout<<"\n\t  P"<<process[k].pid<<"\t\t   "<<st<<"\t\t   "<<ct;
			st = ct;
			if(set == 1){
				break;
			}		
		}
		if(t_n==n){
			break;
		}	
	}
	for(int i = 0; i<n; i++){
		process[i].t_bt = process[i].bt;
	}
	
	print_ganttchart();
	
	print_processtable();
}

int main(){
	cout<<"\n	______PRIORITY BASED (NON-PREEMPTIVE)______	  \n";
	Helper process_set1;
	process_set1.priority_based();
}
