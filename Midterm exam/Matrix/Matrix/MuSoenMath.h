#pragma once
#include <iostream>
using namespace std;

class mat3 {
public:
	float num[3][3];

	mat3(float a, float b, float c, // 3 X 3 행렬 생성 함수
		float d, float e, float f,
		float g, float h, float i) {

		//int arr[] = { a, b, c, d, e, f, g, h, i }; // 행렬 안에 들어갈 매개변수를 배열로 선언
		//int arr_num = 0; // 3 X 3 배열 안에 값을 쉽게 넣기 위한 변수

		num[0][0] = a; num[0][1] = b; num[0][2] = c; // 배열에 순차적으로 매개변수를 넣어줌
		num[1][0] = d; num[1][1] = e; num[1][2] = f;
		num[2][0] = g; num[2][1] = h; num[2][2] = i;

		//for (int i = 0; i < 3; i++) { // 이중 for문으로 3 X 3 배열 생성
		//	for (int j = 0; j < 3; j++) {
		//		num[j][i] = arr[arr_num++]; 
		//	}
		//}
	}
};

class vec3 {
public:
	float vec[3];
	float vm[3]; // 곱해진 값을 임시 배열에 저장한다.

	vec3(float a, float b, float c) { // 3 X 1 행렬 생성 함수
		//int arr[] = { a, b, c }; // 행렬 안에 들어갈 매개변수를 배열로 선언
		//int arr_num = 0; // 1 X 3 배열 안에 값을 쉽게 넣기 위한 변수

			vec[0] = a; // 배열에 순차적으로 매개변수를 넣어줌
			vec[1] = b;
			vec[2] = c;
		
	}

	vec3& operator*(mat3 arr) { // 행렬곱 구현 함수

		this->vm[0] = vec[0] * arr.num[0][0] + vec[1] * arr.num[1][0] + vec[2] * arr.num[2][0]; // 곱한 값을 배열(연산 결과 배열)에 저장해줌
		this->vm[1] = vec[0] * arr.num[0][1] + vec[1] * arr.num[1][1] + vec[2] * arr.num[2][1];
		this->vm[2] = vec[0] * arr.num[0][2] + vec[1] * arr.num[1][2] + vec[2] * arr.num[2][2];

		this->vec[0] = vm[0];
		this->vec[1] = vm[1];
		this->vec[2] = vm[2];

		//for (int i = 0; i < 3; i++) { // 이중 for문으로 3 X 1과 3 X 3 행렬곱 시행
		//	for (int j = 0; j < 3; j++) {
		//		result.vec[i] += vec[j] * arr.num[j][i]; 
		//	}
		//}
		return (*this); // 곱한 결괏값을 반환함.
	}

	friend std::ostream& operator << (std::ostream& out, const vec3& point) { // 출력 연산자 오버로딩
		out << "( " << point.vec[0] << ", " << point.vec[1] << ", " << point.vec[2] << " )"; // 출력
		return out; // 출력값을 반환함.
	}
};