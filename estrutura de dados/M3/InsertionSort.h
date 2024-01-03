#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

template<typedef T>
void insertionSort(int &c, int &m, int qtd, T v[])
{
    c=0;
    m=0;
    for(int i=0; i<qtd-1; i++)
        for(int j=i+1; j>0; j--)
        {
            c++;
            if(v[j]>v[j-1])
            {
                swap(v[j], v[j-1]);
                m++;
            }
            else
                break;
        }
}

#endif // INSERTIONSORT_H_INCLUDED
