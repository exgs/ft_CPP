#include <iostream>

#include <list>

using namespace std;

int main() {
	int ari[]={1,2,3,4,5};
	list<int> li(&ari[0],&ari[5]);
	list<int>::iterator it;
	for (it=li.begin();it!=li.end();it++) {
	printf("%d\n",*it);
	}
}

// 출처: https://eehoeskrap.tistory.com/263 [Enough is not enough]
