#include<bits/stdc++.h>
using namespace std;

class Semaphore {
public:
	int value;
	bool block;
    void Set(int v ){
	    value = v;
	    block = false;
	}
};

queue<Semaphore> q;

void P(Semaphore s)
{
	s.value = s.value - 1;
	if (s.value < 0 ) {
		s.block = true;
		q.push(s);
	}
	else
		return;
}

void V(Semaphore s)
{
	s.value = s.value + 1;
	if (s.value <= 0) {
		Semaphore p = q.pop();
		s.block = false;
	}
	else
		return;
}

int main(){
    int n;
    Semaphore p[n];
    cout<<"Number of Process: ";
    cin>>n;
    for(int i=0;i<n;i++){
        p[i].Set(i+1);
    }
}

