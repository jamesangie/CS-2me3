## @file SALst.py
#  @author James Zhang
#  @brief SALst
#  @date 08/02/2019

from StdntAllocTypes import *
from AALst import *
from DCapALst import *

## @brief A NamedTuple representing the different lists of
class studentT(typing.NamedTuple):
    macid: str
    info: SInfoT

## @brief get the gpa of student
#  @detail
#  @param m macid of student
#  @param s set of students
def get_gpa(m, s):
    return True

## @The class that associate with students
class SALst():

    ## @brief SAlst constructor
    #  @details set s to empty dictionary
    def init():
        SALst.s = {}

    ## @brief add i to s[m]
    #  @param m the key
    #  @param i the element
    def add(self,m,i):
        if m in self.s.keys():
            raise KeyError
        else:
            self.s[m] = i

    ## @brief remove s[m]
    #  @param m the key
    def remove(self, m):
        if m in self.s.keys():
            del self.s[m]
        else:
            raise KeyError

    ## @brief check if m is an key in s
    #  @param m the key
    def elm(self, m):
        return m in self.s.keys()

    ## @brief output the element from m
    #  @param m the key
    def info(self, m):
        if m in self.s.keys():
            return self.s[m]
        else:
            raise KeyError

    ## @brief output the sorted students list by their gpa
    #  @param f function representing the student we want
    def sort(self, f):
        return True

    ## @brief output the average of student's gpa
    #  @param m the key
    def average(f):
        return 's'

    ## @brief output the element from m
    def allocate():
        return 's'