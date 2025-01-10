/*
https://leetcode.com/problems/course-schedule-ii/description/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
*/



class Solution {
public:
    bool dfs(vector<vector<int>> &preList, vector<int> &res, vector<int> &vis, int course){
        if(vis[course] == 1) return true;

        if(vis[course] == 2) return false; // padh chuka hai
        vis[course] = 1;
        vector<int> preReqVec = preList[course];
        for(auto req : preReqVec){
            if(dfs(preList, res, vis, req)){
                return true;
            }
        }

        vis[course] = 2;
        res.push_back(course);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preList(numCourses);
        for(auto preReq : prerequisites){
            preList[preReq[0]].push_back(preReq[1]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> res;
        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0){
                if(dfs(preList, res, vis, i)){
                    return {};
                }
            }
        }

        return res;
    }
};

// Time Complexity:

// Constructing the adjacency list: O(E), where E is the number of prerequisites.
// DFS traversal: O(V+E), where V is the number of courses and E is the number of prerequisites.
// Overall: O(V+E).

// Space Complexity:

// Adjacency list: O(V+E).
// Visited array and recursion stack: O(V).
// Result list: O(V).
// Overall: O(V+E).