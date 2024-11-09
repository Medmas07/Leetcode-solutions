long long minEnd(int n, int x) {
//     if(n==1)
//         return x;
//     long long j=x,i=0,c=x;
//     for(int i=0;i<n-1;i++){
    
//         do
//         {
//            // printf("j=%d\n",j);
//             j++;
//         }while((x&j)!=x);
//       // printf("c = %d\n",j);
//         c=j;

        
       
//     }
    long long j=x,i=0;
    for(int i=0;i<n-1;i++)
    {
        j++;
        j=(j|x);
    }
    return j;
}