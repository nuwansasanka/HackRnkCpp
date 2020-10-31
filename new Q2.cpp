#include <iostream>
#include<vector>
using namespace std;
int greedy(vector<int> score,int);

int main(){
    
    	vector <int> score;
    		
   
    int n;
    int i; int val;
    cin>>n;
    for(i=0;i<n;i++) 
	{  
        cin>>val;
       score.push_back(val);
     }
     
     greedy(score,n);
}
int greedy(vector<int> score,int n)
{
	int masks[n];
	int t=0,i=0;
	

    
    for(i=0;i<n-1;i++){
        if(i==0 && score[i]>score[i+1])
        {
            masks[i]=2;
            masks[i+1]=1;
        }
        else if(i==0 && score[i]<score[i+1])
        {
            masks[i]=1;
            masks[i+1]=2;
        }
            else if(i==0 && score[i]==score[i+1])
        {
            masks[i]=2;
            masks[i+1]=1;
        }
        
        else if(score[i]>score[i+1])
        {   if(i!=n-2 && score[i+1]>score[i+2]){
            masks[i+1]=2;
             masks[i+2]=1;
             i=i+1;
        }  
           else
           {
              masks[i+1]=1;
           }
        }
        else if(score[i]<score[i+1])
        {
            masks[i+1]=masks[i]+1;
        }
            else if(score[i]=score[i+1])
        {
            masks[i+1]=1;
        }
        
    }
    
    for(i=0;i<n;i++)
    {
        t=t+masks[i];
    }
    cout<<t;
 
	
}
