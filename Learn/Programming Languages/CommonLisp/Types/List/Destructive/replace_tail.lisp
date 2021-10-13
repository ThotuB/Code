(defvar abc '(a b c))
(defvar xyz '(x y z))

(print abc)
(print xyz)

(rplacd abc xyz)

(print abc)
(print xyz)