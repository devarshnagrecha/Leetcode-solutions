<h2><a href="https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/">2350. Shortest Impossible Sequence of Rolls</a></h2><h3>Hard</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given an integer array <code style="user-select: auto;">rolls</code> of length <code style="user-select: auto;">n</code> and an integer <code style="user-select: auto;">k</code>. You roll a <code style="user-select: auto;">k</code> sided dice numbered from <code style="user-select: auto;">1</code> to <code style="user-select: auto;">k</code>, <code style="user-select: auto;">n</code> times, where the result of the <code style="user-select: auto;">i<sup style="user-select: auto;">th</sup></code> roll is <code style="user-select: auto;">rolls[i]</code>.</p>

<p style="user-select: auto;">Return<em style="user-select: auto;"> the length of the <strong style="user-select: auto;">shortest</strong> sequence of rolls that <strong style="user-select: auto;">cannot</strong> be taken from </em><code style="user-select: auto;">rolls</code>.</p>

<p style="user-select: auto;">A <strong style="user-select: auto;">sequence of rolls</strong> of length <code style="user-select: auto;">len</code> is the result of rolling a <code style="user-select: auto;">k</code> sided dice <code style="user-select: auto;">len</code> times.</p>

<p style="user-select: auto;"><strong style="user-select: auto;">Note</strong> that the sequence taken does not have to be consecutive as long as it is in order.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> rolls = [4,2,1,2,3,3,2,4,1], k = 4
<strong style="user-select: auto;">Output:</strong> 3
<strong style="user-select: auto;">Explanation:</strong> Every sequence of rolls of length 1, [1], [2], [3], [4], can be taken from rolls.
Every sequence of rolls of length 2, [1, 1], [1, 2], ..., [4, 4], can be taken from rolls.
The sequence [1, 4, 2] cannot be taken from rolls, so we return 3.
Note that there are other sequences that cannot be taken from rolls.</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> rolls = [1,1,2,2], k = 2
<strong style="user-select: auto;">Output:</strong> 2
<strong style="user-select: auto;">Explanation:</strong> Every sequence of rolls of length 1, [1], [2], can be taken from rolls.
The sequence [2, 1] cannot be taken from rolls, so we return 2.
Note that there are other sequences that cannot be taken from rolls but [2, 1] is the shortest.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> rolls = [1,1,3,2,2,2,3,3], k = 4
<strong style="user-select: auto;">Output:</strong> 1
<strong style="user-select: auto;">Explanation:</strong> The sequence [4] cannot be taken from rolls, so we return 1.
Note that there are other sequences that cannot be taken from rolls but [4] is the shortest.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">n == rolls.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= n &lt;= 10<sup style="user-select: auto;">5</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= rolls[i] &lt;= k &lt;= 10<sup style="user-select: auto;">5</sup></code></li>
</ul>
</div>