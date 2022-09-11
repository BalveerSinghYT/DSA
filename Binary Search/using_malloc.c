#include <stdio.h>
#include <stdlib.h>

int Binary(int data[], int item, int n){
    int mid, lb, ub;
    lb = 0; ub = n-1;
    mid = (lb + ub)/2;

    while (lb != ub && data[mid] != item){
        if (item < data[mid]){
            ub = mid - 1;
        }
        else if (item > data[mid]){
            lb = mid + 1;
        }

        mid = (int)(lb+ub)/2;
    }
    if (data[mid] == item){
        printf("Element found at location: %i\n", mid+1);
        return 0;
    }
    else{
        printf("Element not found!\n");
        return 0;
    }
}

int main(void)
{
    int *p, n, x = 1, temp = 0, i, item, loc, lb, ub;
    char choice;
    printf("Enter size of array: ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Enter element in array: ");
        scanf("%d", &p[i]);
    }

    while (x == 1)
    {
        printf("--------------------------------------------\n");
        printf("1. print array\n");
        printf("2. binary search\n");
        printf("3. exit\n");
        printf("enter your choice from above:\t");
        scanf("\n%c", &choice);

        switch (choice)
        {
            case '1':
                printf("Array is: ");
                for (i = 0; i < n; i++)
                {
                    printf("%d\t", *(p + i));
                }
                printf("\n");
                break;

            case '2':
                printf("Enter element you want to search: ");
                scanf("%d", &item);
                Binary(p, item, n);
                break;

            case '3':
                x = x + 1;
                break;

            default :
                printf("invalid choice! \n");
                break;
        }
    }
    free(p);
    return 0;
}
