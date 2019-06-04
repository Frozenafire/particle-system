#pragma once
#include"word.h"
extern CParticle Stone1;
extern CParticle Stone2;
extern CParticle Stone3;
extern GLfloat R;
extern GLfloat sx;
extern GLfloat sy;
extern GLfloat sx1;
extern GLfloat sy1;
extern GLfloat sx2;
extern GLfloat sy2;
bool InitStarLine1();
bool InitStarLine2();
bool InitStarLine3();
void UpdateStarLine1();
void UpdateStarLine2();
void UpdateStarLine3();
void myIdle();