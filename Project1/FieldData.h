#pragma once
class FieldData
{
public:
	FieldData();
	virtual ~FieldData() = default;
	void draw();
	void setField(int x, int y, int value) { field[x][y] = value; }
	int getField(int x, int y) { return field[x][y]; }
private:
	const double brank = 8.0;
	int field[8][16];				// �Ֆʏ��
	double randValue[8][16][2];        //���Ƃł���
	double randValueVel[8][16][2];
};

