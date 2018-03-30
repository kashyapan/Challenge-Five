def  checkStr(num , deno ) :

    try:
        
        if num[1] != deno[0]:
            return False

        resSingDig = float(num[0]) / float(deno[1])
        resWholeDig = float(num) / float(deno)

        return (resSingDig == resWholeDig)

    except:
        return False


for deno in range(10 , 99):
    for num in range(10 , 99):
        if checkStr(str(num) , str(deno) ) == True:
            print num , " / " ,deno