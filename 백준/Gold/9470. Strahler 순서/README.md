# [Gold III] Strahler 순서 - 9470 

[문제 링크](https://www.acmicpc.net/problem/9470) 

### 성능 요약

메모리: 2060 KB, 시간: 0 ms

### 분류

그래프 이론(graphs), 위상 정렬(topological_sorting)

### 문제 설명

<p>In geology, a river system can be represented as a directed graph. Each river segment is an edge;with the edge pointing the same way the water flows. Nodes are either the source of a river segment(for example, a lake or spring), where river segments merge or diverge, or the mouth of the river</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/strahler.png" style="height:299px; width:354px"></p>

<p>Note: The number in a box is the order. The number in a circle is the node number.</p>

<p>The Strahler order of a river system is computed as follows.</p>

<ul>
	<li>The order of each source node is 1.</li>
	<li>For every other node, let i be the highest order of all its upstream nodes. If just one upstreamnode has order i, then this node also has order i. If two or more upstream nodes have orderi, then this node has order i+1.</li>
</ul>

<p>The order of the entire river system is the order of the mouth node. In this problem, the river systemwill have just one mouth. In the picture above, the Strahler order is three (3).</p>

<p>You must write a program to determine the order of a given river system.</p>

<p>The actual river with the highest order is the Amazon, with order 12. The highest in the U.S. is theMississippi, with order 10.</p>

<p>Node M is the mouth of the river. It has no outgoing edges.</p>

### 입력 

 <p>The first line of input contains a single integer K, (1 ≤ K ≤ 1000), which is the number of data setsthat follow. Each data set should be processed identically and independently.</p>

<p>Each data set consists of multiple lines of input. The first line of each data set contains three positiveintegers, K, M and P (2 ≤ M ≤ 1000). K is the data set number. M is the number of nodes in thegraph and P is the number of edges. The first line is followed by P lines, each describing an edge ofthe graph. The line will contain two positive integers, A and B, indicating that water flows from node Ato node B (1 ≤ A, B ≤ M). Node M is the mouth of the river. It has no outgoing edges.</p>

### 출력 

 <p>For each data set there is a single line of output. The line consists of the data set number, a singlespace and the order of the river system.</p>

