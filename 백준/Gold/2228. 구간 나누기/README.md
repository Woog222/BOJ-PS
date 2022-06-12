# [Gold IV] 구간 나누기 - 2228 

[문제 링크](https://www.acmicpc.net/problem/2228) 

 
 dp initial value problem :

initial value :  INF (unconditionally less than any value), we are lookin for max answer, so its reasonable

after we passed that dp element, we need to modify the value to identify we already checked this status, for memoization. its somewhat tricky in this problem. usually, with initial value -1, we set it to integer greater or equal than zero. but it's not possible.

two way for circumventing this:
1) use boolean check arr, c[][], for checking we have seted the value in dp[][]. it needs more memory space, but very simple and intuitive, concise, not complicated.
2) set another value, that is differentiated with the initial value and valid value. in this case, -4000000. it is differentiated with the initial value INF, and due to the condition in problem, actual caculated value cant reach -4000000. but it needs more care, strict precaculation for preventing fatal logical error. may not be recommended in such a complicated case. 

