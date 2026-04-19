#include <stdio.h>
#include <stdlib.h>

int search(int key,int frames[],int m)
{
    for(int i=0;i<m;i++)
    {
        if(key==frames[i])
        {
            return i;
        }
    }
    return -1;
}

void fifo(int n,int m,int pages[],int frames[])
{
    
    int index = 0,faults =0;
    for(int i=0;i<n;i++)
    {
        if(search(pages[i],frames,m) == -1)
        {
            frames[index] = pages[i];
            index = (index+1)%m;
            faults++;
        }
        
        printf("\n Page %d",pages[i]);
        printf("\n");
        for(int i=0;i<m;i++)
        {
            printf("%d ",frames[i]);
        }
        printf("\n");
    }
    printf("Total page faults : %d",faults);
}

int main() {
    int n,m;
    
    printf("enter no of pages : ");
    scanf("%d",&n);
    
    int pages[n];
    
    printf("\nenter ref string : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    
    printf("enter number of frames : ");
    scanf("%d",&m);
    
    int frames[m];
    
    for(int i=0;i<m;i++)
    {
        frames[i] = -1;
    }
    
    fifo(n,m,pages,frames);

    return 0;
}
