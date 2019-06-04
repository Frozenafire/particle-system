#include"particle.h"
#include"word.h"
#include"Star.h"
CParticle Stone1;
CParticle Stone2;
CParticle Stone3;
GLfloat R = 1.0f;
GLfloat sx = -3.0f;
GLfloat sy = 3.0f;
GLfloat sx1 = -2.0f;
GLfloat sy1 = 3.0f;
GLfloat sx2 = -1.0f;
GLfloat sy2 = 3.0f;
float vx1 = 0.01; float vy1 = 0.01; float ax1 = 0.000005; float ay1 = 0.000005;
float vx2 = 0.015; float vy2 = 0.015; float ax2 = 0.000005; float ay2 = 0.000005;
float vx3 = 0.013; float vy3 = 0.013; float ax3 = 0.000005; float ay3 = 0.000005;
bool InitStarLine1()
{
	for (int i = 0; i < Stone1.GetNumOfParticle(); ++i)
	{
		//初始化颜色
		r = 255;
		g = 0;
		b = 0;
		Stone1.SetColor(i, r, g, b);

		//初始化坐标
		x = sx - 0.35 + 0.002*(rand() % 100);
		y = sy + 0.0025*(rand() % 100);
		Stone1.SetPosition(i, x, y, z);


		//初始化速度
		vx = (0.00001 * (rand() % 100) - 0.0005);
		vy = (0.001 + 0.0002 * (rand() % 10));
		vz = 0;
		Stone1.SetVelocity(i, vx, vy, vz);

		//初始化加速度
		ax = 0;
		ay = 0.00001f;
		az = 0;
		Stone1.SetAcceleration(i, ax, ay, az);

		//初始化生命周期
		lifetime = 10;
		Stone1.SetLifeTime(i, lifetime);

		//消失速度
		dec = 0.005 * (rand() % 50);
		Stone1.SetFade(i, dec);

		//初始化大小
		Stone1.SetSize(i, 0.01f);
	}
	return true;
}

/** 更新粒子 */
void UpdateStarLine1()
{
	/** 更新位置 */
	x += vx;
	y -= vy;

	/** 更新生存时间 */
	lifetime -= dec;

	/** 如果粒子消失或生命结束 */
	if (lifetime <= 0 || y<-1)
	{
		/** 初始化位置 */
		x = sx - 0.35 + 0.002*(rand() % 100);
		y = sy + 0.0025*(rand() % 100);
		/** 初始化速度 */
		vx = (0.00001 * (rand() % 100) - 0.0005);
		vy = (0.001 + 0.0002 * (rand() % 10));
		vz = 0;

		/** 初始化加速度 */
		ax = 0;
		ay = 0.00001f;
		az = 0;
		lifetime = 10;
		dec = 0.005*(rand() % 50);
	}
}

bool InitStarLine2()
{
	for (int i = 0; i < Stone2.GetNumOfParticle(); ++i)
	{
		//初始化颜色
		r = 255;
		g = 0;
		b = 0;
		Stone2.SetColor(i, r, g, b);

		//初始化坐标
		x = sx1 - 0.35 + 0.002*(rand() % 100);
		y = sy1 + 0.0025*(rand() % 100);
		Stone2.SetPosition(i, x, y, z);


		//初始化速度
		vx = (0.00001 * (rand() % 100) - 0.0005);
		vy = (0.001 + 0.0002 * (rand() % 10));
		vz = 0;
		Stone2.SetVelocity(i, vx, vy, vz);

		//初始化加速度
		ax = 0;
		ay = 0.00001f;
		az = 0;
		Stone2.SetAcceleration(i, ax, ay, az);

		//初始化生命周期
		lifetime = 10;
		Stone2.SetLifeTime(i, lifetime);

		//消失速度
		dec = 0.005 * (rand() % 50);
		Stone2.SetFade(i, dec);

		//初始化大小
		Stone2.SetSize(i, 0.02f);
	}
	return true;
}

/** 更新粒子 */
void UpdateStarLine2()
{
	/** 更新位置 */
	x += vx;
	y -= vy;

	/** 更新生存时间 */
	lifetime -= dec;

	/** 如果粒子消失或生命结束 */
	if (lifetime <= 0 || y<-1)
	{
		/** 初始化位置 */
		x = sx1 - 0.35 + 0.002*(rand() % 100);
		y = sy1 + 0.0025*(rand() % 100);
		/** 初始化速度 */
		vx = (0.00001 * (rand() % 100) - 0.0005);
		vy = (0.001 + 0.0002 * (rand() % 10));
		vz = 0;

		/** 初始化加速度 */
		ax = 0;
		ay = 0.00001f;
		az = 0;
		lifetime = 10;
		dec = 0.005*(rand() % 50);
	}
}

bool InitStarLine3()
{
	for (int i = 0; i < Stone3.GetNumOfParticle(); ++i)
	{
		//初始化颜色
		r = 255;
		g = 0;
		b = 0;
		Stone3.SetColor(i, r, g, b);

		//初始化坐标
		x = sx2 - 0.35 + 0.002*(rand() % 100);
		y = sy2 + 0.0025*(rand() % 100);
		z = -1;
		Stone3.SetPosition(i, x, y, z);


		//初始化速度
		vx = (0.00001 * (rand() % 100) - 0.0005);
		vy = (0.001 + 0.0002 * (rand() % 10));
		vz = 0;
		Stone3.SetVelocity(i, vx, vy, vz);

		//初始化加速度
		ax = 0;
		ay = 0.00001f;
		az = 0;
		Stone3.SetAcceleration(i, ax, ay, az);

		//初始化生命周期
		lifetime = 10;
		Stone3.SetLifeTime(i, lifetime);

		//消失速度
		dec = 0.005 * (rand() % 50);
		Stone3.SetFade(i, dec);

		//初始化大小
		Stone3.SetSize(i, 0.02f);
	}
	return true;
}

/** 更新粒子 */
void UpdateStarLine3()
{
	/** 更新位置 */
	x += vx;
	y -= vy;

	/** 更新生存时间 */
	lifetime -= dec;

	/** 如果粒子消失或生命结束 */
	if (lifetime <= 0 || y<-1)
	{
		/** 初始化位置 */
		x = sx2 - 0.35 + 0.002*(rand() % 100);
		y = sy2 + 0.0025*(rand() % 100);
		z = -1;
		/** 初始化速度 */
		vx = (0.00001 * (rand() % 100) - 0.0005);
		vy = (0.001 + 0.0002 * (rand() % 10));
		vz = 0;

		/** 初始化加速度 */
		ax = 0;
		ay = 0.00001f;
		az = 0;
		lifetime = 10;
		dec = 0.005*(rand() % 50);
	}
}
void myIdle()
{
	sx += vx1;
	sy -= vy1;
	vx1 += ax1;
	vy1 += ay1;
	if (sx >= 6.0f)
	{
		vx1 = 0.01; vy1 = 0.01;
		sx = -4.0f + (0.06*(rand() % 100));
		sy = 3.0f;
	}
	if (sy <= -1.0f)
	{
		vx1 = 0.01; vy1 = 0.01;
		sy = 2.0f;
	}

	sx1 += vx2;
	sy1 -= vy2;
	vx2 += ax2;
	vy2 += ay2;
	if (sx1 >= 6.0f)
	{
		vx2 = 0.01; vy2 = 0.01;
		sx1 = -4.0f + (0.06*(rand() % 100));
		sy1 = 3.0f;
	}
	if (sy1 <= -1.0f)
	{
		vx2 = 0.01; vy2 = 0.01;
		sy1 = 2.0f;
	}

	sx2 += vx3;
	sy2 -= vy3;
	vx3 += ax3;
	vy3 += ay3;
	if (sx2 >= 6.0f)
	{
		vx3 = 0.01; vy3 = 0.01;
		sx2 = -4.0f + (0.06*(rand() % 100));
		sy2 = 3.0f;
	}
	if (sy2 <= -1.0f)
	{
		vx3 = 0.01; vy3 = 0.01;
		sy2 = 2.0f;
	}

}
