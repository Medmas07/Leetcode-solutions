int compare(const void *a, const void *b) {
    char *num1 = *(char **)a;
    char *num2 = *(char **)b;

    // Create concatenated strings for comparison
    char *concat1 = malloc(strlen(num1) + strlen(num2) + 1);
    char *concat2 = malloc(strlen(num2) + strlen(num1) + 1);

    strcpy(concat1, num1);
    strcat(concat1, num2);
    
    strcpy(concat2, num2);
    strcat(concat2, num1);

    int result = strcmp(concat1, concat2);

    free(concat1); // Free the allocated memory
    free(concat2); // Free the allocated memory

    return result > 0 ? -1 : 1; // Sort in descending order
}


char* largestNumber(int* nums, int numsSize) {
   
    char**tch=malloc(sizeof(char*)*numsSize);
    char*b=malloc(12);
    char*b1=malloc(12);
    int n=0,l=0;
    /*int max=0;
    for(int i=0;i<numsSize;i++)
    {
        max=i;
        for(int j=i+1;j<numsSize;j++)
        {
            if(max<nums[j])
                max=j;
        }
        if(max!=i)
        {
            l=nums[i];
            nums[i]=nums[max];
            nums[max]=l;
        }
    }*/
    
   
    
    for(int i=0;i<numsSize;i++)
    {
        tch[i]=malloc(sizeof(char)*(12));
        sprintf(tch[i],"%d",nums[i]);
        l=strlen(tch[i]);
        n+=l;
    }
    char*chReturn=malloc(sizeof(char)*(n)+1);
    strcpy(chReturn,"");
     /*char* max=tch[0];
    for(int i=0;i<numsSize;i++)
    {
        max=tch[i];
        
        for(int j=i+1;j<numsSize;j++)
        {
            strcpy(b,tch[j]);
            strcpy(b1,max);
            if(strcmp(strcat(b,max),strcat(b1,tch[j]))>0)
                max=tch[j];
        }
        if(max!=tch[i] )
        {
            strcpy(b,tch[i]);
            strcpy(tch[i],max);
            strcpy(max,b);
        }
    }
    */
    qsort(tch, numsSize, sizeof(char*), compare);

    
   // printf("%p",chReturn);
    
    for(int i=0;i<numsSize;i++)
    {
        strcat(chReturn,tch[i]);
        free(tch[i]);
        chReturn[strlen(chReturn)]='\0';
    }
    free(tch);
    sscanf(chReturn,"%d",&l);
    if(l==0)
        return chReturn+strlen(chReturn)-1;
    return chReturn;
}