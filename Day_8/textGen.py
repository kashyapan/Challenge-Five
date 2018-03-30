import random


fo = open("in.txt" , "w")


t = 100000

fo.write( "{} \n".format(t) )

while t > 0:
    x = random.randint(-1000 , 15000)
    fo.write( "{} ".format(x) )
    t -= 1

fo.close() 
