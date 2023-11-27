#pragma once

#include <vector>

using namespace std;

extern const int iAlturaMargem;
extern const int iLarguraMargem;

extern const int iAltura;
extern const int iLargura;

extern const int iAlturaTotal;
extern const int iLarguraTotal;

extern bool bFinaldoJogo;
extern bool bPause;

extern const int iTickRateRapido;
extern const int iTickRateNormal;
extern const int iTickRateDevagar;

extern int iTickRate;

extern int iCobraX[];
extern int iCobraY[];
extern int iMacaX, iMacaY;
extern int iPontuacao, iPontuacaoPass;

extern int iX, iY;

extern char cDirecao;

extern vector<vector<char>> cTela;
extern vector<vector<char>> cTelaPass;
extern vector<vector<char>> cPrimeiraTela;
