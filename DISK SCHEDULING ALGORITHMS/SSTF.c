/* Shortest Seek Time First Algo */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,head;
    
    printf("enter no of requests : ");
    scanf("%d",&n);
    
    int req[n];
    int vis[n];
    
    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
    }
    
    printf("\nenter the requests : ");
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
        int min = 999999999;
        int index = -1;
        
        for(int j=0;j<n;j++)
        {
            if(!vis[j])
            {
                int dist = abs(head-req[j]);
                
                if(dist<min)
                {
                    min = dist;
                    index = j;
                }
            }
        }
        
        total += min;
        printf("->%d",req[index]);
        head = req[index];
        vis[index] = 1;
    }
    
    printf("\nTotal Cost : %d",total);

    return 0;
}
