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

    Vector(float a, float b, float c) { // 빈 벡터 생성자
        x = a;
        y = b;
        z = c;
    }
};

class Matrix {
public:
    float element[3][3];
    Matrix() { 
        // 행렬 생성자, 행렬을 0으로 초기화시킨다.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                element[i][j] = 0;
            }
        }
    }

    Matrix(float a, float b, float c, float d, float e, float f, float g, float h, float i) { 
        // 행렬 생성자, 받아온 값을 이중 for문을 통해 element에 넣는다.
        float saveArr[9] = { a, b, c, d, e, f, g, h, i };
        int saveArr_num = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                element[i][j] = saveArr[saveArr_num++];
            }
        }
    }

    Matrix operator *(Matrix& m) // 행렬 X 행렬 오버로딩
    {
        // 행렬과 행렬의 곱을 구현하여 임시 저장 행렬인 result에 값을 넣고, 다시 element에 값을 넣어 해당 값을 반환한다.
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

    Vector operator *(Vector& v) {  // 행렬 X 벡터 오버로딩
         // 행렬과 벡터의 곱을 구현하여 임시 저장 벡터인 nv에 값을 넣고, 해당 값을 반환한다.
        Vector nv;
        nv.x = element[0][0] * v.x + element[0][1] * v.y + element[0][2] * v.z;
        nv.y = element[1][0] * v.x + element[1][1] * v.y + element[1][2] * v.z;
        return nv;
    }
};
