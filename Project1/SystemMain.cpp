#include <glut.h>
#include "SystemMain.h"
#include "Define.h"

void SystemMain::lightInit(void) {
    glEnable(GL_LIGHTING);  //�����̐ݒ��L���ɂ���
    glEnable(GL_LIGHT0);    //0�Ԗڂ̌�����L���ɂ���(8�܂Őݒ�\)
    glEnable(GL_NORMALIZE); //�@���x�N�g���̎������K����L��

    glShadeModel(GL_SMOOTH); //�X���[�Y�V�F�[�f�B���O�ɐݒ�

}

void SystemMain::display() {
    SystemMain::getIns()->draw();
}

void SystemMain::reshape(int w, int h) {
    SystemMain::getIns()->reshapeFunc(w, h);
}

void SystemMain::timerFunc(int t)             // �w�莞�Ԍ�ɌĂяo�����֐��iTimer�R�[���o�b�N�֐��j
{
    SystemMain::getIns()->update();
}

void SystemMain::specialKey(int key, int x, int y)             // �w�莞�Ԍ�ɌĂяo�����֐��iTimer�R�[���o�b�N�֐��j
{
    SystemMain::getIns()->keyCall(key, x, y);
}

void SystemMain::draw() {
    glClearColor(0.1, 0.1, 0.1, 1.0); // ��ʃN���A
    glClear(GL_COLOR_BUFFER_BIT);

    view2D();
    backGround.draw();


    GLfloat  light_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    view3D();
    gluLookAt(7.0, 16.0, 70.0, 7.0, 16.0, 0.0, 0.0, 1.0, 0.0);
    fieldData.draw();

    glutSwapBuffers(); // �o�b�t�@�̐؂�ւ�


}

void SystemMain::reshapeFunc(int w, int h) // �E�C���h�E�T�C�Y�ύX���ɌĂяo�����֐��iReshape�R�[���o�b�N�֐��j
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / h, 1.0, 100.0); // �������e
    winH = h;
    winW = w;
}

void SystemMain::view2D() {
    glMatrixMode(GL_PROJECTION);// �ˉe�ϊ��s��ݒ�
    glLoadIdentity();// �P�ʍs���ݒ�
    glOrtho(0, Define::WIN_W, Define::WIN_H, 0, -1, 1);// ���ˉe�ϊ��ݒ�
    glMatrixMode(GL_MODELVIEW);// ���f���r���[�ϊ��s��ݒ�
    glLoadIdentity();// �P�ʍs���ݒ�
    glDisable(GL_LIGHTING); // ���C�e�B���O�𖳌���
}

void SystemMain::view3D() {
    glEnable(GL_LIGHTING); // ���C�e�B���O��L����
    glMatrixMode(GL_PROJECTION);// �ˉe�ϊ��s��ݒ�
    glLoadIdentity();
    gluPerspective(30.0, (double)winW / winH, 1.0, 100.0); // �������e
    glMatrixMode(GL_MODELVIEW);// ���f���r���[�ϊ��s��ݒ�
    glLoadIdentity();// �P�ʍs���ݒ�
}

void SystemMain::update() {
    //�`��˗�
    glutPostRedisplay();
    //���^�C�}�[�o�^
    glutTimerFunc(30, SystemMain::getIns()->timerFunc, 0);
}

void SystemMain::keyCall(int key, int x, int y) {
    this->key.specialKey(key, x, y);
}