int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int s=0,max=accounts[0][0];
    for(int i=0;i<accountsSize;i++)
    {
        for(int j=0;j<*accountsColSize;j++)
        {//printf("%d\n",s);
         s+=accounts[i][j];}
        if(s>max)
            max=s;
        s=0;
    }
    return max;
}