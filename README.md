# Controle de Estoque em C

## Introdução
Este projeto é um **sistema de controle de estoque** desenvolvido em linguagem C, que permite gerenciar produtos, registrando compras e vendas. Os dados são armazenados em um arquivo de texto (`estoque.txt`).

## Funcionalidades
✅ Cadastro de produtos
✅ Listagem dos produtos cadastrados
✅ Registro de compras (entrada de estoque)
✅ Registro de vendas (saída de estoque)
✅ Atualização automática do estoque

## Estrutura do Programa
O programa utiliza uma estrutura `struct` para representar um produto:
```c
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;
```
Cada produto possui **código, nome, quantidade e preço**, armazenados no arquivo `estoque.txt`.

### 1. Cadastrar Produto
Adiciona um novo produto ao arquivo `estoque.txt`.
#### Exemplo de entrada:
```plaintext
Digite o código do produto: 1
Nome do produto: Arroz
Quantidade inicial: 10
Preço do produto: 5.50
```

### 2. Listar Produtos
Exibe todos os produtos cadastrados.
#### Exemplo de saída:
```plaintext
Lista de Produtos:
Código: 1 | Nome: Arroz | Quantidade: 10 | Preço: 5.50
Código: 2 | Nome: Feijão | Quantidade: 5 | Preço: 6.20
```

### 3. Registrar Compra
Aumenta a quantidade de um produto existente no estoque.
#### Exemplo de entrada:
```plaintext
Código do produto: 1
Quantidade comprada: 5
```

### 4. Registrar Venda
Diminui a quantidade de um produto no estoque.
#### Exemplo de entrada:
```plaintext
Código do produto: 1
Quantidade vendida: 3
```

## Como Executar o Programa
1. **Compilar** o programa com um compilador C, como `gcc`:
   ```sh
   gcc estoque.c -o estoque
   ```
2. **Executar** o programa:
   ```sh
   ./estoque
   ```
3. Utilizar o menu para interagir com o sistema.

