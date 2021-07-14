package LeetCode.Binary_Tree;

import java.util.Queue;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

// 到底该用什么数据类型？？
public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] indegrees = new int[numCourses];
        ArrayList<ArrayList<Integer>> adjacency = new ArrayList<>(); //
        // List<List<Integer>> adjacency = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < numCourses; i++) 
            adjacency.add(new ArrayList<>());  
        
        for (int[] cp : prerequisites) {
            indegrees[cp[0]]++;
            adjacency.get(cp[1]).add(cp[0]);
        }

        for (int i = 0; i < numCourses; i++) 
            if (indegrees[i] == 0)
                queue.add(i);

        while (!queue.isEmpty()) {
            int pre = queue.poll();
            numCourses--;
            for (int cur : adjacency.get(pre))
                if (--indegrees[cur] == 0)
                    queue.add(cur);
        }
        return numCourses == 0;
    }
}
