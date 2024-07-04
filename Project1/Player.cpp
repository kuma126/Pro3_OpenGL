#include <complex>
#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"
#include "SystemMain.h"

Player::Player() : x(0.0), y(0.0), z(-20.0), angleY(-M_PI / 2), speed(0.0), speedMax(0.8), accel(0.01), handling(0.2 * M_PI / 360), handleAngle(0.0), handleAngleMax(8 * M_PI / 360) {

}

void Player::draw() {
    glPushMatrix(); {
        GLfloat mat0ambi[] = { 0.329412,  0.223529, 0.027451, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
        GLfloat mat0diff[] = { 0.780392,  0.568627, 0.113725, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
        GLfloat mat0spec[] = { 0.992157,  0.941176, 0.807843, 1.0 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
        GLfloat mat0shine[] = { 27.89743616 };//�^�J
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //���@�̕`��
        glTranslatef(x, y, z); //�ʒu�ϐ������ƂɈړ�
        glRotatef(angleY * (180 / M_PI), 0.0, 1.0, 0.0);  //Y���܂���angleY(���W�A��)��]
        glutSolidTeapot(1.0);            //���@�̓e�B�[�|�b�g(��)
    }glPopMatrix();

    glPushMatrix(); {       //�n���h��
        GLfloat mat0ambi[] = { 0.1,  0.1, 0.1, 1.0 };//����
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0ambi); //�����̔��˗���ݒ�
        GLfloat mat0diff[] = { 0.1,  0.1, 0.1, 1.0 };//����
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0diff); //�g�U���̔��˗���ݒ�
        GLfloat mat0spec[] = { 0.1,  0.1, 0.1, 1.0 };//����
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0spec); //���ʌ��̔��˗���ݒ�
        GLfloat mat0shine[] = { 27.89743616 };//����
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0shine);
        //�n���h���̕`��
        glTranslatef(x, y + 1, z); //�ʒu�ϐ������ƂɈړ�
        glRotatef(angleY * (180 / M_PI) + 90, 0.0, 1.0, 0.0);  //Y�������angleY(���W�A��)��]
        glRotatef(HandelRate * -handleAngle * (180 / M_PI), 0.0, 0.0, 1.0);  //Z�������angleY(���W�A��)��]
        glutSolidTorus(0.2, 0.7, 5, 20);            //�n���h���̊O��
        glutSolidTorus(0.2, 0.0, 5, 10);            //�n���h���̒��S
        glPushMatrix(); {
            glTranslatef(0.3 * cos(M_PI / 2), 0.3 * sin(M_PI / 2), 0.0); //�n���h���̒��g1
            glRotatef(90, 0.0, 0.0, 1.0);
            glScalef(0.6, 0.2, 0.2);
            glutSolidCube(0.8);
        }glPopMatrix();
        glPushMatrix(); {
            glTranslatef(0.3 * cos(7 * M_PI / 6), 0.3 * sin(7 * M_PI / 6), 0.0); //�n���h���̒��g2
            glRotatef(210, 0.0, 0.0, 1.0);
            glScalef(0.6, 0.2, 0.2);
            glutSolidCube(0.8);
        }glPopMatrix();
        glPushMatrix(); {
            glTranslatef(0.3 * cos(11 * M_PI / 6), 0.3 * sin(11 * M_PI / 6), 0.0); //�n���h���̒��g2
            glRotatef(330, 0.0, 0.0, 1.0);
            glScalef(0.6, 0.2, 0.2);
            glutSolidCube(0.8);
        }glPopMatrix();
    }glPopMatrix();
}

void Player::update() {
    //�n���h����]
    if (SystemMain::getIns()->key.getKeyLeftON()) {
        handleAngle += handling;
    }
    if (SystemMain::getIns()->key.getKeyRightON()) {
        handleAngle -= handling;
    }
    if (handleAngle > handleAngleMax) {
        handleAngle = handleAngleMax;
    }
    if (handleAngle < -handleAngleMax) {
        handleAngle = -handleAngleMax;
    }
    //�A�N�Z��
    if (SystemMain::getIns()->key.getKeyUpON()) {
        speed += accel;
    }
    if (SystemMain::getIns()->key.getKeyDownON()) {
        speed -= accel;
    }
    speed -= 0.004;       //�������Ȃ��Ă����x�͌���
    if (speed > speedMax) {
        speed = speedMax;
    }
    if (speed < 0) {
        speed = 0;
    }
    if (speed > 0) {
        angleY += speed * handleAngle;
        x += speed * cos(angleY);
        z += speed * -sin(angleY);
    }
    else if (speed < 0){
        angleY -= speed * handleAngle;
        x += abs(speed) * -cos(angleY);
        z += abs(speed) * sin(angleY);
    }

    //�J�����ʒu�̍X�V
    SystemMain::getIns()->camera.setX(x - 15 * cos(angleY));
    SystemMain::getIns()->camera.setY(y + 2.5);
    SystemMain::getIns()->camera.setZ(z + 15 * sin(angleY));
}