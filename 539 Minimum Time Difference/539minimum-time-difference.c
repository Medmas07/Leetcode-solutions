void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b); 
}

int findMinDifference(char** timePoints, int timePointsSize) {
   int*t=malloc(sizeof(int)*(timePointsSize+1));
    int m=0,h=0,z=0;
    for(int i=0;i<timePointsSize;i++)
    {
        z=sscanf(timePoints[i],"%d:%d",&h,&m);
        t[i]=h*60+m;
    }
    //printArray(t,timePointsSize);
    int min=0;
   /* for(int i=0;i<timePointsSize;i++)
    {
        min=t[i];
        for(int j=i+1;j<timePointsSize;j++)
        {
            if(t[j]<min)
            {
                min=t[j];
                t[j]=t[i];
                t[i]=min;
            }
        }
        
    }*/
    qsort(t, timePointsSize, sizeof(int), cmp);
    int v=timePointsSize;
    if(t[0]==0)
    {t[timePointsSize]=1440;
     v++;}
    //printArray(t,v);
    min=t[timePointsSize-1];
    for(int i=0;i<v-1;i++)
    {
        if(t[i+1]-t[i]<min)
        {
            min=t[i+1]-t[i];
        }
    }
    if(1440+t[0]-t[v-1]<min && t[0]!=0)
        min=1440+t[0]-t[v-1];
        
    return min;
    
}