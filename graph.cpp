#include <iostream>
#include <vector>
using namespace std;

class Edge {
   public:
    int scr, dest;

    Edge(int s, int d) {
        this->scr = s;
        this->dest = d;
    }
};

class adjacency {
   private:
    int v;
    vector<vector<Edge>> graph;
    public:
    adjacency(int n) : v(n), graph(n) {}
    void insert(int scr, int dest) {
        if (graph.size() <= scr) {
            graph.push_back({Edge(scr, dest)});
        } else {
            graph[scr].push_back(Edge(scr, dest));
        }
    }
    void nighbore(int vertex) {
        if (graph.size() <= vertex) {
            return;
        } else {
            for (int i = 0; i < graph[vertex].size(); i++) {
                cout << graph[vertex][i].scr << "," << graph[vertex][i].dest<<" ";
            }
            cout << endl;
        }
    }
};
