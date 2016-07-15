#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define lines printf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
using namespace std;
int IN () {                                       // REMEMBER TO CHANGE DATATYPE
    bool minus = false;                                     
    int result = 0;
    char ch;
    ch = getcx();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getcx();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getcx();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
template<class ty>void oup(ty x) {
        char s[20];
        short i=0;
        do{
            s[i++]=x%10+'0';
            x/=10;
        }while(x);
        --i;
        while(i>-1)putcx(s[i--]);
}
