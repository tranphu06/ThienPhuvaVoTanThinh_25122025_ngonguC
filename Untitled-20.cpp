foo(int): 

movs r0, #1 

bx lr 

.LC0: 

.ascii "X is larger then X + 1\015\000" 

main: 

push {r3, lr} 

movw r0, #:lower16:.LC0 

movt r0, #:upper16:.LC0 

bl puts 

movs r0, #0 

pop {r3, pc}