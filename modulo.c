using namespace std;

int modul(long long a,long long b,long long M){
    long long K=1,Y=a;
    while(b > 0){
        if(b%2 == 1){
            K=(K*Y)%M;
        }
        Y= (Y*Y)%M; 
        b /= 2;
    }
    return K%M;
}

int main()
{
    long long a,b,M;
    cin>>a>>b>>M;
    cout<<modul(a,b,M);
    
    return 0;
}