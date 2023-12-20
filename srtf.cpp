#include<bits/stdc++.h>
using namespace std;

struct data
{
	int p,at,bt;
};
int n;
struct data k[10];
vector<int> v;
vector<pair<int,int> > m;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.second!=b.second)
	return a.second<b.second;
	return a.first<b.first;
}
void push_into_pair(int min)
{
	for(int g=1;g<=n;g++)
	{
		if(k[g].at==min)
		{
			m.push_back({k[g].p,k[g].bt});
		}
	}
}
void push_into_vect(int j){
	for(int g=1;g<=n;g++)
	{
		if( k[g].at==j)
			v.push_back(g);
	}
}
int main()
{
	int min=99;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>k[i].p>>k[i].at>>k[i].bt;
	if(min>k[i].at)
		min=k[i].at;}
	
	push_into_vect(min);
	push_into_pair(min);
	sort(m.begin(),m.end(),cmp);
	int t=0;
	if(t<min)
	{
		cout<<t<<" to "<<min<<" idle"<<endl;
		t+=min;
	}
	int hash[n];
	while(v.size()!=n)
	{
		cout<<t<<" to "<<t+1<<" p"<<m[0].first<<endl;
		int a=m[0].first;
		hash[a]=t+1;
		m[0].second--;
		if(m[0].second==0)
			m[0].second=99;
		t+=1;
		push_into_vect(t);
		push_into_pair(t);
		sort(m.begin(),m.end(),cmp);
	}
	while(m[0].second!=99)
	{
		cout<<t<<" to "<<t+m[0].second<<" p"<<m[0].first<<endl;
		int b=m[0].first;
		hash[b]=t+m[0].second;
		t+=m[0].second;
		m[0].second=99;
		sort(m.begin(),m.end(),cmp);
	}
	vector<int> tat(n);
	vector<int> wt(n);
	for(int i=1;i<=n;i++)
	{
		tat[i]=hash[i]-k[i].at;
		wt[i]=tat[i]-k[i].bt;
	}
	cout<<endl<<"pro   at   bt   ct  tat  wt"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<k[i].p<<"    "<<k[i].at<<"    "<<k[i].bt<<"    "<<hash[i]<<"    "<<tat[i]<<"    "<<wt[i];
		cout<<endl;
	}
	int atat=0,awt=0;
	for(int i=1;i<=n;i++)
	{
		atat+=tat[i];
		awt+=wt[i];
	}
	cout<<endl<<"avereage tat is: "<<atat/n<<endl<<"average awt is: "<<" "<<awt/n;

}
/*
6
1 0 8
2 1 4
3 2 2
4 3 1
5 4 3
6 5 2  */