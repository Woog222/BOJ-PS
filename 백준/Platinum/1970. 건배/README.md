# [Platinum IV] 건배 - 1970 

[문제 링크](https://www.acmicpc.net/problem/1970) 

### 성능 요약

메모리: 6060 KB, 시간: 1396 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>The professors of the Bayerische Mathematiker Verein have their annual party in the local Biergarten. They are sitting at a round table each with his own pint of beer. As a ceremony each professor raises his pint and toasts one of the other guests in such a way that no arms cross. </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9c925ad5-5280-432f-8dad-9aee677ee769/-/preview/" style="width: 211px; height: 98px;"></p>

<p>Figure 2: Toasting across a table with eight persons:no arms crossing(left), arms crossing(right) </p>

<p>We know that the professors like to toast with someone that is drinking the same brand of beer, and we like to maximize the number of pairs of professors toasting with the same brand , again without crossing arms. Write an algorithm to do this, keeping in mind that every professor should take part in the toasting.</p>

### 입력 

 <p>The frist line of the input contains a single number: the number of test cases to follow. Each test case has the following format: </p>

<ul>
	<li>One line with an even number p, satisfying 2 ≤ p ≤ 1000: the number of participants </li>
	<li>One line with p integers (separated by single spaces) indicating the beer brands fro the consecutive professors( in clockwise order, starting at an arbitrary position). Each value is between 1 and 100 (boudaries included).</li>
</ul>

### 출력 

 <p>For every test case in the input, the output should contain a single number on a single line: the maximum number of non-intersecting toasts of the same beer brand for this test case.</p>

<p> </p>

