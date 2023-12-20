
 //fifo practice

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];

	int f;
	cin>>f;
	int ff=f;
	queue<int> q;
	vector<int> hash(10);
	int i=0;
	int faults=0,hits=0;
	while(q.size()<f)
	{
		if(hash[v[i]]!=1)
		{
			q.push(v[i]);
			hash[v[i]]=1;
			faults++;
		}
		else
			hits++;
		i++;
	}
	//cout<<q.size()<<hits<<faults<<endl;
	
	
	for(int j=i;j<n;j++)
	{
		if(hash[v[j]]!=1)
		{
			int w=q.front();
			hash[w]=0;
			faults++;
			q.pop();
			q.push(v[j]);
			hash[v[j]]=1;

		}
		else
		{
			hits++;
		}
	}
	cout<<"hits are: "<<hits<<"faluts are: "<<faults;

}