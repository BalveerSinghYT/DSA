#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p, a, x = 1, temp = 0, i, data;
    char choice;
    printf("Enter size of array: ");
    scanf("%d", &a);

    p = (int *)malloc(a * sizeof(int));

    for (i = 0; i < a; i++)
    {
        printf("Enter element in array: ");
        scanf("%d", &p[i]);
    }

    while (x == 1)
    {
        printf("--------------------------------------------\n");
        printf("1.print array\n");
        printf("2.linear search\n");
        printf("3.exit\n");
        printf("enter your choice from above:\t");
        scanf("\n%c", &choice);
        
        switch (choice)
        {
            case '1':
                printf("Array is: ");
                for (i = 0; i < a; i++)
                {
                    printf("%d\t", p[i]);
                }
                printf("\n");
                break;

            case '2':
                printf("Enter element you want to search: ");
                scanf("%d", &data);
                for (i = 0; i < a; i++)
                {
                    if (*(p + i) == data)
                    {
                        temp = temp + 1;
                        break;
                    }
                }
                if (temp == 1)
                {
                    printf("Wow!, %d Found at %d index\n", data, i);
                    temp = 0;
                }
                else
                    printf("Uff... %d not found\n", data);
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