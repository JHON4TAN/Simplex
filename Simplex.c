#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>



int qtdX, qtdFuncoesLimitantes;
int totalLinhas, totalColunas;
int colunaPivo,linhaMenorElemento;
double variavel_entrada=1000;
double coluna_variavel_entrada;
double tabela[10][10];
double menorPivo=1000, elementoPivo;
int linhaPivo;
double novaLinhaPivo[10];
int variaveisBasicas[10], contBasicas;
int variaveisNaoBasicas[10], contNaoBasicas;




void buscarVariavelEntrada(){
variavel_entrada=1000;
linhaMenorElemento=0;
colunaPivo=0;



printf("\n\n Procurando Variavel Que Entra: \n");
Sleep(4000);



for(int i=0;i<totalLinhas;i++){
for(int j=0;j<totalColunas;j++){
if(tabela[i][j] < variavel_entrada){
variavel_entrada = tabela[i][j];
linhaMenorElemento = i;
colunaPivo = j;
}
}
}







printf("\n\n Assim temos que a Variavel que Entra eh |%.2lf|\n", variavel_entrada);
}



void buscarLinhaPivo(){
menorPivo=1000;
linhaPivo=0;
elementoPivo=0;



printf("\n\n Obtendo Linha Pivo: \n\n");
Sleep(5000);



for(int i=0;i<totalLinhas;i++){
if(i == linhaMenorElemento) continue;
coluna_variavel_entrada = tabela[i][totalColunas-1] / tabela[i][colunaPivo];
if(coluna_variavel_entrada < menorPivo && coluna_variavel_entrada>0){
menorPivo = coluna_variavel_entrada;
linhaPivo = i;
}
}
elementoPivo=tabela[linhaPivo][colunaPivo];
printf("\n\n Linha Pivo: %d\n",linhaPivo);
printf("\n\n Elemento Pivo: %.2lf\n",elementoPivo);
}



void calcularNovasLinhas(){
printf("\n\n Calculando novas Linhas: \n");
Sleep(5000);



int aux=0;
while(aux<totalLinhas){
if(aux!=linhaPivo){
printf("\n\n Nova %d � Linha: \n",aux);



double auxLinha[totalColunas];
double representanteInverso = tabela[aux][colunaPivo] * -1;
for(int i=0;i<totalColunas;i++){
auxLinha[i] = tabela[linhaPivo][i] * representanteInverso;
tabela[aux][i] += auxLinha[i];



printf("%.2lf ", tabela[aux][i]);
}
printf("\n");
}
aux++;
Sleep(2000);
}
}



void calcularNovaLinhaPivo(){
printf("\n\n Calculando Nova Linha Pivo: \n\n");
Sleep(5000);



printf("\n\n Nova Linha Pivo: \n");
for(int i=0;i<totalColunas;i++){
tabela[linhaPivo][i] = tabela[linhaPivo][i] / elementoPivo;
printf("%.2lf ",tabela[linhaPivo][i]) ;
}
printf("\n");



calcularNovasLinhas();
}



void iniciarMetodoSimplex(){
buscarVariavelEntrada();



buscarLinhaPivo();



calcularNovaLinhaPivo();



Sleep(2000);
printf("\n\n Formato da tabela POS METODO: \n");
for(int i=0;i<totalLinhas;i++){
printf("\n");
for(int j=0;j<totalColunas;j++){
printf("%2.lf, ", tabela[i][j], " ");
}
}



printf("\n\n");
printf("\n--------------------------------------------------------------------------------\n");



}



bool verificarTabela(){
printf("\n\n Verificando se a solucao eh otimo ou nao: ");
Sleep(2000);



for(int i=0;i<totalColunas;i++){
if(tabela[0][i]<0){
printf("\n\n Solucao nao eh otima\n");
return false;
}
}
printf("\n\n Solucao eh otima\n");
Sleep(3000);



return true;
}



void buscarVariaveisBasicas_naoBasicas(){
double aux=0;



for(int i=1;i<totalColunas-1;i++){
for(int j=0;j<totalLinhas;j++){
aux += tabela[j][i];
}
if(aux==1){
variaveisBasicas[contBasicas] = i;
contBasicas++;
}
else{
variaveisNaoBasicas[contNaoBasicas] = i;
contNaoBasicas++;
}
aux=0;
}
}



void calcularVariaveisBasicas_NaoBasicas(){
printf("\n\n Calculando Resposta Final e Variaveis Basicas e Nao Basicas: \n");
Sleep(3000);



printf("\n\n Variaveis Basicas: \n");



for(int i=0;i<contBasicas;i++){
if(variaveisBasicas[i] <= qtdX){
double valorResp=0;
for(int j=0;j<totalLinhas;j++){
if(tabela[j][variaveisBasicas[i]] == 1){
valorResp = tabela[j][totalColunas-1];
break;
}
}
printf("X%d = %.2lf\n",variaveisBasicas[i],valorResp);
}
else if(variaveisBasicas[i] > qtdX){
double valorResp=0;
for(int j=0;j<totalLinhas;j++){
if(tabela[j][variaveisBasicas[i]] == 1){
valorResp = tabela[j][totalColunas-1];
break;
}
}
printf("xF%d = %.2lf\n",variaveisBasicas[i]-qtdX,valorResp);
}
}



printf("\n\n Variaveis Nao Basicas: \n");
double zero=0;
for(int i=0;i<contNaoBasicas;i++){
if(variaveisNaoBasicas[i] <= qtdX){
printf("X%d = %.2lf\n",variaveisNaoBasicas[i],zero);
}
else if(variaveisNaoBasicas[i] > qtdX){
printf("xF%d = %.2lf\n",variaveisNaoBasicas[i]-qtdX,zero);
}
}



}



int main(){
system("color 0A");


  system("cls");
   printf("\n ----------- Programa Simplex ------------- ");
   printf("\n ----------- Participantes ---------------- ");
   printf("\n ----------- Affonso Camargo -------------- ");
   printf("\n ----------- Jeferson Ferreira ------------ ");
   printf("\n ----------- Jhonatan Mello --------------- ");



printf("\n\n Quantas funcoes limitantes? ");
scanf("%d", &qtdFuncoesLimitantes);
printf("\n\n Quantos X existem? ");
scanf("%d", &qtdX);



totalColunas = qtdX + (qtdFuncoesLimitantes + 2);
totalLinhas = qtdFuncoesLimitantes + 1;



printf("\n\n Informe os valores da tabela inicial formada linha a linha: \n");
for(int i=0;i<totalLinhas;i++){
for(int j=0;j<totalColunas;j++){
printf ("\n Elemento[%d][%d]: ", i, j);
scanf("%lf", &tabela[i][j]);
}
}



printf("\n--------------------------------------------------------------------------------\n");
printf("\n\n Formato da primeira tabela: \n");
for(int i=0;i<totalLinhas;i++){
printf("\n");
for(int j=0;j<totalColunas;j++){
printf("%2.lf, ", tabela[i][j], " ");
}
}



do{
printf("\n#####################################################################################\n");
system("\n color 0A");
iniciarMetodoSimplex();



}while(!verificarTabela());





buscarVariaveisBasicas_naoBasicas();
calcularVariaveisBasicas_NaoBasicas();



printf("\n\nCalculando Z: \n");
Sleep(2000);



double respostaFinal=0;



for(int i=0;i<totalLinhas;i++){
if(tabela[i][0] != 0){
respostaFinal = tabela[i][totalColunas-1] / tabela[i][0];
break;
}
}



printf("Valor de Z (LUCRO MAXIMO OU GASTO MINIMO): %.2lf\n",respostaFinal);


system("pause");
return 0;
}
