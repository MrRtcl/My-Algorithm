f = open('key.txt','r')

content = f.read()
print content
cc = ''
f.close()
for i in range(len(content)):
    if(i % 2 == 0):
        cc += chr(ord(content[i])+2)
    else:
        cc += chr(ord(content[i])-1)
cc = cc.encode('utf-8')
f = open('key1.txt','w')
f.write(cc)
f.close()