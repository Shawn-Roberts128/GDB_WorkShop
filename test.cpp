#include<cstring> 
using namespace std;

struct t {
  int a;
  char b;
  char c[100];
};



int main (){ 

   t test;
   test.a = 26;
   test.b = 'b';
   strcpy(test.c, "deadBeef");

}
