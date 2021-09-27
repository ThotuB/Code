import sys, os

# add parent directory to path
sys.path += [os.path.abspath(sys.path[0] + '/..')] 
# add nested package to path
sys.path += [os.path.abspath(sys.path[0] + '/nested_package')] 
# add other package to path
sys.path += [os.path.abspath(sys.path[0] + '/../other_package')]

from file_up import function_up
from file_down import function_down
from file import function


if __name__ == '__main__':
    # for path in sys.path:
    #     print(path)

    function_up()
    function_down()
    function()