<div align="center">

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

<!-- Anime Girl Side Banner using shields and badges -->
<img align="right" src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExdWp5dGRveWxueTdkYmVuNGQ5aThsNmRkd2k3bndmNzBtdTQ3bnZjNiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/RbDKaczqWovIugyJmW/giphy.gif" width="200px" style="border-radius: 20px;"/>

# 🌐 Graph Theory in Competitive Programming
### 图论在竞技编程中的应用

<img src="https://readme-typing-svg.demolab.com/?font=Fira+Code&size=22&pause=1000&color=A855F7&center=true&vCenter=true&width=600&lines=Master+Graph+Theory+%F0%9F%94%A5;%E4%BB%8E%E9%9B%B6%E5%BC%80%E5%A7%8B%E6%8E%8C%E6%8F%A1%E5%9B%BE%E8%AE%BA+%F0%9F%9A%80;DFS+%7C+BFS+%7C+Dijkstra+%7C+Union+Find;Two+Solved+Problems+Included+%E2%9C%85" alt="Typing SVG" />

<br/>

![Graph](https://img.shields.io/badge/Topic-Graph%20Theory-blueviolet?style=for-the-badge&logo=graphql)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus)
![Platform](https://img.shields.io/badge/Platform-Codeforces-orange?style=for-the-badge)
![Problems](https://img.shields.io/badge/Solved-2%20Problems-success?style=for-the-badge)
![Bilingual](https://img.shields.io/badge/Bilingual-EN%20%7C%20ZH-red?style=for-the-badge)

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

</div>

<br/>

## 📚 Table of Contents | 目录

| # | Section | 章节 |
|---|---------|------|
| 1 | [What is a Graph?](#-what-is-a-graph--什么是图) | 什么是图？ |
| 2 | [Graph Types](#-graph-types--图的类型) | 图的类型 |
| 3 | [Key Algorithms](#-key-algorithms--核心算法) | 核心算法 |
| 4 | [Solved Problem 1 – New Year Transportation](#-solved-problem-1--new-year-transportation) | 解题一 |
| 5 | [Solved Problem 2 – Rumor (World of Farcraft)](#-solved-problem-2--rumor-world-of-farcraft) | 解题二 |
| 6 | [Tips & Tricks](#-tips--tricks--技巧总结) | 技巧总结 |

<br/>

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

## 🔷 What is a Graph? | 什么是图？

<div align="center">
<img src="https://d8it4huxumps7.cloudfront.net/bites/wp-content/banners/2025/1/6799ae760e1c9_graph_data_structure.jpg?d=1200x800" width="300px" alt="Graph Example"/>
<br/>
<img src="https://i.pinimg.com/originals/1a/ac/4c/1aac4c47ec04942f259cd0c37a0a5749.jpg" width="250px" alt="Graph Animation"/>
</div>

> **EN:** A **Graph** is a collection of **nodes (vertices)** connected by **edges**. It models relationships between objects — networks, maps, social connections, and more.

> **ZH:** **图**是由**节点（顶点）**和**边**组成的数据结构，用于建模对象之间的关系，如网络、地图、社交关系等。

```
Graph G = (V, E)
V = {1, 2, 3, 4, 5}        ← Vertices / 顶点
E = {(1,2), (1,3), (2,4)}  ← Edges / 边
```

<br/>

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

## 🔷 Graph Types | 图的类型

<div align="center">
<img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExYm5mNGk5bHJmMXJ0cHdjeGdpbnFhcmVmdGZwOGh1ZWU3Nzl1ZTBueiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/xT9IgzoKnwFNmISR8I/giphy.gif" width="280px" alt="Network Animation"/>
</div>

| Type | English | 中文 | Example |
|------|---------|------|---------|
| 🔁 | Undirected Graph | 无向图 | Friendship network |
| ➡️ | Directed Graph (Digraph) | 有向图 | Twitter follows |
| ⚖️ | Weighted Graph | 带权图 | Road distances |
| 🌲 | Tree | 树 | File system |
| 🔄 | Cyclic Graph | 有环图 | Road network |
| 🚫 | DAG (Directed Acyclic Graph) | 有向无环图 | Task scheduling |

### Representation | 图的表示方式

**Adjacency List (推荐 / Recommended):**
```cpp
vector<int> adj[100005];  // adj[u] contains all neighbors of u
// adj[u] 包含 u 的所有邻居

adj[1].push_back(2);  // Edge 1 → 2
adj[2].push_back(1);  // Edge 2 → 1 (undirected / 无向)
```

**Adjacency Matrix:**
```cpp
int graph[1005][1005];
graph[u][v] = 1;  // Edge exists / 边存在
graph[v][u] = 1;  // For undirected / 无向图
```

<br/>

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

## 🔷 Key Algorithms | 核心算法

<div align="center">
<img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExbzM0N3ptYzR0aml4bWE1dWM0dDZ2OTRxNTlydGVsNnpueXFjNzJkNiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/077i6AULCXc0FKTj9s/giphy.gif" width="260px" alt="Algorithm Animation"/>
</div>

### 1️⃣ DFS — Depth First Search | 深度优先搜索

> **EN:** Explores as deep as possible before backtracking. Great for connectivity, cycles, and components.

> **ZH:** 尽可能深入探索，然后回溯。适用于连通性、环检测和连通分量。

```cpp
bool visited[100005];
vector<int> adj[100005];

void dfs(int node) {
    visited[node] = true;
    for (auto child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
}
```

---

### 2️⃣ BFS — Breadth First Search | 广度优先搜索

> **EN:** Explores level by level. Perfect for **shortest path** in unweighted graphs.

> **ZH:** 逐层探索，最适合**无权图中的最短路径**。

```cpp
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (auto child : adj[node]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }
}
```

---

### 3️⃣ Dijkstra | 迪杰斯特拉算法

> **EN:** Shortest path in **weighted graphs** (non-negative weights).

> **ZH:** 求**带权图**中的最短路径（权值非负）。

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
vector<int> dist(n+1, INT_MAX);
dist[src] = 0;
pq.push({0, src});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
```

---

### 4️⃣ Union-Find (DSU) | 并查集

> **EN:** Efficiently groups nodes into **connected components**.

> **ZH:** 高效地将节点分组为**连通分量**。

```cpp
int parent[100005];
int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
void unite(int x, int y) { parent[find(x)] = find(y); }
```

<br/>

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

## ✅ Solved Problem 1 — New Year Transportation

<div align="center">

![Codeforces](https://img.shields.io/badge/Codeforces-500A-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Graph%20%7C%20Simulation-purple?style=for-the-badge)

</div>

### 📋 Problem Statement | 题意

> **EN:** There are `n` cells. From cell `i`, you can jump to cell `i + a[i]`. Starting at cell `1`, can you reach cell `t`?

> **ZH:** 有 `n` 个格子，从格子 `i` 可以跳到格子 `i + a[i]`。从格子 `1` 出发，能否到达格子 `t`？

### 🖼️ Problem Screenshot | 题目截图

<div align="center">
<img src="img/Screenshot 2026-06-03 183014.png" width="600px" alt="Problem Screenshot"/>
</div>

### 💡 Key Idea | 核心思路

> **EN:** Follow the actual **jump path**: from cell `count`, jump to `count + a[count-1]`. If you land on `t` → YES. If you overshoot `t` → NO.

> **ZH:** 沿着**真实跳跃路径**前进：从 `count` 跳到 `count + a[count-1]`。若落到 `t` → YES，若超过 `t` → NO。

### ❌ Wrong Approach | 错误做法
```cpp
count++;  // ❌ Moving one step at a time — WRONG!
          // ❌ 每次只移动一步 — 错误！
```

### ✅ Correct Solution | 正确解法

<div align="center">
<img src="img/Screenshot 2026-06-03 182932.png" width="600px" alt="Problem Screenshot"/>
</div>

### 🔍 Trace Example | 执行追踪

```
n=8, t=4, a = [1, 2, 1, 2, 1, 2, 1]

Step 1: count=1 → tt = 1+1 = 2  → jump to 2
Step 2: count=2 → tt = 2+2 = 4  → tt == t → ✅ YES
```

<br/>

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

## ✅ Solved Problem 2 — Rumor (World of Farcraft)

<div align="center">

![Codeforces](https://img.shields.io/badge/Codeforces-693C-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Graph%20%7C%20DFS%20%7C%20Components-purple?style=for-the-badge)

</div>

### 📋 Problem Statement | 题意

> **EN:** `n` characters, some are friends. Bribing one character spreads the rumor to all their friends. Find the **minimum cost** to inform everyone.

> **ZH:** `n` 个角色，部分是朋友。贿赂一个角色，谣言会传遍他所有朋友。求让所有人知道谣言的**最小花费**。

### 🖼️ Problem Screenshot | 题目截图

<div align="center">
<img src="img/Screenshot 2026-06-03 183105.png" width="600px" alt="Rumor Problem"/>
</div>

### 💡 Key Idea | 核心思路

> **EN:** Find all **connected components** using DFS. For each component, bribe only the **cheapest character** (minimum cost). Sum up all minimums.

> **ZH:** 用 DFS 找出所有**连通分量**。对每个分量，只需贿赂**最便宜的角色**（最小花费）。将所有最小值相加即为答案。

```
Component 1: {1, 4, 5}  → min cost = min(2,4,8) = 2
Component 2: {2}        → min cost = 5
Component 3: {3}        → min cost = 3
Total = 2 + 5 + 3 = 10 ✅
```

### ❌ Wrong Approach | 错误做法

```cpp
// ❌ Bug 1: Running DFS inside edge-reading loop
for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    // DFS here is WRONG — graph not fully built yet!
    // 此处 DFS 错误 — 图还未完全构建！
}

// ❌ Bug 2: Not including start node in min calculation
void dfs(int node, ...) {
    for (auto child : adj[node]) {
        Min_Nbr = min(Min_Nbr, Ci[child]); // misses node itself!
        // 漏掉了起始节点本身！
    }
}

// ❌ Bug 3: 0-indexed vs 1-indexed mismatch
// 数组下标从0开始但题目从1开始
```

### ✅ Correct Solution | 正确解法

<div align="center">
    <img src="img/Screenshot 2026-06-03 182851.png" width="600px" alt="Rumor Problem"/>
</div>

<br/>

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

## 💡 Tips & Tricks | 技巧总结

<div align="center">
<img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExbjZyMzlvenZqdWttaGI2bHFyMm93YTd4eGF1bnk3Yzk1cjRleTJrNiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/LmNwrBhejkK9EFP504/giphy.gif" width="250px" alt="Tips"/>
</div>

| # | Tip (EN) | 技巧（中文） |
|---|----------|------------|
| 1 | Always read ALL edges before running DFS/BFS | 先读完所有边，再运行 DFS/BFS |
| 2 | Use 1-indexed arrays when problem uses 1-based nodes | 题目从1开始时使用1-indexed数组 |
| 3 | Include start node in min/max calculations in DFS | DFS中不要忘记起始节点 |
| 4 | Use `long long` when cost can reach 10⁹ × 10⁵ | 花费可能很大时使用 `long long` |
| 5 | Track visited[] to avoid infinite loops | 用 visited[] 避免无限循环 |
| 6 | For shortest path → BFS (unweighted) / Dijkstra (weighted) | 最短路：无权用BFS，带权用Dijkstra |

<br/>

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>

<div align="center">

### 🌟 Graph Complexity Cheatsheet | 图算法复杂度速查

| Algorithm | Time | Space | Use Case |
|-----------|------|-------|----------|
| DFS | O(V+E) | O(V) | Components, Cycles |
| BFS | O(V+E) | O(V) | Shortest Path (unweighted) |
| Dijkstra | O((V+E) log V) | O(V) | Shortest Path (weighted) |
| Bellman-Ford | O(VE) | O(V) | Negative weights |
| Floyd-Warshall | O(V³) | O(V²) | All-pairs shortest path |
| Union-Find | O(α(N)) | O(N) | Dynamic connectivity |

<br/>

<img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExcm9qNHIxbzlvaHc4aDM5YWVrbHo0dW9sMm95YzM5dGhxM3lvanpwMyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/du3J3cXyzhj75IOgvA/giphy.gif" width="200px"/>

**Made with ❤️ for Competitive Programmers | 为竞技编程爱好者用心制作**

![Visitors](https://visitor-badge.laobi.icu/badge?page_id=graph.cp.readme)
[![GitHub Stars](https://img.shields.io/github/stars/yourusername/yourrepo?style=social)](https://github.com)

</div>

<img src="https://i.imgur.com/waxVImv.png" alt="Colorful Divider" width="100%"/>
