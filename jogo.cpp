#include "jogo.h"

using namespace std::chrono;

//Checa se a maca criada e valida
bool posicaoInvalida(int x, int y)
{
    if (iX == x && iY == y)
        return true;

    for (int k = 0; k < iPontuacao; k++)
    {
        if (iCobraY[k] == y && iCobraX[k] == x)
            return true;
    }

    return false;
}

//Cria uma maca
void criarMaca(void)
{
    bool bMacaValida;

    do
    {
        bMacaValida = true;

        //Gera uma maca em uma posicao randomica, limitada ao tamanho do tabuleiro
        iMacaX = rand() % iLargura;
        iMacaY = rand() % iAltura;

        //Checa se a maca tem posicao igual a de alguma parte da cobra, se sim a regera
        if (posicaoInvalida(iMacaX, iMacaY))
            bMacaValida = false;
    } while(!bMacaValida);

    return;
}

//Checa colisao
void checarColisao(void)
{
    if (iX == iMacaX && iY == iMacaY)
    {
        iPontuacao++;
        criarMaca();
    }

    //Checa se a posicao da cabeca coincide com a parede
    if (iX >= iLargura || iX < 0 || iY >= iAltura || iY < 0)
    {
        bFinaldoJogo = true;
    }

    //Checa se a cabeca tem posicao igual a de alguma parte da cobra
    for (int k = 1; k <= iPontuacao; k++)
    {
        if (iCobraY[k] == iY && iCobraX[k] == iX)
        {
            bFinaldoJogo = true;
        }
    }

    return;
}

//Atualiza o jogo no "backend"
void atualizarJogo(void)
{
    switch (cDirecao)
    {
    case 'l':
        iX--;
        break;
    case 'r':
        iX++;
        break;
    case 'u':
        iY--;
        break;
    case 'd':
        iY++;
        break;
    }

    checarColisao();

    for (int i = iPontuacao; i > 0; i--)
    {
        iCobraX[i] = iCobraX[i - 1];
        iCobraY[i] = iCobraY[i - 1];
    }

    iCobraX[0] = iX;
    iCobraY[0] = iY;

    return;
}

//Inicio do jogo
void iniciarJogo(void)
{
    system("CLS");

    redimensionarCMD(573,600);

	//Define a seed da funcao rand() como o tempo atual
    srand(time(NULL));

    //Limpa todas as variaveis não definidas
    bFinaldoJogo = false;
    bPause = false;
    cDirecao = ' ';
	iPontuacao = 0;
	iPontuacaoPass = iPontuacao;

	//"Seta" as matrizes para ' ' em toda memoria igual
    for (int i = 0; i < iAltura; ++i)
    {
        for (int j = 0; j < iLargura; ++j)
            {
                cTela[i][j] = ' ';
                cTelaPass[i][j] = ' ';
            }
    }

    for (int i = 0; i < iAlturaTotal; ++i)
    {
        for (int j = 0; j < iLarguraTotal; ++j)
            {
                cPrimeiraTela[i][j] = ' ';
            }
    }

    //"Seta" os vetores para ' ' em toda memoria igual
    memset((char*)iCobraX, ' ', iLargura);
    memset((char*)iCobraY, ' ', iAltura);

	//Cria a primeira maca
    criarMaca();

	//Define uma area de nascimento aceitavel para a cobra (meio do tabuleiro e em x = 4)
	int iAreaDeNascX = iLargura/4;
	int iAreaDeNascY = iAltura/4;

	//Cobra nasce em um Y randomizado dentro da area de nascimento aceitavel
	iX = rand() % iAreaDeNascX + iAreaDeNascX;
	iY = rand() % iAreaDeNascY + iAreaDeNascY;

    //Desenha e imprime a primeira tela, com a pontuação vazia, o espaço vazio da matriz tela e a borda
    desenharPrimeiraTela();
    imprimirPrimeiraTela();

    return;
}

//Loop do jogo
void jogo(void)
{
    char cInput;

    //Inicia e gera o primeiro jogo
    iniciarJogo();

    do
    {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        atualizarJogo();
        gameInput();
        atualizarTela();
        renderizar();
        if(bPause)
        {
            do
            {
                cInput = menuInput();
            } while(cInput != 'p');
            bPause = false;
        }

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::milli> time_span = t2 - t1;

        int deltaTempo = iTickRate - time_span.count();

        if(deltaTempo<0)
            deltaTempo = 0;

        Sleep(deltaTempo);
    } while(!bFinaldoJogo);

    int iFimdoJogoX = (iLarguraMargem+(iLarguraTotal/3))+1;
    int iFimdoJogoY = (iAlturaMargem+(iAlturaTotal/2))-1;

    cursorPara(iFimdoJogoX,iFimdoJogoY);
    cout << "Fim do jogo";

    cursorPara(iLarguraMargem,(iAlturaTotal+7));
    cout << "Aperte 'Enter' para jogar novamente ou 'E-";

    cursorPara(iLarguraMargem,(iAlturaTotal+8));
    cout << "sc' para voltar ao menu principal";

    do
    {
        cInput = menuInput();

        switch (cInput)
        {
        case 13:
            jogo();
            break;
        default:
            break;
        }
    } while(cInput != 27); //27 é o valor retornado pelo getch() quando o usuario aperta 'Esc'

    return;
}
