class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if(numerator==0):
            return "0"
        num=abs(numerator)
        denom=abs(denominator)
        mod1 = num % denom
        a=format(num / denom, '.20f')
       # print(a)
        b=""
        if(numerator*denominator <0):
            b="-"
        b+=a[0:a.index(".")]
        #print(b)
        if(mod1==0):
            return b
        c=0
        b+="."

        mod=mod1
        w=""
        boolii=False
        v=[mod]
        while(mod!=0 ):
            mod*=10
            c=mod/denom
            w+=str(int(c))
            mod=mod%denom

            if(mod in v):
                boolii=True
                break
            v.append(mod)
        if boolii == False:
            return b + w
        else:
            repeat_index = v.index(mod)
            return b + w[:repeat_index] + "(" + w[repeat_index:] + ")"

        return b