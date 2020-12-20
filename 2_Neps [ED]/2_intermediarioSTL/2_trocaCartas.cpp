#include <bits/stdc++.h>

using namespace std;

int main() {
    set <int> s1,s2;
    set <int>::iterator it;
    int A,B,C,num,ct=0;
    cin >> A >> B;
    for(int i=0;i<A;++i){
        cin >> num;
        s1.insert(num);
    }
    for(int i=0;i<B;++i){
        cin >> num;
        s2.insert(num);  
    }
    for(it=s2.begin();it!=s2.end();++it){
        if(s1.find(*it)!=s1.end())ct++;
    }

    C = min(s1.size(),s2.size());
    cout << C-ct << endl;
    return 0;
}