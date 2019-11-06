#pragma once

////////////////////////////////////////
//
//3D图形学里面的向量类。自己实现
//
////////////////////////////////////////
#include<math.h>
class Vector3
{
public:
	float x, y, z;

	Vector3();
	~Vector3();
	//复制构造函数
	Vector3(const Vector3 &a) :x(a.x),y(a.y),z(a.z){}
	//初始化三个值的构造函数
	Vector3(float nx, float ny, float nz):x(nx),y(ny),z(nz) {}

	//重载赋值.&表示直接引用而不是使用形参
	Vector3 &operator =(const Vector3 &a){
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	//重载相等比较。末尾const的意思是常函数，即不能修改对象里面的值，只读。参数列表里的const也是只读不可修改的意思
	bool operator==(const Vector3 &a)const {
		return x == a.x&&y == a.y&&z == a.z;
	}

	//重载不相等比较
	bool operator!=(const Vector3 &a)const {
		return x != a.x || y != a.y || z != a.z;
	}

	////////////
	//向量运算
	////////////
	//置为零向量.零向量就是值全为0的向量
	void zero() {
		x = y = z = 0;
	}

	//变负向量
	Vector3 operator-()const {
		return Vector3(-x, -y, -z);
	}

	//重载加法和减法
	Vector3 operator +(const Vector3 &a)const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	Vector3 operator-(const Vector3 &a)const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	//向量与标量的乘除法
	Vector3 operator*(float a)const {
		return Vector3(x*a, y*a, z*a);
	}
	Vector3 operator/(float a)const {
		if (a == 0) { throw __EXCEPTIONS; }
		float f = 1.0f / a;
		return Vector3(x / f, y / f, z / f);
	}

	//重载自反运算符
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

	//向量标准化和归一化
	void normalize() {
		float magsq = x * x + y * y + z * z;//求向量的模
		if (magsq > 0.0f) {
			float oneOverMag = 1.0f / sqrt(magsq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	//向量点乘。结果是一个标量
	float operator*(const Vector3 &a)const {
		return x * a.x + y * a.y + z * a.z;
	}

	//计算向量的模
	static float vectorMag(const Vector3 &a) {
		return sqrt(a.x*a.x + a.y * a.y + a.z * a.z);
	}

	//计算两个向量的叉乘
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
//非成员函数。其实可以写为静态函数
//
/////////////////
inline float vectorMag() {
	
}