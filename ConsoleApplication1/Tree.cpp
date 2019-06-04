#include"particle.h"
#include"word.h"
#include"Tree.h"
CParticle Tree;
bool InitTree()
{
	for (int i = 0; i < Tree.GetNumOfParticle(); ++i)
	{
		//初始化颜色
		r = 249;
		g = 204;
		b = 226;
		Tree.SetColor(i, r, g, b);

		//初始化坐标
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

		//初始化速度
		vx = (0.000001 * (rand() % 100) - 0.00005) * 5;
		vy = 0.0000002 * (rand() % 1000) + 0.0002;
		vz = 0;
		Tree.SetVelocity(i, vx, vy, vz);

		//初始化加速度
		ax = 0;
		ay = 0.000000f;
		az = 0;
		Tree.SetAcceleration(i, ax, ay, az);

		//初始化生命周期
		lifetime = 10000;
		Tree.SetLifeTime(i, lifetime);

		//消失速度
		dec = 0;
		Tree.SetFade(i, dec);

		//初始化大小
		Tree.SetSize(i, 0.08f);
	}
	return true;
}

/** 更新粒子 */
extern int ii = 0;
void UpdateTree()
{
	/** 更新位置 */
	x += vx;
	y -= vy;
	/** 如果粒子消失或生命结束 */
	if (y <= -1 || lifetime <= 0)
	{
		ii++;

		/** 初始化位置 */
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

		/** 初始化速度 */
		vx = (float)(0.000001 * (rand() % 100) - 0.00005) * 5;
		vy = (float)(0.0000002 * (rand() % 1000)) + 0.0002;
		vz = 0;

		/** 初始化加速度 */
		ax = 0;
		ay = 0.000000f;
		az = 0;
		lifetime = 10000;
		dec = 0;
	}
}
