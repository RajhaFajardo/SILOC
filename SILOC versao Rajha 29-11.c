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
        printf("      1 - Menu funcionário\n");
        printf("      2 - Menu veículo\n");
        printf("      3 - Menu cliente\n");
        printf("      4 - Menu locações\n");
        printf("      5 - Sair\n");
        printf("\n--------------------------------------\n");
        printf("\n  Digite o número da operação desejada: ");
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
            system("cls");
            printf("\n-----------MENU FUNCIONÁRIO----------------\n");
            printf("\n    1 - Cadastrar funcionário\n");
            printf("      2 - Pesquisar funcionário\n");
            printf("      3 - Sair\n");
            printf("\n----------------------------------------\n");
            printf("\n Digite o número da operação desejada: ");
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
                printf("Opção inválida\n\n");
                system("pause");
                system("cls");
            }
            break;

        case 2:
            system("cls");
            printf("\n-------------MENU VEÍCULO----------------\n");
            printf("\n      1 - Cadastrar veículo \n");
            printf("        2 - Pesquisar veículo \n");
            printf("        3 - Consultar status veículo \n");
            printf("        4 - Sair\n");
            printf("\n------------------------------------------\n");
            printf("\n Digite o número da operação desejada: ");
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
                printf("\n\nOpção inválida\n\n");
                system("pause");
                system("cls");
            }
            break;

        case 3:
            system("cls");
            printf("\n-------------MENU CLIENTE----------------\n");
            printf("\n    1 - Cadastrar cliente\n");
            printf("      2 - Pesquisar cliente\n");
            printf("      3 - Consultar locações do cliente\n");
            printf("      4 - Sair\n");
            printf("\n------------------------------------------\n");
            printf("\nDigite o número da operação desejada: ");
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
                printf("Opção inválida\n\n");
                system("pause");
                system("cls");
            }

            break;
        case 4:
            system("cls");
            printf("\n---------------MENU LOCAÇÕES-----------------\n");
            printf("\n       1 - Nova locação\n");
            printf("         2 - Consulta de locações\n");
            printf("         3 - Total de locações\n");
            printf("         4 - Dar baixa em locação\n");
            printf("         5 - Sair\n");
            printf("\n----------------------------------------------\n");
            printf("Digite o número da operação desejada: ");
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
                printf("Opção inválida\n\n");
                system("pause");
                system("cls");
            }

            break;

        case 5:
            printf("\n---Sair---\n");
            break;

        default:
            printf("Opção inválida!");
            system("pause");
            system("cls");
        }
    }
    while (opcao != 5);
    return 0;

}


//--------------------------FUNÇÕES FUNCIONÁRIOS----------------------------
//FUNCIONARIO = código, nome, telefone, cargo, salario

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
        printf("Informe o código do funcionário: \n");
        scanf("%d", &vet_funcionario.codfuncionario);

        printf("Informe o nome do funcionário: \n");
        fflush(stdin);
        gets(vet_funcionario.nome);

        printf("Informe o salário do funcionário: \n");
        fflush(stdin);
        gets(vet_funcionario.salario);

        printf("Informe o cargo do funcionário:\n");
        fflush(stdin);
        gets(vet_funcionario.cargo);

    }
    fseek(funcionario,0,SEEK_END);
    fwrite(&funcionario,sizeof(funcionario),1,funcionario);
    fclose(funcionario);
    system("pause");
    system("cls");
}

void listaFunc  // alterar dados da função
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



//----------------------------FUNÇÕES VEÍCULO--------------------------------


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
        printf("Informe o código do veículo: \n");
        scanf("%d", &vet_veiculo.codVeiculo);

        printf("Informe o modelo: \n");
        fflush(stdin);
        gets(vet_veiculo.modelo);

        printf("Informe a cor do veículo: \n");
        fflush(stdin);
        gets(vet_veiculo.cor);

        printf("Informe a placa do veículo: \n");
        fflush(stdin);
        gets(vet_veiculo.placa);

        printf("Informe o valor da diária: \n");
        scanf("%f", &vet_veiculo.valorDiaria);

        printf("Informe a Quantidades de Ocupantes: \n");
        scanf("%d", &vet_veiculo.qtdeOcupantes);

        printf("Informe o status do veiculo: \n");
        fflush(stdin);
        gets(vet_veiculo.status);

        printf("Descrição do veículo: \n");
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
        printf("Digite o código do Veículo a ser pesquisado: \n");
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
            printf("O código do Veículo é: %d \n", vet_veiculo.codVeiculo);
            printf("O modelo do carro é: %s \n", vet_veiculo.modelo);
            printf("A cor do carro é: %s \n", vet_veiculo.cor);
            printf("A placa do Veículo é: %s \n", vet_veiculo.placa);
            printf("O valor da diária do Veículo é: %d \n", vet_veiculo.valorDiaria);
            printf("A quantidade de ocupantes do Veículo é: %d \n", vet_veiculo.qtdeOcupantes);
            printf("Status: %s \n", vet_veiculo.status);
            printf("Descrição: %s", vet_veiculo.descricao);
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

//------------------------------FUNÇÕES CLIENTE--------------------------------
//CLIENTE = código, nome, endereço, telefone
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

        printf("Informe o endereço do cliente: \n");
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


consultaClie() // alterar dados da função
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

//---------------------------FUNÇÕES LOCAÇÃO--------------------------------
//LOCACAO = código da locacao, data de retirada, data de devolução, seguro, quantidade de dias,código do cliente, código do veiculo

/*Restrições:
Cadastro Locação
 - necessário que o cliente e o veiculo estejam cadastrados
 - status veiculo == disponivel,alugado, manutenção.
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
        printf("Digite o nome do Cliente para cadastrar a Locação: \n");
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
            printf("Para data de Retirada do Veículo informe: \n");

            printf("O dia: \n");
            scanf("%c", &vet_locacao.retirada.dia1);
            printf("O mês: \n");
            scanf("%d", &vet_locacao.retirada.mes1);
            printf("O ano: \n");
            scanf("%d", &vet_locacao.retirada.ano1);

            printf("Para data de Devolução do veículo informe: \n");

            printf("O dia: \n");
            scanf("%c", &vet_locacao.devolucao.dia2);
            printf("O mês: \n");
            scanf("%d", &vet_locacao.devolucao.mes2);
            printf("O ano: \n");
            scanf("%d", &vet_locacao.devolucao.ano2);

            printf("Quantidade de ocupantes: \n");
            scanf("%d", &vet_veiculo.qtdeOcupantes);

            //A partir disso, o sistema deve encontrar um veículo que esteja disponívelpara a necessidade do cliente e
            //calcular a quantidade de diárias com base na data de retirada e devolução;

            printf("Deseja Seguros ? \n");
            printf("Digite [1] -> Sim. \n");
            printf("Digite [2] -> Não. \n");
            printf("\n--- ATENÇÃO ---\nSerá acrescentádos uma taxa de R$ 50,00\n--- ATENÇÃO ---\n");
            scanf("%d", &respostaSeguro);
            fechaLocacao(locacao, cliente, veiculo);
        }
    }
    fclose(locacao);
}

}

void consuLoc() // alterar dados da função
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

        printf("\n Entre com o codigo da locação que deseja encerrar:\n");
        scanf("%d",&cod);


        if (y==-1)
            printf("\n Código não encontrado\n\t");
        else
        {
            for (cont=y+1; cont<*indice+1; cont++) //1 ao 50
            {
                clien[cont-1].codigo=clien[cont].codigo;

//O registro da posicao anterior  do vetor é sobrescrito com o proximo registro da próxima posição.(ex. pos 0 é substituido pela pos 1);

            }
            printf("\n--Locação encerrada com sucesso!--\n\t");
            *indice=*indice-1;
        }

    }

    void totLoc()
    {

    }


