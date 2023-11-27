#include "menu.h"

using namespace std;

//Gerenciamento de input do menu
char menuInput(void)
{
    char cInput = tolower(getch());
    return cInput;
}

//Menu de configuracao da velocidade
void configuracaoVelocidade(void)
{
    char cInput;
    //O menu se mantém na tela até o usuário retornar ao menu principal
    //demonstrando qual a opcao selecionada
    do
    {
        system("CLS");

        cout << "\n <\t    Configuracao da velocidade\n\n\n\n Selecione uma das opcoes:\n\n";
        cout << " a. Devagar\t";
        if(iTickRate == iTickRateDevagar)
            cout << "(selecionado)";

        cout << "\n\n b. Normal\t";
        if(iTickRate == iTickRateNormal)
            cout << "(selecionado)";

        cout << "\n\n c. Rapida\t";
        if(iTickRate == iTickRateRapido)
            cout << "(selecionado)";

        cursorPara(0,(iAlturaTotal+8));
        cout << " Aperte 'Esc' para voltar";

        cInput = menuInput();

        switch (cInput)
        {
            case 'a':
                iTickRate = iTickRateDevagar;
                break;
            case 'b':
                iTickRate = iTickRateNormal;
                break;
            case 'c':
                iTickRate = iTickRateRapido;
                break;
            default:
                break;
        }
    } while (cInput != 27); //27 é o valor retornado pelo getch() quando o usuario aperta 'Esc'

    return;
}

//Tutorial/Boas vindas, so aparece uma vez por instancia
void tutorial(void)
{
    char cInput;

    do
    {
    system("CLS");

    redimensionarCMD(600,600);

    cout << "\n Este e um 'jogo da cobrinha' (Snake Game)\n\n";
    cout << " E recomendado que o jogo seja 'Executado como\n administrador' para o gerenciamento correto\n do Prompt de Comando\n\n\n\n";
    cout << " Os controles sao:\n\n";
    cout << "   W  \n";
    cout << " A S D\t=\tControle das direcoes da cobra\n\n";
    cout << " 'Esc'\t=\tTermina a sessao atual do jogo\n\n";
    cout << " 'P'\t=\tPausa a sessao atual do jogo\n\n";

    cursorPara(0,(iAlturaTotal+8));
    cout << " Aperte 'Enter' para continuar";

    cInput = menuInput();

    } while(cInput != 13); //13 é o valor retornado pelo getch() quando o usuario aperta 'Enter'

    return;
}

//Menu principal, ou leva para o jogo ou leva para a configuracao
void menu(void)
{
    char cInput;

    do
    {
        system("CLS");

        redimensionarCMD(600,600);

        cout << "\n\t\t  Menu principal\n\n\n\n Selecione uma das opcoes:\n\n";
        cout << " a. Jogar\n\n b. Velocidade da cobra";

        cursorPara(0,(iAlturaTotal+8));
        cout << " Aperte 'Esc' para sair";

        cInput = menuInput();

        switch (cInput)
        {
        case 'a':
            jogo();
            break;
        case 'b':
            configuracaoVelocidade();
            break;
        default:
            break;
        }

    } while (cInput != 27); //27 é o valor retornado pelo getch() quando o usuario aperta 'Esc'

    return;
}
