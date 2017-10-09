#include<bits/stdc++.h>

using namespace std;

struct Process
{
  int pid;
  int bt;
};

bool comparison(Process a, Process b)
{
  return (a.bt < b.bt);
}

void findWaitingTime(Process proc[], int n, int wt[])
{
  wt[0] = 0;
  for (int i = 1;i < n; i++)
    wt[i] = proc[i-1].bt + wt[i-1];
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
  for (int i=0 ; i < n; i++)
  tat[i] = proc[i].bt + wt[i];
}

void findAvgTime(Process proc[], int n)
{
  int wt[n], tat[n], total_wt = 0, total_tat = 0;
  findWaitingTime(proc, n ,wt);
  findTurnAroundTime(proc, n, wt, tat);

  cout<<"\nProcesses "<<" Burst Time "<<" Waiting Time "<<" Turnaround Time \n";
  for(int i = 0; i < n; i++)
  {
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];
    cout<<" "<<proc[i].pid<<"\t\t"<<proc[i].bt<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
  }

  cout<<"Average waiting Time = "<<float(total_wt)/float(n);
  cout<<"\nAverage Turnaround Time = "<<float(total_tat)/float(n);
}

int main()
{
  Process proc[] = {{1,6}, {2,8}, {3,7}, {4,3}};
  int n = sizeof proc/sizeof proc[0];
  sort(proc, proc + n, comparison);
  cout<<"ORDER IN WHICH THE PROCESSES GET EXECUTED\n";
  for(int i = 0; i < n; i++)
    cout<<proc[i].pid<<" ";
  findAvgTime(proc, n);
  return 0;
}
