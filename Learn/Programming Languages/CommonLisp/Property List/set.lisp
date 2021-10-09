(defvar bob '(
    (temperature 100)
    (pressure (120 60))
    (pulse 72)
    (blood-type "A")
    (name "Bob")
))

(setf (get 'bob 'pulse) 20)

(print bob)
