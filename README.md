*This project has been created as part of the 42 curriculum by mabenois*

# Description
The Push swap project is a simple yet highly structured algorithmic challenge
in wich you have to find the shortest sequence of Push_swap instructions 
needed to sort the given integers.
for this, you have the following instructions:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.


I used the LSD (Least Significant Digit) Radix sort, so it sort the numbers
by seing them as bits instead of base 10 numbers.

# Instructions
run `make`, then ./push_swap STACK_A

STACK_A needs to be a list of integers ex: "5 7 2 -4"

# Resources
the github repo of this project:
https://github.com/ManechBV/push_swap

i watched this videos and it helped me a lot to understand Radix:
https://youtu.be/mVRHvZF8xtg

No ai was used.
