#include<stdio.h>
#include <glut.h>
#include "Key.h"

void Key::specialKey(int key, int x, int y)
{
	//�L�[���͍͂\���̂Ɉꎞ�ۑ����Ă���
	this->x = x;	//�}�E�Xx
	this->y = y;	//�}�E�Xy

	switch (key) {
	case GLUT_KEY_UP:
		printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		this->c = 's';
		break;
	case GLUT_KEY_DOWN:
		printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		this->c = 'x';
		break;
	case GLUT_KEY_LEFT:
		printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		this->c = 'z';
		break;
	case GLUT_KEY_RIGHT:
		printf("(%3d,%3d)��[��]��������܂���\n", x, y);
		this->c = 'c';
		break;
	}
}