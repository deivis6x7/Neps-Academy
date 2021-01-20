#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int father[MAX], weight[MAX];

int find(int num){
    if(father[num]==num)
        return num;
    return father[num]=find(father[num]);
}
 
void join(int x, int y){ 
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    if(weight[x]<weight[y])
        father[x]=y;
    if(weight[x]>weight[y])
        father[y]=x;
    if(weight[x]==weight[y]){
        father[x]=y;
        weight[y]++;
    }
}

int main(){
    char op;
    int n, k, i, bank1, bank2;
    cin>>n>>k;
    
    for(i=1; i<=n; i++)
        father[i]=i;
    
    for(i=1; i<=k; i++){
        cin>>op>>bank1>>bank2;
        if(op=='F')
            join(bank1, bank2);
        
        if(op=='C'){
            if(find(bank1)==find(bank2))
                cout<<"S\n";
            else
                cout<<"N\n";
        }
    }
    
    return 0;
}