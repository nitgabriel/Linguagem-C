//Gabriel Damasceno Machado              RA 1680482222026
//Gabriel Pereira Rodrigues de Santana   RA 1680482222001
//Nicole Kelly da Silva                  RA 1680482222013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int codigo;
    char tipo;
    float estoque;
    float custo;
    float margem;
} Produto;

typedef struct {
    char uf[3];
    int icms;
} UF;

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

void ler_produtos(const char *arquivo, Produto *produtos, int n) {
    FILE *fp = fopen(arquivo, "r");
    for (int i = 0; i < n; ++i) {
        fscanf(fp, "%d;%c;%f;%f;%f;", &produtos[i].codigo, &produtos[i].tipo, &produtos[i].estoque, &produtos[i].custo, &produtos[i].margem);
    }
    fclose(fp);
}

int main() {
    int QtdeVendasDia = 0, dia_inicial, dia_final, mes_inicial, mes_final, ano_inicial, ano_final, data_valida = 0;
    Produto produtos[15];
    UF ufs[] = {
        {"AC", 7}, {"AL", 7}, {"AP", 7}, {"AM", 0}, {"BA", 7}, {"CE", 7},
        {"DF", 7}, {"ES", 12}, {"GO", 7}, {"MA", 7}, {"MT", 7}, {"MS", 7},
        {"MG", 12}, {"PA", 7}, {"PB", 7}, {"PR", 12}, {"PE", 7}, {"PI", 7},
        {"RJ", 12}, {"RN", 7}, {"RS", 12}, {"RO", 7}, {"RR", 7}, {"SC", 12},
        {"SP", 18}, {"SE", 7}, {"TO", 7}
    };

    ler_produtos("PRODUTOS.TXT", produtos, 15);
    
    do{
        printf("Digite a data inicial (DD MM AAAA): ");
        scanf("%d %d %d", &dia_inicial, &mes_inicial, &ano_inicial);

        printf("Digite a data final (DD MM AAAA): ");
        scanf("%d %d %d", &dia_final, &mes_final, &ano_final);

        if (ano_inicial < 2016) {
            printf("Ano inicial deve ser no minimo 2016.\n");
        } else if (ano_final < ano_inicial) {
            printf("Ano final deve ser maior ou igual ao ano inicial.\n");
        } else if (ano_final == ano_inicial && mes_final < mes_inicial) {
            printf("Mes final deve ser maior ou igual ao mes inicial no mesmo ano.\n");
        } else if (dia_inicial < 1 || dia_inicial > 31 || dia_final < 1 || dia_final > 31) {
            printf("Dia inicial e final devem estar entre 1 e 31.\n");
        } else if (dia_final <= dia_inicial && mes_inicial == mes_final && ano_inicial == ano_final){
        	printf("A data final deve ser maior que a data inicial!\n");
        }else{
            data_valida = 1;
        }
        
    } while (data_valida != 1);

	printf("Digite a quantidade de vendas diarias do periodo: ");
	scanf("%d", &QtdeVendasDia); 
    while (QtdeVendasDia <= 0){
		printf("A quantidade de vendas deve ser maior que zero!");
		scanf("%d", &QtdeVendasDia);   	
	}
	printf("-------------------------------------------------------\n");
	printf("|------------------VENDAS DO PERIODO------------------|\n");	
	printf("+------+-----+-----+-------+--------+-------+----+----+\n");
	printf("| Ano  | Mes | Dia | Codigo| Qtd.Ven| Preco | UF |ICMS|\n");
	printf("+------+-----+-----+-------+--------+-------+----+----+\n");

	
    FILE *saida = fopen("saida.txt", "w");
    
    srand(time(NULL));

	for (int a = ano_inicial; a <= ano_final; a++) {
        int mes_inicio = (a == ano_inicial) ? mes_inicial : 1;
        int mes_fim = (a == ano_final) ? mes_final : 12;

        for (int m = mes_inicio; m <= mes_fim; m++) {
            int dias_mes = 0;
            if (m == 4 || m == 6 || m == 9 || m == 11) {
                dias_mes = 30;
            } else if (m == 2) {
                dias_mes = (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) ? 29 : 28;
            } else {
                dias_mes = 31;
            }

            int dia_inicio = (a == ano_inicial && m == mes_inicial) ? dia_inicial : 1;
            int dia_fim = (a == ano_final && m == mes_final) ? dia_final : dias_mes;

            for (int d = dia_inicio; d <= dia_fim; d++) {
                if (DiaSemana(d, m, a) != 0) {
                    for (int i = 0; i < QtdeVendasDia; i++) {
                        Produto p = produtos[rand() % 15];
                        float quantidade_vendida = p.tipo == 'P' ? (rand() % 1000) / 1000.0 : rand() % 100;
                        float preco_venda = p.custo * (1 + p.margem / 100);
                        int indice_uf = rand() % (sizeof(ufs) / sizeof(ufs[0]));
                        UF uf = ufs[indice_uf];

                        if (rand() % 100 < 35) {
                            float variacao = ((rand() % 17) - 8) / 100.0;
                            preco_venda *= (1 + variacao);
                        }
						printf("| %4d |  %02d |  %02d | %5d | %6.3f | %5.2f | %2s | %2d |\n", a, m, d, p.codigo, quantidade_vendida, preco_venda, uf.uf, uf.icms);
                        fprintf(saida, "%04d;%02d;%02d;%05d;%.3f;%.2f;%s;%d;\n", a, m, d, p.codigo, quantidade_vendida, preco_venda, uf.uf, uf.icms);
                    }
                }
            }
            dia_inicial = 1;
        }
        mes_inicial = 1;
    }

    fclose(saida);
    
	printf("-------------------------------------------------------\n");
	
	system("pause");

    return 0;
}
