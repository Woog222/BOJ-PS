# [Platinum V] 0과 1 - 8111 

[문제 링크](https://www.acmicpc.net/problem/8111) 

### 성능 요약

메모리: 2392 KB, 시간: 0 ms

### 분류

너비 우선 탐색(bfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 수학(math)

### 문제 설명

<p>Certain positive integers have their decimal representation consisting only of ones and zeros, and having at least one digit one, e.g. <code>101</code>. If a positive integer has not such a property, one can try to multiply it by some positive integer to find out whether the product has this property.</p>

<p>Write a program which:</p>

<ul>
	<li>reads from the standard input positive integers n not greater than 20,000,</li>
	<li>for each integer read computes a correct answer,</li>
	<li>writes the answer to the standard output.</li>
</ul>

<p>The answer is either a positive multiple of n whose decimal representation consists of at most 100 (a hundred) digits, only zeros or ones, or the word <code>BRAK</code> ("<em>absence</em>"), if there is no such multiple.</p>

### 입력 

 <p>The standard input contains in the first line a positive integer K < 1,000. In consecutive lines there is a sequence of K numbers in the range of [1...20,000], one number per line. The numbers in the standard input are written correctly, and your program need not verify that.</p>

### 출력 

 <p>Each line of the standard output, starting with the first, should contain:</p>

<ul>
	<li>either only one word <code>BRAK</code>,</li>
	<li>or exactly one positive integer being a multiple of a successive number given in the input; each multiple must be a number composed only of digits 0 and 1, and has to be written with no spaces between the digits.</li>
</ul>

<p>The answers are to be written in standard output in the same order as the corresponding numbers in standard input.</p>

