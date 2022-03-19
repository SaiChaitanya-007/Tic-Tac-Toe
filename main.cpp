#include <bits/stdc++.h>

using namespace std;

int check(vector<vector<char>>&mat,char c){
    for(int i=0;i<3;i++){
        int x=0,y=0;
        for(int j=0;j<3;j++){
            if(mat[i][j]==c)x++;
            if(mat[j][i]==c)y++;
        }
        if(x==3 || y==3)
            return 1;
    }
    if(mat[0][0]==c && mat[1][1]==c && mat[2][2]==c)return 1;
    if(mat[0][2]==c && mat[1][1]==c && mat[2][0]==c)return 1;
    return 0;
}
int coun = 0;
int dfs(vector<vector<char>>&mat,char c,int num){
    if(num==9){
        coun++;
        if(check(mat,'X'))return 1;
        if(check(mat,'O'))return -1;
        return 0;
    }
    if(check(mat,'X'))return 1;
    if(check(mat,'O'))return -1;
    int mymin = 1,mymax = -1;
    int x=-1,y=-1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[i][j]!='#')continue;
            mat[i][j] = c;
            if(c=='X'){
                mymax = max(mymax,dfs(mat,'O',num+1));
            }else{
                mymin = min(mymin,dfs(mat,'X',num+1));
            }
            mat[i][j] = '#';
        }
    }
    return c=='X'?mymax:mymin;
}

int main()
{
    vector<vector<char>> mat(3,vector<char>(3,'#'));
    int num = 0;
    for(auto vec:mat){
        for(auto ele:vec){
            cout << ele << " ";
        }cout << endl;
    }
    while(num<9){
        int x=-1,y=-1;
        int mymin = 1,mymax = -1;
        char c = 'X';
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(mat[i][j]!='#')continue;
                mat[i][j] = c;
                if(c=='X'){
                    int t = dfs(mat,'O',num+1);
                    if(mymax<t){
                        mymax = t;x = i;y=j;
                    }
                }else{
                    int t = dfs(mat,'X',num+1);
                    if(mymin>t){
                        mymin=t;x=i;y=j;
                    }
                }
                mat[i][j] = '#';
            }
        }
        mat[x][y] = 'X';
        cout << "====Computer : " << endl;
        for(auto vec:mat){
            for(auto ele:vec){
                cout << ele << " ";
            }cout << endl;
        }
        num++;
        if(num==9 || check(mat,'X'))
            break;
        cout << "==========   Your Turn ==========" << endl;
        int ind1,ind2;
        cin >> ind1 >> ind2;
        mat[ind1][ind2] = 'O';
        for(auto vec:mat){
            for(auto ele:vec){
                cout << ele << " ";
            }cout << endl;
        }
        num++;
    }


    return 0;
}
