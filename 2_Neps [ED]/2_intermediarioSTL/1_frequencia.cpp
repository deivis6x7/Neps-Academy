#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,v;
    set <int> s;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> v;
        s.insert(v);
    }
    cout << s.size() << endl;
    return 0;
}