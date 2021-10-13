(defvar lst1 '(1 2 3 4 5))

(print (last lst1))
; equivalent to:
(print (list (car (reverse lst1))))


(defvar lst2 '((1 2) (3 4) (5 6)))
    
(print (last lst2))