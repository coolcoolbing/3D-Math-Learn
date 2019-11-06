#pragma once

////////////////////////////////////////
//
//3Dͼ��ѧ����������ࡣ�Լ�ʵ��
//
////////////////////////////////////////
class Vector3
{
public:
	float x, y, z;

	Vector3();
	~Vector3();
	//���ƹ��캯��
	Vector3(const Vector3 &a) :x(a.x),y(a.y),z(a.z){}
	//��ʼ������ֵ�Ĺ��캯��
	Vector3(float nx, float ny, float nz):x(nx),y(ny),z(nz) {}

	//���ظ�ֵ
	Vector3 &operator =(const Vector3 &a){
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	//������ȱȽϡ�ĩβconst����˼�ǳ��������������޸Ķ��������ֵ��ֻ���������б����constҲ��ֻ�������޸ĵ���˼
	bool operator==(const Vector3 &a)const {
		return x == a.x&y == a.y&&z == a.z;
	}

	//���ز���ȱȽ�
	bool operator!=(const Vector3 &a)const {
		return x != a.x || y != a.y || z != a.z;
	}

	//��������

	//��Ϊ������.����������ֵȫΪ0������
	void zero() {
		x = y = z = 0;
	}

	//�为����
	Vector3 operator-()const {
		return Vector3(-x, -y, -z);
	}



};



Vector3::Vector3()
{
}


Vector3::~Vector3()
{
}
