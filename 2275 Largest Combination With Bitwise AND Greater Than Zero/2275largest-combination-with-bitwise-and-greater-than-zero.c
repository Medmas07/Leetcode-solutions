// int bitwise(int*t,int n)
// {
//     int u=t[0];
//     for(int i=1;i<n;i++)
//     {
//         u=u&t[i];
//     }
//     return u;
// }

int puiss(int a,int b)
{
    int k=1;
    for(int i=0;i<b;i++)
    {
        k*=a;
    }
    return k;
}
int max(int*t,int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(max<t[i])
            max=t[i];
    }
    return max;
}
int largestCombination(int* candidates, int candidatesSize) {
//     int b=bitwise(candidates,candidatesSize);
//     int long_comb=candidatesSize;
//     if(bitwise(candidates,candidatesSize)>0)
//     {
//         return candidatesSize;
//     }
//     else
//     {
//         for(int i=candidatesSize-1;i>=1;i--)
//     {
//         for(int j=0;j<candidatesSize-i;j++)
//         {
//             printf("i %d\n",i);
//            printf("bitwise%d\n",bitwise(candidates+j,i));
//             if(bitwise(candidates+j,i)>0)
//                 return i;
                
//         }
//     }
//         return 0;
//     }
    
    int* t=calloc(sizeof(int),25);
    int count=0;
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<candidatesSize;j++)
        {
            // if(i==0 && candidates[j]==1)
            // {
            //     t[i]++;
            // }
            // printf("candidates %d\n",candidates[j]);
            // printf("%d    %d\n",puiss(2,i),puiss(2,i+1));
            count=candidates[j]%puiss(2,i+1);
         if(puiss(2,i)<=count && count<puiss(2,i+1))
            {
                t[i]++;
            }
        }
        // printf("t[%d]=%d\n",i,t[i]);
    }
    return max(t,24);
}