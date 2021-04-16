#include "graph_array.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void graph_array::createGraph(ELEMTYPE n)
{
    graph_size = n;
    ELEMTYPE data;
    //分配n个结点空间,并进行初始化
    for(int i = 0;i < n;++i)
    {
        cout << "please enter the data of node :" << endl;
        cin >> data;
        nodeArray[i].data = data;
    }

    //分配n*n个结点空间，存储结点之间的关系，并对其初始化
    for(int i = 0;i < n;++i)
    {
        for(int j = 0;j < n;++j)
        {
            cout << "please enter the relationship with other node :" << endl;
            int tmp;
            cin >> tmp;
            cout << "node :" <<i<<"with node :"<<j<<"\t"<<tmp<< endl;
            arcArray[i][j] = tmp;
        }
    }
    cout << "End create!" << endl;
    for(int i = 0;i < n;++i)
    {
        for(int j = 0;j < n;++j)
        {
            cout << arcArray[i][j] << " ";
            if(j == n - 1)
                cout << endl;
        }
    }
}

ELEMTYPE graph_array::locateGraphNode(ELEMTYPE a)
{
    for(int i = 0;i < graph_size;++i)
    {
        if(nodeArray[i].data == a)
        {
            //输出结点其他信息
            cout << i << endl;
            //返回该节点的下标
            return i;
        }
    }
    //图中不存在该结点
    return -1;
}
void graph_array::getAdjNode(ELEMTYPE a)
{
    int ptr,k;
    ptr = locateGraphNode(a);
    k = graph_size;
    cout << "ptr="<<ptr<<"\tk="<< k <<"\t"<< endl;
    for(int i = 0;i<k;++i)
    {
        if(arcArray[i][ptr] == 1)
        {
            cout << "adjust node = "<<nodeArray[i].data <<"\tindex = "<< i << endl;
        }
    }

}
