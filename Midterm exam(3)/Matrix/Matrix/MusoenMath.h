#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Vector {
public:
    float x, y, z;

    Vector() {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector(float a, float b, float c) { // �� ���� ������
        x = a;
        y = b;
        z = c;
    }
};

class Matrix {
public:
    float element[3][3];
    Matrix() { 
        // ��� ������, ����� 0���� �ʱ�ȭ��Ų��.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                element[i][j] = 0;
            }
        }
    }

    Matrix(float a, float b, float c, float d, float e, float f, float g, float h, float i) { 
        // ��� ������, �޾ƿ� ���� ���� for���� ���� element�� �ִ´�.
        float saveArr[9] = { a, b, c, d, e, f, g, h, i };
        int saveArr_num = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                element[i][j] = saveArr[saveArr_num++];
            }
        }
    }

    Matrix operator *(Matrix& m) // ��� X ��� �����ε�
    {
        // ��İ� ����� ���� �����Ͽ� �ӽ� ���� ����� result�� ���� �ְ�, �ٽ� element�� ���� �־� �ش� ���� ��ȯ�Ѵ�.
        Matrix ResultMat(element[0][0], element[0][1], element[0][2], element[1][0], element[1][1], element[1][2], element[2][0], element[2][1], element[2][2]); 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                float result = 0;
                for (int k = 0; k < 3; k++) {
                    result += element[i][k] * m.element[k][j];
                }
                ResultMat.element[i][j] = result;
            }
        }
        return ResultMat;
    }

    Vector operator *(Vector& v) {  // ��� X ���� �����ε�
         // ��İ� ������ ���� �����Ͽ� �ӽ� ���� ������ nv�� ���� �ְ�, �ش� ���� ��ȯ�Ѵ�.
        Vector nv;
        nv.x = element[0][0] * v.x + element[0][1] * v.y + element[0][2] * v.z;
        nv.y = element[1][0] * v.x + element[1][1] * v.y + element[1][2] * v.z;
        return nv;
    }
};
