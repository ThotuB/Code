(defvar lst1 '(1 2 3 4 5))

; 1 atom
(print (cons 0 lst1))
(print (cons '(0) lst1))

; 2 atoms
(print (cons '(-1 0) lst1))
(print (cons -1 (cons 0 lst1)))
