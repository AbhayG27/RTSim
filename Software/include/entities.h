#pragma once
#include <common.h>
#include <mem.h>
#include <Vec.h>
//common business layer and data layer entities
struct boundingVol;
struct triangle;
struct ray;
struct precomputedRay;
//Only data layer specific entities
struct leafNode;
struct treeNode;
//entity definitions
struct boundingVol
{
	static Vec3<TYPE> planeNorms[7];
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
	Vec3<TYPE> precomp[14];
};

struct leafNode
{
	boundingVol bVol;
	mem_addr_t triangles;
	int numTriangles;
	short isLeaf;
};

struct treeNode
{
	boundingVol bVol;
	mem_addr_t children;
	int numChildren;
	short isLeaf;
};

