#include <bits/stdc++.h>
using namespace std;

int main (){
    int m,n,i,num,*ptr;
    cin >> n;
    int V[n];
    for(i=0;i<n;++i)cin >> V[i];

    cin >> m;
    for(i=0;i<m;++i){
        cin >> num;
        ptr = find(V,V+n,num);
        (*ptr)=-1;
    }

    for(i=0;i<n;++i){
        if(V[i]!=-1)cout << V[i] << " ";
    }
    cout << endl;

    return 0;
}