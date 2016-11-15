/*0 0 0 0 0 0 0 0 0 0
  0 1 0 0 0 0 0 0 0 0
  0 1 0 1 1 1 1 1 1 1
  0 1 0 1 0 0 0 1 0 0
  0 1 0 0 0 1 0 1 0 1
  0 1 0 1 1 1 0 0 0 1
  0 1 0 1 1 1 0 1 0 1
  0 1 0 0 0 1 0 0 0 1
  0 1 0 1 0 1 0 1 0 0
  0 0 0 0 0 0 0 1 0 0*/


#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node{
public:
     int x;
	 int y;
	 int lx;
	 int ly;
	 int poi;
	 int oi;
	 int c; 	
};

void ans(node a[]){
    stack<node> answer;
	answer.push(a[99]);
	int x=a[99].x;
	int y=a[99].y;
	int lx=a[99].lx;
	int ly=a[99].ly;
	while(1){
	   answer.push(a[lx*10+ly]);
	   node *p;
	   p=&answer.top();
	   x=p->x;
	   y=p->y;
	   lx=p->lx;
	   ly=p->ly;
	   if(lx==-1)
	   break;	
	}
	while(answer.empty()!=1){
		node *q;
	    q=&answer.top();
	    cout<<q->x<<" and "<<q->y<<endl;
	    a[q->x*10+q->y].c=1;
	    answer.pop();
	} 
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout<<a[i*10+j].c<<" ";
		}
		cout<<endl;
	}
	cout<<a[99].oi<<endl;      	 	
}

bool good(int x,int y,int poi,int oi){
	if(x<=9&&x>=0&&y<=9&&y>=0&&poi==0&&oi==0)
	return 1;
	return 0;
} 

int main(){
	node a[100];
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++){
			a[10*i+j].x=i;
			a[10*i+j].y=j;
			cin>>a[10*i+j].poi;
			a[10*i+j].oi=0;
			a[10*i+j].c=0;
		}
	queue<node> mylist;
	mylist.push(a[0]);
	a[0].oi=1;
	a[0].lx=-1;
	a[0].ly=-1;
	while(1){
		node *p;
		p=&mylist.front();
		int x=p->x;
		int y=p->y;
		;
		if(good(x+1,y,a[(x+1)*10+y].poi,a[(x+1)*10+y].oi)) {
			mylist.push(a[(x+1)*10+y]);
			a[(x+1)*10+y].lx=x;
			a[(x+1)*10+y].ly=y;
			a[(x+1)*10+y].oi=a[x*10+y].oi+1;
			p=&mylist.back();                  
			if(p->x==9&&p->y==9){
				ans(a);
				break;
			}
		}
		if(good(x,y+1,a[x*10+y+1].poi,a[x*10+y+1].oi)) {
			mylist.push(a[x*10+y+1]);
			a[x*10+y+1].lx=x;
			a[x*10+y+1].ly=y;
			a[x*10+y+1].oi=a[x*10+y].oi+1;
			p=&mylist.back();
			if(p->x==9&&p->y==9){
				ans(a);
				break;
			}
		}
		if(good(x-1,y,a[(x-1)*10+y].poi,a[(x-1)*10+y].oi)) {
			mylist.push(a[(x-1)*10+y]);
			a[(x-1)*10+y].lx=x;
			a[(x-1)*10+y].ly=y;
			a[(x-1)*10+y].oi=a[x*10+y].oi+1;
			p=&mylist.back();
			if(p->x==9&&p->y==9){            
				ans(a);
				break;
			}
		}
		if(good(x,y-1,a[x*10+y-1].poi,a[x*10+y-1].oi)) {
			mylist.push(a[x*10+y-1]);
			a[x*10+y-1].lx=x;
			a[x*10+y-1].ly=y;
			a[x*10+y-1].oi=a[x*10+y].oi+1;
			p=&mylist.back();
			if(p->x==9&&p->y==9){
				ans(a);
				break;
			}
		} 
		mylist.pop();	
		if(mylist.empty()==1){
			cout<<"no path\n";
			break;
		}		
	}
    return 0;
}