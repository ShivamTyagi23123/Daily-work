#include <stdio.h>  

int main()
{  
    int n, i;  
    int A1[100];  
    int max, min;  

    printf("Enter number: ");  
    scanf("%d", &n);  
    printf("Enter elements: ", n);  
    for(i = 0; i < n; i++)  
    {  
        scanf("%d", &A1[i]);  
    }  
    max = arr[0];  
    min = arr[0];  
    for(i = 1; i < n; i++)  
    {  
        if(arr[i] > max)  
        { 
            max = arr[i];  
        }  
        if(arr[i] < min)  
        {  
            min = arr[i];  
        }  
    }  
    printf("Maximum element is: %d\n", max);  
    printf("Minimum element is: %d\n", min);  
    return 0;  
}
