#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int Greedy(vector<int> weight,int);
int main()
{
	vector <int> weight;
	 int n;
	 cin>>n;
	 int i=0;int val;
	 for(i=0;i<n;i++){
	 	cin>>val;
	 	weight.push_back(val);
	 	
	 }
	 sort(weight.begin(),weight.end());
	Greedy(weight,n);
}
int Greedy(int weight[],int n)
{
	int i=0,j=0,t=0;

	int z=0,m=0;
	
      while(i<n){
		m=weight[i];
	      j=i+1;
		while(m+4>=weight[j])
		{
			j++;
		}
		z++;
	}
	printf("%d",z);
}
