#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
#define int ll
using pi = pair<int, int>;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define FOR3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define FOR_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define all(x) x.begin(), x.end()

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

// [入力
ll in() {
  ll i;
  cin >> i;
  return i;
}

pi in2(int off = 0) {
  ll a, b;
  cin >> a >> b;
  return {a + off, b + off};
}

tuple<ll, ll, ll> in3() {
  ll a, b, c;
  cin >> a >> b >> c;
  return {a, b, c};
}

vi vin(int n, int off = 0) {
  vi A(n);
  for (auto && x : A) {
    cin >> x;
    x += off;
  }
  return A;
}

string sin() {
  string s;
  cin >> s;
  return s;
}
// 入力]

// [出力
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (int i = 0; i < A.size(); i++) {
    if (i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}
// 出力]

template <typename T>
ll sum(T A) {
  return accumulate(all(A), 0);
}

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto && x : A) {
    ++C[x];
  }
  return C;
}

template <typename T>
struct vec2d {
  ll H, W;
  vector<vector<T>> data;
  vec2d(ll H, ll W) : H(H), W(W), data(H, vector<T>(W)) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  void print() { FOR(i, H) print_itr(all(data[i])); }
  vector<T>& operator[](ll i) { return data[i]; }
  pi shape() {return mp(H, W);}
};

template <class T, class U>
bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class U>
bool chmin(T& a, const U& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#line 3 "main.cpp"

template <typename T1, typename T2, typename T3>
void solve() {
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  auto [N, M] = in2();
  ll now = 0;
  vi A(N);
  FOR(i, N) {
    auto [a, b] = in2();
    now += a;
    A[i] = a - b;
  }
  sort(all(A));
  reverse(all(A));
  A = cumsum(A);
  auto n = lower_bound(all(A), now - M) - A.begin();
  if (n == N + 1) n = -1;
  print(n);
  return 0;
}



#line 1 "library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
                           template <>
                           constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
                           template <>
                           constexpr u32 infty<u32> = infty<int>;
                           template <>
                           constexpr u64 infty<u64> = infty<ll>;
                           template <>
                           constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
                           template <>
                           constexpr double infty<double> = infty<ll>;
                           template <>
                           constexpr long double infty<long double> = infty<ll>;

                           using pi = pair<ll, ll>;
                           using vi = vector<ll>;
                           template <class T>
                           using vc = vector<T>;
                           template <class T>
                           using vvc = vector<vc<T>>;
                           template <class T>
                           using vvvc = vector<vvc<T>>;
                           template <class T>
                           using vvvvc = vector<vvvc<T>>;
                           template <class T>
                           using vvvvvc = vector<vvvvc<T>>;
                           template <class T>
                           using pq = priority_queue<T>;
                           template <class T>
                           using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

                           // https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) \
  for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

                           int popcnt(int x) { return __builtin_popcount(x); }
                           int popcnt(u32 x) { return __builtin_popcount(x); }
                           int popcnt(ll x) { return __builtin_popcountll(x); }
                           int popcnt(u64 x) { return __builtin_popcountll(x); }
                           // (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
                           int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
                           int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
                           int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
                           int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
                           // (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
                           int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
                           int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
                           int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
                           int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

                           template <typename T, typename U>
                           T ceil(T x, U y) {
                           return (x > 0 ? (x + y - 1) / y : x / y);
                           }
                           template <typename T, typename U>
                           T floor(T x, U y) {
                           return (x > 0 ? x / y : (x - y + 1) / y);
                           }
                           template <typename T, typename U>
                           pair<T, T> divmod(T x, U y) {
                           T q = floor(x, y);
                           return {q, x - q * y};
                           }

                           template <typename T, typename U>
                           T SUM(const vector<U> &A) {
                           T sum = 0;
                           for (auto &&a: A) sum += a;
                           return sum;
                           }

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

                           template <typename T>
                           T POP(deque<T> &que) {
                           T a = que.front();
                           que.pop_front();
                           return a;
                           }
                           template <typename T>
                           T POP(pq<T> &que) {
                           T a = que.top();
                           que.pop();
                           return a;
                           }
                           template <typename T>
                           T POP(pqg<T> &que) {
                           assert(!que.empty());
                           T a = que.top();
                           que.pop();
                           return a;
                           }
                           template <typename T>
                           T POP(vc<T> &que) {
                           assert(!que.empty());
                           T a = que.back();
                           que.pop_back();
                           return a;
                           }

                           template <typename F>
                           ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
                           if (check_ok) assert(check(ok));
                           while (abs(ok - ng) > 1) {
                           auto x = (ng + ok) / 2;
                           tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));
                           }
                           return ok;
                           }
                           template <typename F>
                           double binary_search_real(F check, double ok, double ng, int iter = 100) {
                           FOR(iter) {
                           double x = (ok + ng) / 2;
                           tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));
                           }
                           return (ok + ng) / 2;
                           }

                           template <class T, class S>
                           inline bool chmax(T &a, const S &b) {
                           return (a < b ? a = b, 1 : 0);
                           }
                           template <class T, class S>
                           inline bool chmin(T &a, const S &b) {
                           return (a > b ? a = b, 1 : 0);
                           }

                           // ? は -1
                           vc<int> s_to_vi(const string &S, char first_char) {
                           vc<int> A(S.size());
                           FOR(i, S.size()) { A[i] = (S[i] != ' ? ' ? S[i] - first_char : -1); }
                           return A;
                           }

                           template <typename T, typename U>
                           vector<T> cumsum(vector<U> &A, int off = 1) {
                           int N = A.size();
                           vector<T> B(N + 1);
                           FOR(i, N) { B[i + 1] = B[i] + A[i]; }
                           if (off == 0) B.erase(B.begin());
                           return B;
                           }

                           // stable sort
                           template <typename T>
                           vector<int> argsort(const vector<T> &A) {
                           vector<int> ids(len(A));
                           iota(all(ids), 0);
                           sort(all(ids),
                           [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
                           return ids;
                           }

                           // A[I[0]], A[I[1]], ...
                           template <typename T>
                           vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
                           vc<T> B(len(I));
                           FOR(i, len(I)) B[i] = A[I[i]];
                           return B;
                           }
#endif
#line 1 "library/other/io.hpp"
// based on yosupo's fastio
#include <unistd.h>

namespace fastio {
#define FASTIO
// クラスが read(), print() を持っているかを判定するメタ関数
struct has_write_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.write(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_write : public decltype(has_write_impl::check<T>(std::declval<T>())) {
};

struct has_read_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.read(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_read : public decltype(has_read_impl::check<T>(std::declval<T>())) {};

struct Scanner {
  FILE *fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <typename T,
            typename enable_if<has_read<T>::value>::type * = nullptr>
  inline bool read_single(T &x) {
    x.read();
    return true;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }
  bool read_single(char &ref) {
    string s;
    if (!read_single(s) || s.size() != 1) return false;
    ref = s[0];
    return true;
  }
  template <class T>
  bool read_single(vector<T> &ref) {
    for (auto &d : ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T, class U>
  bool read_single(pair<T, U> &p) {
    return (read_single(p.first) && read_single(p.second));
  }
  template <size_t N = 0, typename T>
  void read_single_tuple(T &t) {
    if constexpr (N < std::tuple_size<T>::value) {
      auto &x = std::get<N>(t);
      read_single(x);
      read_single_tuple < N + 1 > (t);
    }
  }
  template <class... T>
  bool read_single(tuple<T...> &tpl) {
    read_single_tuple(tpl);
    return true;
  }
  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write(const char val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write('0');
      return;
    }
    if (val < 0) {
      write('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 - i]; }
    pos += len;
  }
  void write(const string s) {
    for (char c : s) write(c);
  }
  void write(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write(s[i]);
  }
  void write(const double x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  void write(const long double x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  template <typename T,
            typename enable_if<has_write<T>::value>::type * = nullptr>
  inline void write(T x) {
    x.write();
  }
  template <class T>
  void write(const vector<T> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  template <class T, class U>
  void write(const pair<T, U> val) {
    write(val.first);
    write(' ');
    write(val.second);
  }
  template <size_t N = 0, typename T>
  void write_tuple(const T t) {
    if constexpr (N < std::tuple_size<T>::value) {
      if constexpr (N > 0) { write(' '); }
      const auto x = std::get<N>(t);
      write(x);
      write_tuple < N + 1 > (t);
    }
  }
  template <class... T>
  bool write(tuple<T...> tpl) {
    write_tuple(tpl);
    return true;
  }
  template <class T, size_t S>
  void write(const array<T, S> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  void write(i128 val) {
    string s;
    bool negative = 0;
    if (val < 0) {
      negative = 1;
      val = -val;
    }
    while (val) {
      s += '0' + int(val % 10);
      val /= 10;
    }
    if (negative) s += "-";
    reverse(all(s));
    if (len(s) == 0) s = "0";
    write(s);
  }
};
Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);
void flush() { printer.flush(); }
void print() { printer.write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.read(head);
  read(tail...);
}
} // namespace fastio
using fastio::print;
using fastio::flush;
using fastio::read;

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 2 "library/alg/monoid/add.hpp"

template <typename X>
struct Monoid_Add {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }
  static constexpr X unit() { return X(0); }
  static constexpr bool commute = true;
};
#line 3 "library/ds/fenwicktree/fenwicktree.hpp"

template <typename Monoid>
struct FenwickTree {
  using G = Monoid;
  using E = typename G::value_type;
  int n;
  vector<E> dat;
  E total;

  FenwickTree() {}
  FenwickTree(int n) { build(n); }
  template <typename F>
  FenwickTree(int n, F f) {
    build(n, f);
  }
  FenwickTree(const vc<E>& v) { build(v); }

  void build(int m) {
    n = m;
    dat.assign(m, G::unit());
    total = G::unit();
  }
  void build(const vc<E>& v) {
    build(len(v), [&](int i) -> E { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m;
    dat.clear();
    dat.reserve(n);
    total = G::unit();
    FOR(i, n) { dat.eb(f(i)); }
    for (int i = 1; i <= n; ++i) {
      int j = i + (i & -i);
      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j - 1]);
    }
    total = prefix_sum(m);
  }

  E prod_all() { return total; }
  E sum_all() { return total; }
  E sum(int k) { return prefix_sum(k); }
  E prod(int k) { return prefix_prod(k); }
  E prefix_sum(int k) { return prefix_prod(k); }
  E prefix_prod(int k) {
    chmin(k, n);
    E ret = G::unit();
    for (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);
    return ret;
  }
  E sum(int L, int R) { return prod(L, R); }
  E prod(int L, int R) {
    chmax(L, 0), chmin(R, n);
    if (L == 0) return prefix_prod(R);
    assert(0 <= L && L <= R && R <= n);
    E pos = G::unit(), neg = G::unit();
    while (L < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }
    while (R < L) { neg = G::op(neg, dat[L - 1]), L -= L & -L; }
    return G::op(pos, G::inverse(neg));
  }

  void add(int k, E x) { multiply(k, x); }
  void multiply(int k, E x) {
    static_assert(G::commute);
    total = G::op(total, x);
    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);
  }

  template <class F>
  int max_right(const F check) {
    assert(check(G::unit()));
    int i = 0;
    E s = G::unit();
    int k = 1;
    while (2 * k <= n) k *= 2;
    while (k) {
      if (i + k - 1 < len(dat)) {
        E t = G::op(s, dat[i + k - 1]);
        if (check(t)) { i += k, s = t; }
      }
      k >>= 1;
    }
    return i;
  }

  int kth(E k) {
    return max_right([&k](E x) -> bool { return x <= k; });
  }
};
#line 2 "library/graph/tree.hpp"

#line 2 "library/graph/base.hpp"

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
};

template <typename T = int, bool directed = false>
struct Graph {
  int N, M;
  using cost_type = T;
  using edge_type = Edge<T>;
  vector<edge_type> edges;
  vector<int> indptr;
  vector<edge_type> csr_edges;
  vc<int> vc_deg, vc_indeg, vc_outdeg;
  bool prepared;

  class OutgoingEdges {
  public:
    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}

    const edge_type* begin() const {
      if (l == r) { return 0; }
      return &G->csr_edges[l];
    }

    const edge_type* end() const {
      if (l == r) { return 0; }
      return &G->csr_edges[r];
    }

  private:
    const Graph* G;
    int l, r;
  };

  bool is_prepared() { return prepared; }
  constexpr bool is_directed() { return directed; }

  Graph() : N(0), M(0), prepared(0) {}
  Graph(int N) : N(N), M(0), prepared(0) {}

  void build(int n) {
    N = n, M = 0;
    prepared = 0;
    edges.clear();
    indptr.clear();
    csr_edges.clear();
    vc_deg.clear();
    vc_indeg.clear();
    vc_outdeg.clear();
  }

  void add(int frm, int to, T cost = 1, int i = -1) {
    assert(!prepared);
    assert(0 <= frm && 0 <= to && to < N);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

  // wt, off
  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off); }

  void read_graph(int M, bool wt = false, int off = 1) {
    for (int m = 0; m < M; ++m) {
      INT(a, b);
      a -= off, b -= off;
      if (!wt) {
        add(a, b);
      } else {
        T c;
        read(c);
        add(a, b, c);
      }
    }
    build();
  }

  void read_parent(int off = 1) {
    for (int v = 1; v < N; ++v) {
      INT(p);
      p -= off;
      add(p, v);
    }
    build();
  }

  void build() {
    assert(!prepared);
    prepared = true;
    indptr.assign(N + 1, 0);
    for (auto && e : edges) {
      indptr[e.frm + 1]++;
      if (!directed) indptr[e.to + 1]++;
    }
    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }
    auto counter = indptr;
    csr_edges.resize(indptr.back() + 1);
    for (auto && e : edges) {
      csr_edges[counter[e.frm]++] = e;
      if (!directed)
        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});
    }
  }

  OutgoingEdges operator[](int v) const {
    assert(prepared);
    return {this, indptr[v], indptr[v + 1]};
  }

  vc<int> deg_array() {
    if (vc_deg.empty()) calc_deg();
    return vc_deg;
  }

  pair<vc<int>, vc<int>> deg_array_inout() {
    if (vc_indeg.empty()) calc_deg_inout();
    return {vc_indeg, vc_outdeg};
  }

  int deg(int v) {
    if (vc_deg.empty()) calc_deg();
    return vc_deg[v];
  }

  int in_deg(int v) {
    if (vc_indeg.empty()) calc_deg_inout();
    return vc_indeg[v];
  }

  int out_deg(int v) {
    if (vc_outdeg.empty()) calc_deg_inout();
    return vc_outdeg[v];
  }

  void debug() {
    print("Graph");
    if (!prepared) {
      print("frm to cost id");
      for (auto && e : edges) print(e.frm, e.to, e.cost, e.id);
    } else {
      print("indptr", indptr);
      print("frm to cost id");
      FOR(v, N) for (auto && e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);
    }
  }

  // G における頂点 V[i] が、新しいグラフで i になるようにする
  Graph<T, directed> rearrange(vc<int> V) {
    int n = len(V);
    map<int, int> MP;
    FOR(i, n) MP[V[i]] = i;
    Graph<T, directed> G(n);
    for (auto && e : edges) {
      if (MP.count(e.frm) && MP.count(e.to)) {
        G.add(MP[e.frm], MP[e.to], e.cost);
      }
    }
    G.build();
    return G;
  }

private:
  void calc_deg() {
    assert(vc_deg.empty());
    vc_deg.resize(N);
    for (auto && e : edges) vc_deg[e.frm]++, vc_deg[e.to]++;
  }

  void calc_deg_inout() {
    assert(vc_indeg.empty());
    vc_indeg.resize(N);
    vc_outdeg.resize(N);
    for (auto && e : edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }
  }
};
#line 4 "library/graph/tree.hpp"

// HLD euler tour をとっていろいろ。
// 木以外、非連結でも dfs 順序や親がとれる。
template <typename GT>
struct Tree {
  using Graph_type = GT;
  GT &G;
  using WT = typename GT::cost_type;
  int N;
  vector<int> LID, RID, head, V, parent, VtoE;
  vc<int> depth;
  vc<WT> depth_weighted;

  Tree(GT &G, int r = 0, bool hld = 1) : G(G) { build(r, hld); }

  void build(int r = 0, bool hld = 1) {
    if (r == -1) return; // build を遅延したいとき
    N = G.N;
    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);
    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);
    depth.assign(N, -1), depth_weighted.assign(N, 0);
    assert(G.is_prepared());
    int t1 = 0;
    dfs_sz(r, -1, hld);
    dfs_hld(r, t1);
  }

  void dfs_sz(int v, int p, bool hld) {
    auto &sz = RID;
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sz[v] = 1;
    int l = G.indptr[v], r = G.indptr[v + 1];
    auto &csr = G.csr_edges;
    // 使う辺があれば先頭にする
    for (int i = r - 2; i >= l; --i) {
      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i + 1]);
    }
    int hld_sz = 0;
    for (int i = l; i < r; ++i) {
      auto e = csr[i];
      if (depth[e.to] != -1) continue;
      depth_weighted[e.to] = depth_weighted[v] + e.cost;
      VtoE[e.to] = e.id;
      dfs_sz(e.to, v, hld);
      sz[v] += sz[e.to];
      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }
    }
  }

  void dfs_hld(int v, int &times) {
    LID[v] = times++;
    RID[v] += LID[v];
    V[LID[v]] = v;
    bool heavy = true;
    for (auto && e : G[v]) {
      if (depth[e.to] <= depth[v]) continue;
      head[e.to] = (heavy ? head[v] : e.to);
      heavy = false;
      dfs_hld(e.to, times);
    }
  }

  vc<int> heavy_path_at(int v) {
    vc<int> P = {v};
    while (1) {
      int a = P.back();
      for (auto && e : G[a]) {
        if (e.to != parent[a] && head[e.to] == v) {
          P.eb(e.to);
          break;
        }
      }
      if (P.back() == a) break;
    }
    return P;
  }

  int e_to_v(int eid) {
    auto e = G.edges[eid];
    return (parent[e.frm] == e.to ? e.frm : e.to);
  }
  int v_to_e(int v) { return VtoE[v]; }

  int ELID(int v) { return 2 * LID[v] - depth[v]; }
  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }

  /* k: 0-indexed */
  int LA(int v, int k) {
    assert(k <= depth[v]);
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u]) return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }
  int la(int u, int v) { return LA(u, v); }

  int LCA(int u, int v) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }
  // root を根とした場合の lca
  int LCA_root(int u, int v, int root) {
    return LCA(u, v) ^ LCA(u, root) ^ LCA(v, root);
  }
  int lca(int u, int v) { return LCA(u, v); }
  int lca_root(int u, int v, int root) { return LCA_root(u, v, root); }

  int subtree_size(int v, int root = -1) {
    if (root == -1) return RID[v] - LID[v];
    if (v == root) return N;
    int x = jump(v, root, 1);
    if (in_subtree(v, x)) return RID[v] - LID[v];
    return N - RID[x] + LID[x];
  }

  int dist(int a, int b) {
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  WT dist_weighted(int a, int b) {
    int c = LCA(a, b);
    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];
  }

  // a is in b
  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }

  int jump(int a, int b, ll k) {
    if (k == 1) {
      if (a == b) return -1;
      return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
    }
    int c = LCA(a, b);
    int d_ac = depth[a] - depth[c];
    int d_bc = depth[b] - depth[c];
    if (k > d_ac + d_bc) return -1;
    if (k <= d_ac) return LA(a, k);
    return LA(b, d_ac + d_bc - k);
  }

  vc<int> collect_child(int v) {
    vc<int> res;
    for (auto && e : G[v])
      if (e.to != parent[v]) res.eb(e.to);
    return res;
  }

  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge) {
    // [始点, 終点] の"閉"区間列。
    vc<pair<int, int>> up, down;
    while (1) {
      if (head[u] == head[v]) break;
      if (LID[u] < LID[v]) {
        down.eb(LID[head[v]], LID[v]);
        v = parent[head[v]];
      } else {
        up.eb(LID[u], LID[head[u]]);
        u = parent[head[u]];
      }
    }
    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);
    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);
    reverse(all(down));
    up.insert(up.end(), all(down));
    return up;
  }

  vc<int> restore_path(int u, int v) {
    vc<int> P;
    for (auto && [a, b] : get_path_decomposition(u, v, 0)) {
      if (a <= b) {
        FOR(i, a, b + 1) P.eb(V[i]);
      } else {
        FOR_R(i, b, a + 1) P.eb(V[i]);
      }
    }
    return P;
  }
};
#line 3 "library/graph/ds/tree_abelgroup.hpp"

template <typename TREE, typename AbelGroup, bool edge, bool path_query,
          bool subtree_query>
struct Tree_AbelGroup {
  using X = typename AbelGroup::value_type;
  TREE &tree;
  int N;
  FenwickTree<AbelGroup> bit, bit_subtree;

  Tree_AbelGroup(TREE &tree) : tree(tree), N(tree.N) {
    build([](int i) -> X { return AbelGroup::unit(); });
  }

  Tree_AbelGroup(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N) {
    build([&](int i) -> X { return dat[i]; });
  }

  template <typename F>
  Tree_AbelGroup(TREE &tree, F f) : tree(tree), N(tree.N) {
    build(f);
  }

  template <typename F>
  void build(F f) {
    vc<X> bit_raw_1(2 * N);
    vc<X> bit_raw_2(N);
    if (!edge) {
      FOR(v, N) {
        X x = f(v);
        bit_raw_1[tree.ELID(v)] = x;
        bit_raw_1[tree.ERID(v)] = AbelGroup::inverse(x);
        bit_raw_2[tree.LID[v]] = x;
      }
    } else {
      FOR(e, N - 1) {
        int v = tree.e_to_v(e);
        X x = f(v);
        bit_raw_1[tree.ELID(v)] = x;
        bit_raw_1[tree.ERID(v)] = AbelGroup::inverse(x);
        bit_raw_2[tree.LID[v]] = x;
      }
    }
    bit.build(bit_raw_1);
    bit_subtree.build(bit_raw_2);
  }

  void add(int i, X x) {
    int v = (edge ? tree.e_to_v(i) : i);
    if (path_query) {
      X inv_x = AbelGroup::inverse(x);
      bit.add(tree.ELID(v), x);
      bit.add(tree.ERID(v), inv_x);
    }
    if (subtree_query) bit_subtree.add(tree.LID[v], x);
  }

  X prod_path(int frm, int to) {
    assert(path_query);
    int lca = tree.LCA(frm, to);
    // [frm, lca)
    X x1 = bit.prod(tree.ELID(lca) + 1, tree.ELID(frm) + 1);
    // edge なら (lca, to]、vertex なら [lca, to]
    X x2 = bit.prod(tree.ELID(lca) + edge, tree.ELID(to) + 1);
    return AbelGroup::op(x1, x2);
  }

  X prod_subtree(int u) {
    assert(subtree_query);
    int l = tree.LID[u], r = tree.RID[u];
    return bit_subtree.prod(l + edge, r);
  }
};
#line 1 "library/ds/fastset.hpp"
/* 64分木。
insert, erase
[]での存在判定
next, prev
*/
struct FastSet {
  using uint = unsigned;
  using ull = unsigned long long;

  int bsr(ull x) { return 63 - __builtin_clzll(x); }
  int bsf(ull x) { return __builtin_ctzll(x); }

  static constexpr uint B = 64;
  int n, lg;
  vector<vector<ull>> seg;
  FastSet(int _n) : n(_n) {
    do {
      seg.push_back(vector<ull>((_n + B - 1) / B));
      _n = (_n + B - 1) / B;
    } while (_n > 1);
    lg = int(seg.size());
  }
  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }
  void insert(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] |= 1ULL << (i % B);
      i /= B;
    }
  }
  void erase(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] &= ~(1ULL << (i % B));
      if (seg[h][i / B]) break;
      i /= B;
    }
  }

  // x以上最小の要素を返す。存在しなければ n。
  int next(int i) {
    chmax(i, 0);
    if (i >= n) return n;
    for (int h = 0; h < lg; h++) {
      if (i / B == seg[h].size()) break;
      ull d = seg[h][i / B] >> (i % B);
      if (!d) {
        i = i / B + 1;
        continue;
      }
      // find
      i += bsf(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsf(seg[g][i / B]);
      }
      return i;
    }
    return n;
  }

  // x以下最大の要素を返す。存在しなければ -1。
  int prev(int i) {
    if (i < 0) return -1;
    if (i >= n) i = n - 1;
    for (int h = 0; h < lg; h++) {
      if (i == -1) break;
      ull d = seg[h][i / B] << (63 - i % 64);
      if (!d) {
        i = i / B - 1;
        continue;
      }
      // find
      i += bsr(d) - (B - 1);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsr(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }

  // [l, r)
  template <typename F>
  void enumerate(int l, int r, F f) {
    int x = l - 1;
    while (1) {
      x = next(x + 1);
      if (x >= r) break;
      f(x);
    }
  }

  void debug() {
    string s;
    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1' : '0');
    print(s);
  }
};
#line 3 "library/graph/ds/incremental_centroid.hpp"

// 木は固定。頂点重みを +1 できる。
// cent: 重心
// max_subtree
template <typename TREE>
struct Incremental_Centroid {
  TREE& tree;
  int N;
  int cent;
  pair<int, int> max_subtree; // (adj, size)
  int wt_sm;
  Tree_AbelGroup<TREE, Monoid_Add<int>, 0, 0, 1> TA;
  FastSet ss;

  Incremental_Centroid(TREE& tree)
    : tree(tree),
      N(tree.N),
      cent(0),
      max_subtree(0, 0),
      wt_sm(0),
      TA(tree),
      ss(N) {}

  int get_subtree_wt(int v) {
    assert(v != cent);
    // cent から見て v 方向
    if (tree.in_subtree(v, cent)) {
      return TA.prod_subtree(tree.jump(cent, v, 1));
    }
    return wt_sm - TA.prod_subtree(cent);
  }

  int move_to(int v) {
    // 圧縮木上で cent から v に進む
    if (tree.in_subtree(v, cent)) {
      // v 方向にある重みの lca
      int a = tree.jump(cent, v, 1);
      int L = tree.LID[a], R = tree.RID[a];
      L = ss.next(L), R = ss.prev(R - 1);
      int x = tree.V[L], y = tree.V[R];
      return tree.lca(x, y);
    }
    int L = tree.LID[cent], R = tree.RID[cent];
    int x = v;
    vc<int> I;
    I.eb(ss.next(0)), I.eb(ss.prev(L - 1));
    I.eb(ss.next(R)), I.eb(ss.prev(N - 1));
    for (auto && idx : I) {
      if (idx == -1 || idx == N) continue;
      if (L <= idx && idx < R) continue;
      int y = tree.V[idx];
      x = tree.lca_root(x, y, cent);
    }
    return x;
  }

  void add(int v) {
    ss.insert(tree.LID[v]), TA.add(v, 1), wt_sm++;
    if (v == cent) return;
    int wt = get_subtree_wt(v);
    if (max_subtree.se < wt) max_subtree = {tree.jump(cent, v, 1), wt};
    if (2 * wt <= wt_sm) return;
    int k = wt;
    assert(wt_sm == 2 * k - 1);
    int to = move_to(v);
    max_subtree = {tree.jump(to, cent, 1), k - 1};
    cent = to;
  }
};
#line 4 "main.cpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  vi X;
  FOR(s, 1441) {
    ll e = s + 120;
    if (e > 1440) break;
    bool ok = 1;
    for (auto && a : A) {
      if (a > s && a < e) ok = 0;
    }
    if (ok) X.eb(s);
  }
  if (len(X) < 2) return NO();
  ll a = X[0], b = X.back();
  return YES(b - a >= 120);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
