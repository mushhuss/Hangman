#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
using namespace std;

//words.txt has 13 words.
// get a random word from  the text file ( fin and for loop and stop it at a random time )
//create a function that checks if the letter matches. 

void iscorrect(char g, string&b, string ans){
    for(int i =0; i < ans.length(); i++){
        if(g == ans[i]){
            b[i] = g;
        }
    }
}

int main(){
    
    string answer;
    fstream fin("words.txt");
    srand(time(0));
    int random = (rand() % 13) + 1;         // gives a random word from the text file as the answer so its different each time
    for(int i = 0; i < random; i++){
        fin >> answer;
    }
    
    string blanks(answer.length(), '_'); //makes a blank string equal to the amount of letters in the answer;

    int guesses = 0;  // initializes the amount of guesses to 0
    string name;

    cout  << "Welcome to hangman!\n" << "Please enter your name to to begin: ";
    cin >> name; 

    
    cout <<"Hello " << name << ".\n" << "The word is " << answer.length() << " letters long\n" << blanks << endl;

        while (guesses <= 6 || blanks != answer){
        char guess;
        string sguess;
        char res;
        cout << "\nWould you like to guess the whole word? (y/n): ";
        cin >> res;
        cout << "Enter a guess: ";
        if(res == 'y'){
            cin >> sguess;
            if (sguess == answer){
                cout << "Correct! The word is: " << answer;
                break;
            }
            else {
                guesses++;
                cout <<"\n" << blanks;
            }
        }
        else if ( res =='n'){
            cin >> guess;
            string prevblanks = blanks;
            iscorrect(guess, blanks, answer);
            if (blanks == prevblanks){
            guesses++; 
            }
            cout << blanks;
        }

        if (guesses>= 6){
            cout << "\nYou lose! The word was: " << answer;
            break;
        }
        cout << "\nYou have " << (6-guesses) << " guesses remaining";
        }
}

    
    


