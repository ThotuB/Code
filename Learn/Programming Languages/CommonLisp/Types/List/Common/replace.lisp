(defvar lst1 '(1 2 3 4 5))

(print (subst 0 3 lst1))


(defvar lst2 '((1 2) (3 4) (5 6)))

(print (subst 0 3 lst2))
(print (subst '(0 0) '(3 4) lst2))