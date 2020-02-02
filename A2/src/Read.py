## @file Read.py
#  @author James Zhang
#  @brief Read
#  @date 08/02/2019

from StdntAllocTypes import *
from DCapALst import *
from SALst import *
from SeqADT import *


def load_stdnt_data(s):
    with open(s, 'r') as infile:
        contents = infile.readlines()

    contents = [x.strip().split(',') for x in contents]
    SALst.init()
    for i in range(0, len(contents)):

        ok = contents[i]



def load_dcap_data(s):
    with open(s, 'r') as infile:
        contents = infile.readlines()

    contents = [x.strip().split(',') for x in contents]

    a = []
    b = []
    for i in range(0, len(contents)):
        ok = contents[i]
        a += [ok[0]]
        b += [int(ok[1])]

    print(a,b)
    DCapALst.init()
    for j in range(0, len(a)):
        DCapALst.add(DCapALst, a[j], b[j])


