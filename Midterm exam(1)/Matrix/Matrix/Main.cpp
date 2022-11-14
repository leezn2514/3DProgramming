#include <iostream> // ����� ���� �Լ�
#include <math.h> // �ﰢ�Լ��� ���� ���� ���� �������
#include "MuSoenMath.h" // MuSoenMath.h ������ �ҷ���


	void main() {
		float radius = 30;
		float scale = 2;

		// (3, 5) �̵�
		mat3 Translate = mat3(1, 0, 0, // MuSoenMath.h ��� ���� ���� mat3 Ŭ������ ������ 3 X 3 ��Ŀ� ���� �־���
							  0, 1, 0,
							  3, 5, 1);

		// 30�� ȸ��
		mat3 Rotate = mat3(cos(radius * (3.14 / 180)), -sin(radius * (3.14 / 180)), 0, // ȣ������ ����� ������ ������ (PI / ����)
						   sin(radius * (3.14 / 180)), cos(radius * (3.14 / 180)), 0,
						   0, 0, 1);

		// 2�� ����
		mat3 Scale = mat3(scale, 0, 0,
						  0, scale, 0,
						  0, 0, 1);

		vec3 v(1, 1, 1); // v�� �⺻ ��ǥ��
		vec3 p(0, 0, 0); // ����� ���� ������ ����

		p = v * Translate * Rotate * Scale;

		cout << p; // ����� �� ���
}



