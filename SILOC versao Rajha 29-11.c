#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int hora; //hora do dia (universal)

typedef struct cadastroCliente
{
    int codCliente;
    char nome[50];
    char endereco[100];
    char telefone[17];
} Cliente;

typedef struct cadastroFuncionario
{
    int codFuncionario;
    char nome[50];
    char telefone[17];
    char cargo[50];
    float salario;
} Funcionario;

typedef struct cadastroLocacao
{
    int codLocacao;
    int dataRetirada;
    int dataDevolucao;
    char seguro[50];
    int qtdDias;
    int codCliente;
    int codVeiculo;
} Locacao;

typedef struct
{
    int codVeiculo;
    char descricao[50];
    char modelo[20];
    char placa[8];
    char cor[20];
    float valorDiaria;
    int qtdeOcupantes;
    char status[8]; //ocupado ou livre
} Veiculo;

void cadastraFunc();
void listaFunc();
void cadastroVeiculo();
void listaVeic();
void statusVeic();
void cadastraClie();
void pesquisaClie();
void consultaClie();
void novaLoc();
void consuLoc();
void baixaLoc();
void totLoc();


int main()
{
    FILE *locacao;
    FILE *cliente;
    FILE *funcionario;
    FILE *veiculo;

    setlocale(LC_ALL, "portuguese");

    int escolha;

    int cod, opcao=0, opfun=0,i;
    do
    {
        printf("\n--------------------------------------\n");
        printf("          MENU PRINCIPAL\n");
        printf("\n--------------------------------------\n");
        printf("      1 - Menu funcion�rio\n");
        printf("      2 - Menu ve�culo\n");
        printf("      3 - Menu cliente\n");
        printf("      4 - Menu loca��es\n");
        printf("      5 - Sair\n");
        printf("\n--------------------------------------\n");
        printf("\n  Digite o n�mero da opera��o desejada: ");
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
            system("cls");
            printf("\n-----------MENU FUNCION�RIO----------------\n");
            printf("\n    1 - Cadastrar funcion�rio\n");
            printf("      2 - Pesquisar funcion�rio\n");
            printf("      3 - Sair\n");
            printf("\n----------------------------------------\n");
            printf("\n Digite o n�mero da opera��o desejada: ");
            scanf("%d", &opfun);
            system("cls");
            switch(opfun)
            {
            case 1:
                cadastraFunc();
                break;
            case 2:
                listaFunc();
                break;
            case 3:
                system("cls");
                break;
            default:
                printf("Op��o inv�lida\n\n");
                system("pause");
                system("cls");
            }
            break;

        case 2:
            system("cls");
            printf("\n-------------MENU VE�CULO----------------\n");
            printf("\n      1 - Cadastrar ve�culo \n");
            printf("        2 - Pesquisar ve�culo \n");
            printf("        3 - Consultar status ve�culo \n");
            printf("        4 - Sair\n");
            printf("\n------------------------------------------\n");
            printf("\n Digite o n�mero da opera��o desejada: ");
            scanf("%d", &opfun);
            system("cls");
            switch(opfun)
            {
            case 1:
                cadastroVeiculo();
                break;
            case 2:
                listaVeic();
                break;
            case 3:
                statusVeic();
                break;
            case 4:
                system("cls");
                break;

            default:
                printf("\n\nOp��o inv�lida\n\n");
                system("pause");
                system("cls");
            }
            break;

        case 3:
            system("cls");
            printf("\n-------------MENU CLIENTE----------------\n");
            printf("\n    1 - Cadastrar cliente\n");
            printf("      2 - Pesquisar cliente\n");
            printf("      3 - Consultar loca��es do cliente\n");
            printf("      4 - Sair\n");
            printf("\n------------------------------------------\n");
            printf("\nDigite o n�mero da opera��o desejada: ");
            scanf("%d", &opfun);
            system("cls");
            switch(opfun)
            {
            case 1:
                cadastraClie();
                break;
            case 2:
                pesquisaClie();
                break;
            case 3:
                consultaClie();
                break;
            case 4:
                system("cls");
                break;
            default:
                printf("Op��o inv�lida\n\n");
                system("pause");
                system("cls");
            }

            break;
        case 4:
            system("cls");
            printf("\n---------------MENU LOCA��ES-----------------\n");
            printf("\n       1 - Nova loca��o\n");
            printf("         2 - Consulta de loca��es\n");
            printf("         3 - Total de loca��es\n");
            printf("         4 - Dar baixa em loca��o\n");
            printf("         5 - Sair\n");
            printf("\n----------------------------------------------\n");
            printf("Digite o n�mero da opera��o desejada: ");
            scanf("%d", &opfun);
            system("cls");
            switch(opfun)
            {
            case 1:
                novaLoc();
                break;
            case 2:
                consuLoc();
                break;
            case 3:
                totLoc();
                break;
            case 4:
                baixaLoc();
                break;
            case 5:
                system("cls");
                break;
            default:
                printf("Op��o inv�lida\n\n");
                system("pause");
                system("cls");
            }

            break;

        case 5:
            printf("\n---Sair---\n");
            break;

        default:
            printf("Op��o inv�lida!");
            system("pause");
            system("cls");
        }
    }
    while (opcao != 5);
    return 0;

}


//--------------------------FUN��ES FUNCION�RIOS----------------------------
//FUNCIONARIO = c�digo, nome, telefone, cargo, salario

void cadastraFunc()
{

    Funcionario vet_funcionario;

    if ((funcionario = fopen("funcionario.dat","a+b")) == NULL)
    {
        printf("Erro de abertura do arquivo. \n");
        exit(1);
    }
    else
    {
        printf("Informe o c�digo do funcion�rio: \n");
        scanf("%d", &vet_funcionario.codfuncionario);

        printf("Informe o nome do funcion�rio: \n");
        fflush(stdin);
        gets(vet_funcionario.nome);

        printf("Informe o sal�rio do funcion�rio: \n");
        fflush(stdin);
        gets(vet_funcionario.salario);

        printf("Informe o cargo do funcion�rio:\n");
        fflush(stdin);
        gets(vet_funcionario.cargo);

    }
    fseek(funcionario,0,SEEK_END);
    fwrite(&funcionario,sizeof(funcionario),1,funcionario);
    fclose(funcionario);
    system("pause");
    system("cls");
}

void listaFunc  // alterar dados da fun��o
{

    int posicao=-1,achou=0;
    mercadoria m;
    fseek(f,0,SEEK_SET);
    fread(&m, siieof(m),1, f);
    while (!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao = posicao +1;
        if (m.codigo==codigo)
        {
            achou=1;
        }
        fread(&m, siieof(m),1, f);
    }
    if (achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}



//----------------------------FUN��ES VE�CULO--------------------------------


void cadastroVeiculo(FILE *veiculo)
{

    Veiculo vet_veiculo;

    if ((veiculo = fopen("veiculo.dat","a+b")) == NULL)
    {
        printf("Erro de abertura do arquivo. \n");
        exit(1);
    }
    else
    {
        printf("Informe o c�digo do ve�culo: \n");
        scanf("%d", &vet_veiculo.codVeiculo);

        printf("Informe o modelo: \n");
        fflush(stdin);
        gets(vet_veiculo.modelo);

        printf("Informe a cor do ve�culo: \n");
        fflush(stdin);
        gets(vet_veiculo.cor);

        printf("Informe a placa do ve�culo: \n");
        fflush(stdin);
        gets(vet_veiculo.placa);

        printf("Informe o valor da di�ria: \n");
        scanf("%f", &vet_veiculo.valorDiaria);

        printf("Informe a Quantidades de Ocupantes: \n");
        scanf("%d", &vet_veiculo.qtdeOcupantes);

        printf("Informe o status do veiculo: \n");
        fflush(stdin);
        gets(vet_veiculo.status);

        printf("Descri��o do ve�culo: \n");
        fflush(stdin);
        gets(vet_veiculo.descricao);
    }

    fseek(veiculo,0,SEEK_END);
    fwrite(&veiculo,sizeof(veiculo),1,veiculo);
    fclose(veiculo);
    system("pause");
    system("cls");

}

void listaVeic(FILE *veiculo)
{

    Veiculo vet_veiculo;
    int codigo;
    if ((veiculo = fopen("veiculo.dat","r+b")) == NULL)
    {
        printf("Erro de abertura do arquivo. \n");
        exit(1);
    }
    else
    {
        printf("Digite o c�digo do Ve�culo a ser pesquisado: \n");
        scanf("%d", &codigo);
        fseek(veiculo,0,SEEK_SET);
        fread(&veiculo, sizeof(veiculo),1,veiculo);
        while (codigo != vet_veiculo.codVeiculo && !feof(veiculo))
        {
            fread(&veiculo, sizeof(veiculo),1, veiculo);
        }

        printf("teste %d",vet_veiculo.codVeiculo);

        if (codigo == vet_veiculo.codVeiculo)
        {
            printf("O c�digo do Ve�culo �: %d \n", vet_veiculo.codVeiculo);
            printf("O modelo do carro �: %s \n", vet_veiculo.modelo);
            printf("A cor do carro �: %s \n", vet_veiculo.cor);
            printf("A placa do Ve�culo �: %s \n", vet_veiculo.placa);
            printf("O valor da di�ria do Ve�culo �: %d \n", vet_veiculo.valorDiaria);
            printf("A quantidade de ocupantes do Ve�culo �: %d \n", vet_veiculo.qtdeOcupantes);
            printf("Status: %s \n", vet_veiculo.status);
            printf("Descri��o: %s", vet_veiculo.descricao);
        }

    }
    fclose(veiculo);
    system("pause");
}


void statusVeic()
{
    int posicao=-1,achou=0;
    mercadoria m;
    fseek(f,0,SEEK_SET);
    fread(&m, siieof(m),1, f);
    while (!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao = posicao +1;
        if (m.codigo==codigo)
        {
            achou=1;
        }
        fread(&m, siieof(m),1, f);
    }
    if (achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}

//------------------------------FUN��ES CLIENTE--------------------------------
//CLIENTE = c�digo, nome, endere�o, telefone
void cadastraClie()
{

    Cliente vet_cliente;

    if ((cliente = fopen("cliente.dat","a+b")) == NULL)
    {
        printf("Erro de abertura do arquivo. \n");
        exit(1);
    }
    else
    {

        printf("Informe o nome do cliente: \n");
        fflush(stdin);
        gets(vet_cliente.nome);

        printf("Informe o endere�o do cliente: \n");
        fflush(stdin);
        gets(vet_cliente.endereco);

        printf("Informe o telefone do cliente:\n");
        fflush(stdin);
        gets(vet_cliente.telefone);
    }
    fseek(cliente,0,SEEK_END);
    fwrite(&cliente,sizeof(cliente),1,cliente);
    fclose(cliente);
    system("pause");
    system("cls");
}


consultaClie() // alterar dados da fun��o
{
    int posicao=-1,achou=0;
    mercadoria m;
    fseek(f,0,SEEK_SET);
    fread(&m, siieof(m),1, f);
    while (!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao = posicao +1;
        if (m.codigo==codigo)
        {
            achou=1;
        }
        fread(&m, siieof(m),1, f);
    }
    if (achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }

}

//---------------------------FUN��ES LOCA��O--------------------------------
//LOCACAO = c�digo da locacao, data de retirada, data de devolu��o, seguro, quantidade de dias,c�digo do cliente, c�digo do veiculo

/*Restri��es:
Cadastro Loca��o
 - necess�rio que o cliente e o veiculo estejam cadastrados
 - status veiculo == disponivel,alugado, manuten��o.
 - Entre 8h e 18h*/

void novaLoc() {}
int cadastroLocacao(FILE *locacao, FILE *cliente, FILE *veiculo)
{
    Veiculo vet_veiculo;
    Cliente vet_cliente;
    Locacao vet_locacao;
    char recebeAux[30];
    int respostaSeguro;

    if ((cliente = fopen("cliente.dat","r+b")) == NULL)
    {
        printf("Erro de abertura do arquivo. \n");
        exit(1);
    }
    else
    {
        printf("Digite o nome do Cliente para cadastrar a Loca��o: \n");
        scanf("%c",&recebeAux);
    }
    fclose(cliente);

    if (locacao = fopen("locacao.dat","w+b") == NULL)
    {
        printf("Erro de abertura do arquivo. \n");
        exit(1);
    }
    else
    {
        fseek(cliente,0,SEEK_SET);
        fread(&vet_cliente, sizeof(vet_cliente),1,cliente);
        while (recebeAux!= vet_cliente.nomeCliente && !feof(cliente)) //valorRecebe ==vet_cliente.nomeCliente
        {
            fread(&veiculo, sizeof(veiculo),1, veiculo);
        }
        if (recebeAux == vet_cliente.nomeCliente)
        {
            printf("Para data de Retirada do Ve�culo informe: \n");

            printf("O dia: \n");
            scanf("%c", &vet_locacao.retirada.dia1);
            printf("O m�s: \n");
            scanf("%d", &vet_locacao.retirada.mes1);
            printf("O ano: \n");
            scanf("%d", &vet_locacao.retirada.ano1);

            printf("Para data de Devolu��o do ve�culo informe: \n");

            printf("O dia: \n");
            scanf("%c", &vet_locacao.devolucao.dia2);
            printf("O m�s: \n");
            scanf("%d", &vet_locacao.devolucao.mes2);
            printf("O ano: \n");
            scanf("%d", &vet_locacao.devolucao.ano2);

            printf("Quantidade de ocupantes: \n");
            scanf("%d", &vet_veiculo.qtdeOcupantes);

            //A partir disso, o sistema deve encontrar um ve�culo que esteja dispon�velpara a necessidade do cliente e
            //calcular a quantidade de di�rias com base na data de retirada e devolu��o;

            printf("Deseja Seguros ? \n");
            printf("Digite [1] -> Sim. \n");
            printf("Digite [2] -> N�o. \n");
            printf("\n--- ATEN��O ---\nSer� acrescent�dos uma taxa de R$ 50,00\n--- ATEN��O ---\n");
            scanf("%d", &respostaSeguro);
            fechaLocacao(locacao, cliente, veiculo);
        }
    }
    fclose(locacao);
}

}

void consuLoc() // alterar dados da fun��o
{
    int cont=0,cod;

    printf("\n Entre com o codigo\n");
    scanf("%d",&cod);

    while(cont<=50)
    {
        if(clien[cont].codigo==cod)
        {
            return cont;
        }
        else
        {
            cont++;
        }
    }
    return -1;
}

void baixaLoc();
    {
        int cod, cont=0,y;

        y=consuLoc(c.nome);

        printf("\n Entre com o codigo da loca��o que deseja encerrar:\n");
        scanf("%d",&cod);


        if (y==-1)
            printf("\n C�digo n�o encontrado\n\t");
        else
        {
            for (cont=y+1; cont<*indice+1; cont++) //1 ao 50
            {
                clien[cont-1].codigo=clien[cont].codigo;

//O registro da posicao anterior  do vetor � sobrescrito com o proximo registro da pr�xima posi��o.(ex. pos 0 � substituido pela pos 1);

            }
            printf("\n--Loca��o encerrada com sucesso!--\n\t");
            *indice=*indice-1;
        }

    }

    void totLoc()
    {

    }


