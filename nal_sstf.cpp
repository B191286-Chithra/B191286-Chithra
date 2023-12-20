//ssts practice

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int head;
	cin>>head;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	sort(v.begin(),v.end());
	int l,r;
	for(int i=0;i<n-1;i++)
	{
	if(v[i]<=head and v[i+1]>=head)
	{
		l=i;
		r=i+1;
		break;
	}

	}
	//cout<<v[l]<<" "<<v[r];
	int count=0,f,sum=0;
	char prev='n';
	int hm=1;
	
	while(count!=n)
	{
		lsum=abs(v[l]-head);
		rsum=abs(v[r]-head);
		if(lsum<rsum)
		{
			sum+=abs(head-v[l]);
			prev=head-v[l];
			count++;
			head=v[l];
			l--;
			if(prev=='r')
				hm++:
			prev='l';

		}
		else
		{
			sum+=abs(v[r]-head);
			if(prev=='l')
				hm++;
			count++;
			head=v[r];
			r++;
			prev='r';
		}
		if(l<0 or r>=n)
		break;
	}
	sum+=abs(v[n-1]-v[0]);
	cout<<sum<<" "<<hm;

}