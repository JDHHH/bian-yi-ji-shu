import re 
import docx
from tkinter import _flatten

AZ = '[A-Z]`*'
az = '[a-z]+'
symbol = '[+*(e]'

list1 = []
first = []
list2 = []
i = 0

def find(p1):
    pattern = re.compile(p1)
    s = (pattern.findall(paragraph.text))
    return s


# read file
fn = r'C:\Users\17408\Desktop\source.docx'
doc = docx.Document(fn)
for paragraph in doc.paragraphs:
    # print(paragraph.text)
    s = find(AZ)
    list1.append(s)
    list2.append(s)
    ss = find(az)
    first.append(ss)
    sss = find(symbol)
    first.append(sss)
    for i in iter(list1):
        # print('first[{0}] = first[{0}]'.format(i[0], i[1]))
        first = list(set(_flatten(first)))
        if first is not None:
            print('first[{0}] = {1}'.format(i[0], first))
        first = list(first)
        first.clear()
        list1.clear()


for i in iter(list2):
    if(len(i[0]) == 1):
        print("first[{0}] = first[{1}]".format(i[0], i[1]))
