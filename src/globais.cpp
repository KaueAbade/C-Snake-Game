#include "globais.h"

using namespace std;

const int iAlturaMargem = 1;
const int iLarguraMargem = 2;

const int iAltura = 9 * 2.5;
const int iLargura = 16 * 2.5;

const int iAlturaTotal = iAltura + iAlturaMargem + 1;
const int iLarguraTotal = iLargura + iLarguraMargem + 1;

bool bFinaldoJogo;
bool bPause;

const int iTickRateRapido = 100;
const int iTickRateNormal = 150;
const int iTickRateDevagar = 200;

int iTickRate = iTickRateNormal;

int iCobraX[(iAltura * iLargura)];
int iCobraY[(iAltura * iLargura)];
int iMacaX, iMacaY;
int iPontuacao, iPontuacaoPass;

int iX, iY;

char cDirecao;

char cTela[22][40];
char cTelaPass[22][40];
char cPrimeiraTela[25 + 1][43 + 1];
