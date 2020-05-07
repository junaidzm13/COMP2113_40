#include <iostream>


using namespace std;


int main() {
  string a[15][15];
  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      if ((j==6|| j==7||j==8||i==6||i==7||i==8) && (j!=i) && (j+i!=14)){
        a[i][j]="XX";
      }
      else{
        a[i][j]="  ";
      }
    }
  }
  string b1[2][2];
  string b2[2][2];
  string b3[2][2];
  string b4[2][2];
  b1[0][0]="R1";
  b1[0][1]="R2";
  b1[1][0]="R3";
  b1[1][1]="R4";
  b2[0][0]="Y1";
  b2[0][1]="Y2";
  b2[1][0]="Y3";
  b2[1][1]="Y4";
  b3[0][0]="B1";
  b3[0][1]="B2";
  b3[1][0]="B3";
  b3[1][1]="B4";
  b4[0][0]="G1";
  b4[0][1]="G2";
  b4[1][0]="G3";
  b4[1][1]="G4";

  a[6][1]="b1";
  a[1][8]="b2";
  a[13][6]="b3";
  a[8][13]="b4";



  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      cout << a[i][j]<<" ";
    }
    cout <<endl;
  }
  cout <<endl<<endl<<"  b1= ";
  for (int i=0; i<2; ++i){
    for (int j=0; j<2;++j){
      cout << b1[i][j]<<" ";
    }
    cout <<endl<<"      ";
  }
  cout <<endl;

cout <<endl<<endl<<"  b2= ";
for (int i=0; i<2; ++i){
  for (int j=0; j<2;++j){
    cout << b2[i][j]<<" ";
  }
  cout <<endl<<"      ";
}
cout <<endl;

cout <<endl<<endl<<"  b3= ";
for (int i=0; i<2; ++i){
for (int j=0; j<2;++j){
  cout << b3[i][j]<<" ";
}
cout <<endl<<"      ";
}
cout <<endl;

cout <<endl<<endl<<"  b4= ";
for (int i=0; i<2; ++i){
for (int j=0; j<2;++j){
  cout << b4[i][j]<<" ";
}
cout <<endl<<"      ";
}
cout <<endl;
}
