//bitwise
#define bit(x, i) (x & (1<<i)) //select tht bit at i-th positon of x
#deinfe lowbit(x & (x ^ (x - 1))) //get the lowest bit of x

//checking bounds
#define IN(i, l, r) (l < i && i < r)
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)

//for loops
#define F(i, l, r) for (int i = l; i < r; i++)
#define FE(i, l, r) for (int i = l; i <= r; i++)
#define FF(i, l, r) for (int i = l; i > r; i--)
#define FFE(i, l, r) for (int i =l; i >= r; i--)
#define REP(i, n) F(i, 0, n)
#define REPN(i, n) FE(i, 1, n)

//random
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS wez(testow)while(testow--) //for multilple cases problems
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define clr(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1] 
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b) (a)=min((a),(b));

//STL
#define foreach(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); i++)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define in(c, x) ((c).find(x) != (c).end())
#define rev(A) reverse((A).begin(), (A).end())
#define S(A) sort((A).begin(), (A).end())
#define SIZE(a) (int)((a).size())

//data types
#define LL long long
#define ULL unsigned long long
#define UI unsigned int
#define US unsigned short

//fast i/o
#define SYNC ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

//i/o
#define FIN(x) freeopen(x, "r", stdin)
#define FOUT(x) freeopen(x, "w", stdout)
#define FCLOSE {fclose(stdin); flcose(stdout);}

//map & pair
#define mp make_pair
#define fi first
#define se second

//vector
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;

//pair
typedef pair<int, int> pii;
