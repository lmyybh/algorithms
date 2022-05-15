# 题目: 节点之和最大的路径 
 <font size=2>难度: <font color='red'>困难</font></font>


**路径** 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 **至多出现一次** 。该路径 **至少包含一个** 节点，且不一定经过根节点。

**路径和** 是路径中各节点值的总和。

给定一个二叉树的根节点 ```root``` ，返回其 **最大路径和**，即所有路径上节点值之和的最大值。


**示例 1：**

![](https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg)
```
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
```

**示例 2：**

![](https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg)
```
输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
```

### 提示
- 树中节点数目范围是 $[1, 3*10^4]$
- -1000 <= Node.val <= 1000


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jC7MId
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


# 题解
节点权重：$w_{node} = node.val + \max(w_{left}, w_{right}, 0)$

节点node的最大路径和：$S_{node} = node.val + \max(w_{left}, 0) + \max(w_{right}, 0)$

**递归实现：**
```Python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        maxSum = -1000
        def dfs(node):
            nonlocal maxSum
            if node is None:
                return 0
            
            leftGain = dfs(node.left)
            rightGain = dfs(node.right)

            s = node.val + max(leftGain, 0) + max(rightGain, 0)
            if s > maxSum:
                maxSum = s
            
            return node.val + max(leftGain, rightGain, 0)
        
        dfs(root)
        return maxSum
```

**算法复杂度：**

时间复杂度：$O(n)$， 每个节点遍历一次

空间复杂度：$O(n)$，递归层数与树的高度相同


