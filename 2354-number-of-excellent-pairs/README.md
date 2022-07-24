<h2><a href="https://leetcode.com/problems/number-of-excellent-pairs/">2354. Number of Excellent Pairs</a></h2><h3>Hard</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given a <strong style="user-select: auto;">0-indexed</strong> positive integer array <code style="user-select: auto;">nums</code> and a positive integer <code style="user-select: auto;">k</code>.</p>

<p style="user-select: auto;">A pair of numbers <code style="user-select: auto;">(num1, num2)</code> is called <strong style="user-select: auto;">excellent</strong> if the following conditions are satisfied:</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><strong style="user-select: auto;">Both</strong> the numbers <code style="user-select: auto;">num1</code> and <code style="user-select: auto;">num2</code> exist in the array <code style="user-select: auto;">nums</code>.</li>
	<li style="user-select: auto;">The sum of the number of set bits in <code style="user-select: auto;">num1 OR num2</code> and <code style="user-select: auto;">num1 AND num2</code> is greater than or equal to <code style="user-select: auto;">k</code>, where <code style="user-select: auto;">OR</code> is the bitwise <strong style="user-select: auto;">OR</strong> operation and <code style="user-select: auto;">AND</code> is the bitwise <strong style="user-select: auto;">AND</strong> operation.</li>
</ul>

<p style="user-select: auto;">Return <em style="user-select: auto;">the number of <strong style="user-select: auto;">distinct</strong> excellent pairs</em>.</p>

<p style="user-select: auto;">Two pairs <code style="user-select: auto;">(a, b)</code> and <code style="user-select: auto;">(c, d)</code> are considered distinct if either <code style="user-select: auto;">a != c</code> or <code style="user-select: auto;">b != d</code>. For example, <code style="user-select: auto;">(1, 2)</code> and <code style="user-select: auto;">(2, 1)</code> are distinct.</p>

<p style="user-select: auto;"><strong style="user-select: auto;">Note</strong> that a pair <code style="user-select: auto;">(num1, num2)</code> such that <code style="user-select: auto;">num1 == num2</code> can also be excellent if you have at least <strong style="user-select: auto;">one</strong> occurrence of <code style="user-select: auto;">num1</code> in the array.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> nums = [1,2,3,1], k = 3
<strong style="user-select: auto;">Output:</strong> 5
<strong style="user-select: auto;">Explanation:</strong> The excellent pairs are the following:
- (3, 3). (3 AND 3) and (3 OR 3) are both equal to (11) in binary. The total number of set bits is 2 + 2 = 4, which is greater than or equal to k = 3.
- (2, 3) and (3, 2). (2 AND 3) is equal to (10) in binary, and (2 OR 3) is equal to (11) in binary. The total number of set bits is 1 + 2 = 3.
- (1, 3) and (3, 1). (1 AND 3) is equal to (01) in binary, and (1 OR 3) is equal to (11) in binary. The total number of set bits is 1 + 2 = 3.
So the number of excellent pairs is 5.</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> nums = [5,1,1], k = 10
<strong style="user-select: auto;">Output:</strong> 0
<strong style="user-select: auto;">Explanation:</strong> There are no excellent pairs for this array.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= nums.length &lt;= 10<sup style="user-select: auto;">5</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= nums[i] &lt;= 10<sup style="user-select: auto;">9</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= k &lt;= 60</code></li>
</ul>
</div>