bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if(n==0)
        return 1;
     if(flowerbedSize==1 && flowerbed[0]==0)
        return 1;
    if(n==flowerbedSize)
        return 0;
   
   /* int d=0,zc=0,pzc=0,k=0;
    for(int i=0;i<flowerbedSize;i++)
    {
       
        pzc=zc;
        k=i;
        while(i< flowerbedSize && flowerbed[i]==0)
        {
            zc++;
            i++;
        }
        printf("zc %d\n",zc);
        if(k==0)
        {
            d+=(zc/2);
            zc=0;
           printf("1\n");
        }
        else if(i< flowerbedSize && flowerbed[i]!=0){
               if(zc%2==1)
            {
                d+=(zc-1)/2;
            }
            else if(zc!=0)
            {
                d+=(zc/2)-1;
            }
            zc=0; 
        }
        else if(flowerbedSize <= i)
        {
            d+=zc/2;
        }
        
        printf("ff  %d\n",d);
        
    }
    
    return n<=d;*/
    int count=0;
    for(int i=0;i<flowerbedSize;i++)
    {
        if(flowerbed[i]==0 )
        {
         if ((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;  // Plante une fleur ici
                count++;  // On a planté une fleur
                if (count >= n) return true;  // Si on a planté suffisamment de fleurs, on retourne true
                i++;  // On saute l'élément suivant, car une fleur ne peut pas être placée côte à côte
            }
        }
    }

    return count >= n; 
}