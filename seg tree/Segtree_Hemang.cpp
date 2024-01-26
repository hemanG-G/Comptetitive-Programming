// jan 15 2024


// level 1 seg tree: range sum , point update
//https://codeforces.com/contest/61/submission/243036375
struct SegTree{
public:
	SegTree(int _n){
		n=_n;
		tree.resize(4*_n,0);
	}
	
	int query(int x, int y){
		return query(x,y,0,n-1,0); // x,y , l,r(the range represented by curr node) , curr index (root ka index = 0) 
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


//level 2 :
