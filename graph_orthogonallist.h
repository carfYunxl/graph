/*---------------------------------------------------------------------------
                                Graph
                               十字链表
邻接表可以很好的存储有向图，但是在求结点的入度时较麻烦，需要遍历整个邻接表，而十字链表可以解
决这个问题。
十字链表的链表结点和顶点与邻接表类似，只不过链表结点增加了in指针域，用来表示指向该结点的弧。
弧结点由弧头弧尾指示域和指向同一结点的链表组成
类组成：
1.一维数组，顶点表，存储顶点信息
2.弧结点，存储弧信息
---------------------------------------------------------------------------*/
#ifndef GRAPH_ORTHOGONALLIST_H
#define GRAPH_ORTHOGONALLIST_H
#include <iostream>
#include <QVector>
using std::cin;
using std::cout;
using std::endl;

#define MAX_SZ 20
typedef int ELEMTYPE;

class vexNode;

class edgeNode
{
public:
    edgeNode()
    {
        headLink = nullptr;
        tailLink = nullptr;
    }
    ~edgeNode()
    {

    }
    int tail;//指向该节点的弧
    int head;//指出该节点的弧

    edgeNode *headLink;//都指向该结点的弧构成的链表
    edgeNode *tailLink;//都指出该结点的弧构成的链表

    int info;//权值
};
class vexNode
{
public:
    vexNode()
    {
        in = nullptr;
        out = nullptr;
    }
    ~vexNode()
    {

    }

    ELEMTYPE data;//数据域
    edgeNode *in;//指向该结点的弧
    edgeNode *out;//指出该节点的弧
};
class graph_OrthogonalList
{
private:
    vexNode array[MAX_SZ];//顶点数组
    int vNum;//图的顶点数
    int eNum;//图的边数
    QVector<edgeNode *>en;//边集向量
public:
    graph_OrthogonalList()
    {

    }
    ~graph_OrthogonalList()
    {

    }

    void create_graph_table(int vexNum);//创建十字链表
    void create_graph_List(int edgeNum,int p[14][3]);//创建十字链表
    void print_graph_OrthogonalList();
};

#endif // GRAPH_ORTHOGONALLIST_H
