#pragma once
#include <iostream>
using namespace std;

// 4 X 4 ���
class mat4 {
public:
	double num[4][4];
	double transpose_num[4][4]; // ��ġ ��ķ� �ٲ� ���� �����ϱ� ���� �迭
	double result[4][4]; // ��Ģ������ ������ �ᱣ���� �ӽ÷� ������ �迭

	mat4(int a, int b, int c, int d, // ������ �����ε�(int), 4 X 4 ��Ŀ� ���� �ִ´�.
		 int e, int f, int g, int h,
		 int i, int j, int k, int l,
		 int n, int m, int o, int p) {

		int arr[] = { a, b, c, d, e, f, g, h, i, j, k, l, n, m, o, p }; // ��� �ȿ� �� �Ű������� �迭�� ����
		int arr_num = 0; // num[][] �迭�� �Ű������� �ݺ������� �ֱ� ���� ��

		for (int i = 0; i < 4; i++) { // ���� for������ 4 X 4 �迭�� ��ġ �迭�� �� ���� �� �ʱ�ȭ
			for (int j = 0; j < 4; j++) {
				num[i][j] = arr[arr_num++];

				transpose_num[i][j] = 0;
				result[i][j] = 0;
			}
		}	
	}

	mat4(double a, double b, double c, double d, // ������ �����ε�(double), 4 X 4 ��Ŀ� ���� �ִ´�.
	 	 double e, double f, double g, double h,
		 double i, double j, double k, double l,
	   	 double n, double m, double o, double p) {

		double arr[] = { a, b, c, d, e, f, g, h, i, j, k, l, n, m, o, p };
		int arr_num = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				num[i][j] = arr[arr_num++];

				transpose_num[i][j] = 0;
				result[i][j] = 0;
			}
		}
	}

	void Identity_matrix() { // ���� ��� �ʱ�ȭ �Լ�
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				num[i][j] = 0;
				if (i == j) num[i][j] = 1; // ��� �� ���� ���� ���(ex (0, 0), (1, 1)) �ش� ��ġ�� ���� 1�� �����Ѵ�.
				cout << num[i][j] << ", ";
			}
			cout << endl;
		}
	}

	void Transpose_matrix() { // ��ġ ��� ���� �Լ�
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->transpose_num[i][j] = num[j][i]; // ��� �� ���� �ٲ� ��ġ�� �����ش�.
				cout << num[i][j] << ", ";
			}
			cout << endl;
		}
	}

	mat4& operator+(mat4 arr) { // ����� ���� �Լ��� ������ �����ε����� ����
		cout.width(5);
		cout << "��� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) { // ���� ���� �迭(���� ��� �迭)�� ����
			for (int j = 0; j < 4; j++) {
				this->result[i][j] = num[i][j] + arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this); // ���� �ᱣ���� ��ȯ��.
	}

	mat4& operator-(mat4 arr) {
		cout.width(5);
		cout << "��� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->result[i][j] = num[i][j] - arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this);
	}

	mat4& operator/(mat4 arr) {
		cout.width(5);
		cout << "��� ������ ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->result[i][j] = num[i][j] / arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this);
	}

	mat4& operator*(mat4 arr) {
		cout.width(5);
		cout << "��� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->result[i][j] = num[i][j] * arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this);
	}

	friend std::ostream& operator << (std::ostream& out, const mat4& point) { // ��� ������ �����ε�
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout.width(5);
				out << point.num[i][j]; // ���
			}
			out << endl;
		}
		return out; // ��°��� ��ȯ��.
	}
};

// 3 X 3 ���
class mat3 {
public:
	double num[3][3];
	double transpose_num[3][3];
	double result[3][3];

	mat3(int a, int b, int c, // ������ �����ε�(int), 3 X 3 ��Ŀ� ���� �ִ´�.
		 int d, int e, int f,
		 int g, int h, int i) {

		int arr[] = { a, b, c, d, e, f, g, h, i }; // ��� �ȿ� �� �Ű������� �迭�� ����
		int arr_num = 0;

		for (int i = 0; i < 3; i++) { // ���� for������ 3 X 3 �迭�� ��ġ �迭�� �� ���� �� �ʱ�ȭ
			for (int j = 0; j < 3; j++) {
				num[i][j] = arr[arr_num++];

				transpose_num[i][j] = 0;
				result[i][j] = 0;
			}
		}
	}

	mat3(double a, double b, double c, // ������ �����ε�(double), 3 X 3 ��Ŀ� ���� �ִ´�.
		 double d, double e, double f,
		 double g, double h, double i) {

		double arr[] = { a, b, c, d, e, f, g, h, i };
		int arr_num = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				num[i][j] = arr[arr_num++];

				transpose_num[i][j] = 0;
				result[i][j] = 0;
			}
		}
	}

	float Identity_matrix() { // ���� ��� �ʱ�ȭ �Լ�
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				num[i][j] = 0;
				if (i == j) num[i][j] = 1;
			}
		}
	}

	void Transpose_matrix() { // ��ġ ��� ���� �Լ�
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				transpose_num[i][j] = num[j][i];
				cout << transpose_num[i][j] << ", ";
			}
			cout << endl;
		}

	}

	mat3& operator+(mat3 arr) { // ����� ���� �Լ��� ������ �����ε����� ����
		cout.width(5);
		cout << "��� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) { // ���� ���� �迭(���� ��� �迭)�� ����
			for (int j = 0; j < 3; j++) {
				this->result[i][j] = num[i][j] + arr.num[i][j];
				this->num[i][j] = result[i][j];

			}
		}
		return (*this); // ���� �ᱣ���� ��ȯ��.
	}

	mat3& operator-(mat3 arr) {
		cout.width(5);
		cout << "��� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->result[i][j] = num[i][j] - arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this);
	}

	mat3& operator/(mat3 arr) {
		cout.width(5);
		cout << "��� ������ ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->result[i][j] = num[i][j] / arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this);
	}

	mat3& operator*(mat3 arr) {
		cout.width(5);
		cout << "��� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->result[i][j] = num[i][j] * arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this);
	}
};

// 3 X 1 ����
class vec3 {
public:
	double vec[3];
	double result[3];

	vec3(int a, int b, int c) { // ������ �����ε�(int), 3 X 1 ��Ŀ� ���� �ִ´�.
		 int arr[] = { a, b, c };

		for (int i = 0; i < 3; i++) {
			vec[i] = arr[i];
			result[i] = 0;
		}
	}

	vec3(double a, double b, double c) { // ������ �����ε�(double), 3 X 1 ��Ŀ� ���� �ִ´�.
		 double arr[] = { a, b, c };

		for (int i = 0; i < 3; i++) {
			vec[i] = arr[i];
			result[i] = 0;
		}
	}

	vec3& operator+(vec3 arr) { 
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) { 
			this->result[i] = vec[i] + arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec3& operator-(vec3 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i] = vec[i] - arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec3& operator/(vec3 arr) {
		cout.width(5);
		cout << "���� ������ ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i] = vec[i] / arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec3& operator*(vec3 arr) { 
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i] = vec[i] * arr.vec[i];
			this->vec[i] = result[i];
		} 
		return (*this); 
	}

	vec3& operator*(mat3 arr) {
		cout.width(5);
		cout << "����, ��� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i] = vec[i] * arr.num[0][i] + vec[1] * arr.num[1][i] + vec[2] * arr.num[2][i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	friend std::ostream& operator << (std::ostream& out, const vec3& point) {
		out << "( " << point.vec[0] << ", " << point.vec[1] << ", " << point.vec[2] << " )";
		return out;
	}
};

// 1 X 3 ����
class vec1x3 {
public:
	double vec[3][1];
	double result[3][1];

	vec1x3(int a, int b, int c) { // ������ �����ε�(int), 1 X 3 ��Ŀ� ���� �ִ´�.
		int arr[] = { a, b, c };

		for (int i = 0; i < 3; i++) {
			vec[i][0] = arr[i];
			result[i][0] = 0;
		}
	}

	vec1x3(double a, double b, double c) { // ������ �����ε�(double), 1 X 3 ��Ŀ� ���� �ִ´�.
		double arr[] = { a, b, c };

		for (int i = 0; i < 3; i++) {
			vec[i][0] = arr[i];
			result[i][0] = 0;
		}
	}

	vec1x3& operator+(vec1x3 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = vec[i][0] + arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x3& operator-(vec1x3 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = vec[i][0] - arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x3& operator/(vec1x3 arr) {
		cout.width(5);
		cout << "���� ������ ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = vec[i][0] / arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x3& operator*(vec1x3 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = vec[i][0] * arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x3& operator*(mat3 arr) {
		cout.width(5);
		cout << "���� ��ġ ���� ���\n" << "--------------\n";
		arr.Transpose_matrix();
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = (vec[i][0] * arr.num[i][0]);
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	friend std::ostream& operator << (std::ostream& out, const vec1x3& point) {
		out << "( " << point.vec[0][0] << ", " << point.vec[1][0] << ", " << point.vec[2][0] << " )";
		return out;
	}
};

// 4 X 1 ���
class vec4 {
public:
	double vec[4];
	double result[4];

	vec4(int a, int b, int c, int d) { // ������ �����ε�(int), 4 X 1 ��Ŀ� ���� �ִ´�.
		int arr[] = { a, b, c, d };

		for (int i = 0; i < 4; i++) {
			vec[i] = arr[i];
			result[i] = 0;
		}
	}

	vec4(double a, double b, double c, double d) { // ������ �����ε�(double), 4 X 1 ��Ŀ� ���� �ִ´�.
		double arr[] = { a, b, c, d };

		for (int i = 0; i < 4; i++) {
			vec[i] = arr[i];
			result[i] = 0;
		}
	}

	vec4& operator+(vec4 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i] = vec[i] + arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec4& operator-(vec4 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i] = vec[i] - arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec4& operator/(vec4 arr) {
		cout.width(5);
		cout << "���� ������ ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i] = vec[i] / arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec4& operator*(vec4 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i] = vec[i] * arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec4& operator*(mat4 arr) {
		cout.width(5);
		cout << "����, ��� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
				this->result[i] = vec[i] * arr.num[0][i] + vec[1] * arr.num[1][i] + vec[2] * arr.num[2][i] + vec[3] * arr.num[3][i];
				this->vec[i] = result[i];		
		}
		return (*this);
	}

	friend std::ostream& operator << (std::ostream& out, const vec4& point) {
		out << "( " << point.vec[0] << ", " << point.vec[1] << ", " << point.vec[2] << ", " << point.vec[3] << " )";
		return out;
	}
};

// 1 X 4 ����
class vec1x4 {
public:
	double vec[4][1];
	double result[4][1];

	vec1x4(int a, int b, int c, int d) { // ������ �����ε�(int), 1 X 4 ��Ŀ� ���� �ִ´�.
		int arr[] = { a, b, c, d };

		for (int i = 0; i < 4; i++) {
			vec[i][0] = arr[i];
			result[i][0] = 0;
		}
	}

	vec1x4(double a, double b, double c, double d) { // ������ �����ε�(double), 1 X 4 ��Ŀ� ���� �ִ´�.
		double arr[] = { a, b, c, d };

		for (int i = 0; i < 4; i++) {
			vec[i][0] = arr[i];
			result[i][0] = 0;
		}
	}

	vec1x4& operator+(vec1x4 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = vec[i][0] + arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x4& operator-(vec1x4 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = vec[i][0] - arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x4& operator/(vec1x4 arr) {
		cout.width(5);
		cout << "���� ������ ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = vec[i][0] / arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x4& operator*(vec1x4 arr) {
		cout.width(5);
		cout << "���� ���� ���\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = vec[i][0] * arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x4& operator*(mat4 arr) {
		cout.width(5);
		cout << "���� ��ġ ���� ���\n" << "--------------\n";
		arr.Transpose_matrix();
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = (vec[i][0] * arr.num[i][0]);
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	friend std::ostream& operator << (std::ostream& out, const vec1x4& point) {
		out << "( " << point.vec[0][0] << ", " << point.vec[1][0] << ", " << point.vec[2][0] << ", " << point.vec[3][0] << " )";
		return out;
	}
};