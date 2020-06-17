# _*_ coding: utf-8 _*_

import re
# create a new dict to store the data
mydict = {'for':1,':':17,'if':2,':=':18,'then':3,'<':20,'else':4,'<>':21,'while':5,'<=':22,'do':6,'>':23, '[a-zA-Z_][a-zA-Z_0-9]*':10,'>=':24,'[0-9][0-9]*':11,'=':25,'+':13,';':26,'-':	14,'(':	27,'*':	15,	')':28,'/':16,'#':0,'until':29,'int':30,'input':31,'output':32,}

array = {'for', 'if','then', 'else','while','do','until', 'int', 'output', 'input'}
symbol = {'/','*','-','+','(',')','<','>','#',':',';',' ','='}

# read file
file_object = open('source.txt')
try:
    all_the_text = file_object.read()
    print(all_the_text)
finally:
    file_object.close()
  
all_the_text1 = ' '

# 利用正则表达式查找（变量名称与数字）
def find(p1):
    pattern = re.compile(p1)
    s =''.join(pattern.findall(all_the_text1))
    return s

# 存放关键字、变量名称、数字
alist = []
# 存放运算符号
blist = []

def outputsymbol():
    string = ''.join(blist)
    string = ''.join(string.split())
    if(string):
        #print('@@@@@'+string+'@@@@@')
        all_the_text1 = string
        if(string in mydict):
            print( '(' + str(mydict[string])+',' + string + ')')
    blist.clear()

def outputarray():
    string = ''.join(alist)
    string = ''.join(string.split())
    if(string):
        # print('*****'+string+'*****')
        # 关键字
        if(string in mydict):
            print( '(' + str(mydict[string])+',' + string + ')')
            # 变量名称
        else:
            all_the_text1 = string
            print('allthetext1 = '+string)
            str1 = '[a-zA-Z_][a-zA-Z_0-9]*'
            string = find(str1)
            print(find(str1))
            if(string):
                print( '(' + str(10)+',' +'\'' +string +'\''+ ')')
            # 数字
            else:
                str1 = '[0-9][0-9]*'
                string = find(str1)
                if(string):
                    print( '(' + str(11)+',' +'\'' +string +'\''+ ')')      
    alist.clear()


for i in all_the_text:
    if(i == ' '):
        if(alist != None):
            outputarray()
        if(blist != None):
            outputsymbol()

    if(i not in symbol ):
        alist.append(i)
    else:
        string = ''.join(alist)
        string = ''.join(string.split())
        if(string):
           # print('*****'+string+'*****')
           # 关键字
            if(string in mydict):
                 print( '(' + str(mydict[string])+',' + string + ')')
            # 变量名称
            else:
                all_the_text1 = string
                str1 = '[a-zA-Z_][a-zA-Z_0-9]*'
                string = find(str1)
                if(string):
                    print( '(' + str(10)+',' +'\'' +string +'\''+ ')')
            # 数字
                else:
                    str1 = '[0-9][0-9]*'
                    string = find(str1)
                    if(string):
                        print( '(' + str(11)+',' +'\'' +string +'\''+ ')')      
        alist.clear()

    # 运算符号  
    if(i in symbol):
        blist.append(i)
    else:
        string=''.join(blist)
        string = ''.join(string.split())
        if(string):
            #print('@@@@@'+string+'@@@@@')
            all_the_text1 = string
            if(string in mydict):
                 print( '(' + str(mydict[string])+',' + string + ')')
        blist.clear()

if(alist != None):
    outputarray()
if(blist != None):
    outputsymbol()

