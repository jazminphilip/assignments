#include <iostream>
#include <string>
#include <ctime>

class tictactoe{
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
           (board[1][1] == 'X' || board[1][1] == 'O')){//check diagonala
                return true; 
        }
        return false; //no winner
    };

bool isdraw(){ //1 is a draw
    return (!checkwinner() && move_count == 9); //if there is no winner and the movecount is 9, then output true
};

void initializeboard(){ //extra function to clean up program slightly
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
    move_count = 0;
    current_player = 'X';
    row = 0;
    col = 0;
    buffer_string = "";
}

void playgame(){

    initializeboard();

    do{
        std::cout << std::endl;
        displayboard();

        if (move_count%2 == 0){ //checks to change player
            current_player = 'X';} 
        if (move_count%2 == 1){
            current_player = 'O';}

        std::cout << std::endl << "Turn Count: " << move_count + 1 << " (" << current_player << "'s turn)" << std::endl; 
    
    do{ 
        std::cout << "Enter a valid row (1-3): ";
        std::getline(std::cin, buffer_string);} 
    while (!(buffer_string == "1" || buffer_string == "2" || buffer_string == "3"));

        if(buffer_string == "1"){row = 1;} 
        else if(buffer_string == "2"){row = 2;}
        else if(buffer_string == "3"){row = 3;}
        else{std::cout << "Error Handling Request, ending game..." << std::endl;
            return;} //will most likely not happen but just in case i included it

    do{
        std::cout << "Enter a valid column (1-3): ";
        std::getline(std::cin, buffer_string);}
    while (!(buffer_string == "1" || buffer_string == "2" || buffer_string == "3"));

    if(buffer_string == "1") {col = 1;}
    else if(buffer_string == "2") {col = 2;}
    else if(buffer_string == "3") {col = 3;}
    else {std::cout << "Error Handling Request, ending game..." << std::endl; 
         return;}
    
         //i would have rather preferred putting this all into a single function too but did not

    std::cout << std::endl;
    if(isvalidmove(row-1,col-1) == true){
        makemove(row-1,col-1);
        move_count++;}
    else {std::cout << "Invalid move, Choose once more" << std::endl << std::endl;}
    
    if(checkwinner() == true){break;}

    } while(move_count < 9);

    displayboard();

    if(checkwinner() == true){  
        if(current_player == 'X') { //sorry for nested if statement
            std::cout << "\033[1;34mTHE WINNER IS X!\033[0m" << std::endl << std::endl;} //bold blue text from ANSI escape codes
        else if(current_player == 'O') {
            std::cout << "\033[1;31mTHE WINNER IS O!\033[0m" << std::endl << std::endl;} //bold red text
        else{
            std::cout << "Error handling request, ending game..." <<std::endl; 
            return;}} //weird edge case, could be ommitted

    else if(isdraw() == true){
        std::cout << "\033[1;33mDRAW!!!!!!\033[0m" << std::endl << std::endl;} //bold green text
    else{
        std::cout << "Error Handling Request, ending game..." << std::endl;
        return;} //in case there is a weird edge case somehow
}

int displaymenu(){
    std::cout << "-----------------" << std::endl;
    std::cout << "TicTacToe Menu" << std::endl;
    std::cout << "Player vs Player (1)" << std::endl;
    std::cout << "Player vs AI (2)" << std::endl;
    std::cout << "Quit (3)" << std::endl;
    std::cout << "Gamemode choice: ";

    do{
        std::getline(std::cin, buffer_string);
        if(buffer_string != "1" && buffer_string != "2" && buffer_string != "3") {
            std::cout<< "Only input 1, 2, or 3: " << std::endl;}}
    while(buffer_string != "1" && buffer_string != "2" && buffer_string != "3");
    std::cout << "-----------------" << std::endl;

if(buffer_string == "1"){return 1;}
else if(buffer_string == "2"){return 2;}
else {return 0;} //to quit program
}

void playgameAI(){ 
    initializeboard();
    srand(time(NULL)); //to randomize based on current runtime, i learned about this in a video before this assignment
                       //sorry if that was not what you were looking for...

    do{
    
        if (move_count%2 == 0){ 
            current_player = 'X';} 
        if (move_count%2 == 1){ 
            current_player = 'O';}

        if (current_player == 'X'){
            do{ 
                std::cout << std::endl;
                displayboard();       
                std::cout << std::endl << "Turn Count: " << move_count + 1 << " (" << current_player << "'s turn)" << std::endl;

                do{
                    std::cout << "Enter a valid row (1-3): ";
                    std::getline(std::cin, buffer_string);} 
                while (!(buffer_string == "1" || buffer_string == "2" || buffer_string == "3"));

                if(buffer_string == "1"){row = 1;} 
                else if(buffer_string == "2"){row = 2;}
                else if(buffer_string == "3"){row = 3;} 
                else{std::cout << "Error Handling Request, ending game" << std::endl; //usually will not happen
                    return;}

                do{
                    std::cout << "Enter a valid column (1-3): ";
                    std::getline(std::cin, buffer_string);}
                while (!(buffer_string == "1" || buffer_string == "2" || buffer_string == "3"));
    
                if(buffer_string == "1"){col = 1;}
                else if(buffer_string == "2"){col = 2;}
                else if(buffer_string == "3"){col = 3;}
                else {std::cout << "Error Handling Request, ending game" << std::endl; 
                    return;}
    
                if(isvalidmove(row-1,col-1) == false) {std::cout << std::endl << "Invalid move, Choose once more" << std::endl;}
            } while(isvalidmove(row-1, col-1) == false);

        std::cout << std::endl;
        makemove(row-1,col-1);
        move_count++;
        if(checkwinner() == true){break;}

        } //end of x's move execution

        if (current_player == 'O'){
            do{
                row = rand() % 3 + 1;
                col = rand() % 3 + 1;}
            while (isvalidmove(row - 1,col - 1) == false);
    
            makemove(row-1,col-1);
            move_count++;
            if(checkwinner() == true){break;}} //end of o's move execution

    }while(move_count < 9);

    std::cout << std::endl;
    displayboard();  
    
    if (isdraw() == true){std::cout << "\033[1;33mDRAW!!!!!!\033[0m" << std::endl << std::endl;}

    if(current_player == 'X') {std::cout << "\033[1;34mTHE WINNER IS X!\033[0m" << std::endl << std::endl;} //blue
    else if(current_player == 'O') {std::cout << "\033[1;31mTHE WINNER IS O!\033[0m" << std::endl << std::endl;} //red
    else {
        std::cout << "Error handling request, returning to menu..." << std::endl; //another edge case JUST IN CASE
        return;} 
}
    private: 
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    int move_count = 0;
    int row = 0;
    int col = 0;
    std::string buffer_string = "";
    char current_player = 'X'; // x is first
};


int main(){
    tictactoe game;
    int game_mode = 0;
    std::string choice;
    
 do{
    game_mode = game.displaymenu();
    
    switch(game_mode){
        case 1: // PLAYER VS PLAYER
        game.playgame();
        break;

        case 2: // PLAYER VS AI
        game.playgameAI();
        break;

        default:
        std::cout << "Quitting..." << std::endl;
        return 0; //ends int main completely
    }

    std::cout << "Would you like to return to menu?"  << std::endl << "Yes (1)" << std::endl << "No (2)" << std::endl;
        do{
            std::cout << "Enter Choice: ";
            std::getline(std::cin, choice);}
        while (!(choice == "1" || choice == "2"));

    if(choice == "1"){game_mode = 1;}
    if(choice == "2"){std::cout << "Quitting...";
    return 0;}
}
while(game_mode == 1);
}


