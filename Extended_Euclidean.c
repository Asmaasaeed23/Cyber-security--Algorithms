#include <iostream>

using namespace std;

long long GCD(long long no_1,long long no_2){
    
	int X,Z;
	if(no_1>no_2){   
	    X=no_1;   
	    Z=no_2;
	    
	}
	else{ 
	      X=no_2;   
	      Z=no_1;
	    
	}
	while(X%Z !=0){
		int temp =Z;
		Z= X%Z;
		X=temp;
	}
	return Z;
}


int main()
{
   long long int  M,Y;
   
   	cin >> M;     
	cin >>Y;
	if (Y<0)
	{
		while(Y<0)  Y=Y+M;
	} 
	long long A1,A2,A3,B1,B2,B3;
	A1=1,A2=0,A3=M;
	B1=0,B2=1,B3=Y;
	while(1)
	{
		if (M==1)
		{
		    cout<<"IMPOSSIBLE"<<endl;
		    break;
		    
		}
		if (B3==0)
		{ 
		    cout<<"IMPOSSIBLE"<<endl; 
		    break;
		    
		}
		else {
			if (B3==1 ) 
			{ 
			    B3= GCD(M,Y);
			    
			if(M-Y>0)  cout <<(M-Y)%M<<" ";
			else   {
			    long long x= M-Y+M;    
			    while(x<0) x=x+M;  cout <<x%M<<" ";
			    
			}
			if (B2<0) 
			cout<<(M+B2)%M;
			
			else cout<<B2%M; 
			break;
			    
			}
			else {
			    long long Out = A3 /B3 ;
			    long long temp[3]={A1-Out*B1, A2-Out*B2, A3-Out*B3 };
			A1=B1,A2=B2,A3=B3;
			B1=temp[0]; 
			B2=temp[1];  
			B3=temp[2];
			}
		    
		}
	    
	}

    return 0;
}