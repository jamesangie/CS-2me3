## @file SeqADT.py
#  @author James Zhang
#  @brief SeqADT
#  @date 08/02/2019


## @brief A  generic module that represents a sequence
class SeqADT:

    s = []
    i = 0

    ## @brief SeqADT constructor
    #  @details take l as the initial set, set i to 0
    #  @param l sequence of any type
    def __init__(self, l):
        self.s = l
        self.i = 0

    ## @brief start the sequence
    #  @details set i to 0
    def start(self):
        self.i = 0

    ## @brief pop the seq
    #  @details increment i and output s[i]
    def next(self):
        if not self.end():
            self.i += 1
            return self.s[self.i]
        else:
            raise StopIteration

    ## @brief check if reach the end
    #  @details comparing the len(s) and i, check if there is anything left
    def end(self):
        return self.i >= len(self.s)