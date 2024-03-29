# [Gold II] 수열 만들기 - 19565 

[문제 링크](https://www.acmicpc.net/problem/19565) 

### 성능 요약

메모리: 52684 KB, 시간: 428 ms

### 분류

구성적(constructive), 오일러 경로(eulerian_path), 그래프 이론(graphs)

### 문제 설명

<p>아래 성질을 만족하는 가장 긴 수열 $A$를 출력해 보자.</p>

<ul>
	<li>$A$의 첫 수와 마지막 수는 모두 1이고, 나머지 수는 1 이상 $N$ 이하인 정수이다.</li>
	<li>$1 \le i < j < |A|$일 때, $A_i \neq A_j$, $A_{i+1} \neq A_{j+1}$ 둘 중 하나는 반드시 성립한다.</li>
</ul>

### 입력 

 <p>정수 $N$이 주어진다. ($2 \le N \le 1000$)</p>

### 출력 

 <p>문제 지문에 쓰여 있는 조건을 만족하는 가장 긴 수열을 $A$라 하자.</p>

<p>첫째 줄에는 $A$의 길이를 출력한다.</p>

<p>둘째 줄에는 $A$의 원소들을 출력한다. 이러한 수열이 여러 개일 경우 아무거나 출력한다.</p>

<p>수열을 출력할 때는 한 줄에 모두 출력하되, 수 사이에 공백을 출력해야 한다.</p>

