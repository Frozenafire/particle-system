#include "particle.h"
#include "word.h"
#include "Tree.h"
#include "Snow.h"
#include "Star.h"
GLuint texture[15];//����װ�������Ƶ�����
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
	AUX_RGBImageRec *TextureImage[15];//����װλͼ��Դ������ 

	memset(TextureImage, 0, sizeof(void *) * 2);//��ʼ��ָ������

	char *pictures[] = {// ����һ��λͼ��������
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
		if (TextureImage[i] = LoadBMP(pictures[i]))// ����λͼi�ɹ����޸�״̬��־����StatusΪTRUE
		{
			Status = TRUE;

			glGenTextures(1, &texture[i]);     // Ϊ��i��λͼ��������
			glBindTexture(GL_TEXTURE_2D, texture[i]);// �����ɵ���������ư󶨵�ָ����������
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[i]->sizeX, TextureImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[i]->data);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		if (TextureImage[i])         // �ͷ�λͼ����ռ�õ��ڴ�ռ�
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

	/** �����ٶ� */
	vy += ay;
}

void Tree_DrawGround()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(0, 0.0f, 1.0f, 0.0f);

	/** ָ������ */
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glColor4ub(255, 255, 255, 255);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5, -1.0f, 5);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5, -1.0f, 5);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5, -1.0f, -5);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5, -1.0f, -5);
	glEnd();

	//���Ļ���
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
	/** ������ */
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	for (int i = 0; i < F.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		F.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 2.8, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 2.8, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 2.8, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 2.8, y - size, z);
		glEnd();

		/** ������������ */
		UpdateF();
		F.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < A.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		A.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 2.1, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 2.1, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 2.1, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 2.1, y - size, z);
		glEnd();

		/** ������������ */
		UpdateA();
		A.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}
	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		L.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 1.25, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 1.25, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 1.25, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 1.25, y - size, z);
		glEnd();

		/** ������������ */
		UpdateL();
		L.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		L.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 0.6, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 0.6, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 0.6, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 0.6, y - size, z);
		glEnd();

		/** ������������ */
		UpdateL();
		L.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < D.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		D.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 0.2, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 0.2, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 0.2, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 0.2, y - size, z);
		glEnd();

		/** ������������ */
		UpdateD();
		D.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < O.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		O.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 1.25, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 1.25, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 1.25, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 1.25, y - size, z);
		glEnd();

		/** ������������ */
		UpdateO();
		O.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < W.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		W.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 2.4, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 2.4, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 2.4, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 2.4, y - size, z);
		glEnd();

		/** ������������ */
		UpdateW();
		W.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < N.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		N.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 3.7, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 3.7, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 3.7, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 3.7, y - size, z);
		glEnd();

		/** ������������ */
		UpdateN();
		N.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}



	glutPostRedisplay();
}

void DrawParticleDown()
{

	for (int i = 0; i < F.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		F.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 2.8, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 2.8, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 2.8, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 2.8, y - size, z);
		glEnd();

		/** ������������ */
		UpdateDown();
		F.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < A.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		A.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 2.1, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 2.1, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 2.1, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 2.1, y - size, z);
		glEnd();

		/** ������������ */
		UpdateDown();
		A.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}
	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		L.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 1.25, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 1.25, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 1.25, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 1.25, y - size, z);
		glEnd();

		/** ������������ */
		UpdateDown();
		L.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < L.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		L.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size - 0.6, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size - 0.6, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size - 0.6, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size - 0.6, y - size, z);
		glEnd();

		/** ������������ */
		UpdateDown();
		L.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < D.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		D.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 0.2, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 0.2, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 0.2, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 0.2, y - size, z);
		glEnd();

		/** ������������ */
		UpdateDown();
		D.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < O.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		O.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 1.25, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 1.25, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 1.25, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 1.25, y - size, z);
		glEnd();

		/** ������������ */
		UpdateDown();
		O.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < W.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		W.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 2.4, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 2.4, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 2.4, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 2.4, y - size, z);
		glEnd();

		/** ������������ */
		UpdateDown();
		W.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
	}

	for (int i = 0; i < N.GetNumOfParticle(); ++i)
	{
		/** ������ӵ��������� */
		N.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glColor4ub(r, g, b, 255);
		glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */
										/** �������� */
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x - size + 3.7, y - size, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x - size + 3.7, y + size, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size + 3.7, y + size, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size + 3.7, y - size, z);
		glEnd();

		/** ������������ */
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
			/** ������ӵ��������� */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */

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

			/** ������������ */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

		if (i % 5 == 1) {
			glBindTexture(GL_TEXTURE_2D, texture[5]);
			/** ������ӵ��������� */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */

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

			/** ������������ */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

		if (i % 5 == 2) {
			glBindTexture(GL_TEXTURE_2D, texture[6]);
			/** ������ӵ��������� */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */

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

			/** ������������ */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

		if (i % 5 == 3) {
			glBindTexture(GL_TEXTURE_2D, texture[7]);
			/** ������ӵ��������� */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */

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

			/** ������������ */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

		if (i % 5 == 4) {
			glBindTexture(GL_TEXTURE_2D, texture[8]);
			/** ������ӵ��������� */
			Tree.GetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -6.0f);
			glColor4ub(r, g, b, 255);
			glNormal3f(0.0f, 0.0f, 1.0f);   /**< ���巨�߷��� */

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

			/** ������������ */
			UpdateTree();
			Tree.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
		}

	}
	glutPostRedisplay();//������Ⱦ����
}
void DrawParticleStar()
{
	/** ������ */
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

		/** ������������ */
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

		/** ������������ */
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

		/** ������������ */
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
/** �������� */
void DrawParticleSnow()
{
	/** ������ */
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

		/** ������������ */
		UpdateSnow();
		Snow.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
	}
	glutPostRedisplay();
}
void DrawParticleSnowByWind()
{
	/** ������ */
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

		/** ������������ */
		UpdateSnowByWind();
		Snow.SetAll(i, r, g, b, x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, dec);
	}
	glutPostRedisplay();
}
/** ��ʼ�� */
void init(void)
{
	/** �û��Զ���ĳ�ʼ������ */
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);//ָ����Ȼ����������ֵ(������Ȼ��������ֵ����Ϊ1)
	glDepthFunc(GL_LEQUAL);//ָ��������Ȼ���Ƚ�ֵ(���½��������ֵ��ԭ����1�Ƚϣ�<=��ͨ����������)
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_TEXTURE_2D);             /**< ��������ӳ�� */
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);    /**< ���û�����ӻ�ð�͸��Ч�� */
	glEnable(GL_BLEND);                  /**< ���û�� */

										 /**  �������� */
	if (!LoadGLTextures())
	{
		printf("bmp load failed");
		exit(-1);
	}

	/** ����5000������ */
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
	/** ��ʼ������ */
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

	//��������
	DrawParticleWord();

	glFlush();
}
void displayDown(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	//����FALL DOWN
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
	glViewport(0, 0, width, height);    /**< ���������ӿ� */
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
	glutAddMenuEntry("��", 7);
	glutAddMenuEntry("��", 8);
	glutAddMenuEntry("��", 9);
	glutAddMenuEntry("��", 10);
	glutAddMenuEntry("��", 11);
	glutAddMenuEntry("��", 12);
	glutAddMenuEntry("�Ƴ�", 13);
	glutAddMenuEntry("�Ⱥ�", 14);
	glutAddMenuEntry("����", 15);
	glutAddMenuEntry("����", 16);
	glutAddMenuEntry("����", 17);
	glutAddMenuEntry("�̻�", 18);
	glutAddMenuEntry("��", 19);
	int crewordmenu = glutCreateMenu(processMenuEvents);
	glutAddSubMenu("RGB Menu", colormenu);
	glutAddMenuEntry("��������", 1);
	glutAddMenuEntry("����", 2);
	int cresnowmenu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("����ѩ��", 3);
	glutAddMenuEntry("�η��µ�ѩ��", 4);
	int menu = glutCreateMenu(processMenuEvents);
	glutAddSubMenu("Fall Down", crewordmenu);
	glutAddSubMenu("ѩ��", cresnowmenu);
    glutAddMenuEntry("ӣ����", 5);
	glutAddMenuEntry("����", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv)
{
	r = 255; g = 255; b = 255;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("������ĸ");
	init();
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(displayWord);
	MakeMenu();
	glutMainLoop();
	return 0;
}