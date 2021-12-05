#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

string helper(string tic[3][3],string ch1, string ch2) {
    int A;
    int B;
    for(int i = 0; i < 3; i++) {    //for row
        A = 0;
        B = 0;
        for(int j = 0; j < 3; j++) {
            if(tic[i][j] == ch1) {
                A++;
            } 
            if(tic[i][j] == ch2) {
                    B++;
            }
        }
        if(A == 3) {
            return ch1;
        }
        if(B == 3) {
            return ch2;
        }
    }
    for(int i = 0; i < 3; i++) {    //for col
        A = 0;
        B = 0;
        for(int j = 0; j < 3; j++) {
            if(tic[j][i] == ch1) {
                A++;
            } 
            if(tic[j][i] == ch2) {
                B++;
            }
        }
        if(A == 3) {
            return ch1;
            }
        if(B == 3) {
            return ch2;
            }
    }
    if(tic[0][0] == ch1 && tic[1][1] == ch1 && tic[2][2] == ch1 || 
	   tic[0][2] == ch1 && tic[1][1] == ch1 && tic[2][0] == ch1) {
        return ch1;
    }
    else if(tic[0][0] == ch2 && tic[1][1] == ch2 && tic[2][2] == ch2
	  || tic[0][2] == ch2 && tic[1][1] == ch2 && tic[2][0] == ch2) {
        return ch2;
    }
    return "Draw";
}    

void Disp(string mat[3][3]) {
	cout<<"     |     |     \n";
	cout<<"  "<<mat[0][0]<<"  |  "<<mat[0][1]<<"  |  "<<mat[0][2]<<"    \n";
	cout<<"_____|_____|______\n";
	cout<<"     |     |     \n";
	cout<<"  "<<mat[1][0]<<"  |  "<<mat[1][1]<<"  |  "<<mat[1][2]<<"    \n";  
	cout<<"_____|_____|______\n";
	cout<<"     |     |      \n";
	cout<<"  "<<mat[2][0]<<"  |  "<<mat[2][1]<<"  |  "<<mat[2][2]<<"    \n";
	cout<<"     |     |      \n\n";	
}

void tic_toe() {
	string mat[3][3] = {" "," "," "," "," "," "," "," "," "};
	string pl1, pl2;
	string ch1, ch2;
	cout<<"<<<<<<<<<<<<<::::::::Welcome to this Tic Toe game::::::>>>>"<<endl;
	cout<<"Enter Player1 name::"<<endl;
	cin>>pl1;
	cout<<endl<<"Enter Player2 name::"<<endl;
	cin>>pl2;
	cout<<endl<<pl1<<" Select Your Symbols::::: ";
	cin>>ch1;
	cout<<endl;
	cout<<pl2<<" Select Your Symbols:::::: ";
	cin>>ch2;
	cout<<endl;
	cout<<"Hey who want to play first "<<pl1<<" or "<<pl2<<" write the name::"<<endl;
	int count = 0;
    bool b1 = false, b2 = false;
    string name;
    cin>>name;
    if(name == pl1) {
    	b1 = true;
	}
	if(name == pl2) {
		b2 = true;
	}
    if(b1) {
    for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; ) {
		    count++;
		    int row, col;
		    if((i+j) % 2 == 0) {
		    	cout<<pl1<<" Enter the position:: ";
		    	cin>>row>>col;
		    	if(mat[row-1][col-1] != " ") {
		    		cout<<"Error enter the valid positon::"<<endl;
		    		continue;
				}
		    	mat[row-1][col-1] = ch1;
		    	if(count < 4) {
		    		Disp(mat);
				}
				else {
					Disp(mat);
					string str = helper(mat,ch1, ch2);
					if(str == ch1) {
						cout<<"::::::::::::Congratulation "<<pl1<<" you won the game:::::::::::"<<endl;
						return;
					}
				}
			}
			else {
				cout<<pl2<<" Enter the position:: ";
				cin>>row>>col;
				if(mat[row-1][col-1] != " ") {
		    		cout<<"Error enter the valid positon::"<<endl;
		    		continue;
				}
		    	mat[row-1][col-1] = ch2;
		    	if(count < 4) {
		    		Disp(mat);
				}
				else {
					Disp(mat);
					string str = helper(mat,ch1, ch2);
					if(str == ch2) {
						cout<<":::::>>>>>>>>>>:::::::Congratulation "<<pl2<<" you won the game::::::<<<<<<<<<<<::::::::"<<endl;
						return;
					}
				}
			}
			j++;		
  	    }
	}
    }
	else if(b2) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; ) {
		    count++;
		    int row, col;
		    if((i+j) % 2 == 0) {
		    	cout<<pl2<<" Enter the position:: ";
		    	if(mat[row-1][col-1] != " ") {
		    		cout<<"Error enter the valid positon::"<<endl;
		    		continue;
				}
				cin>>row>>col;
		    	mat[row-1][col-1] = ch1;
		    	if(count < 4) {
		    		Disp(mat);
				}
				else {
					Disp(mat);
					string str = helper(mat,ch1, ch2);
					if(str == ch2) {
						cout<<"::::::::::::::Congratulation "<<pl2<<" you won the game::::::::::::::"<<endl;
						return;
					}
				}
			}
			else {
				cout<<pl1<<" Enter the position::";
				if(mat[row-1][col-1] != " ") {
		    		cout<<"Error enter the valid positon::"<<endl;
		    		continue;
				}
				cin>>row>>col;
		    	mat[row-1][col-1] = ch2;
		    	if(count < 4) {
		    		Disp(mat);
				}
				else {
					Disp(mat);
					string str = helper(mat,ch1, ch2);
					if(str == ch1) {
						cout<<":::::::::::::::::Congratulation "<<pl1<<" you won the game:::::::::::::::"<<endl;
						return;
					}
				}		
			}
			j++;
  	    }
  	}
	}
	cout<<"::::::::::Draw:::::::::---->>>> Play Again::::::::::<<<<-----"<<endl;
	return;
}

int main() {
	tic_toe();
	return 0;
}
