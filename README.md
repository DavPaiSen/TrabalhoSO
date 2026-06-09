Tema: 9- Implementação de um getturnaround() no sistema xv6 com o intuito de 
desenvolver um algoritmo escalonador de processos com analises experimentais de

desempenho e funcionalidade. 

Integrantes:
    Davi Paiva Sendin - 12421BCC004
    Wilson Ribeiro de Andrade Filho - 12311ECP006
    Renato Solva Araújo Rosário - 12421BCC073
    Angelo Ceribelli Piotto - 12421BCC069
    
Ideia e formulação para implementação:

  Para descobrir quanto tempo um processo levou do início ao fim, o sistema 
operacional precisa funcionar como um relógio. No xv6, o tempo é medido pelas 
batidas do relógio interno do computador(clock implementado no hardware da 
máquina). A primeira ideia é fazer o sistema anotar internamente a batida exata 
em que um programa nasceu e a batida exata em que ele encerrou suas atividades. 
A nova função, o getturnaround(), faria apenas a conta de subtração entre esses 
dois momentos para entregar o tempo total de vida daquele programa no sistema.

 O "quantum", no algoritmo de Round Robin, é uma fatia de tempo máxima que cada 
programa tem para usar o processador antes de ser obrigado a dar a vez para o 
próximo da fila. No xv6 original, a regra é bem engessada: a cada única batida 
do relógio, o sistema já troca o programa em execução. A principal ideia do 
grupo irá ser criar um comando simples para você mudar o tamanho dessa fatia de 
tempo direto pelo terminal, sem precisar desligar, reprogramar e reiniciar todo 
o sistema a cada novo teste.

  Ademais, há a percepção que o tempo escolhido deve não ser muito curto e não 
muito longo para permitir ao computador melhor execução em casos de sobrecarga.

  Portanto, para provar esse impacto na prática, a ideia é criar pequenos 
programas de teste. Alguns deles seriam focados apenas em fazer contas 
matemáticas pesadas sem parar, exigindo muito do processador. Outros seriam 
programas que ficam pausando o tempo todo para simular a leitura ou a gravação 
de arquivos. No final, a ideia é construir um "programa chefe" que inicia todos 
esses testes ao mesmo tempo, altera a fatia de tempo do sistema e usa o seu 
getturnaround() para imprimir um relatório final mostrando qual foi o tempo de 
atraso de cada um.






