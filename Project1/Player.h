#pragma once

class Player
{
public:
	Player();
	virtual ~Player() = default;
	void update();
	void draw();
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
private:
	const int HandelRate = 130;		//��������̃n���h���̉�]���x
	double accel;			// �A�N�Z��(�����x)
	double speed;			// ����
	double speedMax;		// �ő呬�x
	double handling;		// �n���h����]�X�s�[�h
	double x, y, z;
	double angleY;			// Y���̉�]��(���W�A��)
	double handleAngle;		// �n���h���̉�]��
	double handleAngleMax;	// �n���h���̍ő��]�p
};

