#include <bits/stdc++.h>

using namespace std;

int main(){
    int c,n,t,d,atual=0,sum=0,ct=0,aux=0;
    cin >> c >> n;
    vector <pair<int,int>> vp(n);
    cin >> vp[0].first >> vp[0].second;
    sum = vp[0].second;
    for(int i=1;i<n;++i){
        cin >> vp[i].first >> vp[i].second;
        if(vp[i].first<=atual){
            aux = sum-vp[i].first;
            if(aux>20)ct++;
            sum+=vp[i].second;
            atual=aux;  
        }else{
            aux = sum-2*(vp[i].first)+atual;
            if(aux>20)ct++;
            //cout << " ??? " << aux << " ";
            sum+=vp[i].second;
            atual+=aux;
        }
    }
    cout << ct << endl;
    
    return 0;
}