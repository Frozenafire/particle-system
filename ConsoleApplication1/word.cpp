#include"particle.h"
#include "word.h"
CParticle Word;
CParticle A;
CParticle D;
CParticle F;
CParticle L;
CParticle N;
CParticle O;
CParticle W;

float x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade,dec;
int r, g, b;
float a;
bool InitA()
{
	for (int i = 0; i < A.GetNumOfParticle(); ++i)
	{
		///��ʼ����ɫ
		//��(244)  ��(0)  ��(2)  #F40002
		//��(250)  ��(244)  ��(8)  #FAF408

		A.SetColor(i, r, g, b);


		if (i % 3 == 0) {
			x = (rand() % 400)*0.001f - 0.4;
			y = x * 3 + 0.6;
			z = 0;
			A.SetPosition(i, x, y, z);
		}

		if (i % 3 == 1) {
			x = (rand() % 400)*0.001f;
			y = x * (-3) + 0.6;
			z = 0;
			A.SetPosition(i, x, y, z);
		}

		if (i % 3 == 2) {
			x = 0.001f * (rand() % 400) - 0.2f;
			y = 0.001f * (rand() % 100) - 0.1f;
			z = 0;
			A.SetPosition(i, x, y, z);
		}



		///��ʼ���ٶ�
		if (i % 5 == 0) {
			vx = 0.00001 * (rand() % 100);
			vy = 0.00001 * (rand() % 100);
			vz = 0;
			A.SetVelocity(i, vx, vy, vz);
		}
		else {
			vx = -0.0001 + 0.000001*(rand() % 1000);
			vy = 0;
			vz = 0;
			A.SetVelocity(i, vx, vy, vz);
		}

		///��ʼ�����ٶ�
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		A.SetAcceleration(i, ax, ay, az);

		///��ʼ����������
		lifetime = 1;
		A.SetLifeTime(i, lifetime);

		///��ʧ�ٶ�
		fade = 0.005 * (rand() % 50);
		A.SetFade(i, fade);

		///��ʼ����С
		A.SetSize(i, 0.01f);
	}
	return true;
}
extern int aa = 0;
/** �������� */

void UpdateA()
{
	/** ����λ�� */
	x += vx;
	y += vy;
	z += vz;

	/** �����ٶ� */
	vz += az;
	/** ��������ʱ�� */
	lifetime -= fade;


	/** ���������ʧ���������� */
	if (z >= 1 || lifetime <= 0 || x>0.6 || y>0.8)
	{

		z = 0;

		aa++;

		if (aa % 3 == 0) {
			x = (rand() % 400)*0.001f - 0.4;
			y = x * 3 + 0.6;
		}

		if (aa % 3 == 1) {
			x = (rand() % 400)*0.001f;
			y = x * (-3) + 0.6;
		}

		if (aa % 3 == 2) {
			x = 0.001f * (rand() % 400) - 0.2f;
			y = 0.001f * (rand() % 100) - 0.1f;
		}
/** ��ʼ���ٶ� */


		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;



		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		lifetime = 10;
		fade = 0.005*(rand() % 50);
	}
}


bool InitD()
{
	for (int i = 0; i < D.GetNumOfParticle(); ++i)
	{

		D.SetColor(i, r, g, b);

		///��ʼ������
		if (i % 2 == 0) {
			x = 0.002f * (rand() % 100) - 0.1f;
			y = 0.002f * (rand() % 600) - 0.6f;
			z = 0;
			Word.SetPosition(i, x, y, z);
		}

		if (i % 2 == 1) {
			a = (rand() % 180 - 90)*PI / 180;
			x = 0.6 * cos(a);
			y = 0.6 * sin(a);
			z = 0;
			Word.SetPosition(i, x, y, z);
		}


		///��ʼ���ٶ�
		if (i % 5 == 0) {
			vx = 0.00001 * (rand() % 100);
			vy = 0.00001 * (rand() % 100);
			vz = 0;
			D.SetVelocity(i, vx, vy, vz);
		}
		else {
			vx = -0.0001 + 0.000001*(rand() % 1000);
			vy = 0;
			vz = 0;
			D.SetVelocity(i, vx, vy, vz);
		}

		///��ʼ�����ٶ�
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		D.SetAcceleration(i, ax, ay, az);

		///��ʼ����������
		lifetime = 1;
		D.SetLifeTime(i, lifetime);

		///��ʧ�ٶ�
		fade = 0.005 * (rand() % 50);
		D.SetFade(i, fade);

		///��ʼ����С
		D.SetSize(i, 0.01f);
	}
	return true;
}
extern int dd = 0;
/** �������� */
void UpdateD()
{
	/** ����λ�� */
	x += vx;
	y += vy;
	z += vz;

	/** �����ٶ� */
	vz += az;
	/** ��������ʱ�� */
	lifetime -= fade;


	/** ���������ʧ���������� */
	if (z >= 1 || lifetime <= 0 || x>0.6 || y>0.8)
	{

		z = 0;

		dd++;

		if (dd % 2 == 0) {
			x = 0.002f * (rand() % 100) - 0.1f;
			y = 0.002f * (rand() % 600) - 0.6f;
		}

		if (dd % 2 == 1) {
			a = (rand() % 180 - 90)*PI / 180;
			x = 0.6 * cos(a);
			y = 0.6 * sin(a);
		}

		/** ��ʼ���ٶ� */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		lifetime = 10;
		fade = 0.005*(rand() % 50);
	}
}

bool InitF()
{
	for (int i = 0; i < F.GetNumOfParticle(); ++i)
	{

		F.SetColor(i, r, g, b);

		///��ʼ������
		if (i % 3 == 0) {
			x = 0.002f * (rand() % 60) - 0.35f;                //H
			y = 0.002f * (rand() % 600) - 0.6f;
			z = 0;
			F.SetPosition(i, x, y, z);
		}

		if (i % 3 == 1) {
			x = 0.002f * (rand() % 300) - 0.2f;
			y = 0.002f * (rand() % 60) + 0.5f;
			z = 0;
			F.SetPosition(i, x, y, z);
		}

		if (i % 3 == 2) {
			x = 0.002f * (rand() % 300) - 0.2f;
			y = 0.002f * (rand() % 60);
			z = 0;
			F.SetPosition(i, x, y, z);
		}

		///��ʼ���ٶ�
		if (i % 5 == 0) {
			vx = 0.00001 * (rand() % 100);
			vy = 0.00001 * (rand() % 100);
			vz = 0;
			F.SetVelocity(i, vx, vy, vz);
		}
		else {
			vx = -0.0001 + 0.000001*(rand() % 1000);
			vy = 0;
			vz = 0;
			F.SetVelocity(i, vx, vy, vz);
		}

		///��ʼ�����ٶ�
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		F.SetAcceleration(i, ax, ay, az);

		///��ʼ����������
		lifetime = 1;
		F.SetLifeTime(i, lifetime);

		///��ʧ�ٶ�
		fade = 0.005 * (rand() % 50);
		F.SetFade(i, fade);

		///��ʼ����С
		F.SetSize(i, 0.01f);
	}
	return true;
}
extern int ff = 0;
/** �������� */
void UpdateF()
{
	/** ����λ�� */
	x += vx;
	y += vy;
	z += vz;

	/** �����ٶ� */
	vz += az;
	/** ��������ʱ�� */
	lifetime -= fade;


	/** ���������ʧ���������� */
	if (z >= 1 || lifetime <= 0 || x>0.6 || y>0.8)
	{

		z = 0;

		ff++;

		if (ff % 3 == 0) {
			x = 0.002f * (rand() % 60) - 0.35f;                //H
			y = 0.002f * (rand() % 600) - 0.6f;
		}

		if (ff % 3 == 1) {
			x = 0.002f * (rand() % 300) - 0.2f;
			y = 0.002f * (rand() % 60) + 0.5f;
		}

		if (ff % 3 == 2) {
			x = 0.002f * (rand() % 300) - 0.2f;
			y = 0.002f * (rand() % 60);
		}

		/** ��ʼ���ٶ� */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		lifetime = 10;
		fade = 0.005*(rand() % 50);
	}
}

bool InitL()
{
	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{

		L.SetColor(i, r, g, b);

		///��ʼ������
		if (i % 2 == 0) {
			x = 0.002f * (rand() % 80) - 0.4f;                //H
			y = 0.002f * (rand() % 600) - 0.6f;
			z = 0;
			L.SetPosition(i, x, y, z);
		}

		if (i % 2 == 1) {
			x = 0.002f * (rand() % 300) - 0.2f;
			y = 0.002f * (rand() % 80) - 0.6f;
			z = 0;
			L.SetPosition(i, x, y, z);
		}


		///��ʼ���ٶ�
		if (i % 5 == 0) {
			vx = 0.00001 * (rand() % 100);
			vy = 0.00001 * (rand() % 100);
			vz = 0;
			L.SetVelocity(i, vx, vy, vz);
		}
		else {
			vx = -0.0001 + 0.000001*(rand() % 1000);
			vy = 0;
			vz = 0;
			L.SetVelocity(i, vx, vy, vz);
		}

		///��ʼ�����ٶ�
		ax = 0;
		ay = -0.0000001f*(rand() % 10 + 8);
		az = 0.000000f;
		L.SetAcceleration(i, ax, ay, az);

		///��ʼ����������
		lifetime = 1;
		L.SetLifeTime(i, lifetime);

		///��ʧ�ٶ�
		fade = 0.005 * (rand() % 50);
		L.SetFade(i, fade);

		///��ʼ����С
		L.SetSize(i, 0.01f);
	}
	return true;
}
extern int ll = 0;
/** �������� */
void UpdateL()
{
	/** ����λ�� */
	x += vx;
	y += vy;
	z += vz;

	/** �����ٶ� */
	vz += az;
	/** ��������ʱ�� */
	lifetime -= fade;


	/** ���������ʧ���������� */
	if (z >= 1 || lifetime <= 0 || x>0.6 || y>0.8)
	{

		z = 0;

		ll++;

		if (ll % 2 == 0) {
			x = 0.002f * (rand() % 80) - 0.4f;                //H
			y = 0.002f * (rand() % 600) - 0.6f;
		}

		if (ll % 2 == 1) {
			x = 0.002f * (rand() % 300) - 0.2f;
			y = 0.002f * (rand() % 80) - 0.6f;
		}

		/** ��ʼ���ٶ� */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = -0.000001f*(rand() % 10 + 8);
		az = 0.000000f;
		lifetime = 10;
		fade = 0.005*(rand() % 50);
	}
}

bool InitN()
{
	for (int i = 0; i < N.GetNumOfParticle(); ++i)
	{

		N.SetColor(i, r, g, b);

		///��ʼ������
		if (i % 3 == 0) {
			x = 0.002f * (rand() % 80) - 0.3f;
			y = 0.002f * (rand() % 600) - 0.6f;
			z = 0;
			N.SetPosition(i, x, y, z);
		}

		if (i % 3 == 1) {
			x = 0.002f * (rand() % 300) - 0.3f;
			y = (-2)*x;
			z = 0;
			N.SetPosition(i, x, y, z);
		}

		if (i % 3 == 2) {
			x = 0.002f * (rand() % 80) + 0.3f;
			y = 0.002f * (rand() % 600) - 0.6f;
			z = 0;
			N.SetPosition(i, x, y, z);
		}

		///��ʼ���ٶ�
		if (i % 5 == 0) {
			vx = 0.00001 * (rand() % 100);
			vy = 0.00001 * (rand() % 100);
			vz = 0;
			N.SetVelocity(i, vx, vy, vz);
		}
		else {
			vx = -0.0001 + 0.000001*(rand() % 1000);
			vy = 0;
			vz = 0;
			N.SetVelocity(i, vx, vy, vz);
		}

		///��ʼ�����ٶ�
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		N.SetAcceleration(i, ax, ay, az);

		///��ʼ����������
		lifetime = 1;
		N.SetLifeTime(i, lifetime);

		///��ʧ�ٶ�
		fade = 0.005 * (rand() % 50);
		N.SetFade(i, fade);

		///��ʼ����С
		N.SetSize(i, 0.01f);
	}
	return true;
}
extern int nn = 0;
/** �������� */
void UpdateN()
{
	/** ����λ�� */
	x += vx;
	y += vy;
	z += vz;

	/** �����ٶ� */
	vz += az;
	/** ��������ʱ�� */
	lifetime -= fade;


	/** ���������ʧ���������� */
	if (z >= 1 || lifetime <= 0 || x>0.6 || y>0.8)
	{

		z = 0;

		nn++;

		if (nn % 3 == 0) {
			x = 0.002f * (rand() % 80) - 0.3f;
			y = 0.002f * (rand() % 600) - 0.6f;
		}

		if (nn % 3 == 1) {
			x = 0.002f * (rand() % 300) - 0.3f;
			y = (-2)*x;
		}

		if (nn % 3 == 2) {
			x = 0.002f * (rand() % 80) + 0.3f;
			y = 0.002f * (rand() % 600) - 0.6f;
		}

		/** ��ʼ���ٶ� */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		lifetime = 10;
		fade = 0.005*(rand() % 50);
	}
}

bool InitO()
{
	for (int i = 0; i < O.GetNumOfParticle(); ++i)
	{

		O.SetColor(i, r, g, b);

		///��ʼ������
		a = (rand() % 360)*PI / 180;
		x = 0.4*cos(a);
		y = 0.6*sin(a);
		z = 0;
		O.SetPosition(i, x, y, z);



		///��ʼ���ٶ�
		if (i % 5 == 0) {
			vx = 0.00001 * (rand() % 100);
			vy = 0.00001 * (rand() % 100);
			vz = 0;
			O.SetVelocity(i, vx, vy, vz);
		}
		else {
			vx = -0.0001 + 0.000001*(rand() % 1000);
			vy = 0;
			vz = 0;
			O.SetVelocity(i, vx, vy, vz);
		}

		///��ʼ�����ٶ�
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		O.SetAcceleration(i, ax, ay, az);

		///��ʼ����������
		lifetime = 1;
		O.SetLifeTime(i, lifetime);

		///��ʧ�ٶ�
		fade = 0.005 * (rand() % 50);
		O.SetFade(i, fade);

		///��ʼ����С
		O.SetSize(i, 0.01f);
	}
	return true;
}
extern int oo = 0;
/** �������� */
void UpdateO()
{
	/** ����λ�� */
	x += vx;
	y += vy;
	z += vz;

	/** �����ٶ� */
	vz += az;
	/** ��������ʱ�� */
	lifetime -= fade;


	/** ���������ʧ���������� */
	if (z >= 1 || lifetime <= 0 || x>0.6 || y>0.8)
	{

		z = 0;

		oo++;

		a = (rand() % 360)*PI / 180;
		x = 0.4*cos(a);
		y = 0.6*sin(a);

		/** ��ʼ���ٶ� */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		lifetime = 10;
		fade = 0.005*(rand() % 50);
	}
}

bool InitW()
{
	for (int i = 0; i < W.GetNumOfParticle(); ++i)
	{

		W.SetColor(i, r, g, b);

		///��ʼ������
		if (i % 4 == 0) {
			x = 0.002f * (rand() % 200) - 0.8f;
			y = (-3)*x - 1.8f;
			z = 0;
			W.SetPosition(i, x, y, z);
		}

		if (i % 4 == 1) {
			x = 0.002f * (rand() % 200);
			y = (-3)*x + 0.6f;
			z = 0;
			W.SetPosition(i, x, y, z);
		}

		if (i % 4 == 2) {
			x = 0.002f * (rand() % 200) - 0.4f;
			y = 3 * x + 0.6f;
			z = 0;
			W.SetPosition(i, x, y, z);
		}

		if (i % 4 == 3) {
			x = 0.002f * (rand() % 200) + 0.4f;
			y = 3 * x - 1.8f;
			z = 0;
			W.SetPosition(i, x, y, z);
		}

		///��ʼ���ٶ�
		if (i % 5 == 0) {
			vx = 0.00001 * (rand() % 100);
			vy = 0.00001 * (rand() % 100);
			vz = 0;
			W.SetVelocity(i, vx, vy, vz);
		}
		else {
			vx = -0.0001 + 0.000001*(rand() % 1000);
			vy = 0;
			vz = 0;
			W.SetVelocity(i, vx, vy, vz);
		}

		///��ʼ�����ٶ�
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		W.SetAcceleration(i, ax, ay, az);

		///��ʼ����������
		lifetime = 1;
		W.SetLifeTime(i, lifetime);

		///��ʧ�ٶ�
		fade = 0.005 * (rand() % 50);
		W.SetFade(i, fade);

		///��ʼ����С
		W.SetSize(i, 0.01f);
	}
	return true;
}
extern int ww = 0;
/** �������� */
void UpdateW()
{
	/** ����λ�� */
	x += vx;
	y += vy;
	z += vz;

	/** �����ٶ� */
	vz += az;
	/** ��������ʱ�� */
	lifetime -= fade;


	/** ���������ʧ���������� */
	if (z >= 1 || lifetime <= 0 || x>1 || y>1)
	{

		z = 0;

		ww++;

		if (ww % 4 == 0) {
			x = 0.002f * (rand() % 200) - 0.8f;
			y = (-3)*x - 1.8f;
			ww = 0;
		}

		if (ww % 4 == 1) {
			x = 0.002f * (rand() % 200);
			y = (-3)*x + 0.6f;

		}

		if (ww % 4 == 2) {
			x = 0.002f * (rand() % 200) - 0.4f;
			y = 3 * x + 0.6f;
		}

		if (ww % 4 == 3) {
			x = 0.002f * (rand() % 200) + 0.4f;
			y = 3 * x - 1.8f;
		}

		/** ��ʼ���ٶ� */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		lifetime = 10;
		fade = 0.005*(rand() % 50);
	}
}