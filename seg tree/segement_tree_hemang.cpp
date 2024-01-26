// from : harisam
// T -> nature of node, U->nature of update.
// 99% cases both integers

// TO DO
// 1) CHANGE COMBINE FN
// 2) CHANGE APPLY FN
// 3) CHANGE COMBINE UPDATE FN
// 4) if identity element or update are not int type , custom define == operator () 
//  use identity element or identiy update if required

// NOTE:
//  size of array and seg tree must be same
// use 1 based indexing


template<class T, class U>
struct Lsegtree {
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;
    /*  THIS IS HOW YOU USE IDENTIY ELEMENT AND IDENTY UPDATE
        Definition of identity_element: the element I such that combine(x,I) function = x
        for all x
        //eg QUERY for
        // max ::  T = -inf
        // sum ::  T =  0 
        Definition of identity_update: the element I such that apply(x,I) function = x
        for all x
        // eg: UPDATE : add element to range 
        //  U = 0  ; (add 0 , no change )
        // eg : assign some value to range
        //  U = -1 ; (dont assign if U =-1)
    */

    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }


    T combine(T l, T r)
    {
        // COMBINE TWO NODES
        // OPERATION OF "QUERY"
        // the funcation of what to do with l and r of a node

        // eg : for max QUERY
        // T ans = max(l,r);
        // T ans = min(l,r);
        // T ans = gcd(l,r);
        T ans = (l + r);
        return ans;
    }


    void buildUtil(ll v, ll tl, ll tr, vector<T>&a)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil(2 * v + 1, tl, tm, a);
        buildUtil(2 * v + 2, tm + 1, tr, a);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }



    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
        
        
        // APPLY UPDATE TO NODE
        // UPDATE PART , NOT QUERY
        
        
        // this is just updating values of range to upd    
        // eg1 :  UPDATE sum ? 
        // ans stores the new sum
        T ans = (tr - tl + 1) * upd;

        // eg2 : updating increment range by upd:
        //T ans = curr + (tr - tl + 1)*upd
        
        // eg3:  updating to  max
        // ans stores the max
        // T ans = upd;

        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        // UPDATE PART , NOT QUERY
        // lazy propogation in segment trees
        // AT A NODE combining  lazy update with the new update 

        // the below is case where update means assigning  new value to a range , so old upd useless
        U ans = old_upd;
        ans = new_upd;
         
        //eg : if update means adding 'x' to the range
        // U ans = old_upd + new_upd

        return ans;        
    }


    void push_down(ll v, ll tl, ll tr)
    {
        //for the below line to work, make sure the "==" operator is defined for U.
        if (lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2 * v + 1 <= 4 * n)
        {
            ll tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v, tl, tr);
        if (l > r)return identity_element;
        if (tr < l or tl > r)
        {
            return identity_element;
        }
        if (l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr) >> 1;
        return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
    }

    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v, tl, tr);
        if (tr < l or tl > r)return;
        if (tl >= l and tr <= r)
        {
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
            push_down(v, tl, tr);
        }
        else
        {
            ll tm = (tl + tr) >> 1;
            updateUtil(2 * v + 1, tl, tm, l, r, upd);
            updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
            st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
        }
    }



    void build(vector<T>a)
    {
        assert( (ll)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }
    void update(ll l, ll r, U upd)
    {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};





















// understanding & coding from scratch in progress



template <class node> class segment2 {
   private:
      int id(int l,int r){return (l+r)|(l!=r);}
      void build(int l,int r,typename node::info &y){if(l==r){seg[id(l,r)]=node{y,node::empty_tag()};return;}int mid=(l+r)/2;build(l,mid,y);build(mid+1,r,y);seg[id(l,r)]=node{node::merge(seg[id(l,mid)].Info,seg[id(mid+1,r)].Info),node::empty_tag()};}
      void push_down(int l,int r){int mid=(l+r)/2,ls=id(l,mid),rs=id(mid+1,r),pt=id(l,r);seg[ls]={node::merge(seg[ls].Info,seg[pt].Tag),node::merge(seg[ls].Tag,seg[pt].Tag)};seg[rs]={node::merge(seg[rs].Info,seg[pt].Tag),node::merge(seg[rs].Tag,seg[pt].Tag)};seg[pt].Tag=node::empty_tag();}
      void change(int L,int R,int l,int r,typename node::tag& y){if(L<=l&&r<=R){seg[id(l,r)]={node::merge(seg[id(l,r)].Info,y),node::merge(seg[id(l,r)].Tag,y)};return;}int mid=(l+r)/2;push_down(l,r);if(L<=mid)change(L,R,l,mid,y);if(R>mid)change(L,R,mid+1,r,y);seg[id(l,r)].Info=node::merge(seg[id(l,mid)].Info,seg[id(mid+1,r)].Info);}
      typename node::info query(int L,int R,int l,int r){if(L<=l&&r<=R)return seg[id(l,r)].Info;push_down(l,r);int mid=(l+r)/2;if(L>mid)return query(L,R,mid+1,r);else if(R>mid)return node::merge(query(L,R,l,mid),query(L,R,mid+1,r));else return query(L,R,l,mid);}
   public:
      vector<node> seg;int siz;
      segment2(int n,typename node::info y){siz=n;seg.resize(2*n+4);build(1,siz,y);}
      void change(int l,int r,typename node::tag y){change(l,r,1,siz,y);}
      typename node::info query(int l,int r){return query(l,r,1,siz);}
};
struct node {
   struct info {
      int len,sum;
   }Info;
   struct tag {
      int add;
   }Tag;
   static tag empty_tag() {
      return {0};
   }
   static info merge(info a,info b) {
      return {a.len+b.len,a.sum+b.sum};
   }
   static tag merge(tag a,tag b) {
      return {a.add+b.add};
   }
   static info merge(info a,tag b) {
      return {a.len,a.sum+a.len*b.add};
   }
};


//This is the template code of this segment. It consists of two parts, a `segment2` class, and a `node` struct. next I will describe how to use it efficiently, you only need to care about `node` struct, you don't need to focus on specifics how `segment2` implement.

//There are two substructs in `node`, `info` and `tag`. `info` is generally used to save the information you need, `tags` are generally used to save the modifications you did.

//In the example, we want this segment tree to support interval add, query sum of intervals. So in `info` we write the information we need: `sum`, and the information we need to calculate: `len`. in `tag` we write the number we added.

//Next, four functions need to be filled in.

//- first, `empty_tag`, one of the easiest to understand. +0 = empty tag. do nothing.
// - second, merge two `info`, so it's easy, len and sum are added separately.
// - third, merge two tag, like you `+a` first, and then you `+b`, so merge it is you did `+(a+b)`.
// - last, you need merge a info and tag, so if a interval have len and sum, you did `+x`, then this interval `sum+=len*x`.

// then you do `segment2<node> Q(5,{1,0})`, you can use the tree normally now (The initial information info means that each point starts with 0 and is of length 1.).

// Here are some node examples and explanations:


// interval add, query interval max value
struct node {
   struct info {
      int max;
   }Info;
   struct tag {
      int add;
   }Tag;
   static tag empty_tag() {
      return {0};
   }
   static info merge(info a,info b) {
      return {max(a.max,b.max)};
   }
   static tag merge(tag a,tag b) {
      return {a.add+b.add};
   }
   static info merge(info a,tag b) {
      return {a.max+b.add};
   }
};
segment2<node> Q(maxn,{0});



// interval set value, query interval gcd
struct node {
   struct info {
      int gcd;
   }Info;
   struct tag {
      bool isempty; // Because the interval set cannot be marked empty, you need to manually add this
      int setvalue;
   }Tag;
   static tag empty_tag() {
      return {true,0};
   }
   static info merge(info a,info b) {
      return {__gcd(a.gcd,b.gcd)};
   }
   static tag merge(tag a,tag b) {
      if(b.isempty) return a;
      return b;
   }
   static info merge(info a,tag b) {
      if(b.isempty) return a;
      return {b.setvalue};
   }
};
segment2<node> Q(maxn,{1});
/*
The initial values will still be attempted to be merged during the calculation
so it is necessary to ensure that the RTE is not given
*/



// interval a[i]=max(a[i],x), query interval minum value
struct node {
   struct info {
      int min;
   }Info;
   struct tag {
     int mx;
   }Tag;
   static tag empty_tag() {
      return {-2147483647}; // a[i]=max(a[i],-2147483647) -> did nothing, just a[i]=a[i]
   }
   static info merge(info a,info b) {
      return {min(a.min,b.min)};
   }
   static tag merge(tag a,tag b) {
      return {max(a.mx,b.mx)};
   }
   static info merge(info a,tag b) {
      return {max(b.mx,a.min)};
   }
};
segment2<node> Q(maxn,{0});
///



// single point set value, interval maximum subarray sum
struct node {
   struct info {
      int sum,lmax,rmax,ans;
   }Info;
   struct tag {
      bool empty_tag;
      int set_value;
   }Tag;
   static tag empty_tag() {
      return {true,0};
   }
   static info merge(info a,info b) {
      return {a.sum+b.sum,max(a.lmax,a.sum+b.lmax),max(b.rmax,b.sum+a.rmax),max({a.ans,b.ans,a.rmax+b.lmax})};
   }
   static tag merge(tag a,tag b) {
      if(b.empty_tag) return a;
      return b;
   }
   static info merge(info a,tag b) {
      if(b.empty_tag) return a;
      return {b.set_value,b.set_value,b.set_value,b.set_value};
   }
};
// There are situations where a different order can lead to a different result, and this template can handle it well
// In other words, merge function don't need commutative

//In the 99% cases, segment trees you use can be written all by this template in less than two minutes. unless you want the segment tree to support some special operation like segbeats or something.