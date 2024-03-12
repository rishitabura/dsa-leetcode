/*using dfs
tc - O(n*m)
sc - O(n*m)*/
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int color, int iniColor, int dx[], int dy[]){

        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i<4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                dfs(nrow, ncol, image, ans, color, iniColor, dx, dy);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int iniColor = image[sr][sc];
        vector<vector<int>>ans = image;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        dfs(sr, sc, image,ans, color, iniColor, dx, dy);

        return ans;
        
    }
};