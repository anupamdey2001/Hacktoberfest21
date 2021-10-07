#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

#define PLAYER1 1
#define PLAYER2 2
#define PLAYER1MOVE '0'
#define PLAYER2MOVE 'X'

class Board
{
	private :
        int side;
	public : 
        char** gameBoard;
		Board(int side)
		{
			this->side=side;
            gameBoard = new char*[side];
            for(int i =0;i<side;i++)
            {
                gameBoard[i] = new char[side];
            }

            for(int i=0;i<side;i++)
            {
                for(int j=0;j<side;j++)
                {
                    gameBoard[i][j]=' ';
                }
            }
		}
		
		void showBoard()
        {

            for(int i =0;i<=side*2;i++)
            {  
                cout<<" \t\t\t ";
                for(int j=0;j<side;j++)
                {
                    if(i%2==0)
                    {
                        for(int k =0;k<side;k++)cout<<"----";
                        break;
                    }
                    else
                    {   
                        if(j==0)cout<<"| ";
                        cout<<gameBoard[i/2][j]<<" | ";
                    }
                }
                cout<<"\n";
            }	            
            return;
        }
        

};

class Play : public Board
{   
    private : 
        int side;
        int moveIndex,x,y;
        int place;
        int count,cnt;
    public:
        Play(int side) : Board(side) 
        {
            this->side = side;
            moveIndex = 1;
            count=0;
            cnt=0;
        }
        int turn = PLAYER1;

        bool rowCrossed()
        {
            for(int i = 0; i < side; i++)
            {
                if(gameBoard[i][0]==gameBoard[i][1] && gameBoard[i][1]==gameBoard[i][2] && gameBoard[i][0] !=' ')
                return true;
            }
            return false;
        }
        
        bool columnCrossed()
        {
            for(int i = 0; i < side; i++)
            {
                if(gameBoard[0][i]==gameBoard[1][i] && gameBoard[1][i]==gameBoard[2][i] && gameBoard[0][i] !=' ')
                return true;
            }
            return false;
        }
        
        bool diagonalCrossed()
        {
            if(gameBoard[0][0]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][2] && gameBoard[0][0] !=' ')
                return true;
            if(gameBoard[0][2]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][0] && gameBoard[0][2] !=' ')
                return true;
                
            return false;
        }
        
        bool gameOver()
        {
            return (this->rowCrossed() || this->columnCrossed() || this->diagonalCrossed());
        }

        int getData(int turn)
        {
            int val;
            if(turn==PLAYER1)cout<<"\t\tPlayer 1 Turn\n";
            else
                cout<<"\t\tPlayer 2 Turn\n";
            cout<<"Enter the place where you want to mark : ";
            cin>>val;

            if(val>side*side)
            {   
                cnt++;
                if(cnt<3)
                {
                    system("clear");
                    cout<<"\t\t You Entered Invalid Place \n";
                    cout<<"\t\t Enter Again...\n";
                    return getData(turn);
                }
                else
                {
                    cout<<"You have tried Invalid place for three times \n\n";
                    cout<<"You have to start the game again\n";
                    cout<<"Press ANY KEY for menu\n";
                    return -1;
                }

            }
            cnt=0;
            return val;
        }

        void winner(int turn)
        {
            system("clear");
            showBoard();
            if(turn == PLAYER1)
            {
                cout<<"Congratulations Player 1 "<<endl;
                cout<<"You have won the match"<<endl;;
            }
            else
            {
                cout<<"Congratulations Player 2 "<<endl;
                cout<<"You have won the match"<<endl;;
            }
            return;
        }

        void gameStart(int turn)
        {
            while(this->gameOver()==false && moveIndex != side*side)
            {
                if(turn == PLAYER1)
                {
                    showBoard();
                    place = this->getData(turn);
                    if(place == -1)return;
                    system("clear");
                    x=(place-1)/side;
                    y=(place-1)%side;
                    
                    if(gameBoard[x][y]!=' ')
                    {
                        count++;
                        if(count<3)
                        {
                            cout<<"This place is already marked"<<endl;
                            cout<<"Try Again"<<endl;;
                            
                        }
                        else
                        {
                            cout<<"You have tried 3 times in a wrong place"<<endl;;
                            cout<<"You have to again start the game"<<endl;
                            cout<<"Press ANY KEY for menu"<<endl;
                            return;
                        }
                    }
                    else
                    {
                        count=0;
                        gameBoard[x][y] = PLAYER1MOVE;
                        cout<<"Player 1 has put "<<PLAYER1MOVE<<" in a cell "<<place<<"\n";
                        moveIndex++;
                        turn = PLAYER2;
                    }
                    
                }
                else if(turn == PLAYER2)
                {
                    showBoard();
                    place = this->getData(turn);
                    system("clear");
                    x=(place-1)/side;
                    y=(place-1)%side;
                    
                    if(gameBoard[x][y]!=' ')
                    {
                        count++;
                        if(count<3)
                        {
                            showBoard();
                            cout<<"This place is already marked\n";
                            cout<<"Try Again\n";
                            
                        }
                        else
                        {
                            showBoard();
                            cout<<"You have tried 3 times in a wrong place\n\n";
                            cout<<"You have to again start the game\n";
                            cout<<"Press ENTER for menu\n";
                            return;
                        }
                    }
                    else
                    {
                        count=0;
                        gameBoard[x][y] = PLAYER2MOVE;
                        cout<<"Player 2 has put "<<PLAYER2MOVE<<" in a cell "<<place<<"\n";

                        moveIndex++;
                        turn = PLAYER1;
                    }
                }
            }
            
            if(this->gameOver()==false && moveIndex == side*side)
            {
                system("clear");
                showBoard();
                cout<<"It's a draw match \n\n";
            }
            else
            {
                cout<<moveIndex<<endl;
                if(turn==PLAYER1)turn=PLAYER2;
                else if(turn == PLAYER2)turn = PLAYER1;
                
                winner(turn);
            }

            cout<<"\n\n\t\t\tPress ENTER for menu\n";
            getch();
            getch();

            return ;
        }

};

class Game : public Play
{   
    private:
        int side;
    public :
        Game(int side) : Play(side)
        {
            this->side=side;
        }
        void Menu()
        {
            int choice;

            do 
            {    
                system("clear");
                cout<<endl;
                cout<<"\t 1.  INSTRUCTION"<<endl;
                cout<<"\t 2.  PLAY"<<endl;
                cout<<"\t 3.  BACK"<<endl;
                cout<<"\t Enter your choice : ";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        {
                            system("clear");
                            this->instruction();
                            getch();
                            getch();
                        }
                        break;
                    case 2:
                        system("clear");   
                        gameStart(PLAYER1);
                        getch();
                        getch();
                        return;
                        break;
                    case 3:
                        return;
                        break;
                    default:
                        system("clear");
                        cout<<" \t Invalid Choice"<<endl;
                        cout<<"\t Press ENTER for menu "<<endl;
                        getch();
                        getch();
                        break;
                }
            }while(choice!=3);


            
        }

        void instruction()
        {
            system("clear");
            cout<<endl;
            cout<<"\t\t Tic-Tac_Toe"<<endl;
            cout<<"\t\tChoose a cell no. from 1-"<<side*side<<" as below and play\n\n";
            int p=1;

            for(int i =0;i<=side*2;i++)
            {  
                cout<<"\t\t\t\t ";
                for(int j=0;j<side;j++)
                {
                    if(i%2==0)
                    {
                        for(int k =0;k<side;k++)cout<<"----";
                        break;
                    }
                    else
                    {   
                        if(j==0)cout<<"| ";
                        cout<<p<<" | ";
                        p++;   
                    }
                }
                cout<<"\n";
            }

            cout<<"\n\n\t\t\tPress ENTER to continue. . . \n";

            return;
            
        }

};

int main()
{
    int gridSize;
    while(1)
    {
        system("clear");
        cout<<"\t\t Press 1 for EXIT"<<endl;
        cout<<"\t\t||TIC-TAC-TOE ||"<<endl;
        cout<<"   (Grid Size should be odd and > 2)"<<endl;
        cout<<"Enter the Grid Size :  ";
        cin>>gridSize;

        if(gridSize==1 || gridSize%2==0)
        {
            system("clear");
            cout<<"\t\t//--||-- TIC-TAC-TOE -- ||--\\\\ "<<"\n\n\n";
            cout<<"Wrong grid size, try again "<<endl;
            break;
        }

        Game* g1 = new Game(gridSize);
        g1->Menu();
        delete g1;
    }


    return 0;
}
