//Gabriel Damasceno Machado              RA 1680482222026
//Gabriel Pereira Rodrigues de Santana   RA 1680482222001
//Nicole Kelly da Silva                  RA 1680482222013

//Para alterar arquivos, vá para a linha 204
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int codProduto;
    int inicioEstoque;
    int minEstoque;
} Produto;

typedef struct {
    int codProduto;
    int qtdVendas;
    int sitVendas;
    int canalVendas;
} Venda;

typedef struct {
    int codProduto;
    int qtdCO;
    int qtdMin;
    int qtdVendas;
    int estAposVendas;
    int qtdNecess;
    int qtdTransfer;
} Transfere;

int lerProdutos(const char* filename, Produto** produtosPtr) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return 0;
    }

    Produto* produtos = *produtosPtr;
    int capacidade = 10; 
    produtos = (Produto*)malloc(capacidade * sizeof(Produto));
    

    int i = 0;
    while (fscanf(file, "%d;%d;%d\n", &produtos[i].codProduto, &produtos[i].inicioEstoque, &produtos[i].minEstoque) != EOF) {
        i++;
        if (i >= capacidade) { 
            capacidade *= 2;
            produtos = (Produto*)realloc(produtos, capacidade * sizeof(Produto));
        }
    }

    fclose(file);
    *produtosPtr = produtos;
    return i;
}

int lerVendas(const char* filename, Venda** vendasPtr) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return 0;
    }

    Venda* vendas = *vendasPtr;
    int capacidade = 10; 
    vendas = (Venda*)malloc(capacidade * sizeof(Venda));

    int i = 0;
    while (fscanf(file, "%d;%d;%d;%d\n", &vendas[i].codProduto, &vendas[i].qtdVendas, &vendas[i].sitVendas, &vendas[i].canalVendas) != EOF) {
        i++;
        if (i >= capacidade) { 
            capacidade *= 2;
            vendas = (Venda*)realloc(vendas, capacidade * sizeof(Venda));
        }
    }

    fclose(file);
    *vendasPtr = vendas;
    return i;
}

int calcTransferencia(Produto* produtos, int numProdutos, Venda* vendas, int numVendas, Transfere** transferenciaPtr, int capacidade) {
    int i, j, k = 0;
    Transfere* transferencia = *transferenciaPtr;
    
    for (i = 0; i < numProdutos; i++) {
        transferencia[k].codProduto = produtos[i].codProduto;
        transferencia[k].qtdCO = produtos[i].inicioEstoque;
        transferencia[k].qtdMin = produtos[i].minEstoque;
        transferencia[k].qtdVendas = 0;

        
        for (j = 0; j < numVendas; j++) {
            if (vendas[j].codProduto == produtos[i].codProduto && (vendas[j].sitVendas == 100 || vendas[j].sitVendas == 102)) {
                transferencia[k].qtdVendas += vendas[j].qtdVendas;
            }
        }
        
        transferencia[k].estAposVendas = transferencia[k].qtdCO - transferencia[k].qtdVendas;
        transferencia[k].qtdNecess = (transferencia[k].qtdMin - transferencia[k].estAposVendas) > 0 ? (transferencia[k].qtdMin - transferencia[k].estAposVendas) : 0;
        transferencia[k].qtdTransfer = (transferencia[k].qtdNecess > 0) ? ((transferencia[k].qtdNecess < 10) ? 10 : transferencia[k].qtdNecess) : 0;
        
        k++;
        if (k >= capacidade) {
            capacidade *= 2;
            transferencia = (Transfere*)realloc(transferencia, capacidade * sizeof(Transfere));
        }
    }

    *transferenciaPtr = transferencia;
    return k;
}

void saidaTransferencia(const char* filename, Transfere* transferencia, int numTransfere) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }
    
    fprintf(file, "Necessidade de Transferência Armazém para CO\n");
    fprintf(file, "\nProduto  QtCO  QtMin  QtVendas  Estq.após  Necess.  Transf. de  \n");
    fprintf(file, "                                   Vendas            Arm p/ CO  \n");

    for (int i = 0; i < numTransfere; i++) {
        fprintf(file, "%d   %5d  %5d   %7d   %8d  %7d  %10d\n",
                transferencia[i].codProduto,
                transferencia[i].qtdCO,
                transferencia[i].qtdMin,
                transferencia[i].qtdVendas,
                transferencia[i].estAposVendas,
                transferencia[i].qtdNecess,
                transferencia[i].qtdTransfer);
    }

    fclose(file);
}

void saidaDivergencia(const char* filename, Produto* produtos, int numProdutos, Venda* vendas, int numVendas) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    for (int i = 0; i < numVendas; i++) {
        bool found = false;
        for (int j = 0; j < numProdutos && !found; j++) {
            if (vendas[i].codProduto == produtos[j].codProduto) {
                found = true;
            }
        }

        if (!found) {
            fprintf(file, "Linha %d - Código de produto não encontrado %d\n", i + 1, vendas[i].codProduto);
        }
        if (vendas[i].sitVendas == 135) {
            fprintf(file, "Linha %d - Venda cancelada\n", i + 1);
        }
        if (vendas[i].sitVendas == 190) {
            fprintf(file, "Linha %d - Venda não finalizada\n", i + 1);
        }
        if (vendas[i].sitVendas == 999) {
            fprintf(file, "Linha %d - Erro desconhecido. Acionar equipe de TI.\n", i + 1);
        }
    }

    fclose(file);
}

void totalQtdCanais(const char* filename, Venda* vendas, int numVendas) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    int totalCanais[4] = {0};

    for (int i = 0; i < numVendas; i++) {
        if (vendas[i].sitVendas == 100 || vendas[i].sitVendas == 102) {
            totalCanais[vendas[i].canalVendas - 1] += vendas[i].qtdVendas;
        }
    }

    fprintf(file, "Quantidades de Vendas por canal\n");
    fprintf(file, "\nCanal                  QtVendas\n");
    fprintf(file, "1 – Representantes     %8d\n", totalCanais[0]);
    fprintf(file, "2 – Website            %8d\n", totalCanais[1]);
    fprintf(file, "3 - App móvel Android  %8d\n", totalCanais[2]);
    fprintf(file, "4 - App móvel iPhone   %8d\n", totalCanais[3]);

    fclose(file);
}

int main() {
    Produto* produtos = NULL;
    Venda* vendas = NULL;
    Transfere* transferencia = NULL;

    int numProdutos = lerProdutos("c1_produtos.txt", &produtos);
    int numVendas = lerVendas("c1_vendas.txt", &vendas);
    
    int capacidade = 10;
    transferencia = (Transfere*)malloc(capacidade * sizeof(Transfere));
    
    int numTransfere = calcTransferencia(produtos, numProdutos, vendas, numVendas, &transferencia, capacidade);
    saidaTransferencia("transfere.txt", transferencia, numTransfere);

    saidaDivergencia("divergencias.txt", produtos, numProdutos, vendas, numVendas);
    totalQtdCanais("totcanais.txt", vendas, numVendas);
    
    printf("Gabriel Damasceno Machado              RA 1680482222026\nGabriel Pereira Rodrigues de Santana   RA 1680482222001\nNicole Kelly da Silva                  RA 1680482222013\n");
    printf("\nArquivos txt gerados com sucesso.\n");
    
    free(produtos);
    free(vendas);
    free(transferencia);    

    return 0;
}
