#include"particle.h"
#include"word.h"
#include"Snow.h"
CParticle Snow;

/** 初始化雪花粒子 */
bool InitSnow()
{
	for (int i = 0; i < Snow.GetNumOfParticle(); ++i)
	{
		//初始化颜色
		r = 255;
		g = 255;
		b = 255;
		Snow.SetColor(i, r, g, b);

		//初始化坐标
		x = 0.1f * (rand() % 50) - 2.5f;
		y = 3 + 0.01f * (rand() % 2);
		if ((int)x % 2 == 0)
			z = rand() % 6;
		else
			x = -rand() % 3;
		Snow.SetPosition(i, x, y, z);

		//初始化速度
		vx = 0.00001 * (rand() % 100) - 0.0005;
		vy = 0.0001 + 0.0000002 * (rand() % 10000);
		vz = 0;
		Snow.SetVelocity(i, vx, vy, vz);

		//初始化加速度
		ax = 0;
		ay = 0.000000f;
		az = 0;
		Snow.SetAcceleration(i, ax, ay, az);

		//初始化生命周期
		lifetime = 100;
		Snow.SetLifeTime(i, lifetime);

		//消失速度
		dec = 0.005 * (rand() % 50);
		Snow.SetFade(i, dec);

		//初始化大小
		Snow.SetSize(i, 0.02f);
	}
	return true;
}

/** 更新粒子 */
void UpdateSnow()
{
	/** 更新位置 */
	x += vx;
	y -= vy;


	/** 更新生存时间 */
	//lifetime -= dec;

	if (x > 3)
		x = -2;

	/** 如果粒子消失或生命结束 */
	if (y <= -1 || lifetime <= 0)
	{
		/** 初始化位置 */
		x = 0.1f * (rand() % 50) - 2.5f;
		y = 3 + 0.1f * (rand() % 2);
		if ((int)x % 2 == 0)
			z = rand() % 6;
		else
			z = -rand() % 3;

		/** 初始化速度 */
		vx = (float)(0.00001 * (rand() % 100) - 0.0005);
		vy = (float)(0.0001 + 0.0000002 * (rand() % 10000));
		vz = 0;

		/** 初始化加速度 */
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
		//初始化颜色
		r = 255;
		g = 255;
		b = 255;
		Snow.SetColor(i, r, g, b);

		//初始化坐标
		x = 0.1f * (rand() % 50) - 2.5f;
		y = 3 + 0.01f * (rand() % 2);
		if ((int)x % 2 == 0)
			z = rand() % 6;
		else
			x = -rand() % 3;
		Snow.SetPosition(i, x, y, z);

		//初始化速度
		vx = 0.0001 * (rand() % 100) - 0.005;
		vy = 0.0001 + 0.0000002 * (rand() % 10000);
		vz = 0;
		Snow.SetVelocity(i, vx, vy, vz);

		//初始化加速度
		ax = 0;
		ay = 0.000000f;
		az = 0;
		Snow.SetAcceleration(i, ax, ay, az);

		//初始化生命周期
		lifetime = 100;
		Snow.SetLifeTime(i, lifetime);

		//消失速度
		dec = 0.005 * (rand() % 50);
		Snow.SetFade(i, dec);

		//初始化大小
		Snow.SetSize(i, 0.02f);
	}
	return true;
}

/** 更新粒子 */
void UpdateSnowByWind()
{
	/** 更新位置 */
	x += vx;
	y -= vy;


	/** 更新生存时间 */
	//lifetime -= dec;

	if (x > 3)
		x = -2;

	/** 如果粒子消失或生命结束 */
	if (y <= -1 || lifetime <= 0)
	{
		/** 初始化位置 */
		x = 0.1f * (rand() % 50) - 2.5f;
		y = 3 + 0.1f * (rand() % 2);
		if ((int)x % 2 == 0)
			z = rand() % 6;
		else
			z = -rand() % 3;

		/** 初始化速度 */
		vx = (float)(0.0001 * (rand() % 100) - 0.005);
		vy = (float)(0.0001 + 0.0000002 * (rand() % 10000));
		vz = 0;

		/** 初始化加速度 */
		ax = 0;
		ay = 0.000000f;
		az = 0;
		lifetime = 100;
		dec = 0.005*(rand() % 50);
	}
}

