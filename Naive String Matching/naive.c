#include<stdio.h>
#include<conio.h>
int main()
{
    char arr[]="abcdbcdbcd";
    char ar[]="abcd";
    int n = sizeof(arr)-1;
    int m = sizeof(ar)-1;
int j=0,count=0;

    printf("length of pattern m=%d length of string n=%d\n", m, n);
    for(int i=0;i<n;i++)
    {
    printf("[%c]",arr[i]);
    }
    for(int i=0;i<=n-m;i++){
    
        printf("%d\n",i);
        printf("\n[%c] == [%c] ", ar[j], arr[i]);
        if(ar[j]==arr[i]){
            j++;
            count++;
            if(count==m)
            {
                printf("found \n found at %d",i-m+1);
                return 1;
            }
        }
        else {
            // printf("else");
            j = 0;

            if (count != 0){
                i--;
            }
            count = 0;
        }

    }
    return 0;
}
