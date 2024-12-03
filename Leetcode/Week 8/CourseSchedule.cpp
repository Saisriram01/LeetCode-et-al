class Solution {
public:
    bool dfs(int crs, vector<vector<int>>& prereqforcrs, set<int>& visitedcrs, set<int>& currentlyVisiting) {
        if (currentlyVisiting.find(crs) != currentlyVisiting.end())
            return false;

        if (visitedcrs.find(crs) != visitedcrs.end())
            return true;

        currentlyVisiting.insert(crs);
        for (int prereq : prereqforcrs[crs]) {
            if (!dfs(prereq, prereqforcrs, visitedcrs, currentlyVisiting))
                return false;
        }
        currentlyVisiting.erase(crs);
        visitedcrs.insert(crs);

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> prereqforcrs(numCourses);
        for (auto it : prerequisites) {
            prereqforcrs[it[0]].push_back(it[1]);
        }
        set<int> visitedcrs, currentlyVisiting;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, prereqforcrs, visitedcrs, currentlyVisiting))
                return false;
        }
        return true;
    }
};
