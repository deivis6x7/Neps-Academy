#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,d,left=0,right=0,sum=0,ans=0;
    cin >> n >> d;
    vector <int> v(n*2);
    for(int i=0;i<n;++i){
        cin >> v[i];
        v[i+n]=v[i];
    }

    for(left=0;left<n;++left){
        while(sum<d and right<left+n){
            sum+=v[right++];
        }
        if(sum==d)ans++;
        sum-=v[left];
    }

    cout << ans << endl;

    return 0;
}