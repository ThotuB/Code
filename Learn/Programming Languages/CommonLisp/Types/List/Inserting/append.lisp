(defvar lst1 '(1 2 3 4 5))

; 0 atoms - nil
(print (append lst1 nil))
(print (append nil lst1))

; 1 atom
; (print (append lst1 6)) - doesn't work
(print (append lst1 '(6)))

; 2 atoms
(print (append lst1 '(6 7)))
(print (append lst1 '(6) '(7)))


(defvar lst2 '((1 2) (3 4) (5 6)))

(print (append lst2 '(7)))