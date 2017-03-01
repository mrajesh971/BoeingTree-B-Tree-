#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int k=1;
class btree
{
public:
struct node
{
int count;//for count;
node *child[5];
int p[4];
node()
{
	count=0;
	for(int i=0;i<4;i++)
	p[i]=0;
	
}
};
struct split
{
node *ptr;
int ele;

split()
{
ptr=NULL;
}
};
stack<node*> S;
stack<node*> s1;
queue<node*> myqueue;
node *root;
	node *tree;
btree()
{

 root=NULL;
 //count=0;



/*for(int i=0;i<5;i++)
root.p[i]=0;*/
}
void insert2(node *&root,int data)
{
	if(root==NULL)
	{
		root=new node;
		root->count=1;
		for(int i=0;i<5;i++)
		root->child[i]=NULL;
		root->p[0]=data;
		//k++;
	}
}
void insert(node *&root,int data)
{
int k3=0,k4=0;
if(root==NULL)
return;
else 
{
	//int k3=0,k4=0;
	for(int i=0;i<5;i++)
	{
	if(root->child[i]==NULL)
	 {
	k3++;
     }
}
if(k3==5)
{	//S.push(root);
	inserttree(root,data,root->count+1);
}

else
{
	for(int i=0;i<5;i++)
	{
	if(data>root->p[i])
	{
		k4++;
	}
	else
	break;
	S.push(root);
	s1.push(root);
	insert(root->child[k4],data);
}
}
}
}
/*void insert4(node *&root,int data)
{
	
}*/
void inserttree(node *&temp1,int data,int rootcount)
{
	int k1,k2;
     if(rootcount<5)
{
       
	   	
	int temp,a;
//	cout<<"root->count is"<<root->count;
	cout<<"\t";
	k1=rootcount;
	k2=rootcount-1;
	temp1->p[k2]=data;
	temp1->count=k1;
	//cout<<"yahoo the value of k1 is"<<k1;
	a=temp1->count;
//a=a-1;

//cout<<a<<"**"<<k<<endl;
for(int i=0;i<temp1->count;i++)
{
	for(int j=0;j<temp1->count;j++)
	{
		if(temp1->p[i]<temp1->p[j])
		{
			temp=temp1->p[j];
			temp1->p[j]=temp1->p[i];
			temp1->p[i]=temp;
			
		}
	}

}
}



else
{
checkandsplit(temp1,data); 	
//k=0;
}
}
void insert1(int n1)
{
	
//	insert2(root,n1);
//	else if(root->count<=4)
     if(root==NULL)
	insert2(root,n1);
	else
	insert(root,n1);


	//checkandsplit(root);
}

void display()
{
	display1(root,1);
}
void display1(node *root,int x)
{
	if(root!=NULL)
{
		cout<<endl;
		for(int i=0;i<root->count;i++)
		cout<<root->p[i];
		if(x==1) cout<<"\n";
		else cout<<"   ";
		for(int i=0;i<root->count+1;i++)
		{	myqueue.push(root->child[i]); }
		for(int i=0;i<root->count+1;i++)
		{
		node* tmp=myqueue.front();
		myqueue.pop();
		int n=0;
		if(i==root->count) n=1;
		if(tmp!=NULL)
		display1(tmp,n);
		}
	}
	return;


}


void checkandsplit(node *&root1,int n)
{
	int res,res1;
	
	split a[100];
	a[0].ptr=root1->child[0];

	for(int i=0;i<root1->count;i++)
	{
	a[i].ele=root->p[i];
	a[i+1].ptr=root->child[i+1];
	}
	a[root1->count].ele=n;
	a[root1->count+1].ptr=root1->child[root1->count+1];
	sortandfindmedian(a);
	//cout<<"sorted";
	//for(int i=0;i<=root1->count;i++)
	//cout<<a[i];
	res=root1->count;
	if(res%2==0)
	{
		res=res/2;
	
	}

	else
	{
		res=res/2;
		res=res+1;
	}
	res1=a[res].ele;
	
	//int m=1;
	//cout<<"the value of a[res] is "<<res<<"THE \t"<<a[res1];
	node *tree;
	tree=new node;
	//tree->count=m++;
      
	int i=0;

	tree->p[0]=a[res+1].ele;
	tree->p[1]=a[res+2].ele;
	tree->child[0]=NULL;
	tree->child[1]=NULL;	
	//tree->count=1;
	root1->p[2]=0;
	root1->p[3]=0;
	root1->count=root1->count-2;
	tree->count=root1->count;
	tree->child[2]=NULL;
	tree->child[3]=NULL;
	tree->child[4]=NULL;
	//root->count=1;
	node *tree1;
	node *temp=NULL;
	if(!S.empty())
{
	temp=S.top();
	S.pop();
}
	if(temp==NULL)
{
	tree1=new node;

	tree1->p[0]=res1;
	tree1->count=1;




	tree1->child[0]=root1;
	tree1->child[1]=tree;
	
	root=tree1;
//	insert()
}
else
{
insert(temp,res1);
}	
}
void sortandfindmedian(struct split a[])
{
int j;
for(int p=1;p<=root->count;p++)
{
 int tmp=a[p].ele;
	for(j=p;j>0&&tmp<a[j-1].ele;j--)
	a[j].ele=a[j-1].ele;
	a[j].ele=tmp;
}

for(int p=2;p<=root->count+1;p++)
{
 node* tmp=a[p].ptr;
	for(j=p;j>1&&tmp<a[j-1].ptr;j--)
	a[j].ptr=a[j-1].ptr;
	a[j].ptr=tmp;
}

}

};




int main()
{									
btree b;
int a;

//cout<<"\n1 insert \n2 display";
cout<<endl;
b.insert1(5);
b.insert1(3);
b.insert1(2);
b.insert1(1);
//int rafa=4;
//cout<<rafa;
b.insert1(6);

b.insert1(7);
//b.insert1(10);
//b.insert1(199999999);*/
//cout<<"**"<<b.root->p[0]<<" "<<b.root->child[0]->p[0]<<" "<<b.root->child[1]->p[0]<<endl;
b.display();
return 0;
}

