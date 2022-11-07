#pragma once
#include <iostream>
using namespace std;

class mat3 {
public:
	float num[3][3];

	mat3(float a, float b, float c, // 3 X 3 ��� ���� �Լ�
		float d, float e, float f,
		float g, float h, float i) {

		//int arr[] = { a, b, c, d, e, f, g, h, i }; // ��� �ȿ� �� �Ű������� �迭�� ����
		//int arr_num = 0; // 3 X 3 �迭 �ȿ� ���� ���� �ֱ� ���� ����

		num[0][0] = a; num[0][1] = b; num[0][2] = c; // �迭�� ���������� �Ű������� �־���
		num[1][0] = d; num[1][1] = e; num[1][2] = f;
		num[2][0] = g; num[2][1] = h; num[2][2] = i;

		//for (int i = 0; i < 3; i++) { // ���� for������ 3 X 3 �迭 ����
		//	for (int j = 0; j < 3; j++) {
		//		num[j][i] = arr[arr_num++]; 
		//	}
		//}
	}
};

class vec3 {
public:
	float vec[3];
	float vm[3]; // ������ ���� �ӽ� �迭�� �����Ѵ�.

	vec3(float a, float b, float c) { // 3 X 1 ��� ���� �Լ�
		//int arr[] = { a, b, c }; // ��� �ȿ� �� �Ű������� �迭�� ����
		//int arr_num = 0; // 1 X 3 �迭 �ȿ� ���� ���� �ֱ� ���� ����

			vec[0] = a; // �迭�� ���������� �Ű������� �־���
			vec[1] = b;
			vec[2] = c;
		
	}

	vec3& operator*(mat3 arr) { // ��İ� ���� �Լ�

		this->vm[0] = vec[0] * arr.num[0][0] + vec[1] * arr.num[1][0] + vec[2] * arr.num[2][0]; // ���� ���� �迭(���� ��� �迭)�� ��������
		this->vm[1] = vec[0] * arr.num[0][1] + vec[1] * arr.num[1][1] + vec[2] * arr.num[2][1];
		this->vm[2] = vec[0] * arr.num[0][2] + vec[1] * arr.num[1][2] + vec[2] * arr.num[2][2];

		this->vec[0] = vm[0];
		this->vec[1] = vm[1];
		this->vec[2] = vm[2];

		//for (int i = 0; i < 3; i++) { // ���� for������ 3 X 1�� 3 X 3 ��İ� ����
		//	for (int j = 0; j < 3; j++) {
		//		result.vec[i] += vec[j] * arr.num[j][i]; 
		//	}
		//}
		return (*this); // ���� �ᱣ���� ��ȯ��.
	}

	friend std::ostream& operator << (std::ostream& out, const vec3& point) { // ��� ������ �����ε�
		out << "( " << point.vec[0] << ", " << point.vec[1] << ", " << point.vec[2] << " )"; // ���
		return out; // ��°��� ��ȯ��.
	}
};