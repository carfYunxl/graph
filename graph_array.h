/*-------------------------------------------------------------------------------
 *                                   Graph
 *                         ______图的数组表示法
 *                  参考书籍 : <数据结构 C语言描述> 清华大学出版社
 * 利用数组来作为图的存储结构
 * 需要初始化两个数组
 * 1.数组1为大小为n的一维数组，用来存储n个顶点的相关信息，例如存储的值等的
 * 2.数组2为大小为n*n的二维数组，用来存储n个顶点之间的关系信息
 * 3.通过查询数组1，可以找到每个顶点的信息
 * 4.通过查询数组2，可以找到每个顶点与其他顶点的关系
 *
 * 5.创建顶点关系数组
 *      5.1 输入顶点个数n，然后分配n个空间，来生成一维数组，并依次将顶点信息存入该一维数组
 *      5.2 根据输入顶点个数n，分配n*n二维数组空间，并存储各顶点之间的关系
 *      5.3 图创建完成
 * 6.怎么通过指定数据A，找到该结点信息？怎么找到该结点的度？
 *      6.1 查找一维数组，找到该结点，获得该结点的信息；
 *      6.2 并输出其下标，该下标即为二维数组中该结点指针，根据下标找到该节点边的相关信息-度
 * ----------------------------------------------------------------------------*/
#ifndef GRAPH_ARRAY_H
#define GRAPH_ARRAY_H
#define MAX_SIZE 20

typedef int ELEMTYPE;

class graph_node
{
public:
    //图结点的相关信息
    ELEMTYPE data;
public:
    graph_node()
    {
        data = 0;
    }
    ~graph_node()
    {

    }
};

class graph_array
{
private:
    //一个存储graph_node结点的数组
    graph_node nodeArray[MAX_SIZE];
    //邻接矩阵
    ELEMTYPE arcArray[MAX_SIZE][MAX_SIZE];
    //图的当前大小
    ELEMTYPE graph_size;
public:
    graph_array()
    {
    }
    ~graph_array()
    {

    }
    //创建图
    void createGraph(ELEMTYPE n);
    //获得图的当前大小
    ELEMTYPE getGraphSize()
    {
        return this->graph_size;
    }
    //获得指定结点的下标信息--指针
    ELEMTYPE locateGraphNode(ELEMTYPE a);
    //获得顶点的邻接顶点，如果没有，返回-1
    void getAdjNode(ELEMTYPE a);
    //在现有的图中，插入一个新顶点
};

#endif // GRAPH_ARRAY_H
