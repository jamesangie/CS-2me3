## @file DCapALst.py
#  @author James Zhang
#  @brief DCapALst
#  @date 08/02/2019

from StdntAllocTypes import *


## @brief A abstract data type for departments and their capacity
class DCapALst:

    s = {}

    ## @brief DCapALst constructor
    #  @details create DCapAlst by set s to empty dictionary
    def init():
        DCapALst.s = {}

    ## @brief add n to d
    #  @details add n to dictionary d
    #  @param d the key
    #  @param n the element
    def add(self, d, n):
        if d not in self.s.keys():
            self.s[d] = n
        else:
            raise KeyError

    ## @brief delete d
    #  @details delete everything about key d
    #  @param d the key
    def remove(self, d):
        del self.s[d]

    ## @brief output the elements of d
    #  @param d the key
    def elm(self, d):
        return d, self.s[d]

    ## @brief output the length of the element of d
    #  @param d the key
    def capacity(self, d):
        if d in self.s.keys():
            return len(self.s[d])
        else:
            raise KeyError
