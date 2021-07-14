#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// 6-14
// 有点像DFS 我得知道谁生了谁
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        ans.push_back(kingName);
    }
    
    void birth(string parentName, string childName) {
        mmap[parentName].push_back(childName);
    }
    
    void death(string name) {
        isDead[name] = true;
    }
    
    // 从当前活着的皇帝往后找 如何用栈模拟呢？
    vector<string> getInheritanceOrder() {
        // string king = findKing(ans[0]);
        // stack<string> kings;
        // kings.push(king);
        // while (!kings.empty()) {
        //     string tmp = kings.top();
        //     if (!isDead[tmp])
        //         break;
        // }
        ans.clear();
        ans.push_back(king);
        dfs(king);
        return ans;
    }
private:
    vector<string> ans;
    unordered_map<string, vector<string>> mmap;
    unordered_map<string, bool> isDead;
    
    // string findKing(string king) {
    //     if (!isDead[king])
    //         return king;
    //     for (string s : mmap[king]) {
    //         if (findKing(s) == s)
    //             return s;
    //     }
    //     return "";
    // }

    void dfs(string name) {
        if (mmap.find(name) != mmap.end()) {
            for (auto s : mmap[name]) {
                if (!isDead[s])
                    ans.push_back(s);
                dfs(s);
            }
        }
    }
};


// 又理解错题意了
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        this->kingName = kingName;
        ans.push_back(kingName);
    }
    
    void birth(string parentName, string childName) {
        mmap[parentName].push_back(childName);
    }
    
    void death(string name) {
        isDead[name] = true;
    }
    
    // 每次都从老皇帝开始
    vector<string> getInheritanceOrder() {
        ans.clear();
        dfs(kingName);
        return ans;
    }
private:
    vector<string> ans;
    string kingName;
    unordered_map<string, vector<string>> mmap;
    unordered_map<string, bool> isDead;
    void dfs(string name) {
        if (!isDead[name])
            ans.push_back(name);
        if (mmap.find(name) != mmap.end()) {
            for (auto s : mmap[name])
                dfs(s);
        }
    }
};
// 通过了

// 简洁一些 其实就是深度优先遍历
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) : king(kingName) {
    }
    
    void birth(string parentName, string childName) {
        mmap[parentName].push_back(childName);
    }
    
    void death(string name) {
        isDead[name] = true;
    }
    
    // 每次都从老皇帝开始
    vector<string> getInheritanceOrder() {
        ans.clear();
        dfs(king);
        return ans;
    }
private:
    vector<string> ans;
    string king;
    unordered_map<string, vector<string>> mmap;
    unordered_map<string, bool> isDead;
private:
    void dfs(string name) {
        if (!isDead[name])
            ans.push_back(name);
        for (auto s : mmap[name])
            dfs(s);
    }
};