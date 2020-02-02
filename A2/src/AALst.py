## @file SeqADT.py
#  @author James Zhang
#  @brief SeqADT
#  @date 08/02/2019

from StdntAllocTypes import *

## @brief A NamedTuple representing the different lists of
class AllocAssocListT(typing.NamedTuple):
    DeptT.civil: list
    DeptT.chemical: list
    DeptT.electrical: list
    DeptT.mechanical: list
    DeptT.software: list
    DeptT.materials: list
    DeptT.engphys: list

## @brief class that allocate student to different department
class AALst:
    ## @brief SeqADT constructor
    #  @details take l as the initial set, set i to 0
    #  @param l sequence of any type
    def init(self):
        self.s = AllocAssocListT([],[],[],[],[],[],[])

    ## @brief add student to department
    #  @details add the student to the list according to the input
    #  @param dep the department
    #  @param m the student's id
    def add_stdnt(self, dep, m):
        self.s[dep] += [m]

    ## @brief output the element from d
    #  @param d the key
    def lst_alloc(self, d):
        return self.s[d]

    ## @brief output the length of element of d
    #  @param d the key
    def num_alloc(self, d):
        return len(self.s[d])

