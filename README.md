# Listas

Este repositório contém a implementação de dois Tipos Abstratos de Dados (TADs): **Lista Ligada Simples** e **Lista Circular Duplamente Ligada**, conforme proposto no 1º Trabalho Prático da disciplina **Estrutura de Dados I** (Curso de Engenharia Informática, 2º Ano, ISPTEC).

## 📚 Objectivo

Praticar a implementação de estruturas de dados dinâmicas usando listas encadeadas, com foco nos seguintes tópicos:
- Operações básicas em listas ligadas.
- Manipulação de listas com interseção em Y.
- Eliminação alternada de elementos em lista circular duplamente ligada.

## 📦 Estrutura do Projeto
```
├── EINFT3_TP1_Grupo4/
│   ├── Desafio1.h
│   ├── Desafio2.h
│   └── Desafios.c
├── 2PP_EIN3_T1_A.pdf
└── README.md
```


## 🧩 Desafios

### ✅ Desafio 1: Lista Ligada Simples

- Inicializar lista
- Inserir nó numa posição específica
- Remover nó
- Procurar elemento
- Criar duas listas unidas em forma de Y a partir de vetores
- Imprimir as listas
- Eliminar a lista

### ✅ Desafio 2: Lista Circular Duplamente Ligada

- Inicializar lista
- Inserir nó numa posição específica
- Remover nó
- Imprimir a lista
- Procurar elemento
- Eliminação alternada de pares e ímpares até sobrar um único número
- Eliminar a lista

## 🧪 Como executar

Compile os arquivos com um compilador C:

```bash
gcc main.c lista_simples.c lista_circular_dupla.c -o programa
./programa
