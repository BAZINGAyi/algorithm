#include <iostream>
using namespace std;

// 问题描述：输入一个m行n列的字符矩阵，统计字符”@”组成多少个八连块。
// 如果两个字符“@”所在的格子相邻（横、竖或者对角线方向），就说它们属于同一个八连块。

int m,n,idx[100][100];

void dfs(char (*a)[100], int row, int column){
    
    if(row < 0 || row >= m || column < 0 || column >= n)
        
        return ;

    if(idx[row][column] > 0 || a[row][column] != '@')
        
        return ;
    
    idx[row][column] = 1;
    
    for (int i = -1; i <= 1; i++) { // 遍历除了本身外其它8个位置
        
        for (int j = -1; j <= 1; j++) {
            
            if(i != 0 || j != 0)
                
                dfs(a, row + i, column + j);
            
        }
    }
    
}

int main(int argc, const char * argv[]) {
    

    
    char a[100][100];
    
    for (int i = 0; i < 100; i++) {
        
        for (int j = 0; j < 100; j++) {
            
            a[i][j] = 0;
            
        }
    }
    
    cin>>m>>n;
    
    for (int i = 0; i < m; i++) {
       
        scanf("%s", a[i]);
    }
    
    int cnt = 0;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(idx[i][j] == 0 && a[i][j] == '@'){
                
                dfs(a, i , j);
                
                cnt++;
            
            }
            
        }
    }
    
    cout<<cnt<<endl;
    
 
 
    return 0;
}
