#include "graph_adjList.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void test_graph_adjList()
{
    graph_adjList g;
    g.createAdjGraph(4);
    g.locateVnode(3);
}
int main()
{
    //test_graph_array();
    test_graph_adjList();
}
