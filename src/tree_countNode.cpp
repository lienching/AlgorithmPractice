#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
int data[100001];
int visit[100001];
std::vector<int> child[100001];

int dfs(int n){
   // printf("node %d: %d\n",n,data[n]);
    visit[n]=1;
    data[n]=1;
    for(int i=0;i<child[n].size();++i){
        if(!visit[child[n][i]])
            data[n]+=dfs(child[n][i]);
    }
    return data[n];
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(data,0,sizeof(data));
        int n,n1,n2;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            child[i].clear();
            visit[i]=0;
        }
        for(int i = 0 ; i < n-1 ;i++){
            scanf("%d %d",&n1,&n2);
            child[n1].push_back(n2);
            data[n1]++;
            child[n2].push_back(n1);
            data[n2]++;
        }
        dfs(0);
        printf("node 0: %d\n",n);
        for(int i = 1 ; i < n ; i++){
            printf("node %d: %d\n",i,data[i]);
        }
    }
    return 0;
}