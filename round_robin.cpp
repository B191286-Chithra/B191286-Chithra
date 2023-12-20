#include<bits/stdc++.h>
using namespace std;

struct data{int p,at,bt;}k[10];
queue<int> q;
int tq,n;
void push_into_queue(int j,int l)
{
	map<int,int> ma;
	for(int i=1;i<=n;i++)
	{
		if(k[i].at>j and k[i].at<=l)
			ma.insert({k[i].at,k[i].p});
	}
	for(auto &it: ma)
		q.push(it.second);
}
int main()
{
	int min=99,max=-1;
	cin>>tq;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].p>>k[i].at>>k[i].bt;
		if(min>k[i].at)
			min=k[i].at;
		if(max<k[i].at)
			max=k[i].at;
	}
	
	push_into_queue(-1,min);
	// for(auto it:v)
	// 	cout<<it;
	int t=0;
	if(t<min)
	{
		cout<<t<<" to "<<min<<" idle"<<endl;
		t+=min;
	}
	while(t<max+1)
	{
		if(k[q.front()].bt<tq)
		{
			cout<<t<<" to "<<t+k[q.front()].bt<<" p"<<q.front()<<endl;
			push_into_queue(t,t+k[q.front()].bt);
			t+=k[q.front()].bt;
			q.pop();
		}
		else
		{
			cout<<t<<" to "<<t+tq<<" p"<<q.front()<<endl;
			push_into_queue(t,t+tq);
			t+=tq;
	
			int top=q.front();
			q.pop();
			k[top].bt-=tq;
			if(k[top].bt!=0)
				q.push(top);
		}
	}
	while(!q.empty())
	{
		if(k[q.front()].bt<tq)
		{
			cout<<t<<" to "<<t+k[q.front()].bt<<" p"<<q.front()<<endl;
			t+=k[q.front()].bt;
			q.pop();
		}
		else
		{
			cout<<t<<" to "<<t+tq<<" p"<<q.front()<<endl;
			t+=tq;
			k[q.front()].bt-=tq;
			int top=q.front();
			q.pop();
			if(k[top].bt!=0)
				q.push(top);
		}


	}
}