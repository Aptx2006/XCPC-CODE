#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 返回 left，其中 left[i] 是 nums[i] 左侧最近的严格大于 nums[i] 的数的下标，若不存在则为 -1
// 时间复杂度 O(nums.size())
vector<int> left_greater(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n);
    stack<int> st;
    st.push(-1); // 哨兵
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        while (st.size() > 1 && nums[st.top()] >= x) { // 如果求严格小于，改成 >=
            st.pop();
        }
        left[i] = st.top();
        st.push(i);
    }
    return left;
}

// 返回 right，其中 right[i] 是 nums[i] 右侧最近的严格大于 nums[i] 的数的下标，若不存在则为 nums.size()
// 时间复杂度 O(nums.size())
vector<int> right_greater(vector<int>& nums) {
    int n = nums.size();
    vector<int> right(n);
    stack<int> st;
    st.push(n); // 哨兵
    for (int i = n - 1; i >= 0; i--) {
        int x = nums[i];
        while (st.size() > 1 && nums[st.top()] >= x) { // 如果求严格小于，改成 >=
            st.pop();
        }
        right[i] = st.top();
        st.push(i);
    }
    return right;
}

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/discuss/post/9oZFK9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> L, R;
    L = left_greater(a);
    R = right_greater(a);
    vector<int> L_(n), R_(n);
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 and a[j - 1] % a[i] == 0) {
            j = min(j - 1, L_[j - 1]);
        }
        L_[i] = j;
    }
    for(int i = n - 1; i >= 0; i--) {
        int j = i;
        while(j < n - 1 and a[j + 1] % a[i] == 0) {
            j = max(j + 1, R_[j + 1]);
        }
        R_[i] = j;
    }
    i64 ans = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int last = -1;        
        if(mp.count(a[i])) {
            last = mp[a[i]];
        }
        mp[a[i]] = i;
        i64 l = max({L[i], last, L_[i] - 1});
        i64 r = min(R[i], R_[i] + 1);
        if(l <= i and i <= r) {
            ans += (i - l) * (r - i);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}