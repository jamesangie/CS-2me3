## @file CalcModule.py
#  @title Calcmodule.py
#  @author James Zhang
#  @date 1/16/2018

## @brief Read a list of students and output the sorted students in descending order
#  @detail based on the quicksort learned from algorithm course. modified for this case
def sort(S):
    if len(S) <= 1:
        return S
    ## a for less gpa and b for greater gpa so that we can sort the student in descending order
    a = []
    b = []
    pivot = S.pop()
    for item in S:
        if item['gpa'] < pivot['gpa']:
            a.append(item)
        else:
            b.append(item)
    S.append(pivot)

    return sort(b) + [pivot] + sort(a)


## @brief Read a list of students and calculate the average based on their gender
def average(L,g):
    ## check if the input is valid
    if not(g in ['male', 'female']):
        raise IOError
    s = 0.0
    c = 0
    for i in L:
        if i['gender'] == g:
            s += i['gpa']
            c += 1
    return s/c

## @brief the algorithm that allocate the students to the correspoding major base on their gpa, choices and having free choices or not
#  @param S from readStdnts, F from readFreeChoice, C from readDeptCapacity
def allocate(S, F, C):
    ## sort the students in the beginning so that we always arrange the student with higher gpa first
    SS = sort(S)
    free = []
    notfree = []

    result = {'civil':[], 'chemical':[], 'electrical':[], 'mechanical':[], 'software':[], 'materials':[], 'engphys':[]}
    ## check if the student have free choices or not
    for i in SS:
        ## assmuing only the students with a gpa that is higher or equyal to 4.0 get allocate
        if i['gpa'] >= 4.0:
            if i['macid'] in F:
                free += [i]
            else:
                notfree += [i]
    ## arrange free choices first
    for j in free:
        ## if there is no more space, go to the next choice
        if C[j['choices'][0]] > len(result[j['choices'][0]]):
            result[j['choices'][0]] += [j]
        else:
            if C[j['choices'][1]] > len(result[j['choices'][1]]):
                result[j['choices'][1]] += [j]
            else:
                if C[j['choices'][2]] > len(result[j['choices'][2]]):
                    result[j['choices'][2]] += [j]
    ## using same idea as for free choices, arrange notfree students.
    for k in notfree:
        if C[k['choices'][0]] > len(result[k['choices'][0]]):
            result[k['choices'][0]] += [k]
        else:
            if C[k['choices'][1]] > len(result[k['choices'][1]]):
                result[k['choices'][1]] += [k]
            else:
                if C[k['choices'][2]] > len(result[k['choices'][2]]):
                    result[k['choices'][2]] += [k]

    return result






