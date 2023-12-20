#include<bits/stdc++.h>
using namespace std;

struct data
{
	int p,pri,at,bt;
};
int n;
struct data k[10];
vector<int> v;
vector<pair<int,int> > m;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(k[a.first].pri!=k[b.first].pri)
	return k[a.first].pri<k[b.first].pri;
	else if(k[a.first].at!=k[b.first].at)
	return k[a.first].at<k[b.first].at;
	else if(k[a.first].bt!=k[b.first].bt)
	return k[a.first].bt<k[b.first].bt;
	return k[a.first].p<k[a.first].p;
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
	//cout<<j;
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
	cin>>k[i].p>>k[i].pri>>k[i].at>>k[i].bt;
	if(min>k[i].at)
		min=k[i].at;}
	//cout<<min;
	push_into_vect(min);
	// for(auto it: v)
	// 	cout<<it<<" ";
	push_into_pair(min);
	// for(auto it: m)
	// 	cout<<it.first<<" "<<it.second<<endl;
	sort(m.begin(),m.end(),cmp);
	// for(auto &it: m)
	// 	cout<<it.first<<" "<<it.second<<endl;

	int t=0;
	if(t<min)
	{
		cout<<t<<" to "<<min<<" idle"<<endl;
		t+=min;
	}

	while(v.size()!=n)
	{
		cout<<t<<" to "<<t+1<<" p"<<m[0].first<<endl;
		m[0].second--;
		if(m[0].second==0)
			k[m[0].first].pri=999;
		t+=1;
		push_into_vect(t);
		push_into_pair(t);
		sort(m.begin(),m.end(),cmp);
	}
	while(k[m[0].first].pri!=999)
	{
		cout<<t<<" to "<<t+m[0].second<<" p"<<m[0].first<<endl;
		t+=m[0].second;
		k[m[0].first].pri=999;
		sort(m.begin(),m.end(),cmp);

	}

}