# Calculador de Páscoa e Gerador de Calendário Anual

Este projeto em **C** calcula a data do Domingo de Páscoa para qualquer ano fornecido e gera o **calendário completo** dos 12 meses desse ano no terminal, levando em consideração anos bissextos e o alinhamento correto dos dias da semana.

---

## 📌 Funcionalidades

- **Cálculo da Páscoa (Algoritmo do Computus / Meeus/Jones/Butcher):**
  - Determina com precisão o dia e o mês (março ou abril) da Páscoa para um determinado ano.
  - Utiliza variáveis como o *Número Áureo*, *Século*, *Fatores de Correção* e *Epacta*.
- **Verificação de Ano Bissexto:**
  - Checa se o ano é bissexto (ajustando o mês de Fevereiro para 29 dias).
- **Gerador de Calendário em Formato de Tabela:**
  - Calcula em qual dia da semana cai o dia 1º de Janeiro do ano informado.
  - Imprime no console os 12 meses do ano formatados em colunas (`dom`, `seg`, `ter`, `qua`, `qui`, `sex`, `sab`).

---

## 🧮 Como Funciona o Algoritmo de Páscoa

O código utiliza o algoritmo eclesiástico para determinar a data da Páscoa:
1. **Verificação de Ano Bissexto:**
   $$\text{bissexto} = (\text{ano} \pmod 4 == 0 \text{ e } \text{ano} \pmod {100} \neq 0) \lor (\text{ano} \pmod {400} == 0)$$
2. **Cálculo do Número Áureo ($G$):** $G = (\text{ano} \pmod {19}) + 1$
3. **Determinação da Epacta ($E$) e Correções Solares/Lunares ($X, Z$).**
4. **Localização do Domingo de Páscoa:** Cálculo da Lua Cheia pascal e deslocamento para o domingo subsequente.
5. **Retroprocessamento:** A partir da data da Páscoa (que é sempre um domingo), o algoritmo retrocede no tempo para descobrir em qual dia da semana começou o ano ($1^\circ$ de Janeiro).

---

## 🚀 Como Executar

### Pré-requisitos
- Um compilador C instalado (como `gcc`, `clang` ou `MinGW`).

### Passo a Passo

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   cd seu-repositorio
   ```

2. **Compile o código:**
   ```bash
   gcc main.c -o calendario
   ```

3. **Execute o programa:**
   ```bash
   ./calendario
   ```
   *(No Windows, utilize `calendario.exe`)*

4. **Digite o ano desejado quando solicitado:**
   ```text
   2024
   ```

---

## 💻 Exemplo de Saída

```text
2024
A Páscoa será no dia 31/03
Calendário do ano 2024
|-----------------------------|
|Janeiro                      |
|-----------------------------|
| dom seg ter qua qui sex sab |
|  --  01  02  03  04  05  06 |
|  07  08  09  10  11  12  13 |
|  14  15  16  17  18  19  20 |
|  21  22  23  24  25  26  27 |
|  28  29  30  31  --  --  -- |
|  --  --  --  --  --  --  -- |
|-----------------------------|
...
```

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem C** (padrão C99 / ANSI C)
- **Biblioteca Standard Library:** `<stdio.h>`

---
