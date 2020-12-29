#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int c,n,i,v,p,aux=-1;
    map <int,int> m;
    vector <pair<int,int>> vp;
    cin >> c >> n;
    for(i=0;i<c;++i){
        cin >> p >> v;
        m.insert(make_pair(p,v));
    }
    for(i=0;i<n;++i){
        cin >> p >> v;
        if(v>m[p]){
            v*=-1;
            vp.push_back(make_pair(p,v));
        }
    }

    sort(vp.begin(),vp.end());
    vector <pair<int,int>>::iterator it;
    for(it=vp.begin();it!=vp.end();++it){
        if(aux!=it->first)
            cout << it->first << " " << (-1)*it->second << endl;
        aux = it->first;  
    }
        
    return 0;
}