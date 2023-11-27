#include "output.h"

using namespace std;

//Move o cursor do Prompt de Comando para um x e y
void cursorPara(int x, int y)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        return;

    COORD coord = { (SHORT)x, (SHORT)y };
    if (!SetConsoleCursorPosition(hOut, coord))
        return;

    return;
}

//Imprime a matriz tela
void renderizar(void)
{
    if(bFinaldoJogo)
        return;

    //Compara para todas as posicoes da tela se o buffer e diferente da tela a ser impressa
    //se for diferente, o cursor e movido praquela posicao e a tela nova sobrescreve a antiga
    for (int i = 0; i < iAltura; i++)
    {
        for (int j = 0; j < iLargura; j++)
        {
            if(cTela[i][j] != cTelaPass[i][j])
            {
                //O +1 é para levar em conta a borda, alem da margem
                cursorPara((j+iLarguraMargem+1),(i+iAlturaMargem+1));
                cout << cTela[i][j];
            }
        }
    }

    //O mesmo com a pontuacao, mas nesse caso com apenas uma linha
    if(iPontuacao != iPontuacaoPass)
    {
        cursorPara((iLarguraMargem+11), (iAlturaTotal+2));
        cout << iPontuacao;
    }

	//Gera o buffer da pontuacao e da tela, copiando o novo para o buffer
    iPontuacaoPass = iPontuacao;
    for (int i = 0; i < iAltura; ++i)
    {
        for (int j = 0; j < iLargura; ++j)
            {
                cTelaPass[i][j] = cTela[i][j];
            }
    }

    return;
}

//Atualiza a tela antes de imprimir
void atualizarTela()
{
    for (int i = 0; i < iAltura; ++i)
    {
        for (int j = 0; j < iLargura; ++j)
            {
                cTela[i][j] = ' ';
            }
    }


    for (int k = 0; k <= iPontuacao; k++)
    {
        cTela[iCobraY[k]][iCobraX[k]] = 'o';
    }

    cTela[iMacaY][iMacaX] = '*';
    cTela[iY][iX] = 'O';

    return;
}

void desenharPrimeiraTela(void)
{
    for(int i=iAlturaMargem; i < iAlturaTotal; i++)
    {
        int j = iLarguraMargem;
        cPrimeiraTela[i][j] = '|';

        j = iLarguraTotal;
        cPrimeiraTela[i][j] = '|';
    }

    for(int j=iLarguraMargem; j < iLarguraTotal; j++)
    {
        int i = iAlturaMargem;
        cPrimeiraTela[i][j] = '-';

        i = iAlturaTotal;
        cPrimeiraTela[i][j] = '-';
    }

    cPrimeiraTela[iAlturaMargem][iLarguraMargem] = '#';
    cPrimeiraTela[iAlturaMargem][iLarguraTotal] = '#';

    cPrimeiraTela[iAlturaTotal][iLarguraMargem] = '#';
    cPrimeiraTela[iAlturaTotal][iLarguraTotal] = '#';

    return;
}

void imprimirPrimeiraTela(void)
{
    for (int i = 0; i < (iAltura+(iAlturaMargem*2)+1); i++)
    {
        for (int j = 0; j < (iLargura+(iLarguraMargem*2)); j++)
        {
            cursorPara(j,i);
            cout << cPrimeiraTela[i][j];
        }
    }

    cursorPara(iLarguraMargem,(iAlturaTotal+2));
    cout << "Pontuacao: " << iPontuacao;

    return;
}

void redimensionarCMD(int x, int y)
{
    //Deixa o cursor do CMD invisivel
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;

    SetConsoleCursorInfo(hOut, &cursorInfo);

    //Muda o tamanho da tela do CMD
    MoveWindow(GetConsoleWindow(),320,180,x,y,TRUE);
    ShowScrollBar(GetConsoleWindow(), SB_BOTH, FALSE);
    return;
}
