#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include<bits/stdc++.h>
#include <windows.h>
#include<stdlib.h>
#include<conio.h>
#include <iomanip>
#include<dos.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;
void printChar(char ch,int n)        //function to print patterns
{
    while(n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");                   //setting the console for program
    cout<<"\n\n\t";
    printChar('=',30);
    cout<<" A R C A D E ";
    printChar('=',30);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-----------------------------------------------TICTACTOE GAME----------------------------------------------------------
-------------------------------------------------TICTACTOE GAME----------------------------------------------------------
-------------------------------------------------TICTACTOE GAME--------------------------------------------------------*/

class tictactoe
{
public:

char space[3][3]={{'1' ,'2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='x';
bool tie=false;
string n1;
string n2;
void functionone();
void functiontwo();
bool functionthree();
void display();
};
void tictactoe::functionone()//displaying the board
{



    cout<< "  "<<space[0][0]<<" |  "<<space[0][1]<<" |  "<<space[0][2]<<"   \n";
    cout<<" _  | _  | _ \n";
    cout<<"    |    |   \n";
    cout<< "  "<<space[1][0]<<" |  "<<space[1][1]<<" |  "<<space[1][2]<<"   \n";
    cout<<" _  | _  | _ \n";
    cout<<"    |    |   \n";
    cout<<"  "<<space[2][0]<<" |  "<<space[2][1]<<" |  "<<space[2][2]<<"   \n";
    //cout<<"    |    |   \n";



}
void tictactoe::functiontwo()//function for filling up the board
{
    int digit;
    if (token=='x')
    {
        cout<<"\n"<<n1<<" please enter ";
        cin>>digit;
    }
else if (token=='0')
{   cout<<"\n"<<n2<<" please enter";
    cin>>digit;

}
   if(digit==1 && space[0][0]!='x' && space[0][0]!='0')
   {
       space[0][0]=token;
   }
   else if(digit==2 && space[0][1]!='x' && space[0][1]!='0')
   {
       space[0][1]=token;
   }
   else if(digit==3 && space[0][2]!='x' && space[0][2]!='0')
   {
       space[0][2]=token;
   }
   else if(digit==4 && space[1][0]!='x' && space[1][0]!='0')
   {
       space[1][0]=token;
   }
   else if(digit==5 && space[1][1]!='x' && space[1][1]!='0')
   {
      space[1][1]=token;
   }
   else if(digit==6 && space[1][2]!='x' && space[1][2]!='0')
   {
       space[1][2]=token;
   }
   else if(digit==7 && space[2][0]!='x' && space[2][0]!='0')
   {
       space[2][0]=token;
   }
   else if(digit==8 && space[2][1]!='x' && space[2][1]!='0')
   {
       space[2][1]=token;
   }
   else if(digit==9 && space[2][2]!='x' && space[2][2]!='0')
   {
       space[2][2]=token;
   }
   else if(digit>9 || digit<1)
   {
       cout<<"invalid "<<endl;
   }

   else
   {
       cout<<"there is no empty space";
       functiontwo();
       if(token=='x')
       {
        token='0';
        }
       else
        {
        token='x';

        }

   }

   if(token=='x')
    {
        token='0';
    }
    else
    {
        token='x';
    }

}
bool tictactoe::functionthree()
{
    //checking for horizontal rows  and vertical columns
    for(int i=0;i<3;i++)
    {
        if((space[i][0]==space[i][1]&&space[i][0]==space[i][2])||(space[0][i]==space[1][i]&&space[0][i]==space[2][i]))
            return true;
    }
    // checking for diagonal elenments
    if((space[0][0]==space[1][1]&&space[1][1]==space[2][2])||(space[0][2]==space[1][1]&&space[1][1]==space[2][0]))
    {
            return true;
        }

    for(int i= 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j]!='x'&& space[i][j]!='0')
            {
                return false;
            }
        }

    }
    tie=true;
    return true;
}
void tictactoe::display()
{
    fflush(stdin);
    cout<<"Enter the name of the first player"<<endl;
    getline(cin,n1);
    fflush(stdin);
    cout<<"Enter the name of the second player"<<endl;
    getline(cin,n2);
    cout<<n1<<" is the player one so he /she will play  first\n";
    cout<<n2<<" is the player second so he /she will play second \n";
    while(!functionthree())
    {

        functionone();
        functiontwo();

    }
    if(token=='x'&&tie==false)
    {
        functionone();
        cout<<"Congrats "<<n2<<" wins :)";
    }
    else if(token=='0'&& tie==false)
    {
        functionone();
        cout<<"Congrats "<<n1<<" wins :)";
    }
    else
    {
        functionone();
        cout<<"it is a draw :("<<endl;
    }
     system("pause");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*------------------------------------------------ROCK PAPER SCISSORS----------------------------------------------------------
--------------------------------------------------ROCK PAPER SCISSORS----------------------------------------------------------
--------------------------------------------------ROCK PAPER SCISSORS--------------------------------------------------------*/

class gameRules
{
public:
    char computer;
    char player;
    char playmore;

    // For the rules of the game and returns the result
    int rule(char p, char c)
    {
        if (p == c)
        {
            return 0; // Both player and computer gave same choice
        }

        if (p == 'r' && c == 'p')
        {
            return -1; // Player loses
        }
        else if (p == 's' && c == 'p')
        {
            return 1; // Player wins
        }
        else if (p == 'p' && c == 'r')
        {
            return 1; // Player wins
        }
        else if (p == 's' && c == 'r')
        {
            return -1; // Player loses
        }
        else if (p == 'r' && c == 's')
        {
            return 1; // Player wins
        }
        else if (p == 'p' && c == 's')
        {
            return -1; // Player loses
        }
        return 0;
    }

    //To make the display of the game showing all the rules and description
    void display()
    {
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "\t\t\t\t";
        cout << "\t Welcome to Rock, Paper and Scissors Game" << endl;
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "\t\t\t\t";
        cout << "\t Note: " << endl;
        cout << "\t\t\t\t";
        cout << "\t\t r : Rock" << endl << "\t\t\t\t" << "\t\t p : Paper" << endl << "\t\t\t\t" << "\t\t s : Scissor" << endl << "\t\t\t\t"<< endl ;
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
};

class playGame : public gameRules
{
public:
    //For playing the game
    void play()
    {
        do
        {
            int number = 0;
            srand(time(0));
            number = rand() % 100; // will choose a number in range 0 - 99
            // r - for rock
            // p - for paper
            // s - for scissors
            // Computer will choose it's move according to the random number generated
            if (number < 33)
            {
                computer = 'r';
            }
            else if (number > 66)
            {
                computer = 's';
            }
            else
            {
                computer = 'p';
            }
            cout << "\t\t\t\t";
            cout << "Enter your choice: "; // Takes the player's choice
            cin >> player;
            int result = rule(player, computer); // Calls the rule function to decide the winner
            if(result == 1)
            {
                cout << "\t\t\t\t";
                cout << "Computer gave : "<<computer<<endl;
                cout << "\t\t\t\t";
                cout << "You won! Hurray" << endl;
            }
            else if(result == -1)
            {
                cout << "\t\t\t\t";
                cout << "Computer gave : "<<computer<<endl;
                cout << "\t\t\t\t";
                cout << "You lose! Bad Luck" << endl;
            }
            else
            {
                cout << "\t\t\t\t";
                cout << "Computer gave : "<<computer<<endl;
                cout << "\t\t\t\t";
                cout << "Woah! That's Tie!" << endl;
            }
            cout << "\t\t\t\t";
            cout << "Do you want to Play Again?" << endl;
            cout << "\t\t\t\t";
            cout << "Note: Press 'n' to exit! Press 'y' to continue ";
            cin >> playmore;
            cout << "\t\t\t\t";
            for(int i = 0; i < 50; i++)
            {
                cout << "-";
            }
            cout << endl;
        }while(playmore != 'n');
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*------------------------------------------------CASINO GAME----------------------------------------------------------
--------------------------------------------------CASINO GAME----------------------------------------------------------
--------------------------------------------------CASINO GAME--------------------------------------------------------*/

class Display
{
public:
    void printMessageCenter(const char* message);
    void headMessage(const char *message);
    void welcomeMessage();
    void drawLine(int n, char symbol);
    void rules();
};
void Display::drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
void Display::rules()
{
    headMessage("RULES OF THE GAME");
    cout << "\n\n\n\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
    cout << "\n\n\n\t\t\t Enter any key to continue.....";
    getch();
}
//Align the message
void Display::printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    cout << "\t\t\t";
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        cout <<" ";
    }
    //print message
    cout << message;
}
//Head message
void Display::headMessage(const char *message)
{
    system("cls");
    cout << "\t\t\t###########################################################################";
    cout << "\n\t\t\t############                                                   ############";
    cout << "\n\t\t\t############             Casino Game Project in C++            ############";
    cout << "\n\t\t\t############                                                   ############";
    cout << "\n\t\t\t###########################################################################";
    cout << "\n\t\t\t---------------------------------------------------------------------------\n";
    printMessageCenter(message);
    cout << "\n\t\t\t----------------------------------------------------------------------------";
}
//Display message
void Display::welcomeMessage()
{
    headMessage(" ");
    cout << "\n\n\n\n\n";
    cout << "\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =                    WELCOME                =";
    cout << "\n\t\t\t        =                      TO                   =";
    cout << "\n\t\t\t        =                 CASINO GAME               =";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\n\n\t\t\t Enter any key to continue.....";
    getch();
}
//Main class of the project
class PlayerInfo:public Display
{
public:
    int getGuessNumber();
    void setGuessNumber();
    void setAmount();
    float getAmount();
    int getdice();
    void updateAmount(const bool isWin);
    void setBettingAmount();
    bool isPlayerWin();
    void init();
    void displayMessageAfterPlay(const bool isWin);
    void show();
    PlayerInfo():m_amount(0.00),m_bettingAmount(0.00),m_guessNumber(-1)
    {
    }
private:
    float m_amount; //Total balance of player
    float m_bettingAmount; //Betting Amount
    int m_guessNumber; //Number guessed by player
};
//Set Wallet Amount
void PlayerInfo::setAmount()
{
    headMessage("Set Amount");
    do
    {
        cout << "\n\nEnter Deposit amount to play game : Rs.";
        cin >> m_amount;
        try
        {
        if(m_amount < 0.00f)
        {
            throw 'a';
        }
        }
        catch(char ch)
        {
            cout << "\n\nexception caught\n\nPlease Enter valid amount to play the Game!!";
        }

    }
    while(m_amount < 0.00f);
}
//Get wallet Amount
float PlayerInfo::getAmount()
{
    return m_amount;
}
int PlayerInfo::getGuessNumber()
{
    return m_guessNumber;
}
//Get number from player
void PlayerInfo::setGuessNumber()
{
    headMessage("Set Guess Number");
    do
    {
        cout << "\n\nGuess your number to bet between 1 to 10 :";
        cin >> m_guessNumber;
      try
        {
            if(m_guessNumber <= 0 || m_guessNumber >10)
            throw 1;
        }
        catch(int i)
        {

            cout << "\nException caught \n\nPlease check the number!! should be between 1 to 10\n"
                 <<"\nRe-enter the number\n ";
        }
    }
    while(m_guessNumber <= 0 || m_guessNumber > 10);
}
//Update wallet amount
void PlayerInfo::updateAmount(const bool isWin)
{
    m_amount = isWin ? (m_amount + (m_bettingAmount *10)): (m_amount - m_bettingAmount);
}
//Set betting amount
void PlayerInfo::setBettingAmount()
{
    headMessage("Set Bet Amount");
    float c=0.0;
    do
    {
        cout <<"\n\nEnter money to bet : Rs.";
        cin >> m_bettingAmount;
        try{
        if(m_bettingAmount > m_amount)
        {
            throw c;
        }
        }
        catch(float f)
        {
            cout << "\n\nException caught\n\nYour wallet amount is Rs." << m_amount;
            cout << "\n\nYour betting amount is more than your current balance";
        }
    }
    while(m_bettingAmount > m_amount);
}
//Check is player w
bool PlayerInfo::isPlayerWin()
{
    // Will hold the randomly generated integer between 1 and 10
    const int dice = rand()%10 + 1;
    return ((dice == m_guessNumber)? true:false);
}
//Init the game.
void PlayerInfo::init()
{
    welcomeMessage();
    // "Seed" the random generator
    srand(time(0));
    rules();
}
//Display message after each play
void PlayerInfo::displayMessageAfterPlay(const bool isWin)
{
    if(isWin)
    {
        cout << "\n\nGood Luck!! You won Rs." << m_bettingAmount * 10;
        cout << "\n\nNow update Amount is Rs." << m_amount;
    }
    else
    {
        cout << "\n\nBad Luck this time !! You lost Rs."<< m_bettingAmount <<"\n";
        cout << "\n\nNow update Amount is Rs." << m_amount;
    }
}
void PlayerInfo::show()
{
    char choice;
    //init game
    init();
    //Set wallet amount
    setAmount();
    do
    {
        cout << "\n\nYour current balance is Rs." << getAmount() << "\n";
        //Set bet amount
        setBettingAmount();
        //Set guess number
        setGuessNumber();
        //Check whether player lose or win the game
        const bool isPlayerWin1 = isPlayerWin();
        //Update wallet amount
        updateAmount(isPlayerWin1);
        //Display the result after each play
        displayMessageAfterPlay(isPlayerWin1);
        //Check wallet amount and accordingly ask the player
        //to play again
        if(getAmount() == 0.00f)
        {
            cout << "You have no money to play, Good Bye..";
            break;
        }
        //Ask use choice for replay
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }
    while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\n\tThanks for playing game. Your balance amount is Rs." << getAmount() << "\n\n";
    drawLine(70,'=');
    system("pause");
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-----------------------------------------------SNAKE GAME----------------------------------------------------------
-------------------------------------------------SNAKE GAME----------------------------------------------------------
-------------------------------------------------SNAKE GAME--------------------------------------------------------*/

class gameSetUp
{
public:
    bool isAlive = true;
    int foodPosX, foodPosY;
    int row, col;
    int countFood = 0;
    int playmore;

    int playFieldWidth = 30;
    int playFieldHeight = 20;
    int x = playFieldWidth / 2, y = playFieldHeight / 2; // x = 15 and y = 10

    //To make the display of the game showing all the rules and description
    void display()
    {
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "\t\t\t\t";
        cout << "\t Welcome to Snake Game" << endl;
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "\t\t\t\t";
        cout << "\t Note: " << endl;
        cout << "\t\t\t\t";
        cout << "\t\t X : Player" << endl << "\t\t\t\t" << "\t\t O : Food" << endl <<endl;
        cout << "\t\t\t\t" << "\t\t KEY_UP : To go up" << endl << "\t\t\t\t" << "\t\t KEY_DOWN : To go down" << endl
             <<"\t\t\t\t"<<"\t\t KEY_LEFT : To go left" << endl << "\t\t\t\t" << "\t\t KEY_RIGHT : To go right" << endl << endl;
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        Sleep(5000); // Allows the program to wait for a set amount of time
        // Here, the set amount of time is 5 sec.
    }

    //To generate the food for the first time
    void initializeFoodPos()
    {
        foodPosX = rand() % (playFieldWidth - 4) + 2;
        foodPosY = rand() % (playFieldHeight - 4) + 2;
        /*
        playFieldWidth - 4 = 30 - 4 = 26
        rand() % (playFieldWidth - 4) gives a random number between 0 and 26
        rand() % (playFieldWidth - 4) + 2 increases the random generated by 2

        Similar process is taking place with Height.
        */
    }
};

class updateGame : public gameSetUp
{
public:
    //Generates new food for the snake
    void updateFoodPos()
    {
        if (x == foodPosX && y == foodPosY) // If position of snake and food is same, i.e., snake eats the food
        {
            countFood++; // score increases by 1
            foodPosX = rand() % (playFieldWidth - 4) + 2; // Produces new position for food by same logic
            foodPosY = rand() % (playFieldHeight - 4) + 2; // Produces new position for food by same logic
        }
    }

    //Checks if the snake has touched the boundaries or not
    void getSnakeCondition()
    {
        if (x == 0 || x == playFieldWidth   || y == 0 || y == playFieldHeight )
        {
            isAlive = false; // If snake has touched the boundaries, isAlive is updated to false
        }
    }
};

class playSnakeGame : public updateGame
{
public:
    enum directions { UP, DOWN, LEFT, RIGHT };
    directions dir;

    //Takes input directions from the player
    void getKeyStroke()
    {
        // The player can play with direction keys or the alphabet keys
        if (_kbhit()) // To determine whether a key has been pressed or not
        {
            switch (_getch())
            {
            case 'a': case 'A': case KEY_LEFT: // Snake goes left
                dir = LEFT;
                break;
            case 'd': case 'D': case KEY_RIGHT: // Snake goes right
                dir = RIGHT;
                break;
            case 'w': case 'W': case KEY_UP: // Snake goes up
                dir = UP;
                break;
            case 's': case 'S': case KEY_DOWN: // Snake goes down
                dir = DOWN;
                break;
            }
        }
    }

    //To move the snake according to the direction given by the player
    void getSnakeMovement()
    {
        if (dir == LEFT) // Snake moves left
            x--;
        else if (dir == RIGHT) // Snake moves right
            x++;
        else if (dir == UP) // Snake moves up
            y--;
        else if (dir == DOWN) // Snake moves down
            y++;
        else
            return; // If any other key is pressed, the snake will keep moving in the direction mentioned previously.
    }

    //To draw the boundary of the game
    void setPlayField()
    {
        system("cls"); // To clear the screen
        for (row = 0; row <= playFieldHeight; row++) // row will go from 0 to 20
        {
            for (col = 0; col <= playFieldWidth; col++) // col will go from 0 to 30
            {
                if (row == 0 || row == playFieldHeight )
                    cout << "*";
                else if (col == 0 || col == playFieldWidth )
                    cout << "*";
                else if (row == y && col == x) // Initially, x = 15 and y = 10
                    cout << "X"; // "X" represents the player
                else if (row == foodPosY && col == foodPosX)
                    cout << "O"; // "O" represents the food
                else
                    cout << " "; // It prints the empty field to play
            }
            cout << endl;
        }
    }

    //To play the game
    void playGame()
    {
        initializeFoodPos(); // Calling a function of gameSetUp class
        while (isAlive) // isAlive is true initially as defined in gameSetUp class
        {
            setPlayField(); // Calling the function of platSnakeGame class
            updateFoodPos(); // Calling the function of updateGame class
            getKeyStroke(); // Calling the function of platSnakeGame class
            getSnakeMovement(); // Calling the function of platSnakeGame class
            getSnakeCondition(); // Calling the function of updateGame class
            Sleep(100); // Allows the program to wait for a set amount of time
        }
        cout << "\t\tNumber of food eaten = "<< countFood <<endl; // Displays the score of the player
        playAgain();
    }

    //Sets the conditions for the new game
    void playAgain()
    {
        cout << "\t\tDo you want to play more? " << endl;
        cout << "\t\t\t1. YES " << endl << "\t\t\t2. NO " << endl << endl;
        cout <<"\t\tPLease enter your choice : ";
        cin >> playmore;
        if (playmore == 1) // Starts the new game
        {
            x = playFieldWidth / 2;
            y = playFieldHeight / 2;

            initializeFoodPos();
            countFood = 0;
            isAlive = true;
            playGame();
        }
        else // Displays the thank you message if player wants to exit
        {
            cout << "\n\t\tThanks for playing!! " << endl;
            cout << "\t\tHope you enjoyed playing it!! :)" << endl << endl;
        }
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-----------------------------------------------MAIN  FUNCTION----------------------------------------------------------
-------------------------------------------------MAIN  FUNCTION----------------------------------------------------------
-------------------------------------------------MAIN  FUNCTION--------------------------------------------------------*/

int main()
{
    SetConsoleTitle("ARCADE | JIIT");
    string passw="12345",p="";
    char pas[10];
    int k=0;
	cout<<"\t\tLOGIN"<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"|\tEnter password :           |"<<endl;
	cout<<"|__________________________________|"<<endl;
	cout<<"\n\t\t\t\t\t"<<endl;
	while( k<5)
	{
	    pas[k]=getch();
	    char s=k;
	    if(s>5)
		 break;
	    else cout<<"*";
	    k++;
	}
	pas[k]='\0';
	p=pas;

	if(p.compare(passw)==0)                                 //verifying password
	{
	    getch();
		system("cls");
		cout<<" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *";
		cout<<"\n\n\t\t\t\t\t     *                    *";
		cout<<"\n\n\t\t\t\t\t     *       Welcome      *";
		cout<<"\n\n\t\t\t\t\t     *                    *";
		cout<<"\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *";
		cout<<"\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ";
		getch();
		title();
		cout<<"\n\n\t\t\t\tLab Final Even Semester 2022";
    cout<<"\n\n\t\t   Team : Abiha Naqvi , Apeksha Jain , Saara Tyagi , Pooja Sharma \n\n\t\t\t   21103073\t  21103081\t 21103058\t  21103063";
    cout<<"\n\n\t\t\t Jaypee Institute of Information Technology\n\t\t\t";
    printChar('=',38);
    cout<<"\n\n\n\t\t\t       Press any key to Enter";

    getch();
	while(1)
    {
        title();
        cout<<"\n\t";
        printChar('*',64);

 /*-----------------------------------------------M E N U----------------------------------------------------------
--------------------------------------------------M E N U----------------------------------------------------------
--------------------------------------------------M E N U--------------------------------------------------------*/

    //menu for user to access the different functions
        cout<<"\n\n\t\t\t\t1. Tic Tac Toe";
        cout<<"\n\n\t\t\t\t2. Rock Paper Scissors Game";
        cout<<"\n\n\t\t\t\t3. Casino Game";
        cout<<"\n\n\t\t\t\t4. Snake Game";
        cout<<"\n\n\t\t\t\t5. Logout\n\n\t";
        printChar('*',64);
        int choi;
        cout<<"\n\n\t\t\t\tEnter Your Choice :\t";
        cin>>choi;
    if(choi==1)
    {
        system("cls");
        tictactoe t1;//object of the class tictactoe
        t1.display();
    }
    else if(choi==2)
    {
        system("cls");
        playGame p; // An object of class playGame
        p.display(); // Calling of display function through the object
        p.play(); // Calling
    }
    else if(choi==3)
    {
        system("cls");
        PlayerInfo c1;
        c1.show();
    }
    else if(choi==4)
    {
        system("cls");
        srand(time(NULL)); // Sets the seed of the random number generator algorithm used by the function rand()
        playSnakeGame play; // Creating an object of playSnakeGame class
        play.display(); // Calling the function through the object
        play.playGame(); // Calling the function through the object
        system("PAUSE"); //To pause a program
    }
    else if(choi==5)
    {
        cout<<"\t\t\t\tLogged out successfully"<<endl;
        break;
    }
    else
    {
        cout<<"\n\t\tNo Action Detected";
        cout<<"\n\t\tPress Any Key\n\n\n";
        getch();
        system("pause");
    }

    }
	}

	else
    {
        printf("\n\n\n\n\t\t\t\t\t  Wrong Password .Please try again.\n");      //in case password is wrong
        getch();
    }
    return 0;
}
