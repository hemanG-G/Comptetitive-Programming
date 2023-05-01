// from : harisam

#define ll long long
template<class T, class U>
// T -> node, U->update.


// TO DO
// 1) CHANGE COMBINE FN
// 2) CHANGE APPLY FN
// 3) CHANGE COMBINE UPDATE FN
//  use identity element or identiy update if required

// NOTE:
//  size of array and seg tree must be same
// use 1 based indexing


struct Lsegtree {
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;

    /*
        THIS IS HOW YOU USE IDENTIY ELEMENT AND IDENTY UPDATE

        Definition of identity_element: the element I such that combine(x,I) = x
        for all x

        Definition of identity_update: the element I such that apply(x,I) = x
        for all x
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
        // change this function as required.
        // the funcation of what to do with l and r of a node

        // eg : for max
        // ans = max(l,r);
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
        // this is just updating values of range to upd
        T ans = (tr - tl + 1) * upd;
        // ans stores the sum of tl to tr
        // so this is how you update every element in tl - tr to upd

        // eg : increment range by upd:
        //T ans = curr + (tr - tl + 1)*upd

        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        // lazy propogation in segment trees
        // combining  the lazy update with the new update , to update together

        //eg : if update means adding 'x' to the range
        // U ans = old_upd + new_upd



        // the below is case where update means assigning value to a range
        U ans = old_upd;
        ans = new_upd;
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