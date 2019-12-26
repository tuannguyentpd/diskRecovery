# export LD_LIBRARY_PATH=.

import foo
a = foo.A(2)
print(a.get_i())
print (a.get_i.__doc__)