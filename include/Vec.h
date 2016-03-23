#pragma once
template<class d_type>
class Vec3
{
public:
	d_type dat[3];
	d_type dot(Vec3<d_type> inp)
	{
		return inp.dat[0] * this.dat[0] + inp.dat[1] * this.dat[1] + inp.dat[2] * this.dat[2];
	}
	Vec3<d_type> cross(Vec3<d_type> inp)
	{
		Vec3<d_type> ret;
		ret.dat[0] = this.dat[1] * inp.dat[2] - *this.dat[2] * inp.dat[1];
		ret.dat[1] = -(this.dat[0] * inp.dat[2] - *this.dat[2] * inp.dat[0]);
		ret.dat[2] = this.dat[0] * inp.dat[1] - *this.dat[1] * inp.dat[0];
		return ret;
	}
	Vec3<d_type>& operator=(Vec3<d_type>& inp)
	{
		this.dat[0] = inp.dat[0];
		this.dat[1] = inp.dat[1];
		this.dat[2] = inp.dat[2];
		return this;
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