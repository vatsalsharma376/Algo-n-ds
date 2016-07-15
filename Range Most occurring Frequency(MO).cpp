#include <bits/stdc++.h>
using namespace std;
#define getcx getchar_unlocked
#define putcx putchar_unlocked
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846
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
typedef long long ll ;
typedef unsigned long long ull ;


int N , Q , arr[100000+10] , ans[100000+10] , cnt[200000+10] , freq[200000+10] , maxi , block = 550 ;

struct Node
{
    int L , R , id ;
    bool operator < (const Node &A) const
    {
        if(L/block == A.L/block) return R < A.R ;
        else return L/block < A.L/block ;
    }
}input[100000+10];

void add(int index)
{
    if(index==0) return ;
    if(cnt[arr[index]]!=0) freq[cnt[arr[index]]]--;
    cnt[arr[index]]++;
    freq[cnt[arr[index]]]++;
    if(cnt[arr[index]]>maxi) maxi = cnt[arr[index]] ;
}

void remove(int index)
{
    if(index==0) return ;
    freq[cnt[arr[index]]]--;
    if(freq[maxi]==0) maxi--;
    cnt[arr[index]]--;
    if(cnt[arr[index]]!=0)freq[cnt[arr[index]]]++;
}

int main()
{
    while( true)
    {
    	N=IN();
    	if(!N) break;
        Q=IN();
        for(int i=1;i<=N;i++)
        {
            arr[i]=IN();
            arr[i]+=100000;
        }
        for(int i=1;i<=Q;i++)
        {
            //scanf("%d%d",&input[i].L,&input[i].R);
            input[i].L=IN();
            input[i].R=IN();
            input[i].id = i ;
        }
        sort(input+1,input+Q+1);
        int currentL = 0 , currentR = 0 ;
        for(int i=1;i<=Q;i++)
        {
            int L = input[i].L , R = input[i].R ;
            while( currentL < L ) remove(currentL++);
            while( currentL > L ) add(--currentL) ;
            while( currentR < R ) add(++currentR);
            while( currentR > R ) remove(currentR--);
            ans[input[i].id] = maxi ;
        }
        for(int i=1;i<=Q;i++){
        	oup(ans[i]); puts("");	
        } 
        for(int i=0;i<=200000;i++) freq[i] = cnt[i] = maxi = 0 ;
    }
    return 0;
}
