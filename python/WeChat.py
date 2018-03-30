#-*-coding:utf-8-*-
import itchat
itchat.auto_login(hotReload=True)
itchat.dump_login_status()
friends = itchat.get_friends(update=True)[0:]
female = male = others= 0
for friend in friends:
    sex = friend["Sex"]
    if sex == 1:
        male += 1
    elif sex == 2:
        female += 1
    else:
        others += 1
print "male:"+str(male)
print "female:"+str(female)
print "others:"+str(others)
