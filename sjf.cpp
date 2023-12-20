//shortest job first

#include<bits/stdc++.h>
using namespace std;

struct data
{
	int p,at,bt;	
};

int main()
{
		int n;
		cin>>n;
		struct data s[n];
		for(int i=1;i<=n;i++)
		cin>>s[i].p>>s[i].at>>s[i].bt;
		
		
		int min_arr=999,index,b;
		for(int i=1;i<=n;i++)
		{
			if(min_arr>s[i].at)
			{
				index=s[i].p;
				min_arr=s[i].at;
				b=s[i].bt;	
			}
			else if(min_arr==s[i].at)
			{
				if(s[index].bt>s[i].bt)
				{
					min_arr=s[i].at;
					index=s[i].p;
					b=s[i].bt;
				}
			}
		}
		//cout<<index<<endl<<endl;
		s[index].bt=999;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(s[j].bt<s[i].bt)
				{
					int temp=s[j].p;
					s[j].p=s[i].p;
					s[i].p=temp;
					
					temp=s[j].at;
					s[j].at=s[i].at;
					s[i].at=temp;
					
					temp=s[j].bt;
					s[j].bt=s[i].bt;
					s[i].bt=temp;
				
				}
				else if(s[j].bt==s[i].bt)
				{
					if(s[j].at<s[i].at)
					{
						int temp=s[j].p;
					s[j].p=s[i].p;
					s[i].p=temp;
					
					temp=s[j].at;
					s[j].at=s[i].at;
					s[i].at=temp;
					
					temp=s[j].bt;
					s[j].bt=s[i].bt;
					s[i].bt=temp;
					}
					else if(s[j].at==s[i].at)
					{
						if(s[j].p<s[i].p)
						{
							int temp=s[j].p;
							s[j].p=s[i].p;
							s[i].p=temp;
					
							temp=s[j].at;
							s[j].at=s[i].at;
							s[i].at=temp;
					
							temp=s[j].bt;
							s[j].bt=s[i].bt;
							s[i].bt=temp;
						}
					}
				}
			}
		}
		
		//for(int i=1;i<=n;i++)
		//cout<<s[i].p<<" "<<s[i].at<<" "<<s[i].bt<<endl;
		
		int t=0;
		if(t<min_arr)
		cout<<t<<" to "<<min_arr<<" --> "<<"idle"<<endl;
		t=t+min_arr;
		cout<<t<<" to "<<t+b<<" --> "<<" p"<<index<<endl;
		t=t+b;
		
		for(int i=1;i<n;i++)
		{
			if(t<s[i].at){
			cout<<t<<" to "<<t+s[i].at<<" --> idle"<<endl;
			t=t+s[i].at;}
			cout<<t<<" to "<<t+s[i].bt<<" --> p"<<s[i].p<<endl;
			t=t+s[i].bt;
		}
		
		
		
}