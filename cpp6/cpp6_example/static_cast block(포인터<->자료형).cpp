# include<iostream>
# include<cstdio>

using namespace std;

int main(void){
	//1. array->point//
	int arr[10] = {11,13,15,17,19,21,23,25,27,29};
	int * ptr;
	ptr = static_cast<int *>(arr);
	cout << "1. int array -> int * : ";
	for(int i=0; i<10; i++){
		cout <<  ptr[i] << " ";
	}
	printf("\n");
 
	//2. char * -> int *//
	char str[] = "BlockDMask";
	int *ptr2;
	// ptr2 = static_cast<int *>(str); //Compile error
	//cout << *ptr2 << endl;


	//3. int * -> char *//
	int tmp = 10;
	int *ptr3 = &tmp;
	// char * c = static_cast<char *>(ptr3); //Compile error
	// cout << "3. int* -> char* : " << *c << endl;

	//4. int* -> int//
	// int tmp1 = 10;
	// int *temp1 = static_cast<int *>(tmp1); //Compile error
	// cout << "4. int -> int* : " << *temp1 << endl;

	//5. int -> int*//
	// int *tmp2;
	// int temp2 = static_cast<int>(tmp2); //Compile error
	// cout << "5. int* -> int : " << temp2 << endl;

	return 0;
}


// 출처: https://blockdmask.tistory.com/236?category=249379 [개발자 지망생]
