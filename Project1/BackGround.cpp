#include <glut.h>
#include "BackGround.h"
#include "Define.h"

void BackGround::draw() {   //�w�i�̕`��
    // �s���͗l
    int i, j;
    int loopNum = 33;       //�c�E���̃}�X�̐�
    int count = 0;
    glColor4f(0.3f, 0.0f, 0.5f, 1.0f);
    for (i = 0; i < loopNum; i++) {
        for (j = 0; j < loopNum; j++) {
            if (count % 2 == 0) {       //2��Ɉ��l�p�`��`��
                drawSquare(i * squareSize, j * squareSize);
            }
            count++;
        }
        if (loopNum % 2 == 0) {
            count++;//����Ŏs���͗l�ɂȂ�
        }
    }
    //�t�B�[���h����
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2i(fieldX1, fieldY1);
    glVertex2i(fieldX2, fieldY1);
    glVertex2i(fieldX2, fieldY2);
    glVertex2i(fieldX1, fieldY2);
    glEnd();
}

/*
@brief �����`��`�悷�邽�߂̊֐�
@param x �ʒux
@param y �ʒuy
*/
void BackGround::drawSquare(int x, int y) {
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + squareSize, y);
    glVertex2i(x + squareSize, y + squareSize);
    glVertex2i(x, y + squareSize);
    glEnd();
}