#include <iostream>

using std::cout, std::endl, std::string;

class Vector
{
private:
    float x {1.0}, y {1.0}, z {1.0};
    
public:
    float get_x() const {return x;};
    float get_y() const {return y;};
    float get_z() const {return z;};
    string name {"Unknown"}; 

    Vector() = default;

    Vector(float _x, float _y, float _z) : x{_x}, y {_y}, z {_z} {};
    
	friend std::ostream& operator << (std::ostream& stream, const Vector& v);
	friend Vector 	operator + (const Vector& v_1, const Vector&   v_2);
	friend Vector 	operator + (const Vector& v_1, const float     var);
	friend Vector 	operator + (const float   var, const Vector&   v_1);

	friend Vector& 	operator + (Vector& v_1, const string   _name);

	friend int 		operator > (const Vector& v_1, const Vector& v_2);
};

Vector operator + (const Vector& v_1, const Vector& v_2)
{
	Vector v_3 {v_1.x + v_2.x, v_1.y + v_2.y, v_1.z + v_2.z};
	return v_3;
}

Vector operator + (const Vector& v_1, const float var)
{
	Vector v_3 {v_1.x + var, v_1.y + var, v_1.z + var};
	return v_3;
}

Vector operator + (const float var, const Vector& v_1)
{
	Vector v_3 {v_1.x + var, v_1.y + var, v_1.z + var};
	return v_3;
}

std::ostream& operator << (std::ostream& stream, const Vector& v)
{
	stream << v.name << ": " << v.get_x() << ", " << v.get_y() << ", " << v.get_z() << endl;
	return stream;
}

int operator > (const Vector& v_1, const Vector& v_2)
{
	if ((v_1.x * v_1.x + v_1.y * v_1.y + v_1.z * v_1.z) > (v_2.x * v_2.x + v_2.y * v_2.y + v_2.z * v_2.z)) {
		return 1;
	} else {
		return 0;
	}
}

Vector& operator + (Vector& v_1, string _name)
{
	if (v_1.name == "Unknown") {
		v_1.name = _name;
	} else {
		v_1.name = v_1.name + " " + _name;
	}
	return v_1;	
}
