#include<iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
using namespace std;
template <typename T>
bool is_sorted (T* a, size_t size)
{
    if(a!=NULL)
    {
        for (size_t i = 0; i < size-1; i += 1)
        {
            if(*(a+i)>*(a+i+1))
                return false;
        }
        cout<<"Array Sorted Successfully"<<endl;
        return true;
    }
    else
    {
        cout<<"Empty Array"<<endl;
        return false;
    }
}
template <typename T>
void shell_sort (T* a, size_t size)
{
    if(a!=NULL){
        for (size_t itv = size/2; itv > 0; itv /= 2)
        {
            for (size_t i = itv; i < size; i += 1)
            {
                T temp = *(a+i);
                size_t j;
                for (j = i; j >= itv && *(a+(j-itv)) > temp; j -= itv)
                    *(a+j) = *(a+(j-itv));
                *(a+j) = temp;
            }
        }
    }
    else
        cout<<"Empty Array"<<endl;
}
int* create_array (size_t size)
{
    int* a=new int;
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < size; i++)
        *(a+i) = 1+ rand() % 10000;
    return a;
}

int main ()
{
    size_t size = 1000;
    int* a = create_array (size);
    for(size_t i=0;i<size;i++)
        cout<<*(a+i)<<" ";
    cout << endl;
    shell_sort (a, size);
    assert (is_sorted (a, size));
    cout<<endl<<"The sorted Array is:\n";
    for(size_t i=0;i<size;i++)
        cout<<*(a+i)<<" ";
    delete a;
    return EXIT_SUCCESS;
}