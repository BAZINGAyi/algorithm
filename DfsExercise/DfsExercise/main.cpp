#include <iostream>

using namespace std;

#include "math.h"

/* 问题 1 : 输入一个数 n 输出 1 到 n 的全排列
 */


void printfNumber(char * number){
    
    int temp = 0;
    
    for (int i = 0; i < strlen(number); i++) {
        
        if(temp == 0 && number[i] != '0')
            
            temp = 1;
        
        if(temp == 1)
            
            cout<<number[i];
        
    }
    
    cout<<" ";
}

void dfs_arrange(char * number, int length, int index){
    
    if(index == length){
        
        printfNumber(number);
        
        return;
        
    }
    
    for(int i = 0; i < 10; i++){
        
        number[index] = '0' + i;
        
        dfs_arrange(number, length, index + 1);
        
    }
    
}

void doArrange(int n){
    
    if(n <= 0) return;
    
    char * number = new char[n + 1];
    
    number[n] = '\0';
    
    dfs_arrange(number, n , 0);
    
}

/* 问题2 ： 有 1 - n 张扑克牌，1 - n 个桶 ，将这些扑克牌放入桶，打印出所有的情况
 */
// a 代表放的桶 b代表手里的牌 n 代表几个桶 indes 代表当前在第几个桶中
void dfs_putBucket(int * a, int * b, int index, int n){

    int i ;
    
    if(index == n ){ // 等于 n 证明 n-1 前的排好了
        
        for(i = 0; i < n; i++)
            
            cout<<a[i];
        
        cout<<endl;
    }
    for(i = 0; i < n; i++){
        
        if(b[i] == 0){
            
            b[i] = 1;
            
            a[index] = i + 1;
            
            dfs_putBucket(a, b, index + 1, n);
            
            b[i] = 0;   // 上面的那种情况已经输出，所以需要进行下一种情况，b[i] 清零
            
        }
    
    }
    
    return ;
}

/* 问题3 ： 迷宫由 n 行 m 列的单元格组成( n 和 m 都小于等于50)，每个单元格是空地或障碍物，
 帮助找到一条从迷宫的起点到小哈所在位置的最短路径
 */
int minSum = 9999999;

int findx = 4, findy = 3;

int book[101][101] = {0};

int n = 4, m = 5;

void dfs_find(int (*a)[101], int x, int y, int step){
    
    int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    if(x == findx && y == findy){
        
        if(minSum > step)
            
            minSum = step;
        
        return ;
    }
    
    // 依次查找周围的四个位置
    
    for(int i = 0; i < 4; i++){
        
        int tx = x + direction[i][0];
        
        int ty = y + direction[i][1];
        
        if(tx > m || tx < 1 || ty > n || ty < 1)
            
            continue;
        
        if(book[tx][ty] == 0 && a[tx][ty] == 0){
            
            book[tx][ty] = 1;
            
            dfs_find(a, tx, ty, step + 1);
            
            book[tx][ty] = 0;
        }
    }
    
    return ;
}

/* 问题4 ： 口口口 + 口口口 = 口口口 填入一到九 输出满足的总个数
 */
int a[10] = {0};

int book4[10] = {0};

int sum = 0;

void dfs_sum(int index,int length){
    
    if(index == length + 1){
        
        if(a[1]*100 + a[2]*10 + a[3] + a[4]*100 + a[5]*10 + a[6] == a[7]*100 + a[8]*10 + a[9]){
            
            cout<<a[1]<<a[2]<<a[3]<<"+"<<a[4]<<a[5]<<a[6]<<"="<<a[7]<<a[8]<<a[9]<<endl;
            
            sum++;
        }
        
        return;
    }
    
    for(int i = 1; i <= 9; i++){
        
        if(book4[i] == 0){
            
            book4[i] = 1;
            
            a[index] = i;
            
            dfs_sum(index + 1, length);
            
            book4[i] = 0;
        
        }
    }

}


// 问题5: 在一个 3*4 的格子中，其中 0，0 2，3 位置刨除，在剩下的位置中放入 0 - 9 的数字，要求连续的数字不能相邻

int value[3][4] = {0}, flag_vaule[3][4] = {0};  // value 用来存放放置好的数组，flag_value 用来标示 value 的位置是否能使用

int b[10] = {0}, visit_b[10] = {0};             // b 用来存放生成好的 0 - 9 的数字，visit_b 用来标示 0 - 9 的数字是否被使用

int value_sum = 0;

void init_value(){
    
    for(int i = 0; i < 3; i++)
        
        for(int j = 0; j < 4; j++)
            
            flag_vaule[i][j] = 1;
    
    flag_vaule[0][0] = -1;
    
    flag_vaule[2][3] = -1;

}

void change(){  //  将一维数组变为二维数组
    
    int t=0;
    
    for(int i=0;i<3;i++)
        
        for(int j=0;j<4;j++)
        {
            if(flag_vaule[i][j] == -1)
                
                continue;
            
            value[i][j]=b[t];
            
            t++;
        }

}

int solve(){
    
    change();
    
    int direction[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{1,-1},{-1,1}};
    
    
    int t = 1;
    
    for(int i = 0 ; i < 3 ; i ++)
    {
        for(int j = 0 ; j < 4; j ++)
        {
            //判断每个数周围是否满足
            if(flag_vaule[i][j] == -1)continue;
            
            for( int k = 0 ; k < 8 ; k ++)
            {
                int x,y;
                x = i + direction[k][0];
                y = j + direction[k][1];
                if(x < 0 || x >= 3 || y < 0 || y >= 4 || flag_vaule[x][y] == -1) continue;
                
                if(fabs(value[x][y] - value[i][j]) == 1)
                    
                    t = 0;
            }
        }
    }
    
    if(t == 1)

        return 1;
    
    return 0;

}

void dfs_value(int index){

    if(index == 10){
    
        int a = solve();
        
        if(a)
            
            value_sum++;
    }else{
    
        for(int i = 0; i < 10; i++){
            
            if(!visit_b[i]){
                
                b[index] = i;
                
                visit_b[i] = 1;
                
                dfs_value(index + 1);
                
                visit_b[i] = 0;
            }
         }
    }

}

int main(int argc, const char * argv[]) {
    
    // 问题 1 :
    //doArrange(3);
    
    // 问题 2 :
    //int hand[3] = {0};
    
    //int bucket[3] = {0};
    
    //dfs_putBucket(hand, bucket, 0, 3);
    
    // 问题 3：
    
//    int a[101][101] = {0};
//    
//    cin>>m>>n;
//    
//    int startx = 1,starty = 1;
//    
//    for(int i = 1; i <= m; i++)
//        
//        for(int j = 1; j <= n; j++)
//            
//            cin>>a[i][j];
//    
//    cin>>startx>>starty>>findx>>findy;
//    
//    book[startx][starty] = 1;
//    
//    dfs_find(a, startx, starty, 0);
//    
//    cout<<minSum;
    
//    问题 4 :
    
//    dfs_sum(1, 9);
    
 //   cout<<(sum/2);
    
 //   问题 5:
    
    init_value();
    
    dfs_value(0);
    
    cout<<value_sum;
    
    return 0;
}
