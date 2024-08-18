int nthUglyNumber(int n) {
   /* if(n==1)
        return 1;
    else{
    int i=1,m=0;
    while(n!=1)
    {i++;
     m=i;
    while((m%2==0 || m%3==0 || m%5==0)&&(m!=1))
    {
        if(m%2==0)
            m=m/2;
        if(m%3==0)
            m=m/3;
        if(m%5==0)
            m=m/5;
    }
     if(m==1)      
     n--;
        
            
    }
        return i;
    
}*/
    int uglynumbers[n];
    int i2=0,i3=0,i5=0;
    int nextMultipleOf2=2;
    int nextMultipleOf3=3;
    int nextMultipleOf5=5;
    uglynumbers[0]=1;
    int nextuglynumber=1;
    for(int i=1;i<n;i++)
    {
        /*nextuglynumber=(nextugly2 < nextugly3) ? 
            (nextugly2 < nextugly5 ? nextugly2 : nextugly5):
            (nextugly3 < nextugly5 ? nextugly3 : nextugly5);*/
        
        nextuglynumber = (nextMultipleOf2 < nextMultipleOf3) ? 
                          (nextMultipleOf2 < nextMultipleOf5 ? nextMultipleOf2 : nextMultipleOf5) : 
                          (nextMultipleOf3 < nextMultipleOf5 ? nextMultipleOf3 : nextMultipleOf5);
       
        uglynumbers[i]=nextuglynumber;
        
        if(nextuglynumber==nextMultipleOf2)
        {
            i2++;
            nextMultipleOf2=uglynumbers[i2]*2;
            
        }
           if(nextuglynumber==nextMultipleOf3)
        {
             i3++;
            nextMultipleOf3=uglynumbers[i3]*3;
           
        }
           if(nextuglynumber==nextMultipleOf5)
        {
            i5++;
            nextMultipleOf5=uglynumbers[i5]*5;
            
        }
    }
    return nextuglynumber;
}