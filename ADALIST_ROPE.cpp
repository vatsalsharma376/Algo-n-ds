/*
Queries : 
1 k x means that you will add number x to position k

2 k means that you will erase number from position k

3 k means that you will print number from position k
*/

#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
rope<int>r;
int main(){
    ios_base::sync_with_stdio(0);
    int n,q,i,x,t,k;
    cin>>n>>q;
    for(i=0;i<n;++i){
        cin>>x;
        r.push_back(x);
    }
    while(q--){
        cin>>t>>k;
        --k;
        if(t==1){
            cin>>x;
            r.insert(k,x);
        }
        else if(t==2)r.erase(k,1);
        else cout<<r.at(k)<<'\n';
    }
    return 0;
}
