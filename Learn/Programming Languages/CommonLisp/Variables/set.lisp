(defvar a nil)
(defvar b nil)
(defvar ab nil)

(setq 
    a 'alpha
    b 'beta
    ab (list a b)
)

(print ab)

(defvar c nil)
(defvar d nil)
(defvar cd nil)

(psetq 
    c 'gamma
    d 'delta
    cd (list c d)
)

(print cd)