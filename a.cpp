#include <bits/stdc++.h>
#define MAX(a,b)   (((a)>(b))?(a):(b))
#define MIN(a,b)   (((a)>(b))?(b):(a))
#define ABS(x)     ((x>0)?(x):(-(x)))
#define ulli       unsigned long long int
#define lli        long long int
#define pb         push_back
#define mp         make_pair
#define fi         first
#define se         second
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define vi         vector<lli>
#define pii        pair<lli,lli> 
#define piii       pair<lli,pii > 
#define matrix     vector<vector<lli> > 
#define itr        iterator
#define ub         upper_bound
#define lb         lower_bound
#define rep(lo,hi) for(lli i=lo;i<hi;i++)
#define repe(e,lo,hi) for(lli e=lo;e<hi;e++)
#define trv(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mem(a,val) memset(a,val,sizeof(a))
#define digits(n)  (floor(log10(n))+1)
#define bin_1(n)    __builtin_popcount(n)
#define ios        ios_base::sync_with_stdio(false);cin.tie(0)
#define out        cerr<<(float(clock())/CLOCKS_PER_SEC)<<endl
#define iss(s)     istringstream(s)
#define MOD        1000000007
#define PI         acos(-1.0)
#define eps        1e-9
#define oo         (lli)1e18+10
#define minint     INT_MIN
#define maxint		 INT_MAX
#define lim        100000
#define N (int)1e5+10
const int inf = 0x3f3f3f3f;
using namespace std;
bool v[lim];int len, ps[lim];
/////////SIEVE START////////
void Sieve(){	for (int i = 2; i <lim; i += 2)	ps[i] = 2;//even numbers have smallest prime factor 2
for (lli i = 3; i <lim; i += 2){ if (!v[i]){	ps[i] = i;for (lli j = i; (j*i) <lim; j += 2){
if (!v[j*i])	v[j*i] = true, ps[j*i] = i;}}}}////////SIEVE END/////////
lli CEIL(lli num,lli den) { lli res=num/den; if(num%den) res++; return res; }
lli gcd(lli a,lli b) { if(b==0) return a; return gcd(b,a%b); }
int bin1(lli x) { int r=0; while(x) { r++; x&=x-1; } return r; }
lli exgcd(lli a,lli b,lli &x,lli &y){ if(a==0) { x=0; y=1; return b; } lli x1,y1,gcd=exgcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return gcd; }
lli power(lli b,lli e) { if(e==0) return 1; if (e%2==0) return power(b*b,e/2); return b*power(b*b,e/2); }
double powerf(double b,int e) {if(e==0) return 1; if(e%2==0)return powerf(b*b,e/2); else{ if(e>0)return b*powerf(b*b,e/2); else return powerf(b*b,e/2)/b;}}
lli modpow(lli b,lli e,lli m) { lli r=1; b=b%m; while(e>0) { if(e%2==1) r=(r*b)%m; e/=2; b=(b*b)%m; } return r; }
lli modinverse(lli a,lli mod) { return modpow(a,mod-2,mod);    }
lli modinverse2(lli a,lli m) { lli x,y; exgcd(a,m,x,y);  while(x<0) x+=m; return x; }
lli nCrmod(lli n,lli r,lli m) {if(r>n) r=n-r; lli res=1; for(lli i=r;i>=1;i--) { res=(res*(n-i+1))%m; res=(res*modinverse(i,m)); } return res; }
lli nCr(lli n,lli r) {if(r>n) r=n-r; lli res=1; for(lli i=r;i>=1;i--) { res*=(n-i+1); res/=i; } return res; }
lli totient(lli n) { lli res=n,p; for(p=2;p*p<=n;p++){ if(n%p==0){ while(n%p==0) n/=p; res-=res/p; }} if(n>1) res-=res/n; return res; }
bool isprime(lli x) { if(x==1) return false; for(lli i=2;i*i<=x;i++) if(x%i==0) return false; return true; }
bool isvowel(char c) { if(isupper(c)) c=tolower(c); return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }
bool istriangle(lli a,lli b,lli c) { return (a+b>c)&&(a+c>b)&&(b+c>a); }
lli stringmod(string s,lli mod) { lli res=0; for(unsigned int i=0;i<s.size();i++) res=(res*10+s[i]-'0')%mod; return res; }
lli powinfact(lli n,lli p) { lli res=0,pw=p; while(n>=pw) { res+=(n/pw); pw*=p; } return res; }
matrix matrixmultiply(matrix A,matrix B,lli n) { matrix C(2,vector<lli>(n)); for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) C[i][j]=(C[i][j]+A[i][k]*B[k][j]); return C; }
matrix modmatrixmultiply(matrix A,matrix B,lli n,lli mod) { matrix C(2,vector<lli>(n)); for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod; return C; }
matrix powermatrix(matrix A,lli exp,lli n) { if(exp==1) return A; if(exp%2) return matrixmultiply(A,powermatrix(A,exp-1,n),n); matrix X=powermatrix(A,exp/2,n); return matrixmultiply(X,X,n); }
matrix modpowmatrix(matrix A,lli exp,lli n,lli mod) { if(exp==1) return A; if(exp%2) return modmatrixmultiply(A,modpowmatrix(A,exp-1,n,mod),n,mod); matrix X=modpowmatrix(A,exp/2,n,mod); return modmatrixmultiply(X,X,n,mod); }
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
//////////////////////////////DFS START/////////////////////
void dfs(int i,vi& V,matrix W) { 
       if(V[i]==0) {   V[i] = 1;   //printf("%d ",i+1); ANYTHING YOU WANT TO DO WITH CURRENT DFS ELEMENT
            for(int j=0;j<V.size();j++) {
            	if((W[i][j]!=0)&&(V[j]==0))
            	dfs(j,V,W);}  	}       } 
int count_comp_dfs(int n,matrix W)
{ 
       int start_vertex = 0,count=0; vi V = vi(n, 0);
       do{  count++;
       //printf("\n");WGHATEVER YOU WANNA DO AFTER A COMPONENT
       dfs(start_vertex,V,W); 
       }while((find(all(V), 0) != V.end())&&(start_vertex=find(all(V), 0)-V.begin()));
       //rep(0,n)  cout<<V[i]<<" "; CHECK FINAL STATUS OF ELEMENTS 
       return count;
}
/////////////////////////DFS END////////////////////////
//////////////////////BFS START//////////////////
int count_comp_bfs(int n,matrix W) { 
      int start_vertex = 0,p=0,count=0; vi V(n,0); queue<int> Q; 
      do{ count++; Q.push(start_vertex); V[start_vertex] = 1; 
      while(!Q.empty()) { 
           int i = Q.front(); //////////whatever you wanna do with the element
           Q.pop(); 
           for(int j=0;j<n;j++) { 
                if(W[i][j]!=0&&V[j]==0) {   V[j]=1;    Q.push(j); 
                } 
           }
      }   /////////whatever you wanna do after each component
      }while(find(all(V), 0) != V.end()&&(start_vertex=find(all(V), 0)-V.begin())); 
      rep(0,n)  cout<<V[i]<<" "; //CHECK FINAL STATUS OF ELEMENTS 
      return count; }
//////////////////////BFS END////////////////////
//////////////////////DIJKSTRA START/////
vi dijkstra(int n,matrix W)
{
	vi D(N, 987654321);  set<pii> Q;  D[0] = 0;  Q.insert(pii(0,0));
      while(!Q.empty()) 
           {pii top = *Q.begin();  Q.erase(Q.begin());  int i = top.second, d = top.first;
           for(int j=0;j<n;j++) if(W[i][j]!=0){           			
                int v2 = j,cost=W[i][j];
                if(D[v2]>D[i]+cost) {    if(D[v2] != 987654321) {
                           Q.erase(Q.find(pii(D[v2],v2)));         ///erase from set if present there
                     }
                     D[v2] = D[i] + cost;
                     Q.insert(pii(D[v2], v2));}
           }
}//cout<<D[4];
return D;
}
////////////////////DIJKSTRA END/////////
void pre()
{
}
void judge()
{
	int a,n,x=0,y=0;
	vector<lli> arr,brr;
	cin>>n;
	rep(0,n)
	{
		cin>>a;arr.pb(a);x+=a;
	}
	rep(0,n)
	{
		cin>>a;brr.pb(a);y+=a;
	}
	x=x-*max_element(arr.begin(),arr.end());
	y=y-*max_element(brr.begin(),brr.end());
	if(x<y)
		cout<<"Alice\n";
	else if(x>y)
		cout<<"Bob\n";
	else
		cout<<"Draw\n";
	return;
}
void gcj()
{   //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-output.out","w",stdout);
    freopen("B-large.in","r",stdin);
    freopen("B-large-output.out","w",stdout);
    lli t;
    cin>>t;
    for(lli c=1;c<=t;c++)
    {   cout<<"Case #"<<c<<": ";
    		judge();
        cout<<"\n";
    }
}
int main()
{   
		ios;
    pre();
    lli tt=1;
    cin>>tt;
   	while(tt--)
    {
   		judge();
   	}
   	return 0;
}
