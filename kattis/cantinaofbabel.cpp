// 
// Problem: Cantina of Babel
// Author: Aakarsh Rai (rai53)
// It is ok to show my solution to others
//


// Come and Go


#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iostream>
using namespace std;

// Algorithm: I'm using  Tarjan's algorithm to find the largest SCC 
// this will have the largest group of people who can talk to one another.
// message from any person can reach anyone else.
// the remaining are removed. 

// These are some typedefs to make stuff easier
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum { UNVISITED = -1 };

int dfsNumberCounter, numSCC;
vector<vii> AL;
vi dfs_num, dfs_low, S, visited;                 // global variables
stack<int> St;
// This variable will track the largest SCC size 
int largest = 0;
// This will convert people to numbers. 
unordered_map<string, int> m1;
unordered_map<int, string> m2;
// modified tarjan to track the largest SCC size
void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter;    // dfs_low[u]<=dfs_num[u]
  dfsNumberCounter++;                            // increase counter
  St.push(u);                                    // remember the order
  visited[u] = 1;
  for (auto &[v, w] : AL[u]) {
    if (dfs_num[v] == UNVISITED)
      tarjanSCC(v);
    if (visited[v])                              // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  // This will store the size of the current SCC. 
  int s = 0;
  if (dfs_low[u] == dfs_num[u]) {                // a root/start of an SCC
    ++numSCC;                                    // when recursion unwinds
    while (1) {
      s++;
      largest = max(largest, s);
      int v = St.top(); St.pop(); visited[v] = 0;
      if (u == v) break;
    }
  }
}

// Every person becomes a node.
// A directed edge from A to B if A can speak to B. 

int main() {
  int N, M;
  // This will store the number of edges.
  cin >> N;
  cin.ignore();
  vector<string> speaks(N);
  unordered_map<string, unordered_set<int>> understands;
  int i = 0;
  string dude;
  string lang;
  while (i < N) {
    cin >> dude;
    cin >> lang;
    m1[dude] = i;
    speaks[i] = lang;
    understands[lang].insert(i);
    // We check the next char. If it's a new line or EOF, we must stop .
    while (cin.peek() != '\n' && cin.peek() != EOF) {
        cin >> lang;
        understands[lang].insert(i);
    }
    i++;
  }
  AL.assign(N, vii());
  i = 0;
  while (i < N) {
    for (int j : understands[speaks[i]]) {
        if (i != j) {
            AL[i].emplace_back(j, 1);
        }
    }
    i++;
  }
  // run Tarjan's SCC code here
  dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0); visited.assign(N, 0);
  while (!St.empty()) St.pop();
  dfsNumberCounter = numSCC = 0;
  for (int u = 0; u < N; ++u)
    if (dfs_num[u] == UNVISITED)
      tarjanSCC(u);
  // Number of people - size of largest SCC = number of people who cannot talk to everyone else.
  std::cout << N - largest << std::endl;
  

  return 0;
}