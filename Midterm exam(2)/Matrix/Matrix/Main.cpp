#include <iostream> // ����� ���� �Լ�
#include <math.h> // �ﰢ�Լ��� ���� ���� ���� �������
#include "MuSoenMath.h" // MuSoenMath.h ������ �ҷ���


	int main() {
		mat3 arr1 = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
		mat4 arr2 = mat4(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);	
		vec1x3 vc = vec1x3(1, 2, 3);
		vec1x3 result = vec1x3(0, 0, 0);

		arr1.Transpose_matrix();

		//std::cout << result; // ����� �� ���
}





