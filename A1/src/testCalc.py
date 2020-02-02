## @file testCalc.py
#  @title testCalc.py
#  @author James Zhang
#  @date 1/16/2018

from ReadAllocationData import *
from CalcModule import *

## @brief An easy function that calculate if two numbers are almost equal or not(look at equality with two decimal places).
def fine(a,b):
    if (abs(a-b)/a)<(1.0/100.0):
        return True
    return False

## test calculation of the average gpa for male
print(fine(average(readStdnts('student.txt'),'female'),5.16))

## test the allocate function
ans = {'civil': [{'macid': 'zhany111', 'fname': 'james', 'lname': 'zhang', 'gender': 'male', 'gpa': 8.0, 'choices': ['civil', 'electrical', 'materials']}], 'chemical': [], 'electrical': [{'macid': 'liy200', 'fname': 'iris', 'lname': 'li', 'gender': 'female', 'gpa': 10.0, 'choices': ['electrical', 'materials', 'chemical']}], 'mechanical': [], 'software': [{'macid': 'jiaoz666', 'fname': 'dump', 'lname': 'li', 'gender': 'female', 'gpa': 4.3, 'choices': ['software', 'engphys', 'chemical']}], 'materials': [{'macid': 'fnndp123', 'fname': 'tie', 'lname': 'dan', 'gender': 'male', 'gpa': 8.2, 'choices': ['electrical', 'materials', 'chemical']}, {'macid': 'ojbk123', 'fname': 'an', 'lname': 'li', 'gender': 'male', 'gpa': 6.5, 'choices': ['electrical', 'materials', 'chemical']}], 'engphys': []}

## only test allocate function since it includes sort() and all the functions from ReadAllocatetionData.py
print(allocate(readStdnts('student.txt'),readFreeChoice('free.txt'),readDeptCapacity('dept.txt'))==ans)
