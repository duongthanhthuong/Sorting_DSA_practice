#include <iostream>
using namespace std;
// DE SAI PHAN PRINT ARRAY 
template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start+1; // THEM CONG 1
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};
template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
    int i=1;
    int j=end - start;
    while(j>=i)
    {
        if (*(start+i) > *start)
        {
            if (*(start+j) < *start)
            {
                T tmp = *(start+i);
                *(start+i)= *(start+j);
                *(start+j)= tmp;
                i++;
                j--;
            }
            else
            {
                j--;
            }
        }
        else 
        {
            i++;
        }
    }
    T tmp= *start;
    *start= *(start+j);
    *(start+j)= tmp;
    return start+j;
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
    
    if (end>start)
    {
        cout<<"Insertion sort: ";
        printArray(start,end);
        int current=1;
        while (current< (end-start)+1)
        {
            T tmp= *(start+current);
            int step= current-1;
            while (step>=0 && (tmp< *(start+step)))
            {
                *(start+step+1)= *(start+step);
                step--;
            }
            *(start+step+1)= tmp;
            current++;
        }
    }
    else if (end==start) 
    {
        cout<<"Insertion sort: ";
        printArray(start,end);
    }

}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    //cout<< " so phan tu cua mang : " << end-start+1 << "\n";
    if ((end-start+1) >= min_size)
    {
        cout<<"Quick sort: ";
        printArray(start,end);
        T *p= Partition(start,end);
        hybridQuickSort(start,p-1,min_size);
        hybridQuickSort(p+1,end,min_size);
    }
    else
    {
        insertionSort(start,end);
    }
}
int main()
{
    /*int array[] = {1, 2, 6, 4, 7, 8, 5, 3};
int min_size = 4;
Sorting<int>::hybridQuickSort(&array[0], &array[7], min_size);

int array[] = {2, 6, 4, 12, 23, 1, 0, -12};
int min_size = 4;
Sorting<int>::hybridQuickSort(&array[0], &array[7], min_size);*/

int array[] = {30, 7, 20, 0, -13, 1, 19, 72};
int min_size = 3;
Sorting<int>::hybridQuickSort(&array[0], &array[7], min_size);
    return 0;
}