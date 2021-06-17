#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int father[MAX], weight[MAX], pt[MAX];

int find(int num){
    if(father[num]==num)
        return num;
    return father[num]=find(father[num]);
}
 
void join(int x, int y){ 
    x=find(x);
    y=find(y);
    pt[y] = pt[y] + pt[x];
    father[x]=father[y]; 
}

int main(){
    string str;
    int n,m,i,num,q,a,b,fael,fda,fdb,ans;
    while(cin >> n >> m){
        if(!n and !m)
            break;
        ans=0;
        for(i=1; i<=n; i++){
            cin >> pt[i];
            father[i]=i;
        }
        for(i=0;i<m;++i){
            cin >> q >> a >> b;
            if(q==1){
                join(a,b);
            }else 
                if(q==2){
                fael=find(1);
                fda=find(a);
                fdb=find(b);

                if(pt[fda]<pt[fdb] and fdb==fael){
                    ans++;
                }else
                    if(pt[fda]>pt[fdb] and fda==fael){
                        ans++;
                    }
                }
        }
        cout << ans << endl;        
    }
    
    return 0;
}