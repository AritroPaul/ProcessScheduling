#include<iostream>

using namespace std;

struct process
{
  char processName;
  int arrivalTime, burstTime, ct, waitingTime, turnaroundTime, priority;
  int status;
}
processQueue[10];

int limit;

void arrivalTimeSorting()
{
  process Temp;
  int i,j;
  for(int i = 0;i < limit - 1; i++)
  {
    for(j = i+1; j < limit; j++)
    if(processQueue[i].arrivalTime > processQueue[j].arrivalTime)
    {
      Temp = processQueue[i];
      processQueue[i] = processQueue[j];
      processQueue [j] = Temp;
    }
  }
}

int main()
{
  int i, time = 0, burstTime = 0, largest;
  char c;
  float waitTime = 0, turnaroundTime = 0, averageWaitingTime, averageTurnaroundTime;
  cout<<"Enter Total Number of Processes:\t";
  cin>>limit;
  for(int i=0, c = 'A'; i < limit; i++,c++)
  {
    processQueue[i].processName = c;
    cout<<"Arrival Time: \n";
    cin>>processQueue[i].arrivalTime;
    cout<<"Burst Time: \n";
    cin>>processQueue[i].burstTime;
    cout<<"Priority: \n";
    cin>>processQueue[i].priority;
    processQueue[i].status = 0;
    burstTime = burstTime + processQueue[i].burstTime;
  }
  arrivalTimeSorting();
  processQueue[9].priority = -9999;
  cout<<"Process Name "<<" Arrival Time "<<" Burst Time "<<" Priority "<<" Waiting Time "<<endl;
  for(time = processQueue[0].arrivalTime; time < burstTime;)
  {
    largest = 9;
    for(i = 0; i < limit; i++)
    {
      if(processQueue[i].arrivalTime <= time && processQueue[i].status != 1 && processQueue[i].priority > processQueue[largest].priority)
        largest = i;
    }
    time = time + processQueue[largest].burstTime;
    processQueue[largest].ct = time;
    processQueue[largest].waitingTime = processQueue[largest].ct - processQueue[largest].arrivalTime - processQueue[largest].burstTime;
    processQueue[largest].turnaroundTime = processQueue[largest].ct - processQueue[largest].arrivalTime;
    processQueue[largest].status = 1;
    waitTime = waitTime + processQueue[largest].waitingTime;
    turnaroundTime = turnaroundTime + processQueue[largest].turnaroundTime;
    cout<<processQueue[largest].processName<<"\t\t"<<processQueue[largest].arrivalTime<<"\t\t"<<processQueue[largest].burstTime<<"\t\t"<<processQueue[largest].priority<<"\t\t"<<processQueue[largest].waitingTime<<endl;
  }
  averageWaitingTime = waitTime / limit;
  averageTurnaroundTime = turnaroundTime / limit;
  cout<<"Average Waiting Time: "<<averageWaitingTime;
  cout<<"\nAverage Turnaround Time: "<<averageTurnaroundTime;
}
