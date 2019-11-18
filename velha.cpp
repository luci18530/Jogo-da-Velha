//============================================================================
// Name        : Jogo.cpp
// Author      : Luciano Pereira
// Version     :
// Description :
//============================================================================

#include <iostream>
#include <cstdio>

#include <clocale>


using namespace std;
// 0 = não usado ; 1 = X ; 2 = O

void exibirjogo (int lin, int col, int matriz[3][3]){
  for (lin = 0; lin < 3; lin++){
      if (lin == 0){
      cout << "\n";}
      if (lin != 0 ){
      cout << "\n-----\n";}
    for (col = 0; col<3; col++){
      if (col != 0 ){
      cout << "|";}
      if (matriz[lin][col] == 0){
        cout << " ";
      }

      else if (matriz[lin][col] == 1){
        cout << "X";
      }

      else if (matriz[lin][col] == 2){
        cout << "O";
      }
      
    }
  }
  cout << "\n\n";
}

void jogadajog1 (int jog1lin,int jog1col, char jog1nome [64], int matriz[3][3], bool *error1){
  cout << jog1nome << " : Escolha a linha que você quer marcar: ";
    cin >> jog1lin;
    cout << jog1nome << " : Escolha a coluna que você quer marcar: ";
    cin >> jog1col;
    if (matriz[jog1lin-1][jog1col-1] == 1 ||matriz[jog1lin-1][jog1col-1] == 2 || jog1lin > 3 || jog1col > 3){
      cout << "Posição invalida!!!\n";
      *error1 = true;
      
    }
    else {matriz[jog1lin-1][jog1col-1] = 1;}
}

void jogadajog2 (int jog2lin,int jog2col, char jog1nome [64], int matriz[3][3], bool *error2){
  	cout << jog1nome << " : Escolha a linha que você quer marcar: ";
    cin >> jog2lin;
    cout << jog1nome << " : Escolha a coluna que você quer marcar: ";
    cin >> jog2col;
    if (matriz[jog2lin-1][jog2col-1] == 2 ||matriz[jog2lin-1][jog2col-1] == 1 || jog2lin >3 || jog2col >3){
      cout << "Posição invalida!!!\n";
      *error2 = true;
      // condições de erro do jogador 2
    }
    else {matriz[jog2lin-1][jog2col-1] = 2;}
}
  

int main() {
//setlocale(LC_ALL, "Portuguese_Brasil.1252");
	system("chcp 1252");
	system("cls");
	inicio:
	bool error1 = false;
	bool error2 = false;
	int op_ini = 0;
	int jog1lin = 0;
	int jog1col = 0;
	int jog2lin = 0;
	int jog2col = 0;
	int jogadas = 0;
	int lin = 0;
	int col = 0;
	int matriz [3][3];
	char jog1nome [64];
	char jog2nome [64];

  
	for (lin = 0; lin < 3; lin++){
    for (col = 0; col<3; col++){
      matriz[lin][col] = 0;
    }
  }

  cout << "BEM VINDO AO JOGO DA VELHA\n" << "--------------------------\n" << "POR FAVOR DIGITE\n\n" << "1 - Jogar\n2 - Sair\n\n";

  cin >> op_ini;

  if (op_ini == 1){
    cout << "\nDigite seu nome Jogador 1: ";
    cin >> jog1nome;
    cout << "Digite seu nome Jogador 2: ";
    cin >> jog2nome;
    cout << "\n";
    cout << jog1nome << " Marcará X\n";
    cout << jog2nome << " Marcará O\n\n";

    while (1){
    exibirjogo(lin,col,matriz);
    jogadajog1(jog1lin,jog1col, jog1nome, matriz, &error1);
	
    if (error1 == true){
      volta1:
      error1 = false;
      jogadajog1(jog1lin,jog1col, jog1nome, matriz, &error1);
      if (error1 == true){
        goto volta1;
      }
    }
	jogadas++;
	
	if (jogadas >= 9){
		cout << "\nEmpate !!!\n\nPressione qualquer tecla para continuar\n\n";
		exibirjogo(lin,col,matriz);
		cin.ignore();
   	  cin.get();
	  goto inicio;
	}
   
    if (
      (matriz[0][0] == 1 && matriz[1][0] == 1 && matriz[2][0] == 1) || // vertical l1
      (matriz[0][1] == 1 && matriz[1][1] == 1 && matriz[2][1] == 1) || // vertical l2
      (matriz[0][2] == 1 && matriz[1][2] == 1 && matriz[2][2] == 1) || // vertical l3
      (matriz[0][0] == 1 && matriz[1][1] == 1 && matriz[2][2] == 1) || // diagonal
      (matriz[0][2] == 2 && matriz[1][1] == 2 && matriz[2][0] == 2) || // diagonal /
      (matriz[0][0] == 1 && matriz[0][1] == 1 && matriz[0][2] == 1) || // horizontal c1
      (matriz[1][0] == 1 && matriz[1][1] == 1 && matriz[1][2] == 1) || // horizontal c2
      (matriz[2][0] == 1 && matriz[2][1] == 1 && matriz[2][2] == 1))   // horizonal c3 
      {
        cout << "\nJogador " << jog1nome << " venceu!!!\n\n" "Pressione qualquer tecla para continuar\n\n";
        exibirjogo(lin,col,matriz);
        cin.ignore();
        cin.get();
        goto inicio;
      }

    exibirjogo(lin,col,matriz);
    jogadajog2(jog2lin,jog2col, jog2nome, matriz, &error2);
    
    
    if (error2 == true){
      volta2:
      error2 = false;
      jogadajog2(jog2lin,jog2col, jog2nome, matriz, &error2);
      if (error2 == true){
        goto volta2;
      }
    }
	jogadas++;
    
    if (
    (matriz[0][0] == 2 && matriz[1][0] == 2 && matriz[2][0] == 2) || // vertical l1
    (matriz[0][1] == 2 && matriz[1][1] == 2 && matriz[2][1] == 2) || // vertical l2
    (matriz[0][2] == 2 && matriz[1][2] == 2 && matriz[2][2] == 2) || // vertical l3
    (matriz[0][0] == 2 && matriz[1][1] == 2 && matriz[2][2] == 2) || // diagonal 
    (matriz[0][2] == 2 && matriz[1][1] == 2 && matriz[2][0] == 2) || // diagonal 
	(matriz[0][0] == 2 && matriz[0][1] == 2 && matriz[0][2] == 2) || // horizontal c1
    (matriz[1][0] == 2 && matriz[1][1] == 2 && matriz[1][2] == 2) || // horizontal c2
    (matriz[2][0] == 2 && matriz[2][1] == 2 && matriz[2][2] == 2))   // horizonal c3
    {
      cout << "\nJogador " << jog2nome << " venceu!!!\n\n"  << "Pressione qualquer tecla para continuar\n\n";
      exibirjogo(lin,col,matriz);
      cin.ignore();
   	  cin.get();
	  goto inicio;
    }
	
	


    }
  }

  if (op_ini == 2){
  	
     
	cin.get(); 
   
  }
	return 0;
}
