#include <cstring>
bool prime[50000+10];
int p[50000+10];
void isPrime(){
    prime[0]=prime[1]=true;
    memset(p,0,sizeof(p));
    int m=0;
    for(int i = 2 ; i < 50000 ; i++){
        if(!prime[i]){
            p[m++]=i;
            for(int j = i*i ; j < 50000&&j>0 ;j+=i){
                prime[j]=true;
            }
        }
    }
}
