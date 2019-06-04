#include"particle.h"
#include"word.h"
#include"Tree.h"
CParticle Tree;
bool InitTree()
{
	for (int i = 0; i < Tree.GetNumOfParticle(); ++i)
	{
		//��ʼ����ɫ
		r = 249;
		g = 204;
		b = 226;
		Tree.SetColor(i, r, g, b);

		//��ʼ������
		if (i % 3 == 0) {
			x = 0.1f * (rand() % 20) - 1.0f;
			y = 0.3 + 0.001f * (rand() % 900);
			z = (rand() % 200)*0.01 - 2;
		}

		if (i % 3 == 1) {
			x = 0.1f * (rand() % 20) + 1.0f;
			y = 0.1 + 0.001f * (rand() % 900);
			z = (rand() % 200)*0.01 + 0.5;
		}

		if (i % 3 == 2) {
			x = 0.1f * (rand() % 20) - 3.5f;
			y = 0.2 + 0.001f * (rand() % 900);
			z = (rand() % 200)*0.01;
		}


		Tree.SetPosition(i, x, y, z);

		//��ʼ���ٶ�
		vx = (0.000001 * (rand() % 100) - 0.00005) * 5;
		vy = 0.0000002 * (rand() % 1000) + 0.0002;
		vz = 0;
		Tree.SetVelocity(i, vx, vy, vz);

		//��ʼ�����ٶ�
		ax = 0;
		ay = 0.000000f;
		az = 0;
		Tree.SetAcceleration(i, ax, ay, az);

		//��ʼ����������
		lifetime = 10000;
		Tree.SetLifeTime(i, lifetime);

		//��ʧ�ٶ�
		dec = 0;
		Tree.SetFade(i, dec);

		//��ʼ����С
		Tree.SetSize(i, 0.08f);
	}
	return true;
}

/** �������� */
extern int ii = 0;
void UpdateTree()
{
	/** ����λ�� */
	x += vx;
	y -= vy;
	/** ���������ʧ���������� */
	if (y <= -1 || lifetime <= 0)
	{
		ii++;

		/** ��ʼ��λ�� */
		if (ii % 3 == 0) {
			x = 0.1f * (rand() % 20) - 1.0f;
			y = 0.3 + 0.001f * (rand() % 900);
			z = (rand() % 200)*0.01 - 2;
			ii = 0;
		}

		if (ii % 3 == 1) {
			x = 0.1f * (rand() % 20) + 1.0f;
			y = 0.1 + 0.001f * (rand() % 900);
			z = (rand() % 200)*0.01 + 0.5;
		}

		if (ii % 3 == 2) {
			x = 0.1f * (rand() % 20) - 3.5f;
			y = 0.3 + 0.001f * (rand() % 900);
			z = (rand() % 200)*0.01;
		}

		/** ��ʼ���ٶ� */
		vx = (float)(0.000001 * (rand() % 100) - 0.00005) * 5;
		vy = (float)(0.0000002 * (rand() % 1000)) + 0.0002;
		vz = 0;

		/** ��ʼ�����ٶ� */
		ax = 0;
		ay = 0.000000f;
		az = 0;
		lifetime = 10000;
		dec = 0;
	}
}
