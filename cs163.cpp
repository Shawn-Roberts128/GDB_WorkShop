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
  private:
    char * name;
    char * desc;
    char age[3]; // age between 000 and 999 
};

//DLL,CLL node
struct Node
{
  Node(Person & src);
  Node * next;
  Node * prev;
  Person  data;

};

// DLL/CLL
class Store { 

  public:
    void add (Person & toAdd);
    void disp();
    void remove(char * match);
    void remove(Person & removed, char * match);

  private:
    Node * tail;
    int count;
    void add(Node *tail,  Person & toAdd);
    void disp(Node * head, Node * tail);
    void remove(Node * head, Node * tail, const char * match);
    void remove(Node * head, Node * tail, Person & toFill, const char * match);
};


// Helper functions 
int sstrcpy(char *& dest, const char * src);  
int charDel( char *& toDest );
int menu(Store & toAppendTo);
void add_emp ( Store & toAppendTo);
void change_emp(Store & freds);
void remove_emp(Store & freds);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main () { 

  Store fredMyers;

  while(menu(fredMyers));
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

void add_emp ( Store & toAppendTo){

  Person toAdd;
  toAdd.UserReadIn();

  toAppendTo.add(toAdd);
}

void change_emp( Store & freds){ 
  // get name
  char buff [MAX]; buff[0] = 0;
  cout << "" ;
  cin.get(buff, MAX, '\n');
  cin.ignore(MAX,'n');

  // find employee from list and remove
  Person toChange;
  freds.remove(toChange, buff);

  // change things
  //
  while(toChange.menu());

  // re add to the list

  freds.add(toChange);
}

void remove_emp(Store & freds){

  // get name
  char buff [MAX]; buff[0] = 0;
  cout << "" ;
  cin.get(buff, MAX, '\n');
  cin.ignore(MAX,'n');

  // find employee from list and remove
  freds.remove(buff);

}
int menu(Store & freds ){ 

  char option = '\0';
  cout << endl;
  cout << endl;

  cout 
    << "Hello Dave Welcome to the Main Menu"<< endl
    << ""<< endl
    << ""<< endl
    << "    Is there anything I can Help you with today?" << endl
    << "        A - add employee to the list"<< endl
    << "        B - Display the list"<< endl
    << "        C - remove employee from the list"<< endl
    << "        D - edit employee in the list"<< endl
    << "        E - exit menu"<< endl
    << "";

  cin >> option;
  cin.ignore(100,'\n');
  
  option = toupper(option);

  // check for valid option
  if ((option < 'A')||(option > 'E')) return 1;

  switch (option) {

    case('A'):{
                add_emp(freds);
                return 1;
              }
    case('B'):{
                freds.disp();
                return 1;
              }
    case('C'):{
                remove_emp(freds);
                return 1;
              }
    case('D'):{
                change_emp(freds); 
                return 1;  
              }
    case('E'):{
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


/*----------------------------- Node -------------------------------------------*/  
Node :: Node ( Person & src):
  data(src)
{}

/*----------------------------- Store -------------------------------------------*/  

void Store::add (Person & toAdd){
  add(tail, toAdd);
}
void Store::disp(){
  disp(tail -> next, tail );
}
void Store::remove( char * match){
  remove( tail->next, tail , match);
}
void Store::remove(Person & removed, char * match ){
  remove( tail->next, tail, removed, match );
}


void Store :: add(Node *tail,  Person & toAdd){

  Node * temp = new Node (toAdd);
  if (!tail ) { 
    tail = temp;
    tail -> next = tail;
    tail -> prev = tail;
  }
  else { 
    temp -> next = tail -> next;
    temp -> prev = tail;
    tail = temp;
  }
}
void Store :: disp(Node * head, Node * end){
  if (!head) return;
  if (head == end )
  {
    head -> data.disp();
    return;
  }
  head -> data.disp();
  disp(head -> next, end);

}
void Store :: remove(Node * head, Node * end, const char * match){
  if (!head) return;
  if (head == end )
  { 
    // last item or only item and need to remove
    if (head -> data.checkName(match)){ 
      if (head == tail ) { 
        delete head;
        head = NULL; //another error 
        tail == NULL;
      } else { 
        Node * t_prev = head -> prev;
        Node * t_next = head -> next;
        t_prev -> next = t_next;
        t_next -> prev = t_prev;
        delete head;
        head = NULL;
      }
    } 
    return;
  }
  // normal case

  if (head -> data.checkName(match)){ 
    if (head == tail ) { 
      delete head;
      head = NULL; //another error 
      tail == NULL;
    } else { 
      Node * t_prev = head -> prev;
      Node * t_next = head -> next;
      t_prev -> next = t_next;
      t_next -> prev = t_prev;
      delete head;
      head = NULL;
    }
  } 

  remove ( head -> next, end, match );

}
void Store :: remove(Node * head, Node * end, Person & toFill, const char * match){
  if (!head) return;
  if (head == end )
  { 
    // last item or only item and need to remove
    if (head -> data.checkName(match)){ 
      if (head == tail ) { 
        toFill.cpy(head->data);
        delete head;
        head = NULL; //another error 
        tail == NULL;
      } else { 
        toFill.cpy(head->data);
        Node * t_prev = head -> prev;
        Node * t_next = head -> next;
        t_prev -> next = t_next;
        t_next -> prev = t_prev;
        delete head;
        head = NULL;
      }
    } 
    return;
  }
  // normal case

  if (head -> data.checkName(match)){ 
    if (head == tail ) { 
      toFill.cpy(head->data);
      delete head;
      head = NULL; //another error 
      tail == NULL;
    } else { 
      toFill.cpy(head->data);
      Node * t_prev = head -> prev;
      Node * t_next = head -> next;
      t_prev -> next = t_next;
      t_next -> prev = t_prev;
      delete head;
      head = NULL;
    }
    return;
  } 

  remove ( head -> next, end, toFill, match );
}
