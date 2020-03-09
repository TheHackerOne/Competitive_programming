#include <bits/stdc++.h>
using namespace std;
long maximillian=0;
int main(){
	long t;
	cin>>t;
	while(t--)
	{  
	    long n,k;
	    cin>>n;
	    char c[n];
	    long A[4]={0},B[4]={0},C[4]={0},D[4]={0};
	    long a[n];
	    for(long i=0;i<n;i++)
	    {
	        cin>>c[i];
	        cin>>a[i];
	        if(c[i]=='A')
	        {
	            if(a[i]==12){
	                A[0]+=1;
	            }
	            if(a[i]==3){
	                A[1]+=1;
	            }
	            if(a[i]==6){
	                A[2]+=1;
	            }
	            if(a[i]==9){
	                A[3]+=1;
	            }
	        }
	        else if(c[i]=='B')
	        {
	            if(a[i]==12){
	                B[0]+=1;
	            }
	            if(a[i]==3){
	                B[1]+=1;
	            }
	            if(a[i]==6){
	                B[2]+=1;
	            }
	            if(a[i]==9){
	                B[3]+=1;
	            }
	        }
	        else if(c[i]=='C')
	        {
	            if(a[i]==12){
	                C[0]+=1;
	            }
	            if(a[i]==3){
	                C[1]+=1;
	            }
	            if(a[i]==6){
	                C[2]+=1;
	            }
	            if(a[i]==9){
	                C[3]+=1;
	            }
	        }
	        else if(c[i]=='D')
	        {
	            if(a[i]==12){
	                D[0]+=1;
	            }
	            if(a[i]==3){
	                D[1]+=1;
	            }
	            if(a[i]==6){
	                D[2]+=1;
	            }
	            if(a[i]==9){
	                D[3]+=1;
	            }
	        }
	    }
	    long A1[4]={0},B1[4]={0},C1[4]={0},D1[4]={0};
	    for(int i=0;i<4;i++)
	    {
	           if(i==0)
	           {
	                A1[0]=A[i];
    	            A1[1]=B[i];
    	            A1[2]=C[i];
    	            A1[3]=D[i];
	           }
	           else if(i==1)
	           {
	                B1[0]=A[i];
    	            B1[1]=B[i];
    	            B1[2]=C[i];
    	            B1[3]=D[i];
	           }
	           else if(i==2)
	           {
	                C1[0]=A[i];
    	            C1[1]=B[i];
    	            C1[2]=C[i];
    	            C1[3]=D[i];
	           }
	           else if(i==3)
	           {
	                D1[0]=A[i];
    	            D1[1]=B[i];
    	            D1[2]=C[i];
    	            D1[3]=D[i];
	           }
	    }
	    vector<int> sum;
	    vector<int> ultimate_sum;
	    int first1,second1,third1,fourth1,max=-400,sum1;
	    for(int i=0;i<4;i++)
	    {
	        int first=i;
	        for(int j=0;j<4;j++)
	        {
	            if(j!=first)
	            {
	                int second=j;
	                for(int k=0;k<4;k++)
	                {   
	                    if(k!=first && k!=second)
	                    {
	                        int third=k;
	                        for(int l=0;l<4;l++)
	                        {
	                            if(l!=first && l!=second && l!=third)
	                            {   int fourth=l,total,yes=0;
                                    sum.push_back(A1[first]);
                                    sum.push_back(B1[second]);
                                    sum.push_back(C1[third]);
                                    sum.push_back(D1[fourth]);
                                    sort(sum.begin(),sum.end());
                            	    total=(sum[3]*100)+(sum[2]*75)+(sum[1]*50)+(sum[0]*25);
                            	    for(long i=0;i<4;i++)
                            	    {
                            	        if(sum[i]==0)
                            	            yes+=1;
                            	    }
                            	    sum.clear();
                            	    total-=(yes*100);
                            	   // cout<<total<<"\n";
                            	    if(total>max)
                            	    {
                            	        max=total;
                            	        first1=first;
                            	        second1=second;
                            	        third1=third;
                            	        fourth1=fourth;
                            	    }
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }
        cout<<max<<"\n";
        maximillian+=max;
	 }
	cout<<maximillian<<"\n";
	return 0;
}
