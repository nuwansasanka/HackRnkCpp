#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
  
 
void Sort(double arr[], int n,int arr1[]) 
{ 
   
    if (n == 1) 
        return; 
  
   
    for (int i=0; i<n-1; i++) 
        if (arr[i] < arr[i+1]) {
		
            swap(arr1[i], arr1[i+1]); 
  			swap(arr[i],arr[i+1]);
  		}
    
    Sort(arr, n-1,arr1); 
} 

void knapsack(int arr1[],double arr2[],int M,int N){
	double dencity[M];
	int i,j;
int x[M];
	int wt=0;
	for(i=0;i<M;i++){
		
		dencity[i]=arr2[i]/arr1[i];
		
		}
	
 
	
    Sort(dencity, M,arr1); 
    
    
    
    for(i=0;i<M;i++){
    			x[i]=0;
    		}
    		int val=0;
    		j=0;
    while(wt<N){
    
    	
    		if(wt+arr1[j]<=N){
    			x[j]=1;
    			wt=wt+arr1[j];
    			val=(dencity[j]*arr1[j]*x[j])+val;
    			
			}
			else{
				
				val=val+dencity[j]*(N-wt);
				x[j]=(N-wt)/arr1[j];
				wt=N;
				
				
			}
			j++;
		}
	
    
    
  //Maximum value
	cout<<val;
}

int main(){
	int N ; //number of bottles in each barrel
	int M ;//value of each barrel
	int i;
	int volume[M];
	double value[M];

	
	//cout<<"Enter the number of bottles that sadun has & shop has :";
	cin>>N>>M;
	
	//cout<<"Enter the volume os each barrel:";
	for(i=0;i<M;i++){
		cin>>volume[i];
	}
	

	
	//cout<<"Enter the value of each barrel";
	for(i=0;i<M;i++){
		cin>>value[i];
	}
	
knapsack(volume,value,M,N);

}
