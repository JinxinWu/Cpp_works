/*��д�����ڵ�����Ļ����Ϻϲ����������ϲ�ǰ��ĵ������ַ����Եݼ���
����ʾ�ϲ�ǰ��ĵ�����ע�⣺����й©�ڴ档*/
#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

void insert(node *la,int x){
	node *q=new node;
	q->data=x;
	node *p=la;
	while(p->next&&x>p->next->data)
		p=p->next;
	q->next=p->next;
	p->next=q;
}

void destroy(node *la){
	while(la){
		node *q=la->next;
		delete la;
		la=q;
	}
}

void print(node *la){
	node *q=la->next;
	if(q){
		cout<<q->data;
		q=q->next;
	}
	while(q){
		cout<<"->"<<q->data;
		q=q->next;
	}
	cout<<endl;
}

int main(){
	node *la=new node;
	la->next=NULL;
	node *zh=new node;
	zh->next=NULL;
	node *fu=new node;
	fu->next=NULL;
	int x;
	while(cin>>x){
	    insert(la,x);
		if(x>=0){
			insert(zh,x);
		}
		else{
			insert(fu,x);
		}
	}
	print(la);
	cout<<"\n";
	print(zh);
	cout<<"\n";
	print(fu);
	destroy(la);
	destroy(zh);
	destroy(fu);
	return 0;
}










