#include "particle.h"
#include "word.h"
#include "Tree.h"
#include "Snow.h"
#include "Star.h"
GLuint texture[15];//用于装纹理名称的数组
float angle = 0;
AUX_RGBImageRec *LoadBMP(char *Filename)
{
	FILE *File = NULL;

	if (!Filename)
	{
		return NULL;
	}

	File = fopen(Filename, "r");

	if (File)
	{
		fclose(File);
		return auxDIBImageLoad(Filename);
	}

	return NULL;
}
int LoadGLTextures()
{
	int Status = FALSE;
	AUX_RGBImageRec *TextureImage[15];//用于装位图资源的数组 

	memset(TextureImage, 0, sizeof(void *) * 2);//初始化指针数组

	char *pictures[] = {// 创建一个位图名称数组
		"Debug/wall.bmp",
		"Debug/snowball.bmp",
		"Debug/ground.bmp",
		"Debug/tree.bmp",
		"Debug/flower.bmp",
		"Debug/flower1.bmp",
		"Debug/flower2.bmp",
		"Debug/flower3.bmp",
		"Debug/flower4.bmp",
		"Debug/sky.bmp",
		"Debug/wall_2.bmp",
		"Debug/snow.bmp",
		"Debug/tree_2.bmp",
		"Debug/stone.bmp",
		"Debug/moon.bmp",
	};

	for (int i = 0; i < 15; i++)
	{
		if (TextureImage[i] = LoadBMP(pictures[i]))// 加载位图i成功，修改状态标志变量Status为TRUE
		{
			Status = TRUE;

			glGenTextures(1, &texture[i]);     // 为第i个位图创建纹理
			glBindTexture(GL_TEXTURE_2D, texture[i]);// 将生成的纹理的名称绑定到指定的纹理上
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[i]->sizeX, TextureImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[i]->data);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		if (TextureImage[i])         // 释放位图数组占用的内存空间
		{
			if (TextureImage[i]->data)
			{
				free(TextureImage[i]->data);
			}

			free(TextureImage[i]);
		}
	}
	return Status;
}
void UpdateDown()
{
	x += vx;
	y += vy;
	z += vz;

	/** 更新速度 */
	vy += ay;
}

void Tree_DrawGround()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(0, 0.0f, 1.0f, 0.0f);

	/** 指定纹理 */
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5, -1.0f, 5);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5, -1.0f, 5);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5, -1.0f, -5);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5, -1.0f, -5);
	glEnd();

	//树的绘制
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2, -1.0, -1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2, -1.0, -1);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2, 2.15f, -1);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2, 2.15f, -1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1, -1.0, 1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4, -1.0, 1);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(4, 2.15f, 1);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1, 2.15f, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5, -1.0, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1, -1.0, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1, 2.15f, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5, 2.15f, 0);
	glEnd();


}

void DrawParticleWord()
{
	/** 绑定纹理 */
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	for (int i = 0; i < F.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		F.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 2.8, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 2.8, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 2.8, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 2.8, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateF();
		F.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < A.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		A.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 2.1, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 2.1, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 2.1, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 2.1, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateA();
		A.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}
	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		L.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 1.25, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 1.25, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 1.25, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 1.25, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateL();
		L.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		L.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 0.6, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 0.6, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 0.6, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 0.6, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateL();
		L.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < D.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		D.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 0.2, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 0.2, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 0.2, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 0.2, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateD();
		D.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < O.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		O.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 1.25, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 1.25, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 1.25, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 1.25, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateO();
		O.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < W.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		W.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 2.4, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 2.4, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 2.4, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 2.4, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateW();
		W.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < N.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		N.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 3.7, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 3.7, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 3.7, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 3.7, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateN();
		N.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}



	glutPostRedisplay();
}

void DrawParticleDown()
{

	for (int i = 0; i < F.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		F.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 2.8, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 2.8, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 2.8, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 2.8, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateDown();
		F.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < A.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		A.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 2.1, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 2.1, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 2.1, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 2.1, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateDown();
		A.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}
	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		L.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 1.25, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 1.25, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 1.25, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 1.25, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateDown();
		L.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		L.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 0.6, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 0.6, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 0.6, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 0.6, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateDown();
		L.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < D.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		D.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 0.2, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 0.2, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 0.2, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 0.2, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateDown();
		D.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < O.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		O.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 1.25, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 1.25, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 1.25, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 1.25, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateDown();
		O.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < W.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		W.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 2.4, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 2.4, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 2.4, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 2.4, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateDown();
		W.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < N.GetNumOfParticle(); ++i)
	{
		/** 获得粒子的所有属性 */
		N.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */
										/** 画出粒子 */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 3.7, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 3.7, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 3.7, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 3.7, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateDown();
		N.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}



	glutPostRedisplay();
}
void DrawParticleTree()
{

	for (int i = 0; i<Tree.GetNumOfParticle(); ++i)
	{
		if (i % 5 == 0) {
			glBindTexture(GL_TEXTURE_2D, texture[4]);
			/** 获得粒子的所有属性 */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */

			angle += 0.00001f;
			if (angle == 360.0f) {
				angle = 0;
			}
			glRotatef(angle, x, y, z);

			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
			glEnd();

			/** 更新粒子属性 */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

		if (i % 5 == 1) {
			glBindTexture(GL_TEXTURE_2D, texture[5]);
			/** 获得粒子的所有属性 */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */

			angle += 0.00001f;
			if (angle == 360.0f) {
				angle = 0;
			}
			glRotatef(angle, x, y, z);

			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
			glEnd();

			/** 更新粒子属性 */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

		if (i % 5 == 2) {
			glBindTexture(GL_TEXTURE_2D, texture[6]);
			/** 获得粒子的所有属性 */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */

			angle += 0.00001f;
			if (angle == 360.0f) {
				angle = 0;
			}
			glRotatef(angle, x, y, z);

			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
			glEnd();

			/** 更新粒子属性 */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

		if (i % 5 == 3) {
			glBindTexture(GL_TEXTURE_2D, texture[7]);
			/** 获得粒子的所有属性 */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */

			angle += 0.00001f;
			if (angle == 360.0f) {
				angle = 0;
			}
			glRotatef(angle, x, y, z);

			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
			glEnd();

			/** 更新粒子属性 */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

		if (i % 5 == 4) {
			glBindTexture(GL_TEXTURE_2D, texture[8]);
			/** 获得粒子的所有属性 */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< 定义法线方向 */

			angle += 0.00001f;
			if (angle == 360.0f) {
				angle = 0;
			}
			glRotatef(angle, x, y, z);

			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
			glEnd();

			/** 更新粒子属性 */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

	}
	glutPostRedisplay();//发送渲染请求
}
void DrawParticleStar()
{
	/** 绑定纹理 */
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	for (int i = 0; i<Stone1.GetNumOfParticle(); ++i)
	{

		Stone1.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);
		angle += 0.05f;
		if (angle == 360.0f)
		{
			angle = 0;
		}
		glRotatef(angle, x, y, z);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateStarLine1();
		Stone1.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
	}

	for (int i = 0; i<Stone2.GetNumOfParticle(); ++i)
	{

		Stone2.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);
		angle += 0.05f;
		if (angle == 360.0f)
		{
			angle = 0;
		}
		glRotatef(angle, x, y, z);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateStarLine2();
		Stone2.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
	}

	for (int i = 0; i<Stone3.GetNumOfParticle(); ++i)
	{

		Stone3.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);
		angle += 0.05f;
		if (angle == 360.0f)
		{
			angle = 0;
		}
		glRotatef(angle, x, y, z);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateStarLine3();
		Stone3.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
	}

	glutPostRedisplay();
}
void Snow_DrawGround()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(0, 0.0f, 1.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5, -1.0f, 5);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10, -1.0f, -5);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10, -1.0f, -5);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(5, -1.0f, 5);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1, -1.0f, -2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, -1.0f, -2);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 1.0f, -2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1, 1.0f, -2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2, -1.0f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(3, -1.0f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(3, 1.0f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2, 1.0f, -0.5f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, -1.0f, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1, -1.0f, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1, 1.0f, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 1.0f, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-3, -1.0f, 1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2, -1.0f, 1);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2, 1.0f, 1);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-3, 1.0f, 1);
	glEnd();

	glPopMatrix();
}
void Star_DrawGround()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(0, 0.0f, 1.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(sx, sy, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(sx, sy + 0.5f, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(sx - 0.5f, sy + 0.5f, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(sx - 0.5f, sy, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(sx1, sy1, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(sx1, sy1 + 0.5f, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(sx1 - 0.5f, sy1 + 0.5f, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(sx1 - 0.5f, sy1, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(sx2, sy2, -1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(sx2, sy2 + 0.5f, -1);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(sx2 - 0.5f, sy2 + 0.5f, -1);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(sx2 - 0.5f, sy2, -1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[14]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5, -2, 3);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5, -2, 3);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5, 0, -4);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5, 0, -4);
	glEnd();

	glPopMatrix();
}

float angles = 0.0f;
/** 绘制粒子 */
void DrawParticleSnow()
{
	/** 绑定纹理 */
	glBindTexture(GL_TEXTURE_2D, texture[11]);

	for (int i = 0; i<Snow.GetNumOfParticle(); ++i)
	{
		Snow.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);

		angles += 0.001f;
		if (angles == 360.0f) {
			angles = 0;
		}

		glRotatef(angles, x, y, z);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateSnow();
		Snow.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
	}
	glutPostRedisplay();
}
void DrawParticleSnowByWind()
{
	/** 绑定纹理 */
	glBindTexture(GL_TEXTURE_2D, texture[11]);

	for (int i = 0; i<Snow.GetNumOfParticle(); ++i)
	{
		Snow.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);

		angles += 0.001f;
		if (angles == 360.0f) {
			angles = 0;
		}

		glRotatef(angles, x, y, z);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y - size, z);
		glEnd();

		/** 更新粒子属性 */
		UpdateSnowByWind();
		Snow.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
	}
	glutPostRedisplay();
}
/** 初始化 */
void init(void)
{
	/** 用户自定义的初始化过程 */
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);//指定深度缓冲区的清除值(即将深度缓冲区里的值设置为1)
	glDepthFunc(GL_LEQUAL);//指定用于深度缓冲比较值(即新进像素深度值与原来的1比较，<=则通过，否则丢弃)
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_TEXTURE_2D);             /**< 开启纹理映射 */
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);    /**< 设置混合因子获得半透明效果 */
	glEnable(GL_BLEND);                  /**< 启用混和 */

										 /**  载入纹理 */
	if (!LoadGLTextures())
	{
		printf("bmp load failed");
		exit(-1);
	}

	/** 创建5000个粒子 */
	A.Create(5000);
	D.Create(5000);
	F.Create(5000);
	L.Create(5000);
	N.Create(5000);
	O.Create(5000);
	W.Create(5000);
	Tree.Create(600);
	Snow.Create(1000);
	Stone1.Create(3000);
	Stone2.Create(3000);
	Stone3.Create(3000);
	/** 初始化粒子 */
	InitA();
	InitD();
	InitF();
	InitL();
	InitN();
	InitO();
	InitW();
	InitTree();
	InitSnow();
}
void displayWord(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//绘制文字
	DrawParticleWord();

	glFlush();
}
void displayDown(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	//绘制FALL DOWN
	DrawParticleDown();

	glFlush();
}
void displayTree(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Tree_DrawGround();
	DrawParticleTree();


	glFlush();
}
void displaySnow(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	Snow_DrawGround();
	DrawParticleSnow();

	glFlush();
}
void displaySnowByWind(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Snow_DrawGround();
	DrawParticleSnowByWind();

	glFlush();
}
void displayStar(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Star_DrawGround();
	DrawParticleStar();
	glutIdleFunc(myIdle);
	glFlush();
}
void ChangeSize(int width, int height)
{
	glViewport(0, 0, width, height);    /**< 重新设置视口 */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1700.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void processMenuEvents(int option)
{
	switch (option)
	{
	case 1:glutDisplayFunc(displayWord); break;
	case 2:glutDisplayFunc(displayDown); break;
	case 3:InitSnow(); glutDisplayFunc(displaySnow); break;
	case 4:InitSnowByWind(); glutDisplayFunc(displaySnowByWind); break;
	case 5:InitTree(); glutDisplayFunc(displayTree); break;
	case 6:r = 227; g = 35; b = 34; InitStarLine1(); InitStarLine2(); InitStarLine3(); glutDisplayFunc(displayStar); break;
	case 7:r = 227; g = 35; b = 34; init(); glutDisplayFunc(displayWord); break;
	case 8:r = 244; g = 229; b = 0; init(); glutDisplayFunc(displayWord); break;
	case 9:r = 38; g = 113; b = 178; init(); glutDisplayFunc(displayWord); break;
	case 10:r = 0; g = 142; b = 91; init(); glutDisplayFunc(displayWord); break;
	case 11:r = 241; g = 145; b = 1; init(); glutDisplayFunc(displayWord); break;
	case 12:r = 109; g = 56; b = 137; init(); glutDisplayFunc(displayWord); break;
	case 13:r = 253; g = 198; b = 11; init(); glutDisplayFunc(displayWord); break;
	case 14:r = 234; g = 98; b = 31; init(); glutDisplayFunc(displayWord); break;
	case 15:r = 196; g = 3; b = 125; init(); glutDisplayFunc(displayWord); break;
	case 16:r = 68; g = 78; b = 153; init(); glutDisplayFunc(displayWord); break;
	case 17:r = 6; g = 150; b = 187; init(); glutDisplayFunc(displayWord); break;
	case 18:r = 140; g = 187; b = 38; init(); glutDisplayFunc(displayWord); break;
	case 19:r = 255; g = 255; b = 255; init(); glutDisplayFunc(displayWord); break;
	}
}

void MakeMenu(void)
{

	int colormenu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("红", 7);
	glutAddMenuEntry("黄", 8);
	glutAddMenuEntry("蓝", 9);
	glutAddMenuEntry("绿", 10);
	glutAddMenuEntry("橙", 11);
	glutAddMenuEntry("紫", 12);
	glutAddMenuEntry("黄橙", 13);
	glutAddMenuEntry("橙红", 14);
	glutAddMenuEntry("红紫", 15);
	glutAddMenuEntry("紫蓝", 16);
	glutAddMenuEntry("蓝绿", 17);
	glutAddMenuEntry("绿黄", 18);
	glutAddMenuEntry("白", 19);
	int crewordmenu = glutCreateMenu(processMenuEvents);
	glutAddSubMenu("RGB Menu", colormenu);
	glutAddMenuEntry("生成文字", 1);
	glutAddMenuEntry("下落", 2);
	int cresnowmenu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("产生雪景", 3);
	glutAddMenuEntry("刮风下的雪景", 4);
	int menu = glutCreateMenu(processMenuEvents);
	glutAddSubMenu("Fall Down", crewordmenu);
	glutAddSubMenu("雪景", cresnowmenu);
    glutAddMenuEntry("樱花树", 5);
	glutAddMenuEntry("流星", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv)
{
	r = 255; g = 255; b = 255;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("粒子字母");
	init();
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(displayWord);
	MakeMenu();
	glutMainLoop();
	return 0;
}