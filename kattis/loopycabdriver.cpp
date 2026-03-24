// Come and Go
// check if the graph is strongly connected, i.e. the SCC of the graph is the graph itself (only 1 SCC)

#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;



enum { UNVISITED = -1 };

int dfsNumberCounter, numSCC;
vector<vii> AL, AL_T;
vi dfs_num, dfs_low, S, visited;                 // global variables
stack<int> St;
vector<vector<string> > SCCs;

void tarjanSCC(int u, unordered_map<int, string> &m2) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter;    // dfs_low[u]<=dfs_num[u]
  dfsNumberCounter++;                            // increase counter
  St.push(u);                                    // remember the order
  visited[u] = 1;
  for (auto &[v, w] : AL[u]) {
    if (dfs_num[v] == UNVISITED)
      tarjanSCC(v, m2);
    if (visited[v])                              // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {                // a root/start of an SCC
    ++numSCC;                                    // when recursion unwinds
    SCCs.push_back(vector<string>());
    while (1) {
      int v = St.top(); St.pop(); visited[v] = 0;
      SCCs.back().push_back(m2[v]);
      if (u == v) break;
    }
  }
}


int main() {
  int N, M;
  vector<pair<int,int> > edges;
  N = 0;
  int i = 0;
  std::string a, b;
  unordered_map<string, int> m;
  unordered_map<int, string> m2;
  cin >> M;
  while (i < M) {
    cin >> a;
    cin >> b;
    if (m.contains(a) == false) {
        m[a] = m.size();
        m2[m[a]] = a;
    }
    if (m.contains(b) == false) {
        m[b] = m.size();
        m2[m[b]] = b;
    }
    edges.push_back({m[a], m[b]});
    i++;
  }
  N = m.size();
  //while (scanf("%d %d", &N, &M), (N || M)) {
  AL.assign(N, vii());
  AL_T.assign(N, vii()); // the transposed graph
  int V, W, P;
  for (std::pair<int,int> edge : edges) {
    V = edge.first;
    W = edge.second;
    P = 1;  // p = 1 is used to say taht the edge is only 1 direction. 
    AL[V].emplace_back(W, 1);
    AL_T[W].emplace_back(V, 1);
  }

    // run Tarjan's SCC code here
  dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0); visited.assign(N, 0);
  while (!St.empty()) St.pop();
  dfsNumberCounter = numSCC = 0;
  for (int u = 0; u < N; ++u)
    if (dfs_num[u] == UNVISITED)
      tarjanSCC(u, m2);

    // // run Kosaraju's SCC code here
    // S.clear(); // first pass: record the post-order of original graph
    // dfs_num.assign(N, UNVISITED);
    // for (int u = 0; u < N; ++u)
    //   if (dfs_num[u] == UNVISITED)
    //     Kosaraju(u, 1);
    // int numSCC = 0; // second pass: explore SCCs using first pass order
    // dfs_num.assign(N, UNVISITED);
    // for (int i = N-1; i >= 0; --i)
    //   if (dfs_num[S[i]] == UNVISITED)
    //     numSCC++, Kosaraju(S[i], 2);             // on transposed graph

    // if SCC is only 1, print 1, otherwise, print 0
  std::sort(SCCs.begin(), SCCs.end());
  for (vector<string>& v: SCCs) {
    std::sort(v.begin(), v.end());
  }
  vector<int> broken_locations;

  for (int k = 0; k < SCCs.size(); k++) {
    if (SCCs[k].size() > 1) {
        std :: cout << "okay";
        for (string s: SCCs[k]) {
            std::cout << " " << s;
        }
        std::cout << std::endl;
    } else {
        broken_locations.push_back(k);
    }
  }
  std::cout << "avoid";
  for (int k : broken_locations) {
    std::cout << " " << SCCs[k][0];
  }
   //std::cout << numSCC;
  //}
  return 0;
}