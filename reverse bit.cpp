uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int k = 32;

    while(k--){
        int x = n & 1;
        n = n >> 1;
        res = res | x;
        if(k != 0)
            res = res << 1;
    }
    return res;
}
