// Hangman.cpp
#include "/home/odin/projekt-2/projekt-2-2/include/hangman/Hangman.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>



void Hangman::startGame() {
    char start{};
    std::cout << " ______________ " << std::endl;
    std::cout << " |       }      " << std::endl;
    std::cout << " |       O      " << std::endl;
    std::cout << " |       |      " << std::endl;
    std::cout << " |     / | \\   " << std::endl;
    std::cout << " |    /  |  \\  " << std::endl;
    std::cout << " |      / \\    " << std::endl;
    std::cout << " |     /   \\   " << std::endl;
    std::cout << " |              " << std::endl;
    std::cout << " |_____________ " << std::endl;
    std::cout << "\nPress any key to start and enter \n";
    std::cin >> start;

    loadWords();
    displaytext();
}
    

void Hangman::loadWords() {
    srand(time(NULL)); // Generiere zufälliges Wort aus dem Array
    std::ifstream RandomWord; // List das Wort, was zufällig gewählt wurde
    RandomWord.open("/home/odin/projekt-2/projekt-2-2/src/Words.txt"); // Liest in der Datei mit den Wörtern

    for(int i = 0; i < 99; i++)
    {
     
        RandomWord >> WordList[i]; // fülle Array mit den 100 Wörtern aus der Liste
    }
    int RandomNUM = rand() % 100; // gibt eine zufällige Zahl zwischen 0 und 99 aus 
    Word = WordList[RandomNUM];
    RandomWord.close();

    //Mache Word Geheim!!!
    MysteryWord = std::string(Word.length(), '*'); // Erstze jeden Buchstaben aus dem Wort durch "*"


    
    for(int i = 0; i < 7; i++)
    {
        PreviousGuesses[i] = '-';
    }
    PreviousGuesses[6] = '\0';

}




void Hangman::displaytext() {
    while(Tries >= 0) 
    { 
        CorrectGuess = false; // reset 

        // Zeige die Information an den Nutzer
        std::cout <<"Errate dieses Wort:\n\n";
        std::cout << MysteryWord << std::endl;
        std::cout << "Du hast " << Tries << " Versuche übrig\n";
        
        
        std::cout << "Eingebene Wörter: " << PreviousGuesses << std::endl;

        // Eingabe des Nutzers
        std::cout << "\nGebe einen Buchstaben ein: ";
        std::cin >> Guess;

        checkGuess(Guess);
        displayHangman();
    }
}

void Hangman::checkGuess(char guess) {
    //Ist der Buchstabe im Wort?
    for(int i= 0; i < MysteryWord.length(); i++)
    {
        if(Word[i] == guess) // Überprüfe ob Buchstabe im Wort ist
        {
            MysteryWord[i] = guess;
            CorrectGuess = true;
        }
    }
    if(Word == MysteryWord)
    {
        std::cout << "\nGlückwunsch! Du hast das Wort richtig erraten: " << MysteryWord << std::endl;
        Tries = -1;
    }

    if(CorrectGuess == false)
    {
        Tries--;
        std::cout << "Der Buchtabe " << Guess << " gehört nicht zum Wort!" << std::endl;
    }
    else
    {
        std::cout << "Richtig! " << Guess << " ist im Wort" << std::endl;
    }
}

void Hangman::displayHangman() {
    switch(Tries) 
    {
    case 6:
    {
            std::cout << " ______________ " << std::endl;
            std::cout << " |       }      " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |_____________ " << std::endl;
            break;
        if(CorrectGuess == false)
        {
            PreviousGuesses[0] = Guess;
        }
        break;
    }
    case 5:
    {
            std::cout << " ______________ " << std::endl;
            std::cout << " |       }      " << std::endl;
            std::cout << " |       O      " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |_____________ " << std::endl;
        if(CorrectGuess == false)
        {
            PreviousGuesses[1] = Guess;
        }
        break;
    }
    case 4:
    {
            std::cout << " ______________ " << std::endl;
            std::cout << " |       }      " << std::endl;
            std::cout << " |       O      " << std::endl;
            std::cout << " |       |      " << std::endl;
            std::cout << " |       |      " << std::endl;
            std::cout << " |       |      " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |_____________ " << std::endl;
        if(CorrectGuess == false)
        {
            PreviousGuesses[2] = Guess;
        }
        break;
    }
    case 3:
    {
            std::cout << " ______________ " << std::endl;
            std::cout << " |       }      " << std::endl;
            std::cout << " |       O      " << std::endl;
            std::cout << " |       |      " << std::endl;
            std::cout << " |     / |      " << std::endl;
            std::cout << " |    /  |      " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |_____________ " << std::endl;
        if(CorrectGuess == false)
        {
            PreviousGuesses[3] = Guess;
        }
        break;
    }
    case 2:
    {
            std::cout << " ______________ " << std::endl;
            std::cout << " |       }      " << std::endl;
            std::cout << " |       O      " << std::endl;
            std::cout << " |       |      " << std::endl;
            std::cout << " |     / | \\   " << std::endl;
            std::cout << " |    /  |  \\  " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |_____________ " << std::endl;
        if(CorrectGuess == false)
        {
            PreviousGuesses[4] = Guess;
        }
        break;
    }
    case 1:
    {    
            std::cout << " ______________ " << std::endl;
            std::cout << " |       }      " << std::endl;
            std::cout << " |       O      " << std::endl;
            std::cout << " |       |      " << std::endl;
            std::cout << " |     / | \\   " << std::endl;
            std::cout << " |    /  |  \\  " << std::endl;
            std::cout << " |      /       " << std::endl;
            std::cout << " |     /        " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |_____________ " << std::endl;
        if(CorrectGuess == false)
        {
            PreviousGuesses[5] = Guess;
        }
        break;
    }
    case 0:
    {
            std::cout << " ______________ " << std::endl;
            std::cout << " |       }      " << std::endl;
            std::cout << " |       O      " << std::endl;
            std::cout << " |       |      " << std::endl;
            std::cout << " |     / | \\   " << std::endl;
            std::cout << " |    /  |  \\  " << std::endl;
            std::cout << " |      / \\    " << std::endl;
            std::cout << " |     /   \\   " << std::endl;
            std::cout << " |              " << std::endl;
            std::cout << " |_____________ " << std::endl;
            std::cout << " \nGAME OVER    " << std::endl;
            std::cout <<"Das gesuchte Wort war: " << Word << std::endl;
        Tries=-1;
        break;
    }

    }
}