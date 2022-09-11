int main(){
    int a[] = {1, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a)/4;
    int search;

    printf("Given Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Enter the element you are looking for: ");
    scanf("%i", &search);
    binary_search(a, n, search);
}

int binary_search(int array[], int n, int search){
    int beg, end, mid;
    beg = 0;
    end = n;

    for(int i=0; i<n; i++){
        mid = (beg + end)/2;

        if (array[mid] == search){
            printf("Element found at location: %i", mid+1);
            return 0;
        }
        else if (array[mid]>search){
            end = mid - 1;
        }
        else if (array[mid]<search){
            beg = mid + 1;
        }
    }
    printf("Element not found!");
}
