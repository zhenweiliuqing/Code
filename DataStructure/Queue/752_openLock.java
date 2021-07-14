package LeetCode.BFS;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.HashSet;
import java.util.Queue;
import java.lang.StringBuilder;

class Solution {
    public String codeplus(String str, int i) {
        StringBuilder temp = new StringBuilder(str);
        temp.replace(i, i, ((temp.charAt(i) + 1) % 10).toString());
    }

    public int openLock(String[] deadends, String target) {
        HashSet<String> set = new HashSet<>();
        for (String str : deadends)
            set.add(str);
        Queue<String> q = new LinkedList<>();
        q.offer("0000");
        int step = 0;

        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                String temp = q.poll();
                if (temp == target)
                    return step;
                
                for (int j = 0; j < 4; j++) {
                }
            }
        }
    }
}