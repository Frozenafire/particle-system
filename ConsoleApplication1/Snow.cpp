#include"particle.h"
#include"word.h"
#include"Snow.h"
CParticle Snow;

/** ��ʼ��ѩ������ */
bool InitSnow()
{
	for (int i = 0; i < Snow.GetNumOfParticle(); ++i)
	{
		//��ʼ����ɫ
		r = 255;
		g = 255;
		b = 255;
		Snow.SetColor(i, r, g, b);

		//��ʼ������
		x = 0.1f * (rand() % 50) - 2.5f;
		y = 3 + 0.01f * (rand() % 2);
		if ((int)x % 2 == 0)
			z = rand() % 6;
		else
			x = -rand() % 3;
		Snow.SetPosition(i, x, y, z);

		//��ʼ���ٶ�
		vx = 0.00001 * (rand() % 100) - 0.0005;
		vy = 0.0001 + 0.0000002 * (rand() % 10000);
		vz = 0;
		Snow.SetVelocity(i, vx, vy, vz);

		//��ʼ�����ٶ�
		ax = 0;
		ay = 0.000000f;
		az = 0;
		Snow.SetAcceleration(i, ax, ay, az);

		//��ʼ����������
		lifetime = 100;
		Snow.SetLifeTime(i, lifetime);

		//��ʧ�ٶ�
		dec = 0.005 * (rand() % 50);
		Snow.SetFade(i, dec);

		//��ʼ����С
		Snow.SetSize(i, 0.02f);
	}
	return true;
}

/** �������� */
void UpdateSnow()
{
	/** ����λ�� */
	x += vx;
	y -= vy;


	/** ��������ʱ�� */
	//lifetime -= dec;

	if (x > 3)
		x = -2;

	/** ���������ʧ���������� */
	if (y <= -1 || lifetime <= 0)
	{
		/** ��ʼ��λ�� */
		x = 0.1f * (rand() % 50) - 2.5f;
		y = 3 + 0.1f * (rand() % 2);
		if ((int)x % 2 == 0)
			z = rand() % 6;
		else
			z = -rand() % 3;

		/** ��ʼ���ٶ� */
		vx = (float)(0.00001 * (rand() % 100) - 0.0005);
		vy = (float)(0.0001 + 0.0000002 * (rand() % 10000));
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = 0.000000f;
		az = 0;
		lifetime = 100;
		dec = 0.005*(rand() % 50);
	}
}
bool InitSnowByWind()
{
	for (int i = 0; i < Snow.GetNumOfParticle(); ++i)
	{
		//��ʼ����ɫ
		r = 255;
		g = 255;
		b = 255;
		Snow.SetColor(i, r, g, b);

		//��ʼ������
		x = 0.1f * (rand() % 50) - 2.5f;
		y = 3 + 0.01f * (rand() % 2);
		if ((int)x % 2 == 0)
			z = rand() % 6;
		else
			x = -rand() % 3;
		Snow.SetPosition(i, x, y, z);

		//��ʼ���ٶ�
		vx = 0.0001 * (rand() % 100) - 0.005;
		vy = 0.0001 + 0.0000002 * (rand() % 10000);
		vz = 0;
		Snow.SetVelocity(i, vx, vy, vz);

		//��ʼ�����ٶ�
		ax = 0;
		ay = 0.000000f;
		az = 0;
		Snow.SetAcceleration(i, ax, ay, az);

		//��ʼ����������
		lifetime = 100;
		Snow.SetLifeTime(i, lifetime);

		//��ʧ�ٶ�
		dec = 0.005 * (rand() % 50);
		Snow.SetFade(i, dec);

		//��ʼ����С
		Snow.SetSize(i, 0.02f);
	}
	return true;
}

/** �������� */
void UpdateSnowByWind()
{
	/** ����λ�� */
	x += vx;
	y -= vy;


	/** ��������ʱ�� */
	//lifetime -= dec;

	if (x > 3)
		x = -2;

	/** ���������ʧ���������� */
	if (y <= -1 || lifetime <= 0)
	{
		/** ��ʼ��λ�� */
		x = 0.1f * (rand() % 50) - 2.5f;
		y = 3 + 0.1f * (rand() % 2);
		if ((int)x % 2 == 0)
			z = rand() % 6;
		else
			z = -rand() % 3;

		/** ��ʼ���ٶ� */
		vx = (float)(0.0001 * (rand() % 100) - 0.005);
		vy = (float)(0.0001 + 0.0000002 * (rand() % 10000));
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = 0.000000f;
		az = 0;
		lifetime = 100;
		dec = 0.005*(rand() % 50);
	}
}

