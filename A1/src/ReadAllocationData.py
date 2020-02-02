## @file ReadAllocationData.py
#  @title ReadAllocationData.py
#  @author James Zhang
#  @date 1/16/2018


## @brief Read a file and output the list with student info in it
#  @param a file s with the format of the input file is:
#     first student: macID fname lname gender gpa choise1 choise2 choise3
#     second student: macID fname lname gender gpa choise1 choise2 choise3
#     ...
#     where all different terms are seprated by space and there is no space within any term
def readStdnts(s):

    f = open(s,"r")
    f1 = f.readlines()
    output = []
    for i in f1:
        word = i.split()
        d = {'macid':word[0], 'fname': word[1], 'lname': word[2], 'gender': word[3], 'gpa': float(word[4]), 'choices': [word[5], word[6], word[7]]}
        output += [d]
    f.close()
    return output

## @brief Read a file and output the list with students that have free choices
#  @param a file s with the format of the input file is:
#         first student: macID grade(high school)
#         second student: macID grade(high school)
#     also assume the students with 95+ high school grade are granted free chooces
def readFreeChoice(s):
    f = open(s, "r")
    f1 = f.readlines()
    output = []
    for i in f1:
        word = i.split()
        if float(word[1]) > 95:
            output += [word[0]]

    f.close()
    return output

## @brief Read a file and output the dictionary that shows the capacity of the depts
#  @param a file s with the format of the input file is:
#         first department: dept integer
#         second department: dept integer
def readDeptCapacity(s):

    f = open(s, "r")
    f1 = f.readlines()
    output = {}
    for i in f1:
        word = i.split()
        ## check whether the input is valid
        if word[0] in ['civil', 'chemical', 'electrical', 'mechanical', 'software', 'materials', 'engphys']:
            output[word[0]] = int(word[1])
        else:
            raise IOError

    f.close()
    return output