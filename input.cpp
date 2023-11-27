#include "input.h"

//Verifica se o input e valido
bool inputValido(char cDirecaoNova)
{
    switch(cDirecaoNova)
    {
        case 'a':
        {
            if(cDirecao == 'r' && iPontuacao != 0)
            {
                return false;
            }
            break;
        }
        case 'd':
        {
            if(cDirecao == 'l' && iPontuacao != 0)
            {
                return false;
            }
            break;
        }
        case 'w':
        {
            if(cDirecao == 'd' && iPontuacao != 0)
            {
                return false;
            }
            break;
        }
        case 's':
        {
            if(cDirecao == 'u' && iPontuacao != 0)
            {
                return false;
            }
            break;
        }
    }

    return true;
}

//Input do jogo
void gameInput(void)
{
	if (kbhit()) //Checa se o usuario entrou uma tecla
    {
        char cInput = tolower(getch()); //Armazena qual tecla

		switch (cInput) //Checa qual tecla
        {
        case 'a':
        {
            if(inputValido(cInput))
                cDirecao = 'l';
            break;
        }
        case 'd':
        {
            if(inputValido(cInput))
                cDirecao = 'r';
            break;
        }
        case 'w':
        {
            if(inputValido(cInput))
                cDirecao = 'u';
            break;
        }
        case 's':
        {
            if(inputValido(cInput))
                cDirecao = 'd';
            break;
        }
        case 'p':
            bPause = true;
            break;
        case 27: //27 é o valor retornado pelo getch() quando o usuario aperta 'Esc'
            bFinaldoJogo = true;
            break;
        default:
            break;
        }
	}

	return;
}
