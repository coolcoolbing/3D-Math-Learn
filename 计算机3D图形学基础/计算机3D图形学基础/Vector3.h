#pragma once

////////////////////////////////////////
//
//3D图形学里面的向量类。自己实现
//
////////////////////////////////////////
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

	//重载赋值
	Vector3 &operator =(const Vector3 &a){
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	//重载相等比较。末尾const的意思是常函数，即不能修改对象里面的值，只读。参数列表里的const也是只读不可修改的意思
	bool operator==(const Vector3 &a)const {
		return x == a.x&y == a.y&&z == a.z;
	}

	//重载不相等比较
	bool operator!=(const Vector3 &a)const {
		return x != a.x || y != a.y || z != a.z;
	}

	//向量运算

	//置为零向量.零向量就是值全为0的向量
	void zero() {
		x = y = z = 0;
	}

	//变负向量
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
