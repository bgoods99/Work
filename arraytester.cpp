#include <iostream>

using namespace std;

int x = 1;
void functionOne(){
  int x = 25;
  cout<<"\n x is " << x << "on entering functionOne" << endl;
  ++x;
  cout<<" x is " << x << " on exiting functionOne" << endl;
}
void functionTwo(){
  cout<<"\n x is " <<x<< "on entering functionTwo"<<endl;
  x*=10;
  cout<<" x is "<<x<< "on exiting functionTwo"<<endl;
}
int main(){
  cout<<"(a) x is "<<x<<endl;
  int x = 5;
  cout<<"(b) x is "<<x<<endl;
  {
    int x = 7;
    cout<< "(c) x is "<<x<<endl;
  }
  cout<<"(d) x is "<<x<<endl;
  functionOne();
  functionTwo();
  functionOne();
  functionTwo();
  cout<<"(e) x is "<<x<<endl;
}
