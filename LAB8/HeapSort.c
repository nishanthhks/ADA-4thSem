#include <stdio.h>
#include <time.h>

void heapify(int n , int a[])
{
    int p,c,item;
    for(p=(n-1)/2;p>=0;p--)
    {
        item=a[p];
        c=2*p+1;
        while(c<=n-1)
        {
            if(c+1<=n-1)
            {
                if(a[c]<a[c+1])
                    c++;
            }
                if(item<a[c])
                {
                    a[p]=a[c];
                    p=c;
                    c=2*p+1;
                }
                else
                {
                    break;
                }
        }
        a[p]=item;
    }
}

void heapsort(int n, int a[])
{
    heapify(n,a);
    for(int i=(n-1);i>0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(i,a);
    }
}

int main() {
      int a[15000],n, i,j,ch, temp;
      clock_t start,end;

       while(1)
       {
         printf("\n1:For manual entry of N value and array elements");
         printf("\n2:To display time taken for sorting number of elements N in the range 500 to 14500");
         printf("\n3:To exit");
         printf("\nEnter your choice:");
         scanf("%d", &ch);
         switch(ch)
         {
           case 1:  printf("\nEnter the number of elements: ");
                scanf("%d",&n);
                printf("\nEnter array elements: ");
                for(i=0;i<n;i++)
                 {
                  scanf("%d",&a[i]);
                 }
                start=clock();
                heapsort(n,a);
                end=clock();
                printf("\nSorted array is: ");
                for(i=0;i<n;i++)
                printf("%d\t",a[i]);
                printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
                break;
           case 2:
               n=500;
               while(n<=14500) {
                   for(i=0;i<n;i++)
                    {
                        a[i]=n-i;
                    }
                   start=clock();
                   heapsort(n,a);
                   for(j=0;j<500000;j++){ temp=38/600;}
                   end=clock();
                   printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
                         n=n+1000;
              }
              break;
            case 3: exit(0);
       }
       getchar();
        }
}
