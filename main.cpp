#include "graph_adjlist.h"
#include "graph_array.h"
#include "graph_orthogonallist.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void test_graph_array()
{
    graph_array g;
    g.createGraph(6);
    g.getAdjNode(3);
}

void test_graph_adjlist()
{

    graph_adjList g;
    g.createAdjGraph(6);
    g.locateVnodeOut(3);
    g.locateVnodeIn(5);
}
void test_graph_orthogonallist()
{
    int p[14][3]={
        {0,1,10},
        {0,3,100},
        {1,2,40},
        {1,3,70},
        {1,4,80},
        {2,0,20},
        {2,1,40},
        {2,3,50},
        {3,1,70},
        {3,2,50},
        {3,4,60},
        {4,0,90},
        {4,1,80},
        {4,3,60},
    };
    graph_OrthogonalList g;
    g.create_graph_table(5);
    g.create_graph_List(14,p);
    g.print_graph_OrthogonalList();
    g.create_Indegree_connection();
    g.getIndegree(5);
    g.getOutdegree(5);
}
int main()
{

    test_graph_orthogonallist();
    return 0;
}
