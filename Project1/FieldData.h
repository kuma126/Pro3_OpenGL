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
	int field[8][16];				// �Ֆʏ��
	float randValue[8][16][2];        //���Ƃł���
};

