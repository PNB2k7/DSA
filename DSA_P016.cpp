#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Try(const vector<vector<int>> &v, vector<bool> &col, vector<bool> &d1, vector<bool> &d2, int k, int g, int &max_score){
    if(k >= 8){
        if(g > max_score) max_score = g;
        return;
    }
    for(int i = 0; i < 8; i++){
        // Kiểm tra cột i, đường chéo chính (k - i + 7), đường chéo phụ (k + i)
        if(!col[i] && !d1[k - i + 7] && !d2[k + i]){
            col[i] = d1[k - i + 7] = d2[k + i] = true;
            Try(v, col, d1, d2, k + 1, g + v[k][i], max_score);
            col[i] = d1[k - i + 7] = d2[k + i] = false; // Backtrack
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    for(int t_idx = 1; t_idx <= t; t_idx++){
        vector<vector<int>> v(8, vector<int>(8));
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin >> v[i][j];
            }
        }
        
        vector<bool> col(8, false);
        vector<bool> d1(15, false); 
        vector<bool> d2(15, false); 
        
        int max_score = 0; // Khai báo cục bộ để tránh lỗi lưu trạng thái giữa các test
        Try(v, col, d1, d2, 0, 0, max_score);
        
        cout << "Test " << t_idx << ": " << max_score << "\n";
    }
    return 0;
}