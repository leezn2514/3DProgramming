#include <iostream> // 입출력 관련 함수
#include <math.h> // 삼각함수를 위한 수학 관련 헤더파일
#include "MuSoenMath.h" // MuSoenMath.h 파일을 불러옴


	int main() {
		mat3 arr1 = mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
		mat4 arr2 = mat4(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);	
		vec1x3 vc = vec1x3(1, 2, 3);
		vec1x3 result = vec1x3(0, 0, 0);

		arr1.Transpose_matrix();

		//std::cout << result; // 연산된 값 출력
}





