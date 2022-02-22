#include<stdio.h>
int main()
{
   int n,a[20],x,i,low,high,middle,flag=0 ;

   printf("\n Size of an array:");
   scanf("%d",&n);

   printf("\n Enter array elements in sorted order:");
   for (i=0;i<n;i++)
   { 
       scanf("%d",&a[i]);
       if (i>0 && a[i]<a[i-1])
       {
           printf("\n data must be in ascending order");
           return; 
       } 
   }

   printf("\n Enter number to be searched:");
   scanf("%d",&x);
  
   low= 0;
   high= n-1;
   flag= 0;

   while (low<=high)
   {
         middle=(low + high)/2;
         if (a[middle]==x)
         {
            flag= 1;
            break;	
         }
        else if (x < a[middle] )
                high = middle-1;
             else 
                low = middle+1;
   }

   if (flag=1)
      printf("\n %d is found at %d",x,middle+1);
   else
     printf("\n %d not found",x);
}

/*OUTPUT
 EXAMPLES
 Size of an array:4

 Enter array elements in sorted order:11 5 12 13

 data must be in ascending order
 Size of an array:4

 Enter array elements in sorted order:11 12 13 14

 Enter number to be searched:12

 12 is found at 2
 Size of an array:4

 Enter array elements in sorted order:11 13 14 15

 Enter number to be searched:12

 12 is found at 1
*/


 
