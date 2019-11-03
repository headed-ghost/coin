#include<iostream>
using namespace std;
//用动态规划做coin 
int opp[9999][101];//用来记录你的每种笔的数量 
int main() {

	int n_[6] = { 100,50,20,10,5,1 };

	int m;
	cin >> m;    //m表示要求的数 
	int a[9999];
	a[0] = 0;
	for (int i = 1; i <= m; i++) {//因为硬币这道题是比较简单的一一推的类型所以结束可以是m 
		a[i] = 9999;//先假设要动态的数最大 
		int pl;
		for (int j = 0; j < 6; j++) {//前提i-n_.at(j) 大于0
			if (i - n_[j] >= 0) {
				if (a[i] > a[i - n_[j]] + 1) {
					pl = n_[j];//记录最后一次的优化时 用的那种钱币 
					a[i] = a[i - n_[j]] + 1;

				}
			}
			else {//这种情况为i不足这种情况所以可以不用管 
					   //因为  不足的话肯定不可能是最优解 = =.
			}


		} //这一步完成  第i快钱  可以用 第 n-x快 加一个 pl 完成 
		for (int jii = 0; jii < 6; jii++) {
			if (n_[jii] != pl) {//也就是把n-x的可能赋给i的同时 对 pl的张数加一
				opp[i][n_[jii]] = opp[i - pl][n_[jii]];
			}
			else {
				opp[i][n_[jii]] = opp[i - pl][n_[jii]] + 1;
			}

		}


	}
	for (int i = 0; i < 6; i++) {
		if (i) {
			printf("\n");
		}
		printf("%d", opp[m][n_[i]]);
	}


}