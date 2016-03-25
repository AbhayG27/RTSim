#pragma once
#include <common.h>
#include <mem.h>
#include <Vec.h>
#define ROOT3 1.7321
//common business layer and data layer entities
struct boundingVol;
struct triangle;
struct ray;
struct precomputedRay;
//Only data layer specific entities
struct leafNode;
struct treeNode;
//entity definitions
static Vec3<TYPE> planeNorms[7] = {
	Vec3<TYPE>(1,0,0),
	Vec3<TYPE>(0,1,0),
	Vec3<TYPE>(0,0,1),
	Vec3<TYPE>(1 / ROOT3,1 / ROOT3,1 / ROOT3),
	Vec3<TYPE>(-1 / ROOT3,1 / ROOT3,1 / ROOT3),
	Vec3<TYPE>(-1 / ROOT3,-1 / ROOT3,1 / ROOT3),
	Vec3<TYPE>(1 / ROOT3,-1 / ROOT3,1 / ROOT3)
};
struct boundingVol
{
	Vec2<TYPE> planeD[7];
};
struct triangle
{
	Vec3<TYPE> vertices[3];
};

struct ray 
{
	Vec3<TYPE> orig, dir;
};

struct precomputedRay
{
	Vec2<TYPE> precomp[7];
};

struct leafNode
{
	mem_addr_t triangles;
	int numTriangles;
};

struct treeNode
{
	boundingVol bVol;
	mem_addr_t children;
	int numChildren;
};

