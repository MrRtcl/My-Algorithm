import requests
import random
import time


def main():
    url = "http://www.wjx.cn/handler/processjq.ashx?submittype=1&curID=19588912&t=1514045629369&starttime=2017%2F12%2F24%200%3A45%3A16&rn=2092117975.68293473"
    for i in range(5):
        payload = {'submitdata':'1$'+str(random.randint(1,2))+'}2$'+str(random.randint(1,3))+'}3$'+str(random.randint(1,3))+'}4$'+str(random.randint(1,4))+'}5$'+str(random.randint(1,4))+'}6$'+str(random.randint(1,3))+'}7$'+str(random.randint(1,3))+'}8$'+str(random.randint(1,4))+'}9$'+str(random.randint(1,4))+'}10$'+str(random.randint(1,4))+'}11$'+str(random.randint(1,3))+'}12$'+str(random.randint(1,3))+'}13$'+str(random.randint(1,4))+'}14$'+str(random.randint(1,2))}
        r = requests.post(url, data = payload)
        print r.content

if __name__ == '__main__':
    main()