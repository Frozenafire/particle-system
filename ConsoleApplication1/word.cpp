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
		///初始化颜色
		//红(244)  绿(0)  蓝(2)  #F40002
		//红(250)  绿(244)  蓝(8)  #FAF408

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



		///初始化速度
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

		///初始化加速度
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		A.SetAcceleration(i, ax, ay, az);

		///初始化生命周期
		lifetime = 1;
		A.SetLifeTime(i, lifetime);

		///消失速度
		fade = 0.005 * (rand() % 50);
		A.SetFade(i, fade);

		///初始化大小
		A.SetSize(i, 0.01f);
	}
	return true;
}
extern int aa = 0;
/** 更新粒子 */

void UpdateA()
{
	/** 更新位置 */
	x += vx;
	y += vy;
	z += vz;

	/** 更新速度 */
	vz += az;
	/** 更新生存时间 */
	lifetime -= fade;


	/** 如果粒子消失或生命结束 */
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
/** 初始化速度 */


		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;



		/** 初始化加速度 */
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

		///初始化坐标
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


		///初始化速度
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

		///初始化加速度
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		D.SetAcceleration(i, ax, ay, az);

		///初始化生命周期
		lifetime = 1;
		D.SetLifeTime(i, lifetime);

		///消失速度
		fade = 0.005 * (rand() % 50);
		D.SetFade(i, fade);

		///初始化大小
		D.SetSize(i, 0.01f);
	}
	return true;
}
extern int dd = 0;
/** 更新粒子 */
void UpdateD()
{
	/** 更新位置 */
	x += vx;
	y += vy;
	z += vz;

	/** 更新速度 */
	vz += az;
	/** 更新生存时间 */
	lifetime -= fade;


	/** 如果粒子消失或生命结束 */
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

		/** 初始化速度 */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** 初始化加速度 */
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

		///初始化坐标
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

		///初始化速度
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

		///初始化加速度
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		F.SetAcceleration(i, ax, ay, az);

		///初始化生命周期
		lifetime = 1;
		F.SetLifeTime(i, lifetime);

		///消失速度
		fade = 0.005 * (rand() % 50);
		F.SetFade(i, fade);

		///初始化大小
		F.SetSize(i, 0.01f);
	}
	return true;
}
extern int ff = 0;
/** 更新粒子 */
void UpdateF()
{
	/** 更新位置 */
	x += vx;
	y += vy;
	z += vz;

	/** 更新速度 */
	vz += az;
	/** 更新生存时间 */
	lifetime -= fade;


	/** 如果粒子消失或生命结束 */
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

		/** 初始化速度 */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** 初始化加速度 */
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

		///初始化坐标
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


		///初始化速度
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

		///初始化加速度
		ax = 0;
		ay = -0.0000001f*(rand() % 10 + 8);
		az = 0.000000f;
		L.SetAcceleration(i, ax, ay, az);

		///初始化生命周期
		lifetime = 1;
		L.SetLifeTime(i, lifetime);

		///消失速度
		fade = 0.005 * (rand() % 50);
		L.SetFade(i, fade);

		///初始化大小
		L.SetSize(i, 0.01f);
	}
	return true;
}
extern int ll = 0;
/** 更新粒子 */
void UpdateL()
{
	/** 更新位置 */
	x += vx;
	y += vy;
	z += vz;

	/** 更新速度 */
	vz += az;
	/** 更新生存时间 */
	lifetime -= fade;


	/** 如果粒子消失或生命结束 */
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

		/** 初始化速度 */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** 初始化加速度 */
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

		///初始化坐标
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

		///初始化速度
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

		///初始化加速度
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		N.SetAcceleration(i, ax, ay, az);

		///初始化生命周期
		lifetime = 1;
		N.SetLifeTime(i, lifetime);

		///消失速度
		fade = 0.005 * (rand() % 50);
		N.SetFade(i, fade);

		///初始化大小
		N.SetSize(i, 0.01f);
	}
	return true;
}
extern int nn = 0;
/** 更新粒子 */
void UpdateN()
{
	/** 更新位置 */
	x += vx;
	y += vy;
	z += vz;

	/** 更新速度 */
	vz += az;
	/** 更新生存时间 */
	lifetime -= fade;


	/** 如果粒子消失或生命结束 */
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

		/** 初始化速度 */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** 初始化加速度 */
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

		///初始化坐标
		a = (rand() % 360)*PI / 180;
		x = 0.4*cos(a);
		y = 0.6*sin(a);
		z = 0;
		O.SetPosition(i, x, y, z);



		///初始化速度
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

		///初始化加速度
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		O.SetAcceleration(i, ax, ay, az);

		///初始化生命周期
		lifetime = 1;
		O.SetLifeTime(i, lifetime);

		///消失速度
		fade = 0.005 * (rand() % 50);
		O.SetFade(i, fade);

		///初始化大小
		O.SetSize(i, 0.01f);
	}
	return true;
}
extern int oo = 0;
/** 更新粒子 */
void UpdateO()
{
	/** 更新位置 */
	x += vx;
	y += vy;
	z += vz;

	/** 更新速度 */
	vz += az;
	/** 更新生存时间 */
	lifetime -= fade;


	/** 如果粒子消失或生命结束 */
	if (z >= 1 || lifetime <= 0 || x>0.6 || y>0.8)
	{

		z = 0;

		oo++;

		a = (rand() % 360)*PI / 180;
		x = 0.4*cos(a);
		y = 0.6*sin(a);

		/** 初始化速度 */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** 初始化加速度 */
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

		///初始化坐标
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

		///初始化速度
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

		///初始化加速度
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		W.SetAcceleration(i, ax, ay, az);

		///初始化生命周期
		lifetime = 1;
		W.SetLifeTime(i, lifetime);

		///消失速度
		fade = 0.005 * (rand() % 50);
		W.SetFade(i, fade);

		///初始化大小
		W.SetSize(i, 0.01f);
	}
	return true;
}
extern int ww = 0;
/** 更新粒子 */
void UpdateW()
{
	/** 更新位置 */
	x += vx;
	y += vy;
	z += vz;

	/** 更新速度 */
	vz += az;
	/** 更新生存时间 */
	lifetime -= fade;


	/** 如果粒子消失或生命结束 */
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

		/** 初始化速度 */
		vx = 0.00001 * (rand() % 100);
		vy = 0.00001 * (rand() % 100);
		vz = 0;

		/** 初始化加速度 */
		ax = 0;
		ay = -0.000003f*(rand() % 10 + 8);
		az = 0.000000f;
		lifetime = 10;
		fade = 0.005*(rand() % 50);
	}
}