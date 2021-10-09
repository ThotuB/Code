(defvar bob '(
    (temperature 100)
    (pressure (120 60))
    (pulse 72)
    (blood-type "A")
    (name "Bob")
))

(print
    (assoc 'temperature bob)
)

(print
    (assoc 'gender bob)
)
