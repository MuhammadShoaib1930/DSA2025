#include <iostream>
#include <vector>

#include "graph.cpp"
using namespace std;

int main() {
    adjacencyMetrix graph = adjacencyMetrix(9, true);
    graph.insert(0, 1);
    graph.insert(0, 2);
    graph.insert(1, 3);
    graph.insert(3, 5);
    graph.insert(2, 4);
    graph.insert(4, 5);

    graph.breathFirstSearch();
    graph.preOrder();
    graph.postOrder();
    cout <<"find all paths of  0 to 4"<< endl;
    graph.allPaths(0, 4);

    return 0;
}
// 1 hours completed video
