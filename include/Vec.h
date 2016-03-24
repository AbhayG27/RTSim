#pragma once
template<class d_type>
class Vec3
{
public:
	d_type dat[3];
	Vec3<d_type>()
	{
		dat[0] = 0;
		dat[1] = 0;
		dat[2] = 0;
	}
	Vec3<d_type>(d_type a, d_type b, d_type c)
	{
		dat[0] = a;
		dat[1] = b;
		dat[2] = c;
	}
	d_type dot(Vec3<d_type> inp)
	{
		return inp.dat[0] * dat[0] + inp.dat[1] * dat[1] + inp.dat[2] * dat[2];
	}
	Vec3<d_type> cross(Vec3<d_type> inp)
	{
		Vec3<d_type> ret;
		ret.dat[0] = dat[1] * inp.dat[2] - dat[2] * inp.dat[1];
		ret.dat[1] = -(dat[0] * inp.dat[2] - dat[2] * inp.dat[0]);
		ret.dat[2] = dat[0] * inp.dat[1] - dat[1] * inp.dat[0];
		return ret;
	}
	Vec3<d_type> operator=(Vec3<d_type>& inp)
	{
		dat[0] = inp.dat[0];
		dat[1] = inp.dat[1];
		dat[2] = inp.dat[2];
		return this;
	}
	Vec3<d_type> operator-(Vec3<d_type> inp)
	{
		Vec3<d_type> ret;
		ret.dat[0]= dat[0] - inp.dat[0];
		ret.dat[1]= dat[1] - inp.dat[1];
		ret.dat[2]= dat[2] - inp.dat[2];
		return ret;
	}
	Vec3<d_type>& operator*(d_type scale)
	{
		return Vec3<d_type>(dat[0] * scale, dat[1] * scale, dat[2] * scale);
	}
};
template<class d_type>
class Vec2
{
public:
	d_type dat[2];
	d_type dot(Vec2<d_type> inp)
	{
		return inp.dat[0] * this.dat[0] + inp.dat[1] * this.dat[1];
	}
	Vec2<d_type>& operator=(Vec2<d_type>& inp)
	{
		this.dat[0] = inp.dat[0];
		this.dat[1] = inp.dat[1];
		return this;
	}
};