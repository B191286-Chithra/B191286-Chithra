#include<bits/stdc++.h>
using namespace std;
struct data{
	int p;
	int at;
	int bt;
};
int main()
{
	int n;
	cin>>n;
	
	struct data d[n];
	vector<int> ct(n);
	for(int i=0;i<n;i++)
	cin>>d[i].p>>d[i].at>>d[i].bt;
	vector<int> att(n);
	for(int i=0;i<n;i++)
		att[i]=d[i].at;
	int t=0;
	int l=n;
	while(l--)
	{
		int minarr=100,pro;
		for(int i=0;i<n;i++)
		{
			if(minarr>d[i].at)
			{
				minarr=d[i].at;
				pro=d[i].p;
			}
		}
		
		if(t<minarr)
			cout<<t<<" to   "<<minarr<<" idle "<<endl;
		t=minarr;

		cout<<t<<" to "<<t+d[pro-1].bt<<" p"<<pro<<endl;
		t+=d[pro-1].bt;
		
		ct[pro-1]=t;
		d[pro-1].at=100;
	}
	vector<int> tat(n);
	vector<int> wt(n);
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-att[i];
		wt[i]=tat[i]-d[i].bt;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<d[i].p<<" "<<att[i]<<" "<<d[i].bt<<" "<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;
	}
	

}