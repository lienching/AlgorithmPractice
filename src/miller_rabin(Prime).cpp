#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

typedef long long LL;
using namespace std;
bool isprime(int n);
LL pow(int a,int u ,int n);
LL mul(LL x,LL y,int n);
int main(){
    int in;
    while(cin >> in){
        if(isprime(in)){
            cout << "質數" << endl;
        }
        else{
            cout << "非質數" << endl;
        }
    }
    return 0;
}

bool isprime(int n)
{
    // 預先判斷偶數與1，節省一點時間。
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    
    int u = n - 1, t = 0;
    while (u % 2 == 0) {u >>= 1; t++;}
    
    // 推定是質數，就實施下一次測試；
    // 確定是合數，就馬上結束。
    int sprp[3] = {2, 7, 61};   // 足以涵蓋int範圍
    for (int k=0; k<3; ++k)
    {
        // a沒有大於1、小於n-1的限制，
        // 沒有測試意義的數字，當作是通過測試。
        // （a是質數時，模n後不會等於零，不必特別判斷。）
        int a = sprp[k] % n;
        if (a == 0 || a == 1 || a == n-1) continue;
        
        LL x = pow(a, u, n);
        if (x == 1 || x == n-1) continue;
        
        for (int i = 0; i < t-1; i++)
        {
            x = mul(x, x, n);
            if (x == 1) return false;
            if (x == n-1) break;
        }
        if (x == n-1) continue;
        
        return false;
    }
    // 通過全部測試，確定是質數。
    return true;
}

LL pow(int a,int u ,int n){
    LL t=1;
    for(int i = 0;i<u;i++){
        t*=a;
    }
    return t%n;
}

LL mul(LL x,LL y,int n){
    return x*y%n;
}