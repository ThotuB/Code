(defvar lst '(1 2 3 4 5))

; 1 atom
(print (list lst 6))
(print (list lst '(6)))

; 2 atoms
(print (list lst 6 7))
(print (list lst '(6 7)))
(print (list lst '(6) '(7)))

; create a list
(print (list 1 2 3 4 5))