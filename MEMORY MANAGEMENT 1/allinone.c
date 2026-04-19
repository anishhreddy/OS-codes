#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int hole[MAX];
int process[MAX];
int n,m;

void firstfit();
void bestfit();
void worstfit();

int main() { 
    printf("enter number of holes"); 
    scanf("%d",&n); 
    
    printf("enter size of holes"); 
    for(int i=0;i<n;i++)
    { 
        scanf("%d",&hole[i]); 
    } 
    printf("enter number of processes"); 
    scanf("%d",&m); 
    printf("enter size of processes"); 
    for(int i=0;i<m;i++) 
    { 
        scanf("%d",&process[i]); 
    } 
    bestfit(); 
    return 0; 
    
}

void firstfit(){
    int h[MAX];
    int ans[MAX];
    
    for(int i=0;i<n;i++)
    {
        h[i] = hole[i];
    }
    
    for(int i=0;i<m;i++) ans[i] = -1;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(process[i] <= h[j])
            {
                h[j] -= process[i];
                ans[i] = j;
                break;
            }
        }
    }
    
    for(int i=0;i<m;i++)
    {
        if(ans[i]!=-1)
        {
            printf("\nP%d - (K%d) - block %d",i,process[i],ans[i]);
        }
        else
        {
            printf("\nP%d - (K%d) - NOT ALLOCATED",i,process[i]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf("\nh%d - %d",i,h[i]);
    }
}

void bestfit() {
    int h[MAX];
    int ans[MAX];
    
    for(int i=0;i<n;i++)
    {
        h[i] = hole[i];
    }
    
    for(int i=0;i<m;i++) ans[i] = -1;
    
    for(int i=0;i<m;i++)
    {
        int valuem = 999999999;
        for(int j = 0;j<n;j++)
        {
            if(process[i]<=h[j])
            {
                int d = h[j] - process[i];
                if(d<valuem)
                {
                    valuem = d;
                    ans[i] = j;
                }
            }
        }
        
        if(ans[i]!=-1)
        {
            h[ans[i]] -= process[i];
        }
    }
    
    for(int i=0;i<m;i++)
    {
        if(ans[i]!=-1)
        {
            printf("\nP%d - (%dK) - block%d",i,process[i],ans[i]);
        }
        else
        {
            printf("\nP%d - (%dK) - NOT ALLOCATED",i,process[i]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf("\nh%d - %d",i,h[i]);
    }
}

void worstfit() {
    int h[MAX];
    int ans[MAX];
    
    for(int i=0;i<n;i++)
    {
        h[i] = hole[i];
    }
    
    for(int i=0;i<m;i++) ans[i] = -1;
    
    for(int i=0;i<m;i++)
    {
        int valuem = -1;
        for(int j = 0;j<n;j++)
        {
            if(process[i]<=h[j])
            {
                int d = h[j] - process[i];
                if(d>valuem)
                {
                    valuem = d;
                    ans[i] = j;
                }
            }
        }
        
        if(ans[i]!=-1)
        {
            h[ans[i]] -= process[i];
        }
    }
    
    for(int i=0;i<m;i++)
    {
        if(ans[i]!=-1)
        {
            printf("\nP%d - (%dK) - block%d",i,process[i],ans[i]);
        }
        else
        {
            printf("\nP%d - (%dK) - NOT ALLOCATED",i,process[i]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf("\nh%d - %d",i,h[i]);
    }
}
