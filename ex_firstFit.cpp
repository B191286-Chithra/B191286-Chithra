// eternal practice first fit

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);
	for(int i=1;i<=n;i++)
		cin>>v[i];
	//cout<<"hi";

	int b;
	cin>>b;

	vector<int> block(b);
	for(int i=1;i<=b;i++)
		cin>>block[i];
	vector<int> hash(b);
	int inf=0;

	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(j<=b)
		{
			if(v[i]<=block[j] and hash[j]!=1)
			{
				cout<<"p"<<i<<" is allocated to b"<<j<<endl;
				inf+=block[j]-v[i];
				hash[j]=1;
				break;
			}
			j++;
		}

	}
	cout<<"internal fragmentation: "<<inf<<endl;
	int k=1;
	int exf=0;
	while(k<=b)
	{
		if(hash[k]!=1)
			exf+=block[k];
		k++;
	}
	cout<<"external fragmentation: "<<exf;
}