#pragma once

////////////////////////////////////////
//
//3Dͼ��ѧ����������ࡣ�Լ�ʵ��
//
////////////////////////////////////////
#include<math.h>
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

	//���ظ�ֵ.&��ʾֱ�����ö�����ʹ���β�
	Vector3 &operator =(const Vector3 &a){
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	//������ȱȽϡ�ĩβconst����˼�ǳ��������������޸Ķ��������ֵ��ֻ���������б����constҲ��ֻ�������޸ĵ���˼
	bool operator==(const Vector3 &a)const {
		return x == a.x&&y == a.y&&z == a.z;
	}

	//���ز���ȱȽ�
	bool operator!=(const Vector3 &a)const {
		return x != a.x || y != a.y || z != a.z;
	}

	////////////
	//��������
	////////////
	//��Ϊ������.����������ֵȫΪ0������
	void zero() {
		x = y = z = 0;
	}

	//�为����
	Vector3 operator-()const {
		return Vector3(-x, -y, -z);
	}

	//���ؼӷ��ͼ���
	Vector3 operator +(const Vector3 &a)const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	Vector3 operator-(const Vector3 &a)const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	//����������ĳ˳���
	Vector3 operator*(float a)const {
		return Vector3(x*a, y*a, z*a);
	}
	Vector3 operator/(float a)const {
		if (a == 0) { throw __EXCEPTIONS; }
		float f = 1.0f / a;
		return Vector3(x / f, y / f, z / f);
	}

	//�����Է������
	Vector3 &operator+=(const Vector3 &a) {
		x += a.x; y += a.y; z += a.z;
		return *this;
	}
	Vector3 &operator-=(const Vector3 &a) {
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}
	Vector3 &operator*=(float a) {
		x *= a; y *= a; z *= a;
		return *this;
	}
	Vector3 &operator/=(float a) {
		float o = 1.0f / a;
		x *= o; y *= a; z *= a;
		return *this;
	}

	//������׼���͹�һ��
	void normalize() {
		float magsq = x * x + y * y + z * z;//��������ģ
		if (magsq > 0.0f) {
			float oneOverMag = 1.0f / sqrt(magsq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	//������ˡ������һ������
	float operator*(const Vector3 &a)const {
		return x * a.x + y * a.y + z * a.z;
	}

	//����������ģ
	static float vectorMag(const Vector3 &a) {
		return sqrt(a.x*a.x + a.y * a.y + a.z * a.z);
	}

	//�������������Ĳ��
	static Vector3 crossProduct(const Vector3 &a, const Vector3 &b) {
		return Vector3(
			a.y*b.z - a.z*b.y,
			a.z*b.x - a.x*b.z,
			a.x*b.y - a.y*b.x
		);
	}


};

Vector3::Vector3()
{
}


Vector3::~Vector3()
{
}

/////////////////
//
//�ǳ�Ա��������ʵ����дΪ��̬����
//
/////////////////
inline float vectorMag() {
	
}