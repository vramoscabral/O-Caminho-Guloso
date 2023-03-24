# Trabalho AEDS I - O Caminho Guloso

Nesse trabalho, foi feito um programa usando a linguagem C++, que recebe um número N de matrizes MxM em um arquivo "input.data", e depois percorre as matrizes usando como critério de avanço o número de maior valor.

A matriz gerada no programa com os dados do arquivo passará pela função onde será percorrida, com o critério citado anteriormente e com cinco possibilidades de avanço: para direita, para a esquerda, para baixo, para diagonal direita inferior e diagonal esquerda inferior, e sem a permissão para andar pra cima ou voltar a um elemento que já foi acessado.

## Arquivos

* ```main.cpp```: Arquivo e função principal do código;
* ```mat.hpp```: Declaração das funções utilizadas;
* ```mat.cpp```: Implementação das funções descritas no arquivo hpp;
* ```input.data```: Arquivo com as matrizes que serão lidas;
* ```Makefile```: Automatiza o processo de compilação;

## Funções

* int Tam() : Abre o arquivo e lê os dois primeiros caracteres que determinam o tamanho da matriz, como nessa atividade são usadas apenas matrizes quadradas (com mesma quantidade de linhas e colunas), é retornado apenas um valor.
* void ReadMatriz : A primeira função chamada no main.cpp, essa função lê uma matriz de cada vez após pegar o valor retornado pela função Tam() e gerar uma matriz de ponteiro com as posições obtidas, essa matriz será mostrada na tela do terminal e será encaminhada a próxima função, que é a responsável por percorrer a matriz. Nessa função também é calculada a soma total dos números que foram obtidos no percurso da matriz após passarem pela função WalkMatriz().
* void WalkMatriz (int **m,int size) : Essa função recebe como parâmetro a matriz obtida em ReadMatriz() e o tamanho obtido em Tam().

