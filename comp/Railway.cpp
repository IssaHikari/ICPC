#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// القيود القصوى بناءً على نص المسألة
const int MAXN = 100005;
const int LOGN = 20;

struct Edge {
    int to, id;
};

vector<Edge> adj[MAXN];
int up[MAXN][LOGN];
int depth[MAXN];
int tin[MAXN];
int timer = 0;
int edge_to_parent_id[MAXN];
int diff[MAXN];

// DFS الأول: لحساب قيم الـ LCA وزمن الدخول وعمق العقد
void dfs_lca(int u, int p, int edge_id, int d) {
    tin[u] = ++timer;
    depth[u] = d;
    edge_to_parent_id[u] = edge_id; // حفظ معرف الحافة المتجهة للأب
    up[u][0] = p;
    
    for (int i = 1; i < LOGN; ++i) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    
    for (auto& edge : adj[u]) {
        if (edge.to != p) {
            dfs_lca(edge.to, u, edge.id, d + 1);
        }
    }
}

// دالة لحساب السلف المشترك الأحدث باستخدام الـ Binary Lifting
int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    for (int i = LOGN - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    
    if (u == v) return u;
    
    for (int i = LOGN - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

// إضافة مسار إلى مصفوفة الفروق
void add_path(int u, int v) {
    diff[u] += 1;
    diff[v] += 1;
    diff[get_lca(u, v)] -= 2;
}

// DFS الثاني: لتجميع قيم الفروق من الأسفل إلى الأعلى وفحص الحواف الناجحة
void dfs_sum(int u, int p, vector<int>& result, int k) {
    for (auto& edge : adj[u]) {
        if (edge.to != p) {
            dfs_sum(edge.to, u, result, k);
            diff[u] += diff[edge.to]; // تجميع القيمة من الابن
        }
    }
    
    // بما أننا مررنا بالدورة كاملة، فكل حافة حُسبت مرتين
    if (u != 1 && (diff[u] / 2) >= k) {
        result.push_back(edge_to_parent_id[u]);
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    // قراءة شبكة السكك الحديدية (الشجرة)
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    // بناء معلومات الـ LCA بدءاً من العقدة 1 كجذر للشجرة
    dfs_lca(1, 1, 0, 0);

    // قراءة طلبات نواب الوزراء
    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        vector<int> nodes(s);
        for (int j = 0; j < s; ++j) {
            cin >> nodes[j];
        }
        
        // الخدعة: الترتيب حسب الـ DFS order
        sort(nodes.begin(), nodes.end(), [](int a, int b) {
            return tin[a] < tin[b];
        });
        
        // تحديث مصفوفة الفروق بين كل عقدتين متتاليتين والعقدة الأخيرة مع الأولى
        for (int j = 0; j < s; ++j) {
            int u = nodes[j];
            int v = nodes[(j + 1) % s];
            add_path(u, v);
        }
    }

    vector<int> result;
    dfs_sum(1, 1, result, k);

    // ترتيب معرفات الحواف تصاعدياً حسب المطلوب
    sort(result.begin(), result.end());

    // طباعة النتائج
    cout << result.size() << "\n";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 == result.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}