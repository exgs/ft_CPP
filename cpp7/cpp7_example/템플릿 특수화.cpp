#include<iostream>
#include<string>
using namespace std;
 
template <class T>
T sum(T a, T b){
   return a + b;
}
 
template<>
char * sum<char*> (char* s1, char* s2){
   const char * str= "[char *]문자열은 더할 수 없습니다."; 
   cout << "s1 : " << s1 << endl;
   cout << "s2 : " << s2 << endl;
   return (char*)str; 
}
   
template<>
const char * sum<const char*> (const char * s1,const char *s2){
   const char * str= "[const char *]문자열은 더할 수 없습니다.";
   cout << "const s1 : " << s1 << endl;
   cout << "const s2 : " << s2 << endl;
   return str; 
}
 
template<>
string sum<string>(string s1, string s2){
   string str = "[string]문자열은 더할 수 없습니다.";
   cout << "string s1 : " << s1 << endl;
   cout << "string s2 : " << s2 << endl; 
   return str;
}
 
////////////////////TEST CASE/////////////////////
int main(void){
   int a =10;
   int b =20;
   double d1 = 1.1;
   double d2 = 2.2;
   char * s1 = "Dok2 ";
   char * s2 = "On My Way.";
   string s3 = "ZICO";
   string s4 = "Double D";
 
   cout << sum(a, b) << endl << endl;
   cout << sum(d1, d2) << endl << endl;
   cout << sum(s1, s2) << endl << endl;
   cout << sum("Tiger ", "JK") << endl << endl;
   cout << sum<const char*>(s1, s2) << endl << endl;
   cout << sum(s3, s4) << endl;
 
   return 0;
}
// 출처: https://blockdmask.tistory.com/45 [개발자 지망생]
