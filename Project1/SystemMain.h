#pragma once
#include "Singleton.h"
#include "Key.h"
#include "FieldData.h"
#include "BackGround.h"

class SystemMain final : public Singleton<SystemMain>
{
public:
	SystemMain() = default;
	virtual ~SystemMain() = default;
	void lightInit();
	static void display();			// �R�[���o�b�N���邽�߂ɐÓI�֐��ɂ��Ă���
	static void reshape(int, int);
	static void timerFunc(int);		
	static void specialKey(int, int, int);
private:
	Key key;						//�L�[���͂�ێ�
	FieldData fieldData;
	BackGround backGround;
	int winH, winW;					// �E�B���h�E�T�C�Y��ێ�
	void view2D();					// �`���2D��
	void view3D();					// �`���3D��
	void update();					// ���t���[��(?)�s���鏈��
	void reshapeFunc(int, int);
	void draw();					// �`��p�̏���
	void keyCall(int, int, int);	// �L�[�{�[�h�C�x���g�̏���
};

