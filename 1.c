#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int N,Q, *X,*Y,a,*b,i;
    int time=0;
    int temp;
    printf("Enter the number of questions:\n");
    scanf("%d",&N);
    printf("Enter the number of queries:\n");
    scanf("%d",&Q);

    printf("Enter the time of N questions\n");
    b=(int *)malloc(sizeof(int)*Q);
    X=(int *)malloc(sizeof(int)*N);
    Y=(int *)malloc(sizeof(int)*N);

    for(i=0;i<N;i++)
    {
        scanf("%d",X+i);
    }

    printf("Enter the score for N questions\n");

    for(i=0;i<N;i++)
    {
        scanf("%d",Y+i);
    }

    printf("Enter the number of questions she wants to solve\n");
    for(a=0;a<Q;a++)
    {
        scanf("%d",b+a);
    }
    printf("\n");
    printf("Time required:\n");
    mergeSort(X,0,N-1);
    mergeSort(Y,0,N-1);

    for(a=0;a<Q;a++)
    {
        temp=b[a];

        for(i=0;i<temp;i++)
        {
            time=time+X[N-i-1];

        }
        printf("%d\n",time);
        time=0;
    }
  return 0;
}
