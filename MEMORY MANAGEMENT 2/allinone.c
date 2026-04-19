// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int search(int key,int frame[],int f)
{
    for(int i=0;i<f;i++)
    {
        if(key == frame[i])
        {
            return i;
        }
    }
    return -1;
}

void fifo(int n,int f,int page[],int frame[])
{
    int index = 0;
    int fault = 0;
    for(int i=0;i<n;i++)
    {
        if(search(page[i],frame,f) == -1)
        {
            frame[index] = page[i];
            index = (index+1)%f;
            fault++;
        }
        
        printf("\nPage No : %d \n",page[i]);
        for(int i=0;i<f;i++)
        {
            printf("%d ",frame[i]);
        }
        printf("\n");
    }
    printf("Faults : %d",fault);
}

void lru(int n,int f,int page[],int frame[])
{
    int time[f];
    for(int i=0;i<f;i++)
    {
        time[i] = 0;
    }
    int counter = 0;
    int fault = 0;
    
    for(int i=0;i<n;i++)
    {
        int pos = search(page[i],frame,f);
        
        if(pos != -1)
        {
            time[pos] = ++counter;
        }
        else
        {
            fault++;
            int empty_pos = -1;
            for(int i=0;i<f;i++)
            {
                if(frame[i] == -1)
                {
                    empty_pos = i;
                    break;
                }
            }
            
            if(empty_pos != -1)
            {
                frame[empty_pos] = page[i];
                time[empty_pos] = ++counter;
            }
            else
            {
                int lru = 0;
                for(int i=1;i<f;i++)
                {
                    if(time[i]<time[lru])
                    {
                        lru = i;
                    }
                }
                
                frame[lru] = page[i];
                time[lru] = ++counter;
            }
        }
        printf("Page No %d \n",page[i]);
        for(int i=0;i<f;i++)
        {
            printf("%d ",frame[i]);
        }
        printf("\n");
    }
    printf("faults : %d",fault);
}

void lfu(int n,int f,int page[],int frame[])
{
    int freq[f];
    int time[f];
    int fault = 0;
    int counter = 0;
    
    for(int i=0;i<f;i++)
    {
        freq[i] = 0;
        time[i] = 0;
    }
    
    for(int i=0;i<n;i++)
    {
        int pos = search(page[i],frame,f);
        
        if(pos != -1)
        {
            freq[pos]++;
            time[pos] = ++counter;
        }
        else
        {
            fault++;
            int empty_pos = -1;
            
            for(int i=0;i<f;i++)
            {
                if(frame[i]==-1)
                {
                    empty_pos = i;
                    break;
                }
            }
            
            if(empty_pos != -1)
            {
                frame[empty_pos] = page[i];
                freq[empty_pos] = 1;
                time[empty_pos] = ++counter;
            }
            else
            {
                int lfu = 0;
                for(int i=1;i<f;i++)
                {
                    if(freq[i]<freq[lfu] || (freq[i]==freq[lfu] && time[i]<time[lfu]))
                    {
                        lfu = i;
                    }
                }
                
                frame[lfu] = page[i];
                time[lfu] = ++counter;
                freq[lfu] = 1;
            }
        }
        printf("Page No : %d\n",page[i]);
        for(int i=0;i<f;i++)
        {
            printf("%d ",frame[i]);
        }
        printf("\n");
    }
    printf("Total Faults : %d",fault);
}

void mfu(int n,int f,int page[],int frame[])
{
    int freq[f];
    int time[f];
    int fault = 0;
    int counter = 0;
    
    for(int i=0;i<f;i++)
    {
        freq[i] = 0;
        time[i] = 0;
    }
    
    for(int i=0;i<n;i++)
    {
        int pos = search(page[i],frame,f);
        
        if(pos != -1)
        {
            freq[pos]++;
            time[pos] = ++counter;
        }
        else
        {
            fault++;
            int empty_pos = -1;
            
            for(int i=0;i<f;i++)
            {
                if(frame[i]==-1)
                {
                    empty_pos = i;
                    break;
                }
            }
            
            if(empty_pos != -1)
            {
                frame[empty_pos] = page[i];
                freq[empty_pos] = 1;
                time[empty_pos] = ++counter;
            }
            else
            {
                int mfu = 0;
                for(int i=1;i<f;i++)
                {
                    if(freq[i]>freq[mfu] || (freq[i]==freq[mfu] && time[i]<time[mfu]))
                    {
                        mfu = i;
                    }
                }
                
                frame[mfu] = page[i];
                time[mfu] = ++counter;
                freq[mfu] = 1;
            }
        }
        printf("Page No : %d\n",page[i]);
        for(int i=0;i<f;i++)
        {
            printf("%d ",frame[i]);
        }
        printf("\n");
    }
    printf("Total Faults : %d",fault);
}

int main() {
    int n,f;
    printf("enter number of pages : ");
    scanf("%d",&n);
    
    int page[n];
    printf("enter pages : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&page[i]);
    }
    
    printf("enter no frames : ");
    scanf("%d",&f);
    
    int frame[f];
    
    for(int i=0;i<f;i++)
    {
        frame[i] = -1;
    }
    
    mfu(n,f,page,frame);
}
