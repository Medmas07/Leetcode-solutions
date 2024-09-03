int addDigits(int num) {
    int s=0;
    while(num/10!=0)
    {
        while(num!=0)
        {
            s+=num%10;
            num=num/10;
        }
        num=s;
        s=0;
    }
    return num;
}
