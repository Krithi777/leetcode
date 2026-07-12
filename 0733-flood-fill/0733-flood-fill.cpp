class Solution {
public:
    int row,col;
    void dfs(vector<vector<int>>& image, int i, int j, int color,int val)
    {
        if(i>=0 && j>=0 && i< row && j<col && val!=color && image[i][j]==val)
        {
            image[i][j]=color;
            dfs(image,i-1,j,color,val);
            dfs(image,i+1,j,color,val);
            dfs(image,i,j-1,color,val);
            dfs(image,i,j+1,color,val);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        row=image.size();
        col=image[0].size();
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};