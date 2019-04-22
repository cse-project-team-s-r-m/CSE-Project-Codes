#include<stdio.h>

void selection(int X[],int H[],int n)
{
    int key,secondkey;
    int a,b,i,j,z;
    int L=0;

    for(i=1;i<n;i++)
    {
        key=H[i];
        secondkey=X[i];
        for(j=i-1;j>=0 && key<H[j];j--)
        {
            H[j+1]=H[j];
            X[j+1]=X[j];
        }
        H[j+1]= key;
        X[j+1]= secondkey;
    }

    for(a=0,b=1,i=0;i<n-1;i++)
    {
        if((b>a) && ((H[b]-H[a]) < (X[b]-X[a])))
        {
            z=(pow((X[b]-X[a]),2)+pow((H[b]-H[a]),2));

            if(z>L){L=z;}
            a=b;

            b++;}

        else
        {
            b++;
        }}

    if(a==n-1)
    {
        printf("Minimum possible rope length needed: %d\n",L);
    }
    else
    {
        printf("-1\n");
    }

}

int main()
{
    int X[100], H[100];
    int n,i;

    printf("Enter amount of trees present: \n");
    scanf("%d",&n);

    printf("Enter the co-ordinates and heights in sequence:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&X[i]);
        scanf("%d",&H[i]);
    }

    selection(X,H,n);
}
