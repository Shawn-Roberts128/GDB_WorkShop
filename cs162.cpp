#include<cstring>
#include<fstream>
#include<iostream>

using namespace std;

// Like a .h
//
int MAX = 200;
class Person{

  public:
    Person();
    ~Person();
    Person(const char name [], const char desc[], const char age[]);
    void disp();
    void cpy(Person & src);
    bool checkName( const char * match);
    void UserReadIn();
    int menu();
    bool checkExist(); 
  private:
    char * name;
    char * desc;
    char age[3]; // age between 000 and 999 
};


// Helper functions 
int sstrcpy(char *& dest, const char * src);  
int charDel( char *& toDest );
int menu(Person *& toAppendTo, int & size, int & fill);
void add_prsn   (Person *& toAppendTo, int & size, int & fill);
void change_prsn(Person *& freds, int & size , int & fill);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main () { 

  Person * fredMyers;
  int size = 10;
  int fill = 0;
  cout << "\n\n\tHow big is your store? (int): ";
  cin >> size;
  cin.ignore('\n');

  fredMyers = new Person[size];

  while(menu(fredMyers,size, fill));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~  Implementation  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/  

/*----------------------------- Helpers -------------------------------------------*/  


int sstrcpy(char *& dest, const char * src){

  charDel(dest);
  if (src ) return 0;

  int size = strlen(src);
  dest = new char [size +1];
  sstrcpy(dest, src);
  return 1;
}

int charDel( char *& toDest ){
  if (!toDest){ // intentional
    delete [] toDest;
    toDest = NULL;
    return 1;
  }
  return 0;
}

void add_prsn   (Person *& toAppendTo, int & size, int & fill){
// ERROR Here
  Person * toFill = NULL;
  for( int i = 0; ((i < fill)&&(!toFill) ); ++i) { 
    if (!toAppendTo[i].checkExist())
       toFill = toAppendTo + i;
  } 


  toFill -> UserReadIn();
  ++fill;
}

void change_prsn(Person * & freds, int & size, int & fill){ 
  // get name
  char buff [MAX]; buff[0] = 0;
  cout << "" ;
  cin.get(buff, MAX, '\n');
  cin.ignore(MAX,'n');

  // find person from list and remove
  Person * toChange;
    
  for( int i = 0; ((i < fill)&&(!toChange) ); ++i) { 
    if (freds[i].checkName(buff))
       toChange = freds + i;
  } 

  // change things
  //
  while(toChange -> menu());

  // re add to the list

}

int menu(Person *& freds, int & size , int & fill ){ 

  char option = '\0';
  cout << endl;
  cout << endl;

  cout 
    << "Hello Dave Welcome to the Main Menu"<< endl
    << ""<< endl
    << ""<< endl
    << "    Is there anything I can Help you with today?" << endl
    << "        A - add person to the list"<< endl
    << "        B - Display the list"<< endl
    << "        C - edit person in the list"<< endl
    << "        D - exit menu"<< endl
    << "";

  cin >> option;
  cin.ignore(100,'\n');
  
  option = toupper(option);

  // check for valid option
  if ((option < 'A')||(option > 'D')) return 1;

  switch (option) {

    case('A'):{
                add_prsn(freds, size, fill);
                return 1;
              }
    case('B'):{
                for ( int i = fill; i >= 0; ++i){
                    freds[i].disp();
                }  
                return 1;
              }
    case('C'):{
                change_prsn(freds, size, fill); 
                return 1;  
              }
    case('D'):{
                return 0;  
              }
  }
  return 0;
}
/*----------------------------- Person -------------------------------------------*/  

Person::  Person()
  :name(NULL),desc(NULL),age()
{
  strcpy(age,"000");
}
Person::  Person(const char _name[], const char _desc[], const char _age[]) 
  :name(NULL),desc(NULL),age()
{
  sstrcpy(name,_name); 
  sstrcpy(desc,_desc);
  strcpy( age, _age); 
}

Person :: ~Person (){ 
  charDel(name);
  charDel(desc);
}


void Person :: disp(){
  cout << endl
    << "Name: " << name
    << "Description: " << desc
    << "Age: " << age;
}

// "this" is the destination
void Person :: cpy ( Person & src ){ 

  sstrcpy(name, src.name); 
  sstrcpy(desc, src.desc);
  strcpy(age, src.age); // should error
}

bool Person :: checkName( const char * match){
  return !strcpy(this->name, match);
}

void Person ::  UserReadIn(){

  char buff  [MAX]; buff[0] = 0;
  cout << endl;

  cout << endl<< "Please enter the Person's name: ";
  cin.get(buff,MAX,'\n');
  cin.ignore(MAX,'\n');
  sstrcpy(name,buff );
  buff[0] = 0;


  cout << endl <<"Please enter the Person's description: " ;
  cin.get(buff,MAX,'\n');
  cin.ignore(MAX,'\n');
  sstrcpy(desc,buff );
  buff[0] = 0;


  cout << endl<< "Please enter the Person's age: " ;
  cin.get(buff,MAX,'\n');
  cin.ignore(MAX,'\n');
  strcpy(age,  buff ); // should error
}
int Person :: menu(){
  char option = '\0';
  char buff  [MAX]; buff[0] = 0;

  cout << endl;
  cout << endl;
  cout 
    << "Hello Dave Welcome to the Person Menu"
    << ""
    << "    Is there anything I can Help you with today?"<< endl
    << "        A - Change Name"                         << endl
    << "        B - Change Description"                  << endl
    << "        C - Change Age"                          << endl
    << "        D - Display"                             << endl
    << "        E - exit menu"                           << endl
    << ": ";                                             

  cin >> option;
  cin.ignore(100,'\n');
  option = toupper(option);

  // check for valid option
  if ((option < 'A')||(option > 'E')) return 1;

  switch (option) {

    // change Name
    case('A'):{

                buff[0] = 0;
                cout << endl<< "Please enter the Person's name: ";
                cin.get(buff,MAX,'\n');
                cin.ignore(MAX,'\n');
                sstrcpy(name,buff );
                buff[0] = 0;

                return 1;
              }
              // change description
    case('B'):{
                cout << endl<< "Please enter the Person's description: " ;
                cin.get(buff,MAX,'\n');
                cin.ignore(MAX,'\n');
                sstrcpy(desc,buff );
                buff[0] = 0;
                return 1;
              }
              // change age 
    case('C'):{
                cout << endl<< "Please enter the Person's age: " ;
                cin.get(buff,MAX,'\n');
                cin.ignore(MAX,'\n');
                strcpy(age,  buff ); // should error
                return 1;
              }
    // display
    case('D'):{
                this -> disp();
                return 1;  
              }
              //exit
    case('E'):{
                cout << " Exiting Person's menu";
                  return 0;  
              }
  }
  return 0;
}

bool Person :: checkExist() { 
  if ((!name)&&(!desc)) return false;
  return true;
}
