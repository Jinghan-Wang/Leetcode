/*
* ����һ�������� n ������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��

ʾ�� 1��


���룺n = 3
�����[[1,2,3],[8,9,4],[7,6,5]]
ʾ�� 2��

���룺n = 1
�����[[1]]
 

��ʾ��

1 <= n <= 20
*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // ʹ��vector����һ����ά����
        int startx = 0, starty = 0; // ����ÿѭ��һ��Ȧ����ʼλ��
        int loop = n / 2; // ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
        int mid = n / 2; // �����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
        int count = 1; // ������������ÿһ���ո�ֵ
        int offset = 1; // ��Ҫ����ÿһ���߱����ĳ��ȣ�ÿ��ѭ���ұ߽�����һλ
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;

            // ���濪ʼ���ĸ�for����ģ��ת��һȦ
            // ģ��������д�����(����ҿ�)
            for (j; j < n - offset; j++) {
                res[i][j] = count++;
            }
            // ģ��������д��ϵ���(����ҿ�)
            for (i; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // ģ��������д��ҵ���(����ҿ�)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // ģ��������д��µ���(����ҿ�)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
            startx++;
            starty++;

            // offset ����ÿһȦ��ÿһ���߱����ĳ���
            offset += 1;
        }

        // ���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};

int main() {
    int n = 3;
    Solution solution;
    vector<vector<int>> matrix = solution.generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}