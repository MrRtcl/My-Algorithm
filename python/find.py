#-*-coding=utf-8-*-
from time import sleep
import requests
import re


def getsource():
    url = 'http://oa.sdshiyan.cn/SPOSFiles/Import/1.ashx'
    f = open("list.txt", "r")
    lists = f.readlines()
    f.close()
    for data in lists:
        data = data.replace('\n', '')
        post = {
            'z': 'B',
            'z0': 'UTF-8',
            'z1': 'D:\\SPOS\\SPOSFiles\\UploadFiles\\TeacherFiles\\'+data+'\\InfoFiles\\2018\\7\\'
       }
        r = requests.post(url, data=post)
        if '小题分' in r.content:
            print '\a\a\a\aI Find It:'+data
            print r.content.decode('UTF-8')
            raw_input()
        else:
            print data

def getid():
    url = 'http://oa.sdshiyan.cn/SPOSFiles/Import/1.ashx'
    post = {
        'z':'B',
        'z0':'UTF-8',
        'z1':'D:\\SPOS\\SPOSFiles\\UploadFiles\\TeacherFiles\\'
    }
    r = requests.post(url, data=post)
    lists = re.findall('-\n(.*?)/',r.content,re.S)
    f = open('list.txt','w')
    for i in lists:
        f.write(i+'\n')
    f.close
    
def main():
    getid();
    getsource();

if __name__ == '__main__':
    main()
