#include<iostream>
using namespace std;
//�ö�̬�滮��coin 
int opp[9999][101];//������¼���ÿ�ֱʵ����� 
int main() {

	int n_[6] = { 100,50,20,10,5,1 };

	int m;
	cin >> m;    //m��ʾҪ����� 
	int a[9999];
	a[0] = 0;
	for (int i = 1; i <= m; i++) {//��ΪӲ��������ǱȽϼ򵥵�һһ�Ƶ��������Խ���������m 
		a[i] = 9999;//�ȼ���Ҫ��̬������� 
		int pl;
		for (int j = 0; j < 6; j++) {//ǰ��i-n_.at(j) ����0
			if (i - n_[j] >= 0) {
				if (a[i] > a[i - n_[j]] + 1) {
					pl = n_[j];//��¼���һ�ε��Ż�ʱ �õ�����Ǯ�� 
					a[i] = a[i - n_[j]] + 1;

				}
			}
			else {//�������Ϊi��������������Կ��Բ��ù� 
					   //��Ϊ  ����Ļ��϶������������Ž� = =.
			}


		} //��һ�����  ��i��Ǯ  ������ �� n-x�� ��һ�� pl ��� 
		for (int jii = 0; jii < 6; jii++) {
			if (n_[jii] != pl) {//Ҳ���ǰ�n-x�Ŀ��ܸ���i��ͬʱ �� pl��������һ
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