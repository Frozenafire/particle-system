#include "particle.h"

/***** ����һ������num��Ԫ�ص��������� *****/
int CParticle::Create(long num)
{
	/** ɾ��ԭ�������� */
	if (p)
		delete[]p;
	/** �������� */
	if (p = new Particle[num])
	{
		memset(p, 0, sizeof(Particle)*num);
		pNum = num;
		return pNum;     /** �������Ӹ��� */
	}
	return 0;
}

/**************** ��ɫ���� ******************/
int CParticle::SetColor(GLint r, GLint g, GLint b)
{
	for (int index = 0; index<pNum; index++)
	{
		p[index].r = r;
		p[index].g = g;
		p[index].b = b;
	}
	return true;
}

int CParticle::SetColor(GLint index, GLint r, GLint g, GLint b)
{
	if (index >= 0 && index<pNum)
	{
		p[index].r = r;
		p[index].g = g;
		p[index].b = b;
		return true;
	}
	return false;
}

int CParticle::GetColor(GLint index, GLint &r, GLint &g, GLint &b)
{
	if (index >= 0 && index<pNum)
	{
		r = p[index].r;
		g = p[index].g;
		b = p[index].b;
		return true;
	}
	return false;
}

/***************** λ�ú��� *****************/
int CParticle::SetPosition(GLfloat x, GLfloat y, GLfloat z)
{
	for (int index = 0; index<pNum; index++)
	{
		p[index].x = x;
		p[index].y = y;
		p[index].z = z;
	}
	return true;
}

int CParticle::SetPosition(GLint index, GLfloat x, GLfloat y, GLfloat z)
{
	if (index >= 0 && index<pNum)
	{
		p[index].x = x;
		p[index].y = y;
		p[index].z = z;
		return true;
	}
	return false;
}

int CParticle::GetPosition(GLint index, GLfloat &x, GLfloat &y, GLfloat &z)
{
	if (index >= 0 && index<pNum)
	{
		x = p[index].x;
		y = p[index].y;
		z = p[index].z;
		return true;
	}
	return false;
}

/**************** �ٶȺ��� ****************/
int CParticle::SetVelocity(GLfloat vx, GLfloat vy, GLfloat vz)
{
	for (int index = 0; index<pNum; index++)
	{
		p[index].xv = vx;
		p[index].yv = vy;
		p[index].zv = vz;
	}
	return true;
}

int CParticle::SetVelocity(GLint index, GLfloat vx, GLfloat vy, GLfloat vz)
{
	if (index >= 0 && index<pNum)
	{
		p[index].xv = vx;
		p[index].yv = vy;
		p[index].zv = vz;
		return true;
	}
	return false;
}

int CParticle::GetVelocity(GLint index, GLfloat &vx, GLfloat &vy, GLfloat &vz)
{
	if (index >= 0 && index<pNum)
	{
		vx = p[index].xv;
		vy = p[index].yv;
		vz = p[index].zv;
		return true;
	}
	return false;
}

/******************* ���ٶȺ��� *******************/
int CParticle::SetAcceleration(GLfloat ax, GLfloat ay, GLfloat az)
{
	for (int index = 0; index<pNum; index++)
	{
		p[index].xa = ax;
		p[index].ya = ay;
		p[index].za = az;
	}
	return true;
}

int CParticle::SetAcceleration(GLint index, GLfloat ax, GLfloat ay, GLfloat az)
{
	if (index >= 0 && index<pNum)
	{
		p[index].xa = ax;
		p[index].ya = ay;
		p[index].za = az;
		return true;
	}
	return false;
}


int CParticle::GetAcceletation(GLint index, GLfloat &ax, GLfloat &ay, GLfloat &az)
{
	if (index >= 0 && index<pNum)
	{
		ax = p[index].xa;
		ay = p[index].ya;
		az = p[index].za;
		return true;
	}
	return false;
}

/******************** Size���� ********************/
int CParticle::SetSize(GLfloat size)
{
	for (int index = 0; index<pNum; index++)
	{
		p[index].size = size;
	}
	return true;
}

int CParticle::SetSize(GLint index, GLfloat size)
{
	if (index >= 0 && index<pNum)
	{
		p[index].size = size;
		return true;
	}
	return false;
}

int CParticle::GetSize(GLint index, GLfloat &size)
{
	if (index >= 0 && index < pNum)
	{
		size = p[index].size;
		return true;
	}
	return false;
}

/**************** ��������ʱ�����Ժ��� ***************/
int CParticle::SetLifeTime(GLfloat lifetime)
{
	for (int index = 0; index<pNum; index++)
	{
		p[index].lifetime = lifetime;
	}
	return true;
}

int CParticle::SetLifeTime(GLint index, GLfloat lifetime)
{
	if (index >= 0 && index < pNum)
	{
		p[index].lifetime = lifetime;
		return true;
	}
	return false;
}

int CParticle::GetLifeTime(GLint index, GLfloat &lifetime)
{
	if (index >= 0 && index < pNum)
	{
		lifetime = p[index].lifetime;
		return true;
	}
	return false;
}

/******************** ������ʧ�ٶȺ��� ********************/
int CParticle::SetFade(GLfloat fade)
{
	for (int index = 0; index<pNum; ++index)
	{
		p[index].fade = fade;
	}
	return true;
}

int CParticle::SetFade(GLint index, GLfloat fade)
{
	if (index >= 0 && index < pNum)
	{
		p[index].fade = fade;
		return true;
	}
	return false;
}

int CParticle::GetFade(GLint index, GLfloat &fade)
{
	if (index >= 0 && index < pNum)
	{
		fade = p[index].fade;
		return true;
	}
	return false;
}

/*********** ��ȡ���ӵ��������� ************/
int CParticle::GetAll(int index, 
	GLint &r, GLint &g, GLint &b,           /** ������ɫ */
	GLfloat &x, GLfloat &y, GLfloat &z,     /** ����λ�� */
	GLfloat &vx, GLfloat &vy, GLfloat &vz,  /** �����ٶ� */
	GLfloat &ax, GLfloat &ay, GLfloat &az,  /** ���Ӽ��ٶ� */
	GLfloat &size,                          /** ���Ӵ�С */
	GLfloat &lifetime,                      /** ����ʱ�� */
	GLfloat &fade                            /** ��ʧ�ٶ� */
	)
{
	if (index >= 0 && index<pNum)
	{
		r = p[index].r;
		g = p[index].g;
		b = p[index].b;
		x = p[index].x;
		y = p[index].y;
		z = p[index].z;
		vx = p[index].xv;
		vy = p[index].yv;
		vz = p[index].zv;
		ax = p[index].xa;
		ay = p[index].ya;
		az = p[index].za;
		lifetime = p[index].lifetime;
		size = p[index].size;
		fade = p[index].fade;
		return true;
	}
	return false;
}

/*************** �������ӵ��������� **************/
int CParticle::SetAll(int index, 
	GLint r, GLint g, GLint b,           /** ������ɫ */
	GLfloat x, GLfloat y, GLfloat z,     /** ����λ�� */
	GLfloat vx, GLfloat vy, GLfloat vz,  /** �����ٶ� */
	GLfloat ax, GLfloat ay, GLfloat az,  /** ���Ӽ��ٶ� */
	GLfloat size,                        /** ���Ӵ�С */
	GLfloat lifetime,                    /** ����ʱ�� */
	GLfloat fade                          /** ��ʧ�ٶ� */
	)
{
	if (index >= 0 && index<pNum)
	{
		p[index].r = r;
		p[index].g = g;
		p[index].b = b;
		p[index].x = x;
		p[index].y = y;
		p[index].z = z;
		p[index].xv = vx;
		p[index].yv = vy;
		p[index].zv = vz;
		p[index].xa = ax;
		p[index].ya = ay;
		p[index].za = az;
		p[index].lifetime = lifetime;
		p[index].size = size;
		p[index].fade = fade;
		return true;
	}
	return false;
}