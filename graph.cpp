#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Edge {
    int scr;
    int dest;
    Edge(int s, int d) : scr(s), dest(d) {}
};

class adjacencyMetrix {
   private:
    int v;
    bool isDirected;
    vector<vector<Edge>> graph;

   public:
    adjacencyMetrix(int n, bool isDirected = false) {
        v = n;
        this->isDirected = isDirected;
        graph = vector<vector<Edge>>(n);
    }

    void insert(int scr, int dest) {
        if (scr >= v) return;
        graph[scr].push_back(Edge(scr, dest));
        if (!isDirected) graph[dest].push_back(Edge(dest, scr));
    }

    void nighbore(int vertex) {
        if (vertex >= graph.size()) return;

        for (int i = 0; i < graph[vertex].size(); i++) {
            cout << graph[vertex][i].scr << "," << graph[vertex][i].dest << " ";
        }
        cout << endl;
    }
    void breathFirstSearch(int start = 0) {
        vector<bool> visited(graph.size(), false);
        queue<int> remaning;
        remaning.push(start);
        while (!remaning.empty()) {
            if (!visited[remaning.front()]) {
                visited[remaning.front()] = true;
                cout << remaning.front() << " ";
                for (int i = 0; i < graph[remaning.front()].size(); i++) {
                    remaning.push(graph[remaning.front()][i].dest);
                }
            }
            remaning.pop();
        }
        cout << endl;
    }
    void preOrder(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for (int i = 0; i < graph[start].size(); i++) {
            if (!visited[graph[start][i].dest]) {
                preOrder(graph[start][i].dest, visited);
            }
        }
    }
    void preOrder(int start = 0) {
        vector<bool> visited(graph.size(), false);
        preOrder(start, visited);
        cout << endl;
    }
    void postOrder(int start, vector<bool>& visited) {
        visited[start] = true;

        for (int i = 0; i < graph[start].size(); i++) {
            if (!visited[graph[start][i].dest]) {
                postOrder(graph[start][i].dest, visited);
            }
        }
        cout << start << " ";
    }
    void postOrder(int start = 0) {
        vector<bool> visited(graph.size(), false);
        postOrder(start, visited);
        cout << endl;
    }
    void allPaths(int start, int dest, vector<bool>& visited, string result) {
        if (start == dest) {
            cout << result;
            cout << start << endl;
            return;
        }
        for (int i = 0; i < graph[start].size(); i++) {
            if (!visited[start]) {
                visited[start] = true;
                allPaths(graph[start][i].dest, dest, visited,
                         result + to_string(start) + ",");
                visited[start] = false;
            }
        }
    }
    void allPaths(int start, int dest) {
        vector<bool> visited(graph.size(), false);
        allPaths(start, dest, visited, "");
    }
};
