#include <cmath>
#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MuSoenMath.h"

#pragma comment(lib, "OpenGL32")
using namespace std;
chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;
GLFWwindow* window;
bool isFirstFrame = true;

struct Vertex // ������ ���� ����ü
{
    Vector pos; // ��ġ
    float r, g, b, a; // ����
};

struct Transform // �� ����ü
{
    Matrix translate; // ��ġ
    Matrix scale; // ũ��
    Matrix rotation; // ����
};

Vertex star[5];             // static mesh
Vertex transformedStar[5];  //ȭ�鿡 �׸� ������
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // ȭ�鿡 �׷��� ��

Transform transform;  //world ����� �� transform

float Xp = 1.01f;
float Xm = 0.99f;
float X = 1.0f;
bool if_scale = false;
float PI = 3.1415926;

Matrix translate_p(
    1, 0, 0.001,
    0, 1, 0,
    0, 0, 1
);

Matrix rotation_p(
    cos(PI / 180), -sin(PI / 180), 0,
    sin(PI / 180), cos(PI / 180), 0,
    0, 0, 1
);

Matrix scale_p(
    1.01, 0, 0,
    0, 1.01, 0,
    0, 0, 1
);

Matrix scale_m(
    0.99, 0, 0,
    0, 0.99, 0,
    0, 0, 1
);

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();

    //object������
    /// Star(������) ����
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {
        star[i].pos.x = sin(theta * (PI / 180)) * 0.5f;
        star[i].pos.y = cos(theta * (PI / 180)) * 0.5f;
        star[i].pos.z = 1.0f;

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;

        transformedStar[i] = star[i];

        i++;
    }

    // �� ����
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.x = -sin((float)theta * (PI / 180)) * 0.5;
        circle[theta].pos.y = cos((float)theta * (PI / 180)) * 0.5;
        circle[theta].pos.z = 1.0f;

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }

    //Ʈ������ �ʱ�ȭ (�⺻�� ����)
    transform.translate = Matrix(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
    transform.rotation = Matrix(
        cos(0.0f * (PI / 180)), -sin(0.0f * (PI / 180)), 0,
        sin(0.0f * (PI / 180)), cos(0.0f * (PI / 180)), 0,
        0, 0, 1
    );
    transform.scale = Matrix(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        transform.translate = transform.translate * translate_p;

        transform.rotation = transform.rotation * rotation_p;

        if (if_scale == false)
        {
            transform.scale = transform.scale * scale_p;
            X = X * Xp;
        }
        else if (if_scale == true)
        {
            transform.scale = transform.scale * scale_m;
            X = X * Xm;
        }

        if (X >= 1.3f)
        {
            if_scale = true;
        }
        else if (X <= 0.7f)
        {
            if_scale = false;
        }

        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = transform.translate * transform.rotation * transform.scale * circle[i].pos;
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = transform.translate * transform.rotation * transform.scale * star[i].pos;
        }

        //�� �ʱ�ȭ
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //���β�
        glLineWidth(7.0f);
        //������ �׸���
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        glEnd();

        //���׸���
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.x, transformedCircle[theta].pos.y, 0.0f);
        }
        glEnd();

        //ȭ�� ����
        glfwSwapBuffers(window);
        glfwPollEvents();

        //�����ð� ����
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;
    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();
    exit(EXIT_SUCCESS);
}