/*************************************************************************
    > File Name: sort.cpp
    > Author: Linhu Ying
    > Mail:  linhu.ying@u-blox.com
    > Created Time: Thu Sep 10 09:34:15 2015
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

class Sort
{
  public:
    virtual ~Sort(){}
    virtual void Sort_do(int *array, int low, int high) = 0;
    virtual void Sort_print() = 0;
  protected:
    int *m_array;
    int m_low;
	int m_high;
	int m_length;
};

class QuickSort : public Sort
{
  public:
    QuickSort(int *array, int low, int high);
    virtual ~QuickSort(){}
    virtual void Sort_do(int *array, int low, int high);
    virtual void Sort_print();
    int partition(int *array, int low, int high);
	void Swap(int *array, int i, int j);
};

QuickSort :: QuickSort(int *array, int low, int high)
{
  m_array = array;
  m_low = low;
  m_high = high;
  m_length = high -low + 1;
}

void QuickSort:: Sort_do(int *array, int low, int high)
{
  int p = 0;
  if(low < high)
  {
	p = partition(array, low, high);
    Sort_do(array, low, p-1);
    Sort_do(array, p+1, high);
  }
}

int QuickSort :: partition(int *array, int low, int high)
{
  int piovt = array[low];
  int i = low;
  int j = high;
  
  while (i < j)
  {
    while (i < j)
	{
	  if(array[j] < piovt)
	  {
		Swap(array, i, j);
		break;
	  }
	  j--;
	}
    
	while(i < j)
	{
	  if(array[i] > piovt)
	  {
	    Swap(array, i, j);
        break;
	  }
	  i ++;
	}
  }
  Sort_print();
  return j;
}

void QuickSort :: Sort_print(void)
{
  int i = 0;
  std:: cout << "print array: " << endl; 
  for(i = 0; i < m_length; i++)
	std::cout << m_array[i] << endl;
}

void QuickSort :: Swap(int *array, int i, int j)
{
  int tmp = 0;
  tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

/*---------------------------------------------------------*/

class BinarySort : public Sort
{
  public:
    BinarySort(int *array, int low, int high);
	virtual ~BinarySort() {}
	virtual void Sort_do(int *array, int low, int high);
    virtual void Sort_print();
    void Sort_print(int *array);
};

BinarySort :: BinarySort(int *array, int low, int high)
{
  m_array = array;
  m_low = low;
  m_high = high;
  m_length = high -low + 1;
}

void BinarySort :: Sort_do(int *array, int low, int high)
{
  int length = high - low + 1;
  int start = 0, end = 0;
  int tmp = 0;
  int i, j = 0;
  int pos = 0;

  for(i = 1; i < length; i++)
  {
	 start = 0;
     end = i - 1;
     tmp = array[i];

	 printf("round %d\n", i);
	 
	 while(start <= end)
	 {
	   pos = (start + end)/2;

	   if(tmp == array[pos])
	   {
	     start = pos;
		 break;
	   }

	   if(tmp > array[pos])
		 start = pos + 1;
	   else
		 end = pos -1;
	 }

	 for(j = i; j > start; j--)
	 { 
	   array[j] = array[j-1];
     }

	 array[start] = tmp;

	 Sort_print();

  }
}

void BinarySort :: Sort_print(void)
{
  int i = 0;
  std:: cout << "print array: " << endl; 
  for(i = 0; i < m_length; i++)
	std::cout << m_array[i] << endl;
}

void BinarySort :: Sort_print(int *array)
{
  int i = 0;
  std:: cout << "print array: " << endl; 
  for(i = 0; i < m_length; i++)
	std::cout << array[i] << endl;
}
/*----------------------------------------------------------*/

int main()
{
  int data_array[10] = { 6,8,9,10,3,2,2,5,8,0 }; 
  
//  QuickSort qs(data_array, 0, 9);
 
  BinarySort qs(data_array, 0, 9);

  std::cout << "before quick sort: " << endl;
  
  qs.Sort_print();
  
  qs.Sort_do(data_array, 0, 9);

  std::cout << "after quick sort: " << endl;

  qs.Sort_print();

  return 0;
}


