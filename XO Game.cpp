#include <iostream>
#include <vector>
using namespace std;

class tictac

{
private :   

vector<vector<char>> board;
 char current_player;
public  :

tictac() : board(3, vector<char>(3, ' ')) ,current_player('X') {};


void displayboard(){

    for(int i=0;i<3;i++){
  cout<<"  "<<i+1<<" ";
    }
  cout<<endl;
for(int i=0;i<3;i++){
   cout<<"-----+---+---+\n";
   cout<<i+1<< "| ";
for(int j=0;j<3;j++){
 
cout<<board[i][j]<<" | ";
}

   cout<<"\n";
}
  cout<<"-----+---+---+\n"<<endl;
  
 

    
    }
void switch_player(){

  if(current_player=='X'){
current_player='O';
}
    else
  {current_player='X';}
    
}


bool make_move(int row, int col){

if(row>3 || col>3 || row<1 || col<1 || board[row-1][col-1]!=' '){
return false;
}
board[row-1][col-1] = current_player;
  
  switch_player();
  
  return true;
}

bool check_win(){
for(int i=0; i<3; i++){
if( board[0][i]==current_player && board[1][i]==current_player && board[2][i]==current_player)
{ return true;}
if(board[i][0]==current_player && board[i][1]==current_player && board[i][2]==current_player)
{
return true;
}
if(board[0][0]==current_player && board[1][1]==current_player && board[2][2]==current_player){ return true;}
  
if(board[0][2]==current_player && board[1][1]==current_player && board[2][0]==current_player){ return true;}
}
  return false;
}
char get_current(){ return current_player;}
bool isfull(){

for(auto row: board){
for(char cell :row){
if(cell==' '){
return false;
  }
}
}
  return true;
}


};

int main() {
    tictac game;

    game.displayboard();

    while (true) {
       int r, c;
        cout << "Row and Coloumn For " << game.get_current() << " Player ";
      
        cin >> r >> c;

        if (game.make_move(r, c)) {
            game.displayboard();

            if (game.check_win()) {
                cout << "Player " << game.get_current() << " WINS!";
                break;
            }

            if (game.isfull()) {
                cout << "DRAW";
                break;
            }

           
        } else {
            cout << "Invalid Move. Try again." << endl;
        }
    }

    return 0;
}