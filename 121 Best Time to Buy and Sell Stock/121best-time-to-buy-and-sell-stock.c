int maxProfit(int* prices, int pricesSize) {

    int gainmax=0;
    /*for(int i=0;i<pricesSize;i++)
    {
        for(int j=i+1;j<pricesSize;j++)
        {
            if((prices[j]-prices[i])>gainmax)
                gainmax=prices[j]-prices[i];
        }
    }*/
    int buy=prices[0];
    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]<buy)
            buy=prices[i];
        else if(prices[i]-buy>gainmax)
            gainmax=prices[i]-buy;
    }
    return gainmax;
}