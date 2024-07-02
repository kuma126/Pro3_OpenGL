#include <time.h>
#include <stdlib.h>
#include <glut.h>
#include "FieldData.h"

FieldData::FieldData() {
	int i, j;
    srand((unsigned int)time(NULL));        // �ՖʂɃf�[�^�������_���Őݒu
	for (i = 0; i < 8; i++) {               // �Ֆʂ̏�����
		for (j = 0; j < 16; j++) {
            if (j > 8) {
                field[i][j] = 0;
            }
            else {
                field[i][j] = (rand() % 4);
            }
            randValue[i][j][0] = 0;
            randValue[i][j][1] = 0;
		}
	}
}

void FieldData::draw() {
    int i, j;
    int tmpX, tmpY;
    static const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
    static const GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };
    static const GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
    static const GLfloat blue[] = { 0.0, 0.0, 1.0, 1.0 };
    /*���ꂼ��̔Ֆʂ̏�Ԃ��󂯎��`��*/
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 16; j++) {
            switch (field[i][j]) {
            case 0:
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
                break;
            case 1://�ԃJ�v�Z��
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
                break;
            case 2://���J�v�Z��
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, yellow);
                break;
            case 3://�J�v�Z��
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
                break;
            default:
                break;
            }
            glPushMatrix(); {
                //�}�`�̐F (��)
                static const GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 };
                randValue[i][j][0] += 0.0007 * ((rand() % 11) - 5);
                randValue[i][j][1] += 0.0007 * ((rand() % 11) - 5);
                if (randValue[i][j][0] > 0.01) {
                    randValue[i][j][0] = 0.01;
                }
                if (randValue[i][j][1] > 0.01) {
                    randValue[i][j][1] = 0.01;
                }
                if (randValue[i][j][0] < -0.01) {
                    randValue[i][j][0] = -0.01;
                }
                if (randValue[i][j][1] > -0.01) {
                    randValue[i][j][1] = -0.01;
                }

                glTranslatef((i * 2 + randValue[i][j][0]), (j * 2 + randValue[i][j][0]), 0.0);
                glutSolidSphere(0.95, 50, 50);
            }glPopMatrix();
        }
    }
}