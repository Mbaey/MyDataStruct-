#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e2+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N]={0};

struct tn{
	int d,h;//?
	tn *l,*r,*p;
	tn():l(NULL),r(NULL),p(NULL){};
}nodes[N];
//在栈中，new出来个一样的，所有用tn node,会炸！ 
void insert(tn *f, tn** now, tn &node, int d, int h){
	
	if(*now == NULL){
		node.h=h;
		node.p = f;
		*now = &node;
		return;
	}else{
//		cout << (*now)->d <<endl;
		if((*now)->d > d){
			insert(*now, & (*now)->l, node, d, h+1);
		}else
			insert(*now, & (*now)->r, node, d, h+1);	
	}
	
}
void dfs(tn* now){
	if(now==NULL)
		return;
	
	cout << now->d << " "<< now->h <<endl;
	dfs(now->l);
	dfs(now->r);
}
//c++中 指针的引用方便很多 
void Traversal(int a, int b,tn *&A, tn *&B ){
	_for(i,0,n){
		if(nodes[i].d == a){
			A = &nodes[i];
		}
		
		if(nodes[i].d == b){
			B = &nodes[i];
		}
	}
}
int main() {
	freopen("1.txt", "r", stdin);
	cin >> n ;
	tn *root=NULL;
	
	_for(i,0,n){
		cin >> nodes[i].d;
		insert(NULL, &root, nodes[i], nodes[i].d, 0);
	}
	cin >> m;
	getchar();
	string s;
	int A,B;
	tn *Anode, *Bnode;
	while(m--){
		Bnode = Anode = NULL;
		getline(cin, s);
		if(s.find("root") != -1){
			sscanf(s.c_str(), "%d is the root",  &A);
			if(root->d == A){
				printf("Yes\n");
			}else
				printf("No\n");
		}else if(s.find("siblings") != -1){
			sscanf(s.c_str(), "%d and %d are siblings",  &A, &B);
			Traversal(A,B,Anode, Bnode);
			if(Anode&& Bnode && Anode->p == Bnode->p  && Anode != Bnode){
				printf("Yes\n");
			}else
				printf("No\n");
				
		}else if(s.find("parent") != -1){
			sscanf(s.c_str(), "%d is the parent of %d",  &A, &B);
			Traversal(A,B,Anode, Bnode);
			if(Anode&& Bnode && Anode == Bnode->p){
				printf("Yes\n");
			}else
				printf("No\n");
				
		}else if(s.find("left") != -1){
			sscanf(s.c_str(), "%d is the left child of %d",  &A, &B);
			Traversal(A, B, Bnode, Anode);
			if(!(Anode&& Bnode) ){
				printf("No\n");
				continue;
			}
		//	while(Bnode->p != Anode && Bnode->p != NULL){
//				Bnode = Bnode->p;
//			}
			if(Anode->l == Bnode){
				printf("Yes\n");
			}else
				printf("No\n");
				
		}else if(s.find("right") != -1){
			sscanf(s.c_str(), "%d is the right child of %d",  &A, &B);
			Traversal(A, B, Bnode, Anode);
			if(!(Anode&& Bnode)){
				printf("No\n");
				continue;
			}
			
			//while(Bnode->p != Anode && Bnode->p != NULL){
//				Bnode = Bnode->p;
//			}
			if(Anode->r == Bnode){
				printf("Yes\n");
			}else
				printf("No\n");
		}else{
			sscanf(s.c_str(), "%d and %d are on the same level",  &A, &B);
			Traversal(A,B,Anode, Bnode);
			if(!(Anode&& Bnode)){
				printf("No\n");
				continue;
			}
			
			if(Anode->h == Bnode->h && Anode != Bnode){
				printf("Yes\n");
			}else
				printf("No\n");
		}
	}
//	dfs(root);
	
		
	return 0;
 }
