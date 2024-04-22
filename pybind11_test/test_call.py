import sys
sys.path.insert(0, './cmake-build-debug')
import api_1
import api_2

A = [1.,2.,3.,4.]
B = api_1.modify(A)
print(B)

print("###################")
C = [[1,2,3,4],[5,6]]
D = api_2.modify(C)
print(D)
