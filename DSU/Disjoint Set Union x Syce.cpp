// TRUSTED ATCODER TEMPLATE 

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}
 
    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }
 
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
 
    int leader(int a) { // GETS PARENT == LEADER
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
 
    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }
 
    std::vector<std::vector<int>> groups() { // RETURN ALL GROUPS
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
 
  private:
    int _n;
    std::vector<int> parent_or_size;
};

// USAGE
// dsu d(n);
// if(d.same(u,v)){
           
// }
// d.merge(u,v);

///////////////////////////////////////////////////////////////////////////




// Problem: https://codeforces.com/contest/1476/problem/D

int parent[N],siz[N];
// in dsu true parent is the value which parent[i]=i 
int findParent(int i)
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i]);
    return parent[i];
}
void unionNodes(int a,int b)
{
    int parent_a=findParent(a),parent_b=findParent(b);
    if(parent_a==parent_b)
        return;
    if(siz[parent_a]>=siz[parent_b]){ // assuming b > a 
        swap(parent_a,parent_b);
    }
    siz[parent_b]+=siz[parent_a]; 
    parent[parent_a]=parent_b; // b eats a ( large eats small)
    return;
}
void cleardsu(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
        siz[i]=1;
        parent[i+K]=i+K; // FIRST ARRAY UPTO 3e5 ,then 2nd array starts after 3e5+10 
        siz[i+K]=1;
    }
}
///////////////////////////////////////////



// n= no of nodes
// k = no of connections
// u ,v values inside nodes
// connected_componenets_cnt  == no of parent nodes (each group has 1 parent)


int main() {
	int n , k ;
	cin >> n >> k ;

	for ( int i = 0 ; i < n ; i++) {
		make(i);
	}

	while (k--) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	int connected_componenets_cnt ;

	for (int i ; i <= n ; i++) {
		if (find[i] == i) {
			connected_componenets_cnt++;
		}
	}
}










// !!!!!!!!!CONCEPT!!!!!!!!!!!

//parent array
int parent[n];
// each bucket of this array denote // index = number
// value inside = parent of that index
int size[n]; // array that stores SIZE OF THE GROUP of that index
void make(int a) { // makes a new independent node
	parent[a] = a;
	size[a] = 1; // when a new node is made , its size is 1
}
int find(int a) { // FINDS PARENT OF input
	if (parent[a] == a) return a;
	// this condition is satisfied only i arrive at parent node

	//	WITHOUT PATH COMPRESSION
	// if above not satisfied
	//return find(parent[a]);// recursively find parent of a

	// APPLYING PATH COMPRESSION
	return parent[a] = find(parent[a]);
	// IN THE PARENT ARRAY ,
	//EARLIER THE IMMEDIATE PARENT
	// NOW IS REPLACED BY THE FINAL PARENT OF THAT GROUP
	// !!!!!!!!HENCE PATH COMPRESSION !!!!!!!!!
}
void Union(int a, int b) {
	// first we find root of each graph
	a = find(a);
	b = find(b);
	// if parent of a and b are same ,  we do nothing, as they are from same GROUP
	if (a != b ) {

		// !!!!!!!!!!UNION BY SIZE!!!!!!!!!!
		// FOR BEST OPTIMIZATION , WE ALWAYS ADD SMALL GROUP TO LARGER GROUP
		// so a = larger always
		// b = smaller alwys
		if (size[a] < size[b]) {
			swap(a, b);
		}
		// join parent of one group to parent of other
		parent[b] = a; // JOINTING PARENTS(ROOTS ) OF TWO GROUPS
		//now two groups have been merged
		size[a] += size[b];
	}

}





