#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto() {
    FILE *arquivo_estoque = fopen("estoque.txt", "a");
    if (arquivo_estoque == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Produto p;
    
    printf("Codigo do produto: ");
    scanf("%d", &p.codigo);
    printf("Nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Quantidade inicial: ");
    scanf("%d", &p.quantidade);
    printf("Preco do produto: ");
    scanf("%f", &p.preco);

    fprintf(arquivo_estoque, "%d,%s,%d,%.2f\n", p.codigo, p.nome, p.quantidade, p.preco);
    fclose(arquivo_estoque);
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    FILE *arquivo_estoque = fopen("estoque.txt", "r");
    if (arquivo_estoque == NULL) {
        printf("Erro ao abrir o arquivo ou estoque vazio!\n");
        return;
    }

    Produto p;
    
    printf("Lista de Produtos:\n");
    while (fscanf(arquivo_estoque, "%d,%49[^,],%d,%f\n", &p.codigo, p.nome, &p.quantidade, &p.preco) == 4) {
        printf("Codigo: %d | Nome: %s | Quantidade: %d | Preco: %.2f\n",
               p.codigo, p.nome, p.quantidade, p.preco);
    }

    fclose(arquivo_estoque);
}

void registrarCompra() {
    FILE *arquivo_estoque = fopen("estoque.txt", "r");
    if (arquivo_estoque == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int codigo, quantidade;
    printf("Codigo do produto: ");
    scanf("%d", &codigo);
    printf("Quantidade comprada: ");
    scanf("%d", &quantidade);

    Produto produtos[MAX_PRODUTOS];
    int count = 0, encontrado = 0;

    while (fscanf(arquivo_estoque, "%d,%49[^,],%d,%f\n", &produtos[count].codigo, produtos[count].nome,
                  &produtos[count].quantidade, &produtos[count].preco) == 4) {
        if (produtos[count].codigo == codigo) {
            produtos[count].quantidade += quantidade;
            encontrado = 1;
        }
        count++;
    }
    fclose(arquivo_estoque);

    if (!encontrado) {
        printf("Produto nao encontrado!\n");
        return;
    }

    arquivo_estoque = fopen("estoque.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(arquivo_estoque, "%d,%s,%d,%.2f\n", produtos[i].codigo, produtos[i].nome,
                produtos[i].quantidade, produtos[i].preco);
    }
    fclose(arquivo_estoque);

    printf("Compra registrada com sucesso!\n");
}

void registrarVenda() {
    FILE *arquivo_estoque = fopen("estoque.txt", "r");
    if (arquivo_estoque == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int codigo, quantidade;
    printf("Codigo do produto: ");
    scanf("%d", &codigo);
    printf("Quantidade vendida: ");
    scanf("%d", &quantidade);

    Produto produtos[MAX_PRODUTOS];
    int count = 0, encontrado = 0;

    while (fscanf(arquivo_estoque, "%d,%49[^,],%d,%f\n", &produtos[count].codigo, produtos[count].nome,
                  &produtos[count].quantidade, &produtos[count].preco) == 4) {
        if (produtos[count].codigo == codigo) {
            if (produtos[count].quantidade >= quantidade) {
                produtos[count].quantidade -= quantidade;
                encontrado = 1;
            } else {
                printf("Estoque insuficiente!\n");
                fclose(arquivo_estoque);
                return;
            }
        }
        count++;
    }
    fclose(arquivo_estoque);

    if (!encontrado) {
        printf("Produto nao encontrado!\n");
        return;
    }

    arquivo_estoque = fopen("estoque.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(arquivo_estoque, "%d,%s,%d,%.2f\n", produtos[i].codigo, produtos[i].nome,
                produtos[i].quantidade, produtos[i].preco);
    }
    fclose(arquivo_estoque);

    printf("Venda registrada com sucesso!\n");
}

int main() {
    int opcao;
    do {
        printf("\nControle de Estoque\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Registrar Compra\n");
        printf("4. Registrar Venda\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: registrarCompra(); break;
            case 4: registrarVenda(); break;
            case 5: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}