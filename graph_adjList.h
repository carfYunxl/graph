/*---------------------------------------------------------------------------
                                Graph
                                邻接表
图的另一种存储结构是邻接表,它用一个一维数组存储各顶点的信息，同时每个数组元素
(顶点)又是一个单链表的头结点，单列表的元素存储图的边信息。
邻接表适合既适合存储无向图，也适合有向图，查找一维数组，很容易查找顶点的位置，
再依此头结点，容易找到依附于该顶点的所有边，也容易计算该顶点的出度。但若想计算
该顶点的入读，则需查找整个邻接表。
组成如下：
1.一维数组：存储顶点信息和第一条边的指针；
2.单链表：存储边的头顶点位置，边的信息（如权值），和下一条边的指针；

输入输出举例：
please enter the value of vnode:
1
please enter the value of vnode:
2
please enter the value of vnode:
3
please enter the value of vnode:
4
please enter the value of vnode:
5
please enter the value of vnode:
6
please enter index:
1
3
4
-1
please enter index:
3
4
-1
please enter index:
0
4
5
-1
please enter index:
2
4
5
-1
please enter index:
5
-1
please enter index:
-1
arc 2 contains: < 3,6 >
arc 2 contains: < 3,5 >
arc 2 contains: < 3,1 >
vnode pos = 2
vnode out degree = 3
1
2
3
4
vnode : 5 in degree = 4
---------------------------------------------------------------------------*/
#ifndef _GRAPH_ADJLIST_H
#define _GRAPH_ADJLIST_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_SZ 20
typedef int ELEMTYPE;

//边的类
class arcNode
{
public:
    arcNode()
    {
        next = nullptr;
    }
    ~arcNode()
    {

    }

    int nodePos;//边的头顶点在一维数组中的位置
    //ELEMTYPE info;//边的信息（如权值，路径）等
    arcNode *next;//指向下一条边的指针
};

//顶点的类
class vNode
{
public:
    vNode()
    {
        head = nullptr;
    }
    ~vNode()
    {
    }

    ELEMTYPE data;//顶点信息
    arcNode *head;//头边指针
};
class graph_adjList
{
private:
    vNode array[MAX_SZ];
    int vnum;//图的顶点数
    int arcnum;//图的边数
    //int kind;//图的种类

public:
    graph_adjList()
    {
    }
    ~graph_adjList()
    {
    }
    //创建有向图
    void createAdjGraph(int num);
    void locateVnodeOut(ELEMTYPE data);//查找图的顶点，以及该顶点的出度
    //查找图的顶点，以及该顶点的入度
    void locateVnodeIn(ELEMTYPE data);
};
#endif //_GRAPH_ADJLIST_H
