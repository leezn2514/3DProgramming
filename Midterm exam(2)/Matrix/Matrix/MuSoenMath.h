#pragma once
#include <iostream>
using namespace std;

// 4 X 4 행렬
class mat4 {
public:
	double num[4][4];
	double transpose_num[4][4]; // 전치 행렬로 바뀐 값을 저장하기 위한 배열
	double result[4][4]; // 사칙연산을 시행한 결괏값을 임시로 저장할 배열

	mat4(int a, int b, int c, int d, // 생성자 오버로딩(int), 4 X 4 행렬에 값을 넣는다.
		 int e, int f, int g, int h,
		 int i, int j, int k, int l,
		 int n, int m, int o, int p) {

		int arr[] = { a, b, c, d, e, f, g, h, i, j, k, l, n, m, o, p }; // 행렬 안에 들어갈 매개변수를 배열로 선언
		int arr_num = 0; // num[][] 배열에 매개변수를 반복문으로 넣기 위한 수

		for (int i = 0; i < 4; i++) { // 이중 for문으로 4 X 4 배열과 전치 배열에 값 저장 및 초기화
			for (int j = 0; j < 4; j++) {
				num[i][j] = arr[arr_num++];

				transpose_num[i][j] = 0;
				result[i][j] = 0;
			}
		}	
	}

	mat4(double a, double b, double c, double d, // 생성자 오버로딩(double), 4 X 4 행렬에 값을 넣는다.
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

	void Identity_matrix() { // 단위 행렬 초기화 함수
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				num[i][j] = 0;
				if (i == j) num[i][j] = 1; // 행과 열 값이 같을 경우(ex (0, 0), (1, 1)) 해당 위치의 값을 1로 변경한다.
				cout << num[i][j] << ", ";
			}
			cout << endl;
		}
	}

	void Transpose_matrix() { // 전치 행렬 구현 함수
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->transpose_num[i][j] = num[j][i]; // 행과 열 값을 바꿔 전치를 시켜준다.
				cout << num[i][j] << ", ";
			}
			cout << endl;
		}
	}

	mat4& operator+(mat4 arr) { // 행렬합 구현 함수를 연산자 오버로딩으로 구현
		cout.width(5);
		cout << "행렬 덧셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) { // 합한 값을 배열(연산 결과 배열)에 저장
			for (int j = 0; j < 4; j++) {
				this->result[i][j] = num[i][j] + arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this); // 합한 결괏값을 반환함.
	}

	mat4& operator-(mat4 arr) {
		cout.width(5);
		cout << "행렬 뺄셈 결과\n" << "--------------\n";
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
		cout << "행렬 나눗셈 결과\n" << "--------------\n";
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
		cout << "행렬 곱셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->result[i][j] = num[i][j] * arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this);
	}

	friend std::ostream& operator << (std::ostream& out, const mat4& point) { // 출력 연산자 오버로딩
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout.width(5);
				out << point.num[i][j]; // 출력
			}
			out << endl;
		}
		return out; // 출력값을 반환함.
	}
};

// 3 X 3 행렬
class mat3 {
public:
	double num[3][3];
	double transpose_num[3][3];
	double result[3][3];

	mat3(int a, int b, int c, // 생성자 오버로딩(int), 3 X 3 행렬에 값을 넣는다.
		 int d, int e, int f,
		 int g, int h, int i) {

		int arr[] = { a, b, c, d, e, f, g, h, i }; // 행렬 안에 들어갈 매개변수를 배열로 선언
		int arr_num = 0;

		for (int i = 0; i < 3; i++) { // 이중 for문으로 3 X 3 배열과 전치 배열에 값 저장 및 초기화
			for (int j = 0; j < 3; j++) {
				num[i][j] = arr[arr_num++];

				transpose_num[i][j] = 0;
				result[i][j] = 0;
			}
		}
	}

	mat3(double a, double b, double c, // 생성자 오버로딩(double), 3 X 3 행렬에 값을 넣는다.
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

	float Identity_matrix() { // 단위 행렬 초기화 함수
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				num[i][j] = 0;
				if (i == j) num[i][j] = 1;
			}
		}
	}

	void Transpose_matrix() { // 전치 행렬 구현 함수
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				transpose_num[i][j] = num[j][i];
				cout << transpose_num[i][j] << ", ";
			}
			cout << endl;
		}

	}

	mat3& operator+(mat3 arr) { // 행렬합 구현 함수를 연산자 오버로딩으로 구현
		cout.width(5);
		cout << "행렬 덧셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) { // 합한 값을 배열(연산 결과 배열)에 저장
			for (int j = 0; j < 3; j++) {
				this->result[i][j] = num[i][j] + arr.num[i][j];
				this->num[i][j] = result[i][j];

			}
		}
		return (*this); // 합한 결괏값을 반환함.
	}

	mat3& operator-(mat3 arr) {
		cout.width(5);
		cout << "행렬 뺄셈 결과\n" << "--------------\n";
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
		cout << "행렬 나눗셈 결과\n" << "--------------\n";
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
		cout << "행렬 곱셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->result[i][j] = num[i][j] * arr.num[i][j];
				this->num[i][j] = result[i][j];
			}
		}
		return (*this);
	}
};

// 3 X 1 벡터
class vec3 {
public:
	double vec[3];
	double result[3];

	vec3(int a, int b, int c) { // 생성자 오버로딩(int), 3 X 1 행렬에 값을 넣는다.
		 int arr[] = { a, b, c };

		for (int i = 0; i < 3; i++) {
			vec[i] = arr[i];
			result[i] = 0;
		}
	}

	vec3(double a, double b, double c) { // 생성자 오버로딩(double), 3 X 1 행렬에 값을 넣는다.
		 double arr[] = { a, b, c };

		for (int i = 0; i < 3; i++) {
			vec[i] = arr[i];
			result[i] = 0;
		}
	}

	vec3& operator+(vec3 arr) { 
		cout.width(5);
		cout << "벡터 덧셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) { 
			this->result[i] = vec[i] + arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec3& operator-(vec3 arr) {
		cout.width(5);
		cout << "벡터 뺄셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i] = vec[i] - arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec3& operator/(vec3 arr) {
		cout.width(5);
		cout << "벡터 나눗셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i] = vec[i] / arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec3& operator*(vec3 arr) { 
		cout.width(5);
		cout << "벡터 곱셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i] = vec[i] * arr.vec[i];
			this->vec[i] = result[i];
		} 
		return (*this); 
	}

	vec3& operator*(mat3 arr) {
		cout.width(5);
		cout << "벡터, 행렬 곱셈 결과\n" << "--------------\n";
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

// 1 X 3 벡터
class vec1x3 {
public:
	double vec[3][1];
	double result[3][1];

	vec1x3(int a, int b, int c) { // 생성자 오버로딩(int), 1 X 3 행렬에 값을 넣는다.
		int arr[] = { a, b, c };

		for (int i = 0; i < 3; i++) {
			vec[i][0] = arr[i];
			result[i][0] = 0;
		}
	}

	vec1x3(double a, double b, double c) { // 생성자 오버로딩(double), 1 X 3 행렬에 값을 넣는다.
		double arr[] = { a, b, c };

		for (int i = 0; i < 3; i++) {
			vec[i][0] = arr[i];
			result[i][0] = 0;
		}
	}

	vec1x3& operator+(vec1x3 arr) {
		cout.width(5);
		cout << "벡터 덧셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = vec[i][0] + arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x3& operator-(vec1x3 arr) {
		cout.width(5);
		cout << "벡터 뺄셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = vec[i][0] - arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x3& operator/(vec1x3 arr) {
		cout.width(5);
		cout << "벡터 나눗셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = vec[i][0] / arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x3& operator*(vec1x3 arr) {
		cout.width(5);
		cout << "벡터 곱셈 결과\n" << "--------------\n";
		for (int i = 0; i < 3; i++) {
			this->result[i][0] = vec[i][0] * arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x3& operator*(mat3 arr) {
		cout.width(5);
		cout << "벡터 전치 곱셈 결과\n" << "--------------\n";
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

// 4 X 1 행렬
class vec4 {
public:
	double vec[4];
	double result[4];

	vec4(int a, int b, int c, int d) { // 생성자 오버로딩(int), 4 X 1 행렬에 값을 넣는다.
		int arr[] = { a, b, c, d };

		for (int i = 0; i < 4; i++) {
			vec[i] = arr[i];
			result[i] = 0;
		}
	}

	vec4(double a, double b, double c, double d) { // 생성자 오버로딩(double), 4 X 1 행렬에 값을 넣는다.
		double arr[] = { a, b, c, d };

		for (int i = 0; i < 4; i++) {
			vec[i] = arr[i];
			result[i] = 0;
		}
	}

	vec4& operator+(vec4 arr) {
		cout.width(5);
		cout << "벡터 덧셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i] = vec[i] + arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec4& operator-(vec4 arr) {
		cout.width(5);
		cout << "벡터 뺄셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i] = vec[i] - arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec4& operator/(vec4 arr) {
		cout.width(5);
		cout << "벡터 나눗셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i] = vec[i] / arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec4& operator*(vec4 arr) {
		cout.width(5);
		cout << "벡터 곱셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i] = vec[i] * arr.vec[i];
			this->vec[i] = result[i];
		}
		return (*this);
	}

	vec4& operator*(mat4 arr) {
		cout.width(5);
		cout << "벡터, 행렬 곱셈 결과\n" << "--------------\n";
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

// 1 X 4 벡터
class vec1x4 {
public:
	double vec[4][1];
	double result[4][1];

	vec1x4(int a, int b, int c, int d) { // 생성자 오버로딩(int), 1 X 4 행렬에 값을 넣는다.
		int arr[] = { a, b, c, d };

		for (int i = 0; i < 4; i++) {
			vec[i][0] = arr[i];
			result[i][0] = 0;
		}
	}

	vec1x4(double a, double b, double c, double d) { // 생성자 오버로딩(double), 1 X 4 행렬에 값을 넣는다.
		double arr[] = { a, b, c, d };

		for (int i = 0; i < 4; i++) {
			vec[i][0] = arr[i];
			result[i][0] = 0;
		}
	}

	vec1x4& operator+(vec1x4 arr) {
		cout.width(5);
		cout << "벡터 덧셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = vec[i][0] + arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x4& operator-(vec1x4 arr) {
		cout.width(5);
		cout << "벡터 뺄셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = vec[i][0] - arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x4& operator/(vec1x4 arr) {
		cout.width(5);
		cout << "벡터 나눗셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = vec[i][0] / arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x4& operator*(vec1x4 arr) {
		cout.width(5);
		cout << "벡터 곱셈 결과\n" << "--------------\n";
		for (int i = 0; i < 4; i++) {
			this->result[i][0] = vec[i][0] * arr.vec[i][0];
			this->vec[i][0] = result[i][0];
		}
		return (*this);
	}

	vec1x4& operator*(mat4 arr) {
		cout.width(5);
		cout << "벡터 전치 곱셈 결과\n" << "--------------\n";
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