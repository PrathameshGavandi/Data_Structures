#include<iostream>
using namespace std;

class Arithmetic
{
    private:
        int No1,No2;
    public:
        Arithmetic(int A, int B)
        {
            this->No1 = A;
            this->No2 = B;
        }

        int Addition()
        {
            return No1 + No2;
        }

        int Substraction()
        {
            return No1 - No2;
        }
};
int main()
{
    Arithmetic aboj(11,10);

    cout<<aboj.Addition()<<"\n";
    cout<<aboj.Substraction()<<"\n";
    

    return 0;
} 
