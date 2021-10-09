(defvar lst '(1 2 3))

(print (equal 1 1))
(print (equal 1 2))

(print (equal 'a 'a))
(print (equal 'a 'b))

(print (equal lst lst))
(print (equal lst '(1 2 3)))
(print (equal lst '(1 2 3 4)))

(terpri)

(print (eql lst lst))
(print (eql lst '(1 2 3)))
(print (eql lst '(1 2 3 4)))