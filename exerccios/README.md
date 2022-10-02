## Exercícios Linguagem C - Curso Analise e Desenvolvimento de Sistemas - FATEC - Rubens LARA
### Este repositório tem como ideia organizar os exercícios em linguagem C estudados no 2º semestre do Curso, já aproveitando a ferramenta do GitHub como junção de aprendizado.

Aluno: Mauro Paulino

mauro.paulino@gmail.com

Linkedin: https://www.linkedin.com/in/mauroppjr/


### Exercicios propostos no capitulo 01

    EXERCICIOS CAPITULO 01


    1 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
        multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
        teclado.
        Ex: menor multiplo de 13 maior que 100. Resultado: 104.

    2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
        long, int, float, double e um char e imprima-os no video no seguinte
        formato:

                 10        20        30        40        50        60
         12345678901234567890123456789012345678901234567890123456789012345
             short               long                int
                       float               double              char

    3 - Escreva um programa que receba via teclado um tempo em segundos e converta
        para horas, minutos e segundos.
        Ex.: recebe 3850 segundos que converte para 1h 4min 10s.

    4 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
        variável auxiliar.

    5 - Escreva um programa que lê um valor em reais e calcula qual o menor número
        possível de notas de $100, $50, $20, $10, $5, $2 e $1 em que o valor lido pode
        ser decomposto. Escrever o valor lido e a relação de notas necessárias.    

 
   
### Exercicios propostos no capitulo 02
    


    EXERCICIOS CAPITULO 02


    OBS.: Faça um loop infinito e defina uma saida em todos os exercícios.

    1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
        pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
        comando if-else.

    2 - Resecreva o programa do execicio anterior agora utilizando o comando switch.
        Conte o n. de tentativas e imprima o resultado no video.

    3 - Escreva um programa que receba via teclado numeros inteiros positivos.
        Quando o numero digitado for negativo o programa deve parar e calcula a
        media dos valores positivos digitados.

    4 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
        instantes em que a ligacao foi iniciada e concluida.
        Escreva um programa que recebe via teclado dois instantes dados em
        horas, minutos e segundo e determina o intervalo de tempo
        (em horas, minutos e segundos) decorrido entre eles.

    5 - Um posto está vendendo combustíveis com a seguinte tabela de descontos:
         Álcool
             até 20 litros, desconto de 3% por litro
             acima de 20 litros, desconto de 5% por litro
         Gasolina
              até 20 litros, desconto de 4% por litro
              acima de 20 litros, desconto de 6% por litro
         Escreva um programa que leia o número de litros vendidos e o tipo de
         combustível (codificado da seguinte forma: A-álcool, G-gasolina). Calcule e
         imprima o valor a ser pago pelo cliente sabendo-se que o preço do litro da
         gasolina é R$ 5,88 e o preço do litro do álcool é R$ 4,18.
         

### Exercicios propostos no capitulo 03

    
        /*****************************************************************************

          EXERCICIOS

    *****************************************************************************
    OBS.: Todos os programa devem ser finalizados pelo usuario.

    1 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
        uma funcao para cada operacoes aritmeticas e passe como parametro os 2
        valores recebidos na funcao main(). Retorne os resultados usando o comando
        return e imprima-os no video na funcao main().

    2 - Aproveitando o programa anterior inclua a selecao das operacoes aritmeticas
        para transforma-lo em uma calculadora. (utilize o comando switch). As operacoes
        aritmeticas devem estar em funcoes. O resultado deve ser mostrado na
        funcao main()

    3 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
        pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
        no video na funcao main(). Passe como informacao para a funcao a letra
        digitada.(utilize o comando return). O vetor deve ser uma variavel global.

        vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

    4 - Faça um programa receba dois números inteiros e execute as seguintes funções:
        - Verificar se o número digitado é positivo ou negativo. Sendo que o valor de
          retorno será 1 se positivo, 0 se negativo ou -1 se for igual a 0.
        - Se os 2 números são positivos, retorne a soma dos N números existentes entre
          eles.
        - Se os 2 números são negativos, retorne a multiplicação dos N números existente
          entre eles.

    5 - Escreva um programa que receba um numero N. Escreva uma função que
        retorne a soma dos algarismos de N!. O resultado deve ser mostrado na funcao
        main().
        Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos ´e 2 + 4 = 6.
    */
    
    
### Exercicios propostos no capitulo 04


    /*****************************************************************************

          EXERCICIOS

    *****************************************************************************
    OBS.: Todos os programa devem ser finalizados pelo usuario.

    1 - Escreva um programa que receba um vetor de tamanho 10 e o decomponha em dois
        outros vetores. Um contera' as componentes de ordem ímpar e o outro contera'
        as componentes de ordem par.
        Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7}, o programa
        deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3}.

    2 - Receba via teclado valores do tipo int para uma matriz 5 x 5. Receba via
        teclado um valor x. O programa dever fazer a busca desse valor x na matriz
        e, ao final escrever a localizacao (linha e coluna) ou uma mensagem de
        ”nao encontrado”.

    3 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
        3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

                10        20        30        40        50
        12345678901234567890123456789012345678901234567890
          int                 long                unsigned
                    float               double
          int                 long                unsigned
                    float               double
          int                 long                unsigned
                    float               double

    4 - Receba via teclado dez valores inteiros e ordene por ordem crescente assim
        que sao digitados. Guarde-os em um vetor. Mostre ao final os valores ordenados.

    5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
        que recebe os dados via teclado para esses 2 vetores. Usando o operador
        subtracao "-", subtraia os elementos de mesmo indice dos 2 vetores
        e guarde o resultado num 3. vetor. Imprima na tela o indice, os valores e
        o resultado dos 6 elementos dos vetores.
    */
    
    
 ### Exercicios propostos no capitulo 05
 
 
     /*****************************************************************************

          EXERCICIOS

    *****************************************************************************
    OBS.: Todos os programa devem ser finalizados pelo usuario.

    1 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
        e imprima-os no video no seguinte formato:(Declare os vetores como variavel
        global)

                10        20        30        40        50
        12345678901234567890123456789012345678901234567890
          nome1                                   nome5
                    nome2               nome4
                              nome3

    2 - Receba 2 string de ate 10 caracteres via teclado na funcao main() e noutra
        funcao compare-as mostrando como resultado se são IGUAIS ou DIFERENTES na funcao
        main(). (Declare os vetores como variavel global)

    3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
        para letras maiusculas.

    4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
        para letras minusculas.

    5 - Faca um programa que leia uma palavra (maximo de 20 letras) em uma funcao
        e some 1 no valor ASCII de cada caractere da palavra em outra funcao. Na sua
        funcao main() imprima a string resultante. (Declare o vetor como variavel
        global)
    */
    
    
 ### Exercicios propostos no capitulo 06
 
 
      /*****************************************************************************

            EXERCICIOS

      *****************************************************************************
      OBS.: Faça um loop infinito e defina uma saida em todos os exercícios.

      1 - Escreva um programa que receba via teclado 2 numeros inteiros e
          imprima-os no video com o resultado das 4 operacoes aritmeticas.

      2 - Reescreva o exercicio anterior utilizando operadores de atribuicao
          composta.

      3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
          dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
          data (dia, mes e ano) atual.

      4 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
          as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
          video no formato decimal e hexadecimal.

      5 - Escreva um programa que receba via teclado um valor e tenha o menu abaixo.
             1 - transforma graus Celsius em Fahrenheit e Kelvin
             2 - transforma graus Fahrenheit em Celsius e Kelvin
             3 - transforma graus Kelvin em Celsius e Fahrenheit
          Cada opcao de menu deve chamar uma funcao que retorna o resultado da
          conversao. O resultado deve ser mostrado na funcao main().
      */ 


 ### Exercicios propostos no capitulo 07
    
    /*****************************************************************************                                                            

            EXERCICIOS                                                                                                        

    *****************************************************************************                                                             
      OBS.: Todos os programa devem ser finalizados pelo usuario.                                                                               

      1 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de                                                               
          estruturas de 4 elementos. Receba os dados pelo teclado e imprima-os no                                                               
          video. Faça um menu. (vetor de estruturas)                                                                                            
                      nome, end, cidade, estado, cep                                                                                            

      2 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via                                                               
          teclado e calculo, o numero de dias entre elas e mostre o resultado no                                                                
          video. (vetor de estruturas)                                                                                                          
                      dia, mes, ano                                                                                                             

      3 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de                                                               
          estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.                                                             
          No menu inclua uma 3. opcao que calcula o IMC da pessoal. Faça um menu.                                                               
          (vetor de estruturas)                                                                                                                 
          Calculo do IMC = peso/(altura*altura).                                                                                                
              estrutura: nome, peso, altura                                                                                                     

      4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.                                                             
          Receba dados via teclado e imprima estes conteudos no video no seguinte                                                               
          formato.                                                                                                                              
                   char, int, long, float, double                                                                                               
                   unsigned char, unsigned int, unsigned long,                                                                                  

                  10        20        30        40        50        60        70                                                                
          1234567890123456789012345678901234567890123456789012345678901234567890                                                                
              char      int       long                float               double                                                                
                    unsigned char       unsigned int        unsigned long                                                                       

      */
      
  ### Exercicios propostos no capitulo 08
       
     /****************************************************************************

			EXERCICIOS

    *****************************************************************************
    OBS.: Todos os programa devem ser finalizados pelo usuario.

    1 - Escreva um programa que contenha uma estrutura representando uma data
        valida. Essa estrutura deve conter os campos dia, mes e ano. Em seguida,
        leia duas datas e armazene nessa estrutura usando ponteiros. Calcule e exiba o
        numero de dias que decorreram entre as duas datas usando ponteiros.

    2 - Receba um caracter via teclado usando ponteiros e compara com o vetor abaixo
        usando ponteiros. Mostre como resultado se EXISTE ou NAO EXISTE.
        vetor -> b,d,f,h,j,l,m,o,q,s,u,w,y

    3 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
        Receba os dados pelo teclado usando ponteiros e imprima-os no video
        também usando ponteiros. Utilize um comando de loop. (vetor de estruturas)
                  nome, end, cidade, estado, cep

    4 - Receba 2 string de ate 10 caracteres via teclado, compare-as usando ponteiros
        e mostre como resultado se são IGUAIS ou DIFERENTES.

    5 - Escreva um programa que receba via teclado usando ponteiros um char,
        int, long, unsigned,float, double, unsigned long e unsigned char,
        e imprima-os no video utilizando ponteiros e o operador de conteudo *
        no seguinte formato:

                10        20        30        40        50        60
        123456789012345678901234567890123456789012345678901234567890
            int                 long                unsigned
                      float               double              char
                 unsigned long       unsigned char

    6 - Escreva um programa que receba via teclado numeros inteiros positivos usando
        ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
        a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
        feitos usando ponteiro.
    */

    

  ### Exercicios propostos no capitulo 09
       
     /****************************************************************************

			EXERCICIOS

    *****************************************************************************
	   OBS.: Todos os programa devem ser finalizados pelo usuario.

	1 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
	    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa no
	    video na funcao main(). O vetor é uma variavel local na função main().Passe
	    como parametro para a funcao o vetor e a letra digitada usando ponteiros.
	    Pesquise usando ponteiros. (utilize o comando return)
	    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

	2 - Escreva um programa que receba em 1 funcao 2 strings de ate' 10 caracteres.
	    Os vetores sao declaradas como variavel local na função main().
	    Escreva uma funcao que recebe as 2 strings como parametros usando ponteiros,
	    compare estas 2 strings e retorno 1 se iguais ou 0 se diferentes.

	3 - Escreva um programa que receba n valores via teclado, receba também a
	    operação a ser executada. Quando for digitado "=" o programa deve mostrar
	    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
	    de dados devem ser funções que recebe os valores usando ponteiros.

	4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
	    A estrutura é uma variavel local na função main().Receba via teclado o
	    conteudo de cada um dos membros numa função e imprima-os no video no
	    seguinte formato(também numa função).

		    10        20        30        40        50        60        70
	    1234567890123456789012345678901234567890123456789012345678901234567890
		char      int       long                float               double
		      unsigned char       unsigned int        unsigned long

	5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
	    de 4 elementos como variavel local na funcao main(). Receba os 4 registros
	    sequencialmente pelo teclado numa função e imprima todos os registros no
	    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
	    Coloque no menu a opção de sair tambem. Utilize o comando switch.
	    (vetor de estruturas)
			nome, end, cidade, estado, cep

	6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
	    exclui um registro.
	*/


  ### Exercicios propostos no capitulo 10

	/*****************************************************************************

				EXERCICIOS

	*****************************************************************************
	OBS.: Todos os programa devem ser finalizados pelo usuario.

	1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
	    Receba via teclado diversos caracteres (um por vezes) e armazene-os
	    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
	    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
	    arquivo (um por vezes).

	2 - Escreva um programa para controle de um cadastro de clientes. Para cada
	    registro sera' armazenado nome, end, cidade, estado, cep numa estrutura
	    de dados. A unica estrutura de dados e' uma variavel local na funcao main().
	    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
	    necessario). Nao pode usar vetor de estruturas. Utilize ponteiros.
	    O programa deve ter as seguintes opcoes: (cada opcao e' um funcao)
	    1 - inclui registros
	    2 - listar todos os registros
	    3 - pesquisar registro pelo nome
	    4 - altera registro
	    5 - exclui registro
	    6 - saida

	3 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
	    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
	    dados. Utilize um vetor de estrutura de 4 elementos como variavel local na
	    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
	    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
	    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
	    do arquivo.
	    O programa deve ter as seguintes opcoes:(cada opcao e' um funcao)
	    1 - inserir contato
	    2 - altera contato
	    3 - exclui contato
	    4 - pesquisar um contato pelo nome
	    5 - listar todos os contatos
	    6 - listar os contatos cujo nome inicia com uma letra digitada
	    7 - imprimir os aniversariantes do mês.
	    8 - saida

	4 - Escreva um programa para o controle de mercadorias em uma despensa
	    domestica. Para cada produto sera' armazenado um codigo numerico, nome
	    do produto e quantidade atual numa estrutura de dados. A unica estrutura
	    de dados deve ser declarada como variavel local na funcao main(). Escreva
	    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
	    necessario). Nao pode usar vetor de estruturas. Utilize ponteiros.
	    O programa deve ter as seguintes opcoes: (cada opcao e' um funcao)
	    1 - inclui produtos
	    2 - altera produtos
	    3 - exclui produtos
	    4 - pesquisar uma mercadoria pela descrição
	    5 - listar todos os produtos
	    6 - listar os produtos não disponíveis.
	    7 - alterar a quantidade atual
	    8 - saida
	*/
