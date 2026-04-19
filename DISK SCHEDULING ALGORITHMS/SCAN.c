/* SCAN */

#include <stdio.h>
#include <stdlib.h>

void sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n,head;
    
    printf("enter no of requests : ");
    scanf("%d",&n);
    
    int req[n];
    
    printf("enter requests : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    
    printf("\nenter head (starting pos) ; ");
    scanf("%d",&head);
    
    sort(req,n);
    
    int index = 0;
    
    for(int i=0;i<n;i++)
    {
        if(req[i]>head)
        {
            index = i;
            break;
        }
    }
    
    int disk_size;
    printf("\nenter disk size : ");
    scanf("%d",&disk_size);
    
    int dir;
    printf("\nenter 1 for right and 0 for left : ");
    scanf("%d",&dir);
    
    int total = 0;
    
    printf("\nhead-%d",head);
    
    if(dir = 1)
    {
        for(int i=index;i<n;i++)
        {
            total += abs(head-req[i]);
            printf("->%d",req[i]);
            head = req[i];
        }
        
        if(head!= disk_size-1)
        {
            total += abs(head - (disk_size-1));
            printf("->%d",disk_size-1);
            head = disk_size-1;
        }
        
        for(int i=index-1;i>=0;i--)
        {
            total += (head-req[i]);
            printf("->%d",req[i]);
            head = req[i];
        }
    }
    else
    {
        for(int i=index-1;i>=0;i--)
        {
            total += abs(head - req[i]);
            printf("->%d",req[i]);
            head = req[i];
        }
        
        if(head!=0)
        {
            total += abs(head-0);
            printf("->%d",0);
            head = 0;
        }
        
        for(int i = index;i<n;i++)
        {
            total += abs(head-req[i]);
            printf("->%d",req[i]);
            head = req[i];
        }
    }
    
    printf("\nTotal Cost : %d",total);

    return 0;
}
