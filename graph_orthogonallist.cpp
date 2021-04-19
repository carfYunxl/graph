#include "graph_orthogonallist.h"

//创建顶点数组
void graph_OrthogonalList::create_graph_table(int vexNum)
{
    vNum = vexNum;
    for(int i = 0;i < vexNum;++i)
    {
        cout << "please enter vexNode num :" << endl;
        ELEMTYPE tmp;
        if(cin >> tmp)
        {
            array[i].data = tmp;
        }
    }   
}
//创建边集链表
void graph_OrthogonalList::create_graph_List(int edgeNum,int p[14][3])
{
    for(int i = 0;i < edgeNum;++i)
    {
        //建立
        int t,h,info;
        cout << "please enter the arcNode information" << endl;
        if(cin >> t >> h >> info)
        {
            edgeNode *node = new edgeNode;
            //结点赋值
            node->info = info;
            node->head = h;
            node->tail = t;

            //头插法
            node->tailLink = array[i].out;
            array[i].out = node;

            en.push_back(node);
        }
    }
}
void graph_OrthogonalList::print_graph_OrthogonalList()
{
    for(int i = 0;i<vNum;++i)
    {
        cout << array[i].data << endl;
        edgeNode *p;
        p = array[i].out;
        while(p)
        {
            cout << p->info << "\t";
            p = p->tailLink;
        }
        cout << endl;
    }
}
