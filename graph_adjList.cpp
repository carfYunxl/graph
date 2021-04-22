#include "graph_adjlist.h"

//创建图
void graph_adjList::createAdjGraph(int num)
{
    vnum = num;
    //分配顶点数据
    for(int i = 0;i < num;++i)
    {
        cout << "please enter the value of vnode:" << endl;
        int tmp = 0;;
        if(cin >> tmp)
        {
            array[i].data = tmp;
            array[i].head = nullptr;
        }
    }
    //分配边数据
    //边上的弧头位置，以及下一个指针的位置
    for(int i = 0;i < num;++i)
    {
        cout << "please enter index:" << endl;
        int index = 0;
        while(cin >> index)
        {
            if(index == -1)
            {
                break;
            }else{
                arcNode *node = new arcNode;//分配空间
                node->nodePos = index;     //第一个弧头的索引即为该索引值
                //头插法
                node->next = array[i].head;
                array[i].head = node;
            }

        }
    }
}
//查找图的顶点，以及该顶点的出度
void graph_adjList::locateVnodeOut(ELEMTYPE data)
{
    int tmp = 0;
    int pos = 0;
    for(int i = 0;i < vnum;++i)
    {
        if(array[i].data == data)//找到了该顶点
        {
            pos = i;
            arcNode *p = array[i].head;
            while(p)
            {
                cout << "arc "<<i<<" contains: < " <<data<<","<<p->nodePos + 1<<" >"<<endl;
                p = p -> next;
                tmp++;
            }
        }
    }
    cout << "vnode pos = " << pos << endl;
    cout << "vnode out degree = " << tmp << endl;
}
//计算顶点的入度
void graph_adjList::locateVnodeIn(ELEMTYPE data)
{
    int tmp = 0;
    int pos = 0;
    for(int i = 0;i < vnum;++i)
    {
        if(array[i].data == data)//找到了该顶点
        {
            pos = i;
        }
    }
    for(int i = 0;i < vnum;++i)
    {
        arcNode *p = array[i].head;
        while(p)
        {
            if(p->nodePos == pos)
            {
                cout << array[i].data <<endl;
                tmp++;
                break;
            }
            p = p->next;
        }
    }
    cout << "vnode : " <<data <<" in degree = "<< tmp <<endl;
}
