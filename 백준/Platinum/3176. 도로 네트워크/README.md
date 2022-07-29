# [Platinum IV] 도로 네트워크 - 3176 

[문제 링크](https://www.acmicpc.net/problem/3176) 

### 성능 요약

메모리: 28508 KB, 시간: 224 ms

### 분류

자료 구조(data_structures), 최소 공통 조상(lca), 희소 배열(sparse_table), 트리(trees)

### 문제 설명

<p>The traffic network in a country consists of N cities (labeled with integers from 1 to N) and N-1 roads connecting the cities. There is a unique path between each pair of different cities, and we know the exact length of each road. </p>

<p>Write a program that will, for each of the K given pairs of cities, find the length of the shortest and the length of the longest road on the path between the two cities. </p>

### 입력 

 <p>The first line of input contains an integer N, 2 ≤ N ≤ 100 000. </p>

<p>Each of the following N-1 lines contains three integers A, B and C meaning that there is a road of length C between city A and city B. The length of each road will be a positive integer less than or equal to 1 000 000. </p>

<p>The next line contains an integer K, 1 ≤ K ≤ 100 000. </p>

<p>Each of the following K lines contains two different integers D and E – the labels of the two cities constituting one query. </p>

### 출력 

 <p>Each of the K lines of output should contain two integers – the lengths from the task description for the corresponding pair of the cities. </p>

