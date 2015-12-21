/*************************************************************************
    > File Name: quick_sort.c
    > Author: Linhu Ying
    > Mail:  linhu.ying@u-blox.com
    > Created Time: Mon Dec 14 09:38:23 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

static void swap(int *data, int x, int y)
{
  int tmp = 0;

  if(NULL == data)
  {
    return;
  }

  tmp = data[x];
  data[x] = data[y];
  data[y] = tmp;
}

static int partition(int *data, int low, int high)
{
  int i = low, j = high;
  int piovt = data[low];

  while(i < j)
  {
    while(i < j)
	{
	  if(data[j] < piovt)
	  {
	    swap(data, i, j);
		break;
	  }
	  j --;
	}
	while(i < j)
	{
	  if(data[i] > piovt)
	  {
	    swap(data, i, j);
		break;
	  }
	  i++;
	}
  }
  return j;
}
	
void quick_sort(int *data, int low, int high)
{
  int j = 0;

  if(low < high)
  {
    j = partition(data, low, high);
	quick_sort(data, low, j-1);
    quick_sort(data, j+1, high);
  }
}

int main()
{
  int i = 0;
  int data[10] = {5,6,3,2,1,8,9,7,0,4};
  quick_sort(data, 0, 9);

  for(i=0; i < 10; i++)
  {
    printf("%d\n", data[i]);
  }

  int *ptr = (int *)malloc(sizeof(int));
  free(ptr);
  ptr = NULL;
  free(ptr);

  printf("--------->%d\n", 7%8);

  return 0;
}



