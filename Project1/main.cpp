#include <glut.h>
#include "SystemMain.h"
#include "Define.h"
//#define GL_SILENCE_DEPRECATION //MacOS�̏ꍇ�ŃG���[��\�������Ȃ��ꍇ
//#include <GLUT/glut.h> //MacOS�̏ꍇ
//#include <GL/glut.h> //Linux�̏ꍇ

//    GLUT ���g�p�������ɃR���\�[���E�C���h�E��\�����Ȃ�
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // GLUT������
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(Define::WIN_W, Define::WIN_H); // �E�B���h�E�T�C�Y�̎w��
    glutCreateWindow("PUZZLE");   // �\���E�B���h�E�쐬
    glutReshapeFunc(SystemMain::getIns()->reshape);       // Reshape�R�[���o�b�N�֐��̎w��
    glutDisplayFunc(SystemMain::getIns()->display);     // Display�R�[���o�b�N�֐��̎w��
    glutSpecialFunc(SystemMain::getIns()->specialKey);                    // ����L�[�R�[���o�b�N�֐��̎w��(�������Ƃ�)
    glutTimerFunc(30, SystemMain::getIns()->timerFunc, 0);  // ����I�ɌĂяo�����֐��̎w��

    SystemMain::getIns()->lightInit();   // �����̏����ݒ�(�܂Ƃ߂Ċ֐��ɂ��Ă��邾��)

    glutMainLoop();               // ���C�����[�v��
    return 0;
}