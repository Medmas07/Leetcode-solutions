uint32_t reverseBits(uint32_t n) {
    uint32_t l=0;
    for(int i=0;i<32;i++)
    { 
        l=l<<1;
        l=l|(n&1);
        n=n>>1;
    }
    
    
    return l;
}