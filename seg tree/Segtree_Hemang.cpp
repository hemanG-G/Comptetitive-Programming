// jan 15 2024


// type 1 seg tree: range sum , point update
//https://codeforces.com/contest/61/submission/243036375
struct SegTree{
public:
	SegTree(int _n){
		n=_n;
		tree.resize(4*_n,0);
	}
	
	int query(int x, int y){
		return query(x,y,0,n-1,0); // x,y , l,r(the range of indexes represented by curr node) , curr index (root ka index = 0) 
	}
	
	void update(int ind , int val){
		update(ind,val,0,n-1,0); // ind, val , l,r , curr index
		
	}
	
private:
	vector<int> tree;
	int n; 
	// void build(){
	// }
	int query(int x , int y ,int l , int r , int i ){// sum query l to r here
		if(y<l || x > r ) return 0;
		
		if(l>=x && y>=r)return tree[i]; // WTF
		
		// children of curr node ka ranges are 
		//left child = (l-mid) & right child = (mid+1 - r )
		
		int m = (l+r)>>1;
		
		
		return (query(x,y,l,m,2*i+1)+ query(x,y,m+1,r,2*i+2) ) ;
		
	}
	
	void update(int ind , int  val , int l , int r , int i){
		if(l==r){ // point update
			tree[i]=val;
			return;
		}
		// children of curr node ka ranges are 
		//left child = (l-mid) & right child = (mid+1 - r )
		int m = (l+r)>>1;
		
		 if(m>=ind){
		 	update(ind ,val , l , m  ,2*i +1 );
		 }
		 else{
		 	update(ind , val ,m+1 , r , 2*i+2);
		 }
		tree[i]= tree[2*i +1] + tree[2*i+2];
		
	}
	
};



//type 2 : ( CUSTOM MERGE FUNCTION)
// REST SAME -> RANGE MAX + POINT UPDATE
// problem : https://www.spoj.com/problems/HMLIS/
struct SegTree{
public:
    SegTree(int _n){
        n=_n;
        tree.resize(4*_n,{0,0});
    }
    
    pii query(int x, int y){
        return query(x,y,0,n-1,0); // x,y , l,r(the range represented by curr node) , curr index (root ka index = 0) 
    }
    
    void update(int ind , pii val){
        update(ind,val,0,n-1,0); // ind, val , l,r , curr index
        
    }
    
private:
    vector<pii> tree; // lis , cnt 
    int n; 
    // void build(){
    // }
    pii merge(pii left , pii right){
        if(left.ff == right.ff){
            if(left.ff==0){
                return {0,1};
            }
            
            
            pii result = {left.ff,(left.ss + right.ss)};
            if(result.ss>=MOD)
                result.ss-=MOD;
            
            return result;
            
        }
        return max(left ,right); // we choose max only 
    }
    
    
    pii query(int x , int y ,int l , int r , int i ){// max query l to r here
        if(y<l || x > r ) return {0,1}; // min can always be {1,1} , so 0 will always be ignored    
        
        if(l>=x && y>=r)return tree[i]; // WTF
        
        // children of curr node ka ranges are 
        //left child = (l-mid) & right child = (mid+1 - r )
        
        int m = (l+r)>>1;
        
        
        return merge(query(x,y,l,m,2*i+1),query(x,y,m+1,r,2*i+2) );
        
    }
    
    void update(int ind , pii  val , int l , int r , int i){
        if(l==r){ // point update
            tree[i]=val;
            return;
        }
        // children of curr node ka ranges are 
        //left child = (l-mid) & right child = (mid+1 - r )
        int m = (l+r)>>1;
        
         if(m>=ind){
            update(ind ,val , l , m  ,2*i +1 );
         }
         else{
            update(ind , val ,m+1 , r , 2*i+2);
         }
        tree[i]= merge(tree[2*i +1] , tree[2*i+2] ) ;
        
    }
    
};


//level 2 :


void solve(int tc) {
    int n ;cin >> n ; 
    vi a(n);cin >> a; 
    
    vector<pii> val_ind; 
    fo(i,0,n-1){
        val_ind.pb({a[i],i});
    }
    sort(all(val_ind));
    vi pos(n);
    fo(i,0,n-1){
        pos[val_ind[i].ss]=i;
    }
    
    SegTree tree(n);// lis, cnt pair 
    
    fo(i,0,n-1){
        
        int lb =std::lower_bound (val_ind.begin() ,val_ind.end()  ,make_pair(a[i],-1)) - val_ind.begin();
        pii x = {1,1};//default val
        if(lb>0){
            
            x= tree.query(0,lb-1);
            x.ff++;// lis+1
            if(x.ff>=MOD){
                x.ff-=MOD;
            }
            
        }
        
        tree.update(pos[i],x);
        
        
    }
    
    pii out =  tree.query(0,n-1);
    cout << out.ff << " " << out.ss <<  nl;
}





// type 3 : binary search within the tree itself
// problem :https://leetcode.com/problems/sliding-subarray-beauty/description/
struct SegmentTree {

public:

    SegmentTree (int _n) : n (_n) {
        tree.resize(4*n, 0);
    }

    void update (int ind, int val) {
        update (ind, val, 0, n-1, 0);
    }

    int firstIndexGreaterThanPrefixSumX (int x) {
        return query (x, 0, n-1, 0);
    }

private:

    void update (int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree[i] += val;
            return;
        }

        int m = (l+r)/2;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);

        tree[i] = tree[i*2+1] + tree[i*2+2];
    }

    int query (int x, int l, int r, int i) {
        if (l == r) {
            if (tree[i] >= x) return l;
            return n;
        }

        int m = (l+r)/2;
        int lft = i*2+1, rgt = i*2+2;

        if (tree[lft] >= x) return query (x, l, m, lft);
        return query (x - tree[lft], m+1, r, rgt);
    }

    vector<int> tree;
    int n;
};

class Solution {
    SegmentTree* tree;

    int valToTreeIndex (int val) {
        return (val + 50);
    }

    int treeIndexToVal (int ind) {
        return (ind - 50);
    }

    void Add (int val) {
        tree -> update (valToTreeIndex(val), 1);
    }
    
    void Remove (int val) {
        tree -> update (valToTreeIndex(val), -1);
    }
    
    int XthLargest (int x) {
        int index = tree -> firstIndexGreaterThanPrefixSumX(x);
        int val = treeIndexToVal(index);

        if (val >= 0) return 0;
        return val;
    }
    
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> result;
        int n = nums.size();
        tree = new SegmentTree (101);
        
        for (int j = 0; j < k-1; j ++) Add (nums[j]);
        for (int j = k-1; j < n; j ++) {
            Add (nums[j]);

            result.push_back(XthLargest (x));
            
            Remove (nums[j-k+1]);
        }
        
        return result;
    }
};
