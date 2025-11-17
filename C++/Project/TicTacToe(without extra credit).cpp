#include <iostream>
#include <string>

class digdagdoeuh{
    public:
void displayboard() {
    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << std::endl;
    std::cout << "-----+-----+-----" << std::endl;
    std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << std::endl;
    std::cout << "-----+-----+-----" << std::endl;
    std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << std::endl;
};

bool isvalidmove(int row, int col) { 
if(board[row][col] == 'X'){return false;}
if(board[row][col] == 'O'){return false;}
return true;};

void makemove(int row, int col){
 if(move_count%2 == 0){
    board[row][col] = 'X';}
 else{
    board[row][col] = 'O';} };

bool checkwinner(){
        for(int i = 0; i < 3; i++){
            if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) && 
                (board[i][0] == 'X' || board[i][0] == 'O')){ //check left to right
                return true; 
            }
            if ((board[0][i] == board[1][i] && board[0][i] == board[2][i]) &&
                (board[0][i] ==  'X' || board[0][i] == 'O')){ //check top to down
                return true;
            }
        }
        if(((board[1][1] == board[0][0] && board[1][1] == board[2][2]) || 
           (board[1][1] == board[0][2] && board[1][1] == board[2][0])) &&
           (board[1][1] == 'X' || board[1][1] == 'O')){//check diagonal
                return true; 
        }
        return false; //no winner
    };

bool isdraw(){ //1 is a draw
    return !checkwinner(); //is it not the same?
}; //(ONLY CALL FUNCTION WHEN MOVE COUNT IS 9)

void playgame(){ // IF YOU INPUT A VALUE THAT IS NOT 1-3, MAKE PLAYER DO AGAIN

    do{
    displayboard();
    if (move_count%2 == 0){ //switches player to X
    current_player = 'X';} // 0 is x, 1 is O

    if (move_count%2 == 1){ //switches player to O
    current_player = 'O';}


do{
    std::cout << std::endl << "Turn Count: " << move_count + 1 << " (" << current_player << "'s turn)" << std::endl;
    do{ //YOU HAVE TO FIX IF YOU INPUT A WORD INSTEAD WITHOUT CIN.FAIL
    std::cout << "Enter a valid row (1-3): ";
    std::getline(std::cin, buffer_string);} //use getline
    while (!(buffer_string == "1" || buffer_string == "2" || buffer_string == "3"));
    if(buffer_string == "1"){row = 1;} //check after so that computer doesnt have to keep checking after each input thats not 1 2 or 3
    else if(buffer_string == "2"){row = 2;}
    else if(buffer_string == "3"){row = 3;} //didnt have to use cin.fail
    else{std::cout << "Error Handling Request, ending game" << std::endl; //usually will not happen
         break;}

    do{
    std::cout << "Enter a valid column (1-3): ";
    std::getline(std::cin, buffer_string);}
    while (!(buffer_string == "1" || buffer_string == "2" || buffer_string == "3"));
    if(buffer_string == "1"){col = 1;}
    else if(buffer_string == "2"){col = 2;}
    else if(buffer_string == "3"){col = 3;}
    else {std::cout << "Error Handling Request, ending game" << std::endl; 
         break;}
} while (isvalidmove(row-1,col-1) == false);

    std::cout << "\n";
    if(isvalidmove(row-1,col-1) == true){
        makemove(row-1,col-1);
        move_count++;}

    else {std::cout << "Invalid move, Choose once more" << std::endl << std::endl;}
    
    if(checkwinner() == true){break;}
    } while(move_count < 9);

    displayboard();
    if(checkwinner() == true){ std::cout << "THE WINNER IS " << current_player << "!" << std::endl;}
    else if (isdraw() == true){std::cout << "DRAW!!!!!!" << std::endl;}
    else std::cout << "Returning to Menu..." << std::endl;
}

    private: 
    char board[3][3] =  {   {' ', ' ', ' '},
                            {' ', ' ', ' '},
                            {' ', ' ', ' '}};

    int move_count = 0;
    int row = 0;
    int col = 0;
    std::string buffer_string = "";
    char current_player = 'X'; // x is first
};


int main(){
    digdagdoeuh game;

    game.playgame();
}
