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
        //新结点
        edgeNode *node = new edgeNode;
        //结点赋值
        node->head = p[i][0];
        node->tail = p[i][1];
        node->info = p[i][2];

        //头插法
        node->tailLink = array[node->head].out;
        array[node->head].out = node;

        en.push_back(node);//压入vector中，后续用于指向入度
    }
}
void graph_OrthogonalList::create_Indegree_connection()
{
    array[0].in = en.at(5);
    en.at(5)->headLink = en.at(11);

    array[1].in = en.at(0);
    en.at(0)->headLink = en.at(6);
    en.at(6)->headLink = en.at(8);
    en.at(8)->headLink = en.at(12);

    array[2].in = en.at(2);
    en.at(2)->headLink = en.at(9);

    array[3].in = en.at(1);
    en.at(1)->headLink = en.at(3);
    en.at(3)->headLink = en.at(8);
    en.at(8)->headLink = en.at(13);

    array[4].in = en.at(4);
    en.at(4)->headLink = en.at(10);
}
void graph_OrthogonalList::print_graph_OrthogonalList()
{
    for(int i = 0;i<vNum;++i)
    {
        cout << "-----------------------------" <<endl;
        cout << array[i].data << endl;
        edgeNode *p;
        p = array[i].out;
        while(p)
        {
            cout << p->info << "\t";
            p = p->tailLink;
        }
        cout << endl;
        cout << "-----------------------------" <<endl;
    }
}
void graph_OrthogonalList::getIndegree(ELEMTYPE data)
{
    for(int i = 0;i<vNum;++i)
    {
        if(array[i].data == data)
        {
            int tmp = 0;
            edgeNode *p;
            p = array[i].in;
            while(p)
            {
                tmp++;
                p = p->headLink;
            }
            cout << "the target indegree = " << tmp << endl;
            break;
        }
    }
}
void graph_OrthogonalList::getOutdegree(ELEMTYPE data)
{
    for(int i = 0;i<vNum;++i)
    {
        if(array[i].data == data)
        {
            int tmp = 0;
            edgeNode *p;
            p = array[i].out;
            while(p)
            {
                tmp++;
                p = p->tailLink;
            }
            cout << "the target Outdegree = " << tmp << endl;
            break;
        }
    }
}
