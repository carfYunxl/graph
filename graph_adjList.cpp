#include "graph_adjList.h"

//创建图
void graph_adjList::createAdjGraph(int num)
{
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
	for(int i = 0;i < num;++i)
	{
		cout << "please enter the "<<i<<"arc head:" << endl;

		cout << "enter -1 over" << endl;
		int pos = 0;
		while(cin >> pos)
		{
			if(pos == -1)
				break;
			else
			{
				cout << "please enter the"<<i<<"arc info:" << endl;
				vnum ++;//顶点数+1
				int info = 0;
				if(cin >> info)
				{
					arcNode *node = new arcNode;
					if(!array[i].head)//如果head是空指针，说明还没有边
					{
						array[i].head = node;//node直接给head
					}else{//如果head不空，说明head有结点，使用头插法
						arcNode *p = array[i].head;
						node->next = p;
						array[i].head = node;
					}
					node->nodePos = pos;
					node->info = info;
					node->next = nullptr;
					arcnum ++;//边+1
				}
			}
			cout << "please enter the " << i << "arc head:" << endl;
			cout << "enter -1 over" << endl;
		}
	}
}
//查找图的顶点，以及该顶点的出度
void graph_adjList::locateVnode(ELEMTYPE data)
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
				p = p -> next;
				tmp++;
			}
		}
	}
	cout << "vnode pos = " << pos << endl;
	cout << "vnode out degree = " << tmp << endl;
}