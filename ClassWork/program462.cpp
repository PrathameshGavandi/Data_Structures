#include<iostream>
using namespace std;

template<class T>

T Addition(T No1, T No2)
{
    T Ans;
    Ans = No1 + No2;
    return Ans;
}

int main()
{

    cout<<"Addition of Characters :"<<Addition('a','b')<<"\n";
    cout<<"Addition of Integers :"<<Addition(10,11)<<"\n";
    cout<<"Addition of Floats :"<<Addition(90.3f,78.5f)<<"\n";
    cout<<"Addition of Doubles :"<<Addition(78.256375, 45.725637)<<"\n";
    
    return 0;
}