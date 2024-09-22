/*int cmp(void *b,void*a)
{
    char *num1 = *(char **)a;
    char *num2 = *(char **)b;

   

    int result = strcmp(num1, num2);


    return result > 0 ? -1 : 1; // Sort in descending order
}

int findKthNumber(int n, int k) {
    char**tch=malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
    {
        tch[i]=malloc(11);
        sprintf(tch[i],"%d",i+1);
    }
    qsort(tch,n,sizeof(char*),cmp);
    int res=0;
    sscanf(tch[k-1],"%d",&res);
    return res;
}*/
/*
void find(int*res,int*size,int last,int n,int k)
{
    unsigned int i,x;
    for(i=0;i<=9;i++)
    {
        if(last==0 && i==0)
            i=1;
        x=i+last;
        if(x>n)
            return;
        
        (*size)++;
        if(*size == k)
        {*res=x;return;}
        unsigned int y=x*10;
        if(y <= n)
        {
            find(res,size,x*10,n,k);
        }
    }
}

int findKthNumber(int n, int k) {
    int size=0,last=0,res=0;
    find(&res,&size,last,n,k);
    return res;
}
*/
int count(int n,long prefix1,long prefix2)
{
    int steps=0;
    while(prefix1<=n)
    {
        steps+=(((long)(n+1)<prefix2)?(n+1):(prefix2))-prefix1;
        prefix1*=10;
        prefix2*=10;
    }
    return steps;
}

int findKthNumber(int n,int k)
{
    int steps=0,curr=1;k--;
    while(k>0)
    {
        steps=count(n,curr,curr+1);
        if(steps <= k)
        {
            curr++;
            k-=steps;
            
        }
        else
        {
            curr *=10;
            k--;
        }
    }
    return curr;
}