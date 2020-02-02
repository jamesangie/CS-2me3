## @file StdntAllocTypes.py
#  @author James Zhang
#  @brief StdntAllocTypes
#  @date 08/02/2019

from SeqADT import *
import typing


## @brief A abstract data type that represents gender
class GenT:
    def male(self):
        return self
    def female(self):
        return self


## @brief A abstract data type that represents differert departments
class DeptT:
    ## @brief DeptT constructor
    #  @details create the list containing the different departments
    def __init__(self):
        self.l = [DeptT.civil, DeptT.chemical, DeptT.electrical, DeptT.mechanical, DeptT.software, DeptT.materials, DeptT.engphys]

        self.civil = 0
        self.chemical = 1
        self.electrical = 2
        self.mechanical = 3
        self.software = 4
        self.materials = 5
        self.engphys = 6


## @brief A abstract data type that represents student's info
class SInfoT:
    ## @brief SInfoT constructor
    #  @details Take t as the student, generate the student info
    #  @param t NamedTuple of student's info
    def __init__(self, t):
        max_gpa = 12.0
        min_gpa = 0.0
        self.t = t
        if self.t.gpa > max_gpa or self.t.gpa < min_gpa:
            raise IOError


## @brief A NamedTuple that stores student's info
class student(typing.NamedTuple):
    fname: str
    lname: str
    gender: GenT
    gpa: float
    choices: SeqADT
    freechoice: bool
