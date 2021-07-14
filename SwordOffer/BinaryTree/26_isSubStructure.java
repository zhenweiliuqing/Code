import jdk.nashorn.api.tree.Tree;

// 2-10

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}


// 最后还是记住这个把！！
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (A == null || B == null)
            return false;
        if (TreeAhasTreeB(A, B))
            return true;
        return isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }
    
    public boolean TreeAhasTreeB(TreeNode A, TreeNode B) {
        if (B == null)
            return true;
        if (A == null)
            return false;
        return A.val == B.val && TreeAhasTreeB(A.left, B.left) && TreeAhasTreeB(A.right, B.right);
    }
}
// 这个通过了


class Solution1 {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (B == null || A == null)
            return false;
        return hasSubStructure(A, B);
    }
    public boolean hasSubStructure(TreeNode A, TreeNode B) {
        if (B == null)
            return true;
        if (A == null)
            return false;
        // 这里应该还有机会
        if (A.val != B.val)
            return hasSubStructure(A.left, B) || hasSubStructure(A.right, B);
        return hasSubStructure(A.left, B.left) && hasSubStructure(A.right, B.right);
    }
}
// 这个思路有漏洞 root相同 就再也到不了下边了

// 得找到一个能走到下边的
// 感觉没有及时剪枝
// class Solution {
//     public boolean isSubStructure(TreeNode A, TreeNode B) {
//         if (B == null || A == null)
//             return false;
//         return hasSubStructure(A, B);
//     }

//     public boolean hasSubStructure(TreeNode A, TreeNode B) {
//         if (B == null)
//             return true;
//         if (A == null)
//             return false;
//         boolean ans = false;
//         if (A.val == B.val)
//             ans = hasSubStructure(A.left, B.left) && hasSubStructure(A.right, B.right);
//         if (!ans)
//             ans = hasSubStructure(A.left, B) || hasSubStructure(A.right, B);
//         return ans;
//     }
// }
// 还是不行 有点绕晕了

// 为什么非要用两个递归
class Answer {
    // 这个递归就是遍历树的
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        // 只有开局的时候B会是null  在这个循环中B不变
        if (A == null || B == null)
            return false;
        // if (B == null) 也是可以的
        //     return false;
        // else if (A == null)
        //     return false;
        boolean ans = false;
        ans = TreeAhasTreeB(A, B);
        if (!ans)
            ans = isSubStructure(A.left, B) || isSubStructure(A.right, B);
        return ans;
    }
    
    // 这个递归就是比较数值的
    public boolean TreeAhasTreeB(TreeNode A, TreeNode B) {
        if (B == null)
            return true;
        if (A == null)
            return false;
        if (A.val != B.val)
            return false;
        return TreeAhasTreeB(A.left, B.left) && TreeAhasTreeB(A.right, B.right);
    }
}
// 这个通过了


// 3-16 有漏洞 
// 如果B为null 应该直接输出false
// 打补丁也不行 还是看双递归吧
// class Solution {
//     public boolean isSubStructure(TreeNode A, TreeNode B) {
//         if (A == null && B == null)
//             return true;
//         else if (A == null && B != null)
//             return false;
//         else if (A != null && B == null)
//             return true;
        
//         if (A.val == B.val && isSubStructure(A.left, B.left) && isSubStructure(A.right, B.right))
//             return true;
//         return isSubStructure(A.left, B) || isSubStructure(A.right, B);
//     }
// }


