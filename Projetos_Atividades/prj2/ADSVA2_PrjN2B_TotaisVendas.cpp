//Gabriel Damasceno Machado              RA 1680482222026
//Gabriel Pereira Rodrigues de Santana   RA 1680482222001
//Nicole Kelly da Silva                  RA 1680482222013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int codigo;
    char controle;
    float estoque;
    float preco_custo;
    float margem_lucro;
} Produto;

typedef struct {
    int ano;
    int mes;
    int dia;
    int codigo_produto;
    float quantidade_vendida;
    float preco_venda;
} Venda;

typedef struct {
    int codigo_produto;
    float valor_total;
    float quantidade;
    float preco_medio;
    float lucratividade;
} TotaisProduto;

//Checar se é Domingo, utilizando a biblioteca time.h e retorna 0 caso seja domingo.
int DiaSemana(int dd, int mm, int aa) {
    time_t hora;
    struct tm *phora;
    time(&hora);
    phora = localtime(&hora);
    phora->tm_year = aa - 1900;
    phora->tm_mon = mm - 1;
    phora->tm_mday = dd;
    mktime(phora);
    return phora->tm_wday;
}

void swap(char* a, char* b, size_t size) { //recebe char pois o char é utilizado para apontar um bloco de memória, e size define o tamanho.
    char* temp = (char*)malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void bubblesort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*)) {
    char* array = (char*)base;
    for(size_t i = 0; i < nmemb - 1; i++) {
        for(size_t j = 0; j < nmemb - i - 1; j++) {
            if(compar(array + j*size, array + (j+1)*size) > 0) {
                swap(array + j*size, array + (j+1)*size, size);
            }
        }
    }
}

int comparar_datas(const void *a, const void *b) {
    Venda *venda_a = (Venda *)a;
    Venda *venda_b = (Venda *)b;

    if (venda_a->ano == venda_b->ano) {
        if (venda_a->mes == venda_b->mes) {
            return venda_a->dia - venda_b->dia;
        } else {
            return venda_a->mes - venda_b->mes;
        }
    } else {
        return venda_a->ano - venda_b->ano;
    }
}

int comparar_codigo_produto(const void *a, const void *b) {
    TotaisProduto *totais_a = (TotaisProduto *)a;
    TotaisProduto *totais_b = (TotaisProduto *)b;

    return totais_a->codigo_produto - totais_b->codigo_produto;
}

int comparar_lucratividade(const void *a, const void *b) {
    TotaisProduto *totais_a = (TotaisProduto *)a;
    TotaisProduto *totais_b = (TotaisProduto *)b;

    return (int)(totais_b->lucratividade * 100) - (int)(totais_a->lucratividade * 100);
}

int comparar_contribuicao(const void *a, const void *b) {
    TotaisProduto *totais_a = (TotaisProduto *)a;
    TotaisProduto *totais_b = (TotaisProduto *)b;

    return (int)(totais_b->valor_total * 100) - (int)(totais_a->valor_total * 100);
}


int main() {
    FILE *file_produtos = fopen("produtos.txt", "r");
    FILE *file_vendas = fopen("vendas.txt", "r");

    int numero_produtos = 0;
    int numero_vendas = 0;
	Produto* produtos = NULL;
	Venda* vendas = NULL;
	TotaisProduto* totais_produtos = NULL;

    Produto produto_temp;
    while (fscanf(file_produtos, "%5d;%c;%f;%f;%f;", &produto_temp.codigo, &produto_temp.controle, 
                  &produto_temp.estoque, &produto_temp.preco_custo, &produto_temp.margem_lucro) == 5) {
        produtos = (Produto*)realloc(produtos, (numero_produtos + 1) * sizeof(Produto));
        produtos[numero_produtos++] = produto_temp;
    }

    fclose(file_produtos);

    Venda venda_temp;
    while (fscanf(file_vendas, "%4d;%2d;%2d;%5d;%f;%f;", &venda_temp.ano, &venda_temp.mes, &venda_temp.dia, 
                  &venda_temp.codigo_produto, &venda_temp.quantidade_vendida, &venda_temp.preco_venda) == 6) {
        vendas = (Venda*)realloc(vendas, (numero_vendas + 1) * sizeof(Venda));
        vendas[numero_vendas++] = venda_temp;
    }

    fclose(file_vendas);

    bubblesort(vendas, numero_vendas, sizeof(Venda), comparar_datas);

    totais_produtos = (TotaisProduto*)calloc(numero_produtos, sizeof(TotaisProduto));


    for (int i = 0; i < numero_vendas; i++) {
        bool found = false;
        for (int j = 0; j < numero_produtos && !found; j++) {
            if (vendas[i].codigo_produto == produtos[j].codigo) {
                totais_produtos[j].codigo_produto = produtos[j].codigo;
                totais_produtos[j].valor_total += vendas[i].quantidade_vendida * vendas[i].preco_venda;
                totais_produtos[j].quantidade += vendas[i].quantidade_vendida;
                totais_produtos[j].preco_medio = totais_produtos[j].valor_total / totais_produtos[j].quantidade;
                totais_produtos[j].lucratividade = (totais_produtos[j].preco_medio / produtos[j].preco_custo - 1) * 100;
                found = true;
            }
        }
    }

	bubblesort(totais_produtos, numero_produtos, sizeof(TotaisProduto), comparar_codigo_produto);

	FILE *file_saida = fopen("totvendas.txt", "w");

	fprintf(file_saida, "TOTAIS DE VENDAS POR DIA\n");
	fprintf(file_saida, "Dia             Total  Média/Dia\n");

	float total_vendas_dia = 0;
	int quantidade_vendas_dia = 0;
	int dia_atual = vendas[0].dia;
	int mes_atual = vendas[0].mes;
	int ano_atual = vendas[0].ano;

	for (int i = 0; i < numero_vendas; i++) {
	    if (vendas[i].dia != dia_atual || vendas[i].mes != mes_atual || vendas[i].ano != ano_atual) {
	        if (DiaSemana(dia_atual, mes_atual, ano_atual) != 0) {
	            fprintf(file_saida, "%02d/%02d/%d %10.2f %10.2f\n", dia_atual, mes_atual, ano_atual,
	                    total_vendas_dia, total_vendas_dia / quantidade_vendas_dia);
	        }
	
	        dia_atual = vendas[i].dia;
	        mes_atual = vendas[i].mes;
	        ano_atual = vendas[i].ano;
	        total_vendas_dia = 0;
	        quantidade_vendas_dia = 0;
	    }
	
	    total_vendas_dia += vendas[i].quantidade_vendida * vendas[i].preco_venda;
		quantidade_vendas_dia++;
	}

	if (DiaSemana(dia_atual, mes_atual, ano_atual) != 0) { // saída fora do loop para imprimir o dia 31/12, visto que o loop só imprime caso o dia atual seja diferente do dia anterior e diferente de 0
	    fprintf(file_saida, "%02d/%02d/%d %10.2f %10.2f\n", dia_atual, mes_atual, ano_atual,
	            total_vendas_dia, total_vendas_dia / quantidade_vendas_dia);
	}

	fprintf(file_saida, "\nTOTAIS DE VENDAS POR PRODUTO\n");
	fprintf(file_saida, "Prod.     VlrTot       Qtde   Pç Médio     Lucrat.\n");

	float total_geral_vendas = 0;
	float quantidade_total_produtos = 0;
	float lucratividade_media = 0;

	for (int i = 0; i < numero_produtos; i++) {
	    fprintf(file_saida, "%5d %10.2f %10.2f %10.2f %10.1f%%\n", totais_produtos[i].codigo_produto,
	            totais_produtos[i].valor_total, totais_produtos[i].quantidade,
	            totais_produtos[i].preco_medio, totais_produtos[i].lucratividade);
	
	    total_geral_vendas += totais_produtos[i].valor_total;
	    quantidade_total_produtos += totais_produtos[i].quantidade;
	    lucratividade_media += totais_produtos[i].lucratividade * totais_produtos[i].quantidade;
	}

	lucratividade_media /= quantidade_total_produtos;

	fprintf(file_saida, "\nTOTAL E ESTATÍSTICAS DO PERÍODO\n");
	fprintf(file_saida, "Total Geral de Vendas (R$)          %.2f\n", total_geral_vendas);
	fprintf(file_saida, "Quantidade de produtos vendidos      %.2f\n", quantidade_total_produtos);
	fprintf(file_saida, "Média de Vendas por dia útil (R$)    %.2f\n", total_geral_vendas / quantidade_vendas_dia);
	fprintf(file_saida, "Média de Vendas por produto (R$)         %.2f\n", total_geral_vendas / (float)quantidade_total_produtos);
	fprintf(file_saida, "Lucratividade Média                      %.1f%%\n", lucratividade_media);
	
	bubblesort(totais_produtos, numero_produtos, sizeof(TotaisProduto), comparar_lucratividade);
	
	fprintf(file_saida, "\nPRODUTOS MAIS LUCRATIVOS\n");
	fprintf(file_saida, "Lucratividade média = %.1f%%\n", lucratividade_media);
	fprintf(file_saida, "Prod.   Lucrat.\n");
	
	for (int i = 0; i < numero_produtos; i++) {
	    if (totais_produtos[i].lucratividade > lucratividade_media) {
	        fprintf(file_saida, "%5d     %.1f%%\n", totais_produtos[i].codigo_produto, totais_produtos[i].lucratividade);
	    }
	}
	
	bubblesort(totais_produtos, numero_produtos, sizeof(TotaisProduto), comparar_contribuicao);
	
	fprintf(file_saida, "\nCONTRIBUIÇÃO DE CADA PRODUTO\n");
	fprintf(file_saida, "Prod.      VlrTot    Contrib.\n");
	
	for ( int i = 0; i < numero_produtos; i++) {
		float contribuicao = (totais_produtos[i].valor_total / total_geral_vendas) * 100;
			fprintf(file_saida, "%5d  %10.2f %10.1f%%\n", totais_produtos[i].codigo_produto,
		totais_produtos[i].valor_total, contribuicao);
		}
		
	fclose(file_saida);
    free(produtos);
    free(vendas);
    free(totais_produtos);
    
    printf("Gabriel Damasceno Machado              RA 1680482222026\nGabriel Pereira Rodrigues de Santana   RA 1680482222001\nNicole Kelly da Silva                  RA 1680482222013\n");
    printf("Arquivo txt gerado com sucesso.");

	return 0;

}

