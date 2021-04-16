#include <QCoreApplication>
#include "graph_array.h"
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
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test_graph_array();

    return a.exec();
}
