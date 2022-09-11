#include <stdio.h>

int linear_search(int ITEM, int ARRAY[]){

}

int main(){
    int a[8] = { 10,20,30,40,50,60,90,110 }, n, search;
    
    printf("Array: ");
    for(int i=0; i<n; i++){
        printf("%i \n", a[i]);
    }
    printf("Enter the element you want to search:");
    scanf("%i", &search);

    for(int i=0; i<(sizeof(a)/4); i++){
        if (a[i] == search){
            printf("%d found at location %d", a, i);
            return 0;
        }
        printf("Element not found!");
    }
}