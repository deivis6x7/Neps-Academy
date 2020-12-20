#include <bits/stdc++.h>
using namespace std;

int main (){
    int n, t, h, i, j;
    string str;
    cin >> n >> t;
    vector < pair <int, string> > vp;
    for(i=0; i<n; ++i){
        cin >> str >> h;
        vp.push_back(make_pair(-h,str));
    }
    
    sort(vp.begin(),vp.end()); // ordena pela habilidade (ordem inversa devido ao sinal)
    for(i=0;i<t;++i){
        cout << "Time " << i+1 << endl;
        vector <string> time;
        for(j=i;j<n;j+=t)
            time.push_back(vp[j].second);
        
        sort(time.begin(),time.end()); // ordena pelo nome
        for(j=0;j<time.size();++j)
            cout << time[j] << endl;
        cout << endl;
    }
    
    return 0;
}