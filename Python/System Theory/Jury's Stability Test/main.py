import numpy as np
import string as str

def jury_stability_test(coords):
    def check():
        for c in coords:
            print(c, end='')
            if c > 0 :
                print(" > 0")
            else:
                print(" < 0")
                return False
        return True
    
    next = check()
    if next:
        n = len(coords) - 1
        table = [ coords, 
                  coords[::-1] ]
        
        def next_coord(k, row):
            offset = (row) // 2 - 1
            mat = np.matrix( [ [ table[row-2][0], table[row-2][n-offset-k] ], 
                               [ table[row-1][0], table[row-1][n-offset-k] ] ])
            print( "{}{} = {}".format( str.ascii_lowercase[offset], k, np.matrix(mat) ) )

            return np.linalg.det(mat)

        def print_jury():
            print("Row\t|", end='\t')
            for c in range(n+1):
                print( "z{}".format( c ), end='\t' )
            print()

            print("--------|", end='')
            for i in range( n+1 ):
                print( "---------", end='' )
            print()

            for row in range( len( table ) ):
                print( "{}\t|".format( row + 1 ), end='\t' )
                for col in range( len( table[row] ) ):
                    print( "{} ".format( table[row][col] ), end='\t' )
                print()
        
        for i in range(1, n-1) :
            temp = []
            for j in range(n-i+1):
                temp += [next_coord(j, 2*i)]
            table.append( temp )
            table.append( temp[::-1] )

        print_jury()



delta_z = [0.5, 4, 3, 1]
jury_stability_test(delta_z)