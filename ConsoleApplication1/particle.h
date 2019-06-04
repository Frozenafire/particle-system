#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
//#include <GLAUX.H>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <gl/glut.h>
#include <math.h>

struct Particle
{
	int r, g, b;//粒子颜色
	float x, y, z;//粒子位置
	float xv, yv, zv;//粒子移动速度
	float xa, ya, za;//粒子移动加速度
	float size;//粒子尺寸
	float lifetime;//粒子剩余存在时间
	float fade;//粒子消亡速度
};

class CParticle
{
private:
	Particle* p;        /**< 粒子指针 */
	int pNum;           /**< 粒子数目 */

public:
	
						  
	int Create(long num);       /** 创建粒子数组 */

	/** 设置和获取颜色属性 */
	int SetColor(GLint r, GLint g, GLint b);
	int SetColor(GLint index, GLint r, GLint g, GLint b);
	int GetColor(GLint index, GLint &r, GLint &g, GLint &b);

	/** 设置和获取位置属性 */
	int SetPosition(GLfloat x, GLfloat y, GLfloat z);
	int SetPosition(GLint index, GLfloat x, GLfloat y, GLfloat z);
	int GetPosition(GLint index, GLfloat &x, GLfloat &y, GLfloat &z);
	
	/** 设置和获取速度属性 */
	int SetVelocity(GLfloat vx, GLfloat vy, GLfloat vz);
	int SetVelocity(GLint index, GLfloat vx, GLfloat vy, GLfloat vz);
	int GetVelocity(GLint index, GLfloat &vx, GLfloat &vy, GLfloat &vz);

	/** 设置和获取加速度属性 */
	int SetAcceleration(GLfloat ax, GLfloat ay, GLfloat az);
	int SetAcceleration(GLint index, GLfloat ax, GLfloat ay, GLfloat az);
	int GetAcceletation(GLint index, GLfloat &ax, GLfloat &ay, GLfloat &az);

	/** 设置和获取尺寸属性 */
	int SetSize(GLfloat size);
	int SetSize(GLint index, GLfloat size);
	int GetSize(GLint index, GLfloat &size);

	/** 设置和获取生命值属性 */
	int SetLifeTime(GLfloat lifetime);
	int SetLifeTime(GLint index, GLfloat lifetime);
	int GetLifeTime(GLint index, GLfloat &lifetime);

	/** 设置和获取消失速度属性 */
	int SetFade(GLfloat fade);
	int SetFade(GLint index, GLfloat fade);
	int GetFade(GLint index, GLfloat &fade);

	/** 获取粒子数组地址 */
	Particle *GetParticle() { return p; }

	/** 获得粒子的数目 */
	int GetNumOfParticle() { return pNum; }

	/** 获得粒子所有的属性 */
	int GetAll(int index,                        /** 下标索引 */
		GLint &r, GLint &g, GLint &b,            /** 粒子颜色 */
		GLfloat &x, GLfloat &y, GLfloat &z,      /** 粒子位置 */
		GLfloat &vx, GLfloat &vy, GLfloat &vz,   /** 粒子速度 */
		GLfloat &ax, GLfloat &ay, GLfloat &az,   /** 粒子加速度 */
		GLfloat &size,                           /** 粒子大小 */
		GLfloat &lifetime,                       /** 生命时间 */
		GLfloat &fade                            /** 消失速度 */
		);

	/** 设置粒子的所有属性 */
	int SetAll(int index,                      /** 下标索引 */
		GLint r, GLint g, GLint b,             /** 粒子颜色 */
		GLfloat x, GLfloat y, GLfloat z,       /** 粒子位置 */
		GLfloat vx, GLfloat vy, GLfloat vz,    /** 粒子速度 */
		GLfloat ax, GLfloat ay, GLfloat az,    /** 粒子加速度 */
		GLfloat size,                          /** 粒子大小 */
		GLfloat lifetime,                      /** 生命时间 */
		GLfloat fade                            /** 消失速度 */
		);
};