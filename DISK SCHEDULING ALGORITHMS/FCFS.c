/* First Come First Serve Algo */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,head;
    
    printf("enter no of requests : ");
    scanf("%d",&n);
    
    int req[n];
    
    printf("\nenter requests : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    
    printf("\nenter head (starting pos) : ");
    scanf("%d",&head);
    
    int total = 0;
    
    printf("\nhead-%d",head);
    
    for(int i=0;i<n;i++)
    {
        total += abs(head-req[i]);
        printf("->%d",req[i]);
        head = req[i];
    }
    
    printf("\nTotal Cost : %d",total);

    return 0;
}
