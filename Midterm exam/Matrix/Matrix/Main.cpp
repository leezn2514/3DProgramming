#include <iostream> // 입출력 관련 함수
#include <math.h> // 삼각함수를 위한 수학 관련 헤더파일
#include "MuSoenMath.h" // MuSoenMath.h 파일을 불러옴


	void main() {
		float radius = 30;
		float scale = 2;

		// (3, 5) 이동
		mat3 Translate = mat3(1, 0, 0, // MuSoenMath.h 헤더 파일 내의 mat3 클래스를 선언해 3 X 3 행렬에 값을 넣어줌
							  0, 1, 0,
							  3, 5, 1);

		// 30도 회전
		mat3 Rotate = mat3(cos(radius * (3.14 / 180)), -sin(radius * (3.14 / 180)), 0, // 호도법을 사용해 각도를 구해줌 (PI / 각도)
						   sin(radius * (3.14 / 180)), cos(radius * (3.14 / 180)), 0,
						   0, 0, 1);

		// 2배 증가
		mat3 Scale = mat3(scale, 0, 0,
						  0, scale, 0,
						  0, 0, 1);

		vec3 v(1, 1, 1); // v의 기본 좌표값
		vec3 p(0, 0, 0); // 연산된 값을 저장할 변수

		p = v * Translate * Rotate * Scale;

		cout << p; // 연산된 값 출력
}



