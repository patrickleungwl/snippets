## Test Results

With the compiler optimization level set to O1, the timing of the array copy
using a manual loop look horrible in comparison to a memcpy, as expected
by intuition.

timing manual copy of varying array sizes 1,000,000 times
copy 1 elements took 1139 microsecs
copy 10 elements took 7073 microsecs
copy 100 elements took 71348 microsecs
copy 1000 elements took 619556 microsecs
copy 10000 elements took 6713131 microsecs
copy 100000 elements took 65115221 microsecs
timing mem copy of varying array sizes 1,000,000 times
copy 1 elements took 4241 microsecs
copy 10 elements took 3399 microsecs
copy 100 elements took 3671 microsecs
copy 1000 elements took 21925 microsecs
copy 10000 elements took 207795 microsecs
copy 100000 elements took 4310560 microsecs

However, with the compiler optimization level set to O3, the timing of both
copy methods were equivalent.  This shows that the compiler **optimized away**
the manual copy loop into a straight forward memcpy.

timing manual copy of varying array sizes 1,000,000 times
copy 1 elements took 4206 microsecs
copy 10 elements took 4671 microsecs
copy 100 elements took 4749 microsecs
copy 1000 elements took 29730 microsecs
copy 10000 elements took 214441 microsecs
copy 100000 elements took 4052944 microsecs
timing mem copy of varying array sizes 1,000,000 times
copy 1 elements took 4064 microsecs
copy 10 elements took 3940 microsecs
copy 100 elements took 5032 microsecs
copy 1000 elements took 23138 microsecs
copy 10000 elements took 217735 microsecs
copy 100000 elements took 4192007 microsecs


