typedef long long ll;

template <class T=ll>
 struct SegmentTree {
   ll n;  // 最下段のノード数
   vector<T> node;
   T SIJK;  // 最弱なやつ(INFとか-1とか)
 
  public:
   SegmentTree(vector<T> v) {
     SIJK = (1ll << 31) - 1;  // INFは最弱なので
 
     ll sz = v.size();
     n = 1;
     while (n < sz) n *= 2;  // n…最下段の横幅
     node.resize(2 * n - 1, SIJK);
 
     // 最下段に突っ込む
     for (ll i = 0; i < sz; i++) node[(n - 1) + i] = v[i];
 
     // 最下段以外を更新していく
     for (ll i = n - 2; i >= 0; i--) {
       node[i] = compare(node[i * 2 + 1], node[i * 2 + 2]);
     }
   }
 
   // 結合法則を満たすやつならなんでもいいよー。aかbを返す。
   T compare(T a, T b) {
     return min(a, b);
   }
 
   // i番目の要素をvalに変更する
   void update(ll i, T val) {
     // まず最下段(2n-1)を変更する
     i += n - 1;
     node[i] = val;
 
     // 上に行きながら更新していく
     while (i > 0) {
       i = (i - 1) / 2;  // 親へ
       node[i] = compare(node[2 * i + 1], node[2 * i + 2]);
     }
   }
 
   // [a,b) 中の結果を返す。[l,r)は対象区間の左端と右端。
   T find(ll a, ll b, ll now = 0, ll l = 0, ll r = -1) {
     // 初期化
     if (r < 0) r = n;
 
     // 俺は関係ないとき -> 答えの邪魔にならない値を返す
     if (r <= a || b <= l) return SIJK;
 
     // 要求区間の中にノードがすっぽり入ってる → 計算候補として返す
     if (a <= l && r <= b) return node[now];
 
     // ノードの一部分だけ要求区間に入ってる → 子を再帰的に探索する
     T vl = find(a, b, 2 * now + 1, l, (l + r) / 2);  // 子(左)
     T vr = find(a, b, 2 * now + 2, (l + r) / 2, r);  // 子(右)
     return compare(vl, vr);
   }
 };