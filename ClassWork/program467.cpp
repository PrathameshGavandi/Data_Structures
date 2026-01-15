#include<iostream>
using namespace std;

template <class T>
class Arithmatic
{
    public:
        T No1;
        T No2;

        Arithmatic(T A, T B)
        {
            No1 = A;
            No2 = B;
        }

        T Addition()
        {
            T Ans;
            Ans = No1 + No2;
            return Ans;
        }

        T Substraction()
        {
            T Ans;
            Ans = No1 - No2;
            return Ans;
        }

};

int main()
{
    Arithmatic <int> iobj(11,10);

    cout<<"Addition is : " << iobj.Addition()<<"\n";
    cout<<"Substraction is : " << iobj.Substraction()<<"\n";


    Arithmatic <double> dobj(11.8967,10.4567);

    cout<<"Addition is : " << dobj.Addition()<<"\n";
    cout<<"Substraction is : " << dobj.Substraction()<<"\n";

    return 0;
}