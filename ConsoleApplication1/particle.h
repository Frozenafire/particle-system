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
	int r, g, b;//������ɫ
	float x, y, z;//����λ��
	float xv, yv, zv;//�����ƶ��ٶ�
	float xa, ya, za;//�����ƶ����ٶ�
	float size;//���ӳߴ�
	float lifetime;//����ʣ�����ʱ��
	float fade;//���������ٶ�
};

class CParticle
{
private:
	Particle* p;        /**< ����ָ�� */
	int pNum;           /**< ������Ŀ */

public:
	
						  
	int Create(long num);       /** ������������ */

	/** ���úͻ�ȡ��ɫ���� */
	int SetColor(GLint r, GLint g, GLint b);
	int SetColor(GLint index, GLint r, GLint g, GLint b);
	int GetColor(GLint index, GLint &r, GLint &g, GLint &b);

	/** ���úͻ�ȡλ������ */
	int SetPosition(GLfloat x, GLfloat y, GLfloat z);
	int SetPosition(GLint index, GLfloat x, GLfloat y, GLfloat z);
	int GetPosition(GLint index, GLfloat &x, GLfloat &y, GLfloat &z);
	
	/** ���úͻ�ȡ�ٶ����� */
	int SetVelocity(GLfloat vx, GLfloat vy, GLfloat vz);
	int SetVelocity(GLint index, GLfloat vx, GLfloat vy, GLfloat vz);
	int GetVelocity(GLint index, GLfloat &vx, GLfloat &vy, GLfloat &vz);

	/** ���úͻ�ȡ���ٶ����� */
	int SetAcceleration(GLfloat ax, GLfloat ay, GLfloat az);
	int SetAcceleration(GLint index, GLfloat ax, GLfloat ay, GLfloat az);
	int GetAcceletation(GLint index, GLfloat &ax, GLfloat &ay, GLfloat &az);

	/** ���úͻ�ȡ�ߴ����� */
	int SetSize(GLfloat size);
	int SetSize(GLint index, GLfloat size);
	int GetSize(GLint index, GLfloat &size);

	/** ���úͻ�ȡ����ֵ���� */
	int SetLifeTime(GLfloat lifetime);
	int SetLifeTime(GLint index, GLfloat lifetime);
	int GetLifeTime(GLint index, GLfloat &lifetime);

	/** ���úͻ�ȡ��ʧ�ٶ����� */
	int SetFade(GLfloat fade);
	int SetFade(GLint index, GLfloat fade);
	int GetFade(GLint index, GLfloat &fade);

	/** ��ȡ���������ַ */
	Particle *GetParticle() { return p; }

	/** ������ӵ���Ŀ */
	int GetNumOfParticle() { return pNum; }

	/** ����������е����� */
	int GetAll(int index,                        /** �±����� */
		GLint &r, GLint &g, GLint &b,            /** ������ɫ */
		GLfloat &x, GLfloat &y, GLfloat &z,      /** ����λ�� */
		GLfloat &vx, GLfloat &vy, GLfloat &vz,   /** �����ٶ� */
		GLfloat &ax, GLfloat &ay, GLfloat &az,   /** ���Ӽ��ٶ� */
		GLfloat &size,                           /** ���Ӵ�С */
		GLfloat &lifetime,                       /** ����ʱ�� */
		GLfloat &fade                            /** ��ʧ�ٶ� */
		);

	/** �������ӵ��������� */
	int SetAll(int index,                      /** �±����� */
		GLint r, GLint g, GLint b,             /** ������ɫ */
		GLfloat x, GLfloat y, GLfloat z,       /** ����λ�� */
		GLfloat vx, GLfloat vy, GLfloat vz,    /** �����ٶ� */
		GLfloat ax, GLfloat ay, GLfloat az,    /** ���Ӽ��ٶ� */
		GLfloat size,                          /** ���Ӵ�С */
		GLfloat lifetime,                      /** ����ʱ�� */
		GLfloat fade                            /** ��ʧ�ٶ� */
		);
};