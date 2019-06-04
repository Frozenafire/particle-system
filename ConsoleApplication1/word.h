#pragma once
#define PI 3.1415927
extern CParticle Word;
extern CParticle A;
extern CParticle D;
extern CParticle F;
extern CParticle L;
extern CParticle N;
extern CParticle O;
extern CParticle W;

extern float x, y, z, vx, vy, vz, ax, ay, az, size, lifetime, fade, dec;
extern int r, g, b;
extern float a;
bool InitA();
bool InitD();
bool InitF();
bool InitL();
bool InitN();
bool InitO();
bool InitW();
void UpdateA();
void UpdateD();
void UpdateF();
void UpdateL();
void UpdateN();
void UpdateO();
void UpdateW();