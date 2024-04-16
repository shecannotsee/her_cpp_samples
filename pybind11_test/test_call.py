import sys
sys.path.insert(0, './cmake-build-debug')
import api_1

A = [1.,2.,3.,4.]

B = api_1.modify(A)

print(B)
