/********************************************
作者:Alfeim
题目:建立四叉树
时间消耗:200ms
解题思路:递归
********************************************/
lass Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node *root = new Node(true,true,NULL,NULL,NULL,NULL);
        if(!isLeaf(grid,0,0,n-1,n-1)){
            root->isLeaf = false;
            Solve(root,grid,0,0,n);
        }else{
            root->val = grid[0][0] == 1;
        }

        return root;
    }
    
    void Solve(Node* node,vector<vector<int>>& grid,int i , int j , int size){
        if(size == 1)
            return;
        
         int half = size/2;
        
         node->topLeft = new Node(true,true,NULL,NULL,NULL,NULL);
         node->topRight = new Node(true,true,NULL,NULL,NULL,NULL);
         node->bottomLeft = new Node(true,true,NULL,NULL,NULL,NULL);
         node->bottomRight = new Node(true,true,NULL,NULL,NULL,NULL);
         bool Leaf;
        
         if(!isLeaf(grid, i , j , i + half - 1 ,j + half - 1)) {
             node->topLeft->isLeaf = false;
             Solve(node->topLeft,grid,i,j,half);
         }else
             node->topLeft->val = grid[i][j] == 1;
        
         if(!isLeaf(grid, i , j + half,  i + half - 1,  j + size - 1)) {
             node->topRight->isLeaf = false;
             Solve(node->topRight,grid,i,j + half,half);
         }else
             node->topRight->val = grid[i][j+half] == 1;
         
         if(!isLeaf(grid,i + half , j , i + size - 1, j + half - 1)){
             node->bottomLeft->isLeaf = false;
             Solve(node->bottomLeft, grid, i + half , j , half);
         }else
             node->bottomLeft->val = grid[i + half][j] == 1;

         if(!isLeaf(grid, i  + half , j + half, i + size - 1, j + size - 1)){
             node->bottomRight->isLeaf = false;
             Solve(node->bottomRight, grid ,i + half, j + half, half);
         }else
             node->bottomRight->val = grid[i+half][j+half] == 1;

         return;
    }
    
    
    bool isLeaf(vector<vector<int>>& grid,int rowbegin,int colbegin,int rowend,int colend){
        int first = grid[rowbegin][colbegin];
        for(int i = rowbegin ; i <= rowend; ++i){
            for(int j = colbegin ; j <= colend ; ++j){
                if(grid[i][j] != first)  return false;
            }
        }
        
        return true;
    }
    
    
};
