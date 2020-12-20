#include <bits/stdc++.h>
using namespace std;

int main (){
    int p,s,u,v,i,min=0,max=0;
    vector < pair <int,int> > vp;
    while(cin >> p >> s){ // EOF
        for(i=0;i<s;++i){
            cin >> u >> v;
            vp.push_back (make_pair(u,v));
        }
        sort(vp.begin(),vp.end());
        min = vp[0].first, max = vp[0].second;
        for(i=1;i<s;++i){ //percorre os intervalos
            if(vp[i].first > max){
                cout << min << ' ' << max << endl;
                min = vp[i].first, max = vp[i].second;
            }else if(vp[i].second > max){
                max = vp[i].second;
            }
        }
        cout << min << ' ' << max << endl;
    }
    
    return 0;
}