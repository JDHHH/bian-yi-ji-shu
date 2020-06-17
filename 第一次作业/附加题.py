import re
import time
length = 8

def recompile(p1):
    pattern = re.compile(p1)
    s = ''.join(pattern.findall(string))
    return s

def findAZ(string):
    p1 = '[A-Z]'
    s = recompile(p1)
    if(s and len(string)> length):
        return True
    else:
        print('大写字母！！！')
        return False

def findaz(string):
    p1 = '[a-z]'
    s = recompile(p1)
    if(s and len(string)>length):
        return True
    else:
        print('小写字母！！！')
        return False
    
def find09(string):
    p1 = '[0-9]'
    s = recompile(p1)
    if(s and len(string)>length):
        return True
    else:
        print('数字！！！')
        return False

def findsymbol(string):
    p1 = '[’!"#$%&\'()*+,-./:;<=>?@，。?★、…【】《》？“”‘’！[\\]^_`{|}~\s]'
    s = recompile(p1)
    if(s and len(string)>length):
        return True
    else:
        print('特殊字符！！！')
        return False

def cmpstring(alist,string):
    num = 3
    for i in string:
        for s in alist:
            if(i in s):
                num -=1
                if(num):
                    pass
                else:
                    print('与'+s+'有三个或以上的重复字符！！！')
                    return False
    return True
alist = []
alist.append('by99YL17!')
while True:
    print('请输入您的密码：')
    string = input()
    if(len(string)<8):
        print('太短了！！！')
    else:
        s1 = findAZ(string)
        s2 = findaz(string)
        s3 = find09(string)
        s4 = findsymbol(string)
        s5 = cmpstring(alist,string)
        if(s1 and s2 and s3 and s4 and s5):
            alist.append(string)
            print('OK')
        else:
            print('not OK')
            continue
        time.sleep(5)
        