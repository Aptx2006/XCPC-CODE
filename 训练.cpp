#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& A, int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high + 1;
    while (true) {
        while (true) {
            i++;
            if (i > high || !(A[i] < pivot)) break;
        }
        while (true) {
            j--;
            if (j < low || !(A[j] >= pivot)) break;
        }
        if (i >= j) break;
        swap(A[i], A[j]);
    }
    swap(A[low], A[j]);
    return j;
}

string format(const vector<int>& A, const vector<pair<int, int>>& inter) {
    string res = "";
    set<int> st, ed;
    for (const auto& p : inter) {
        st.insert(p.first);
        ed.insert(p.second);
    }

    for (int i = 0; i < (int)A.size(); ++i) {
        if (st.count(i) && ed.count(i)) {
            // 单元素 [X]
            res += "[" + to_string(A[i]) + "]";
        } else if (st.count(i)) {
            res += "[" + to_string(A[i]);
        } else if (ed.count(i)) {
            res += to_string(A[i]) + "]";
        } else {
            res += to_string(A[i]);
        }
        if (i < (int)A.size() - 1) res += " ";
    }
    return res;
}

void solve(vector<int> a = {5, 5, 8, 3, 4, 3, 2}) {
    vector<int> A = a;
    vector<pair<int, int>> inter = {{0, (int)A.size() - 1}};
    
    cout << "1: " << format(A, inter) << "\n";
    
    int cnt = 2;
    while (true) {
        int tag_i = -1;
        for (int i = 0; i < (int)inter.size(); ++i) {
            if (inter[i].second > inter[i].first) {
                tag_i = i;
                break;
            }
        }
        
        if (tag_i == -1) {
            if (!inter.empty()) {
                inter.clear();
                cout << cnt << ": " << format(A, inter) << "\n";
            }
            break;
        }
        
        int low = inter[tag_i].first;
        int high = inter[tag_i].second;
        int p = partition(A, low, high);
        
        vector<pair<int, int>> new_sub;
        if (p - 1 >= low) {
            new_sub.push_back({low, p - 1});
        }
        if (p + 1 <= high) {
            new_sub.push_back({p + 1, high});
        }
        
        inter.erase(inter.begin() + tag_i);
        inter.insert(inter.begin() + tag_i, new_sub.begin(), new_sub.end());
        
        cout << cnt << ": " << format(A, inter) << "\n";
        cnt++;
        
        bool flag = false;
        for (const auto& p_int : inter) {
            if (p_int.first == p_int.second) {
                flag = true;
                break; 
            }
        }
        
        if (flag) {
            vector<pair<int, int>> filtered;
            for (const auto& p_int : inter) {
                if (p_int.second > p_int.first) {
                    filtered.push_back(p_int);
                }
            }
            inter = filtered;
            cout << cnt << ": " << format(A, inter) << "\n";
            cnt++;
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}