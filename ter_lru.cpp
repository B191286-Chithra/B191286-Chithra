//lru practice
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int f,ff;
	cin>>f;
	ff=f;
	queue<int> q;
	int i=0,faults=0,hits=0;
	vector<int> hash(n,0);
	while(q.size()<f)
	{
		if(hash[v[i]]!=1)
		{
			faults++;
			q.push(v[i]);
			hash[v[i]]=1;
		}
		else
		{	
			hits++;
			int t=q.front();
			q.pop();
			q.push(t);
		}
		i++;
	}

	for(int j=i;j<n;j++)
	{
		if(hash[v[j]]!=1)
		{
			faults++;
			//cout<<"fault "<<faults<<endl;
			hash[v[j]]=1;
			int t=q.front();
			hash[t]=0;
			q.pop();
			q.push(v[j]);
		}
		else
		{
			hits++;
			//cout<<"hits "<<hits<<endl;
			int t=q.front();
			if(t==v[j]){
			q.pop();
			q.push(t);}
			else
			{	q.pop();
				int k=q.front();
				if(k==v[j])
				{
					q.pop();
					int v=q.front();
					q.pop();
					q.push(t);
					q.push(v);
					q.push(k);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(hash[i]==1)
				cout<<i<<"  ";
		}
		cout<<endl;
	}
	cout<<endl<<"hits are: "<<hits<<endl<<"faults are: "<<faults;
}