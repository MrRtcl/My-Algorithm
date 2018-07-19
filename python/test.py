import requests
from base64 import b64decode

url = 'http://ctf5.shiyanbar.com/basic/catch/'

r = requests.get(url)
post = {'pass_key':r.headers['content-row']}

r = requests.post(url,data=post)

print r.content