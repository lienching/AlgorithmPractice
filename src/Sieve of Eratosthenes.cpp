bool prime[MAX];
void isPrime(){
    int s = sqrt(MAX);
    int k,j;
    prime[0] = prime[1] = true;
    for (int i=2; i<=s; i++)
        if (!prime[i]){
            for (k=(MAX-1)/i, j=i*k; k>=i; k--, j-=i)
                if (!prime[k])
                    prime[j] = true;
        }
}

// True為非質數