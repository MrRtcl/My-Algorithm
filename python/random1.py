#-*-coding:utf-8-*-
#注意！！！！只能生成整数随机数


import random
nums = [274,572,74,44,14,15,7]  #每个段的人数
f = open("work.txt","a")        #work.txt是文件名,可以自己改
for num in nums:
    print num
    range1 = input("range1:")       #输入范围1
    range2 = input("range2:")       #输入范围2
    i = 1
    while(i <= num):  
        i += 1
        income = random.randint(range1,range2)
        f.write(str(income)+'\n')
f.close()
