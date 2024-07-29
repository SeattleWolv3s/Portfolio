#include <iostream> 
using namespace std;

int main() {
    int style;
    int artist;
    int piece;
    cout << "Select the Style: (1) Impressionism (2) Surrealism" << endl;
    cin >> style;
    if (cin.fail() || (style != 1 && style != 2)) {
        cout << "Please enter a valid input" << endl;
        return 0;
    }
    else {
        if (style == 1) {
            cout << "Select the Artist: (1) Claude Monet (2) Edgar Degas (3) Pierre-Auguste Renoir" << endl;
            cin >> artist;
            if (cin.fail() || (artist != 1 && artist != 2 && artist != 3)) {
                cout << "Please enter a valid input" << endl;
                return 0;
            }
            else {
                int x;
                if (artist == 1) {x = 1;}
                if (artist == 2) {x = 2;}
                if (artist == 3) {x = 3;}
                switch (x) {
                    case 1 :
                    cout << "Select the Artwork: (1) Water Lilies (2) Impression, Sunrise" << endl;
                    cin >> piece;
                    if(cin.fail() || (piece != 1 && piece != 2)) {
                        cout << "Please enter a valid input" << endl;
                        return 0;
                }
                else {
                    if (piece == 1) {
                        cout << "You have reserved the artwork: Water Lilies" << endl;
                        return 0;
                    }
                    else {
                        cout << "You have reserved the artwork: Impression, Sunrise" << endl;
                        return 0;
                    }
                }
                break;
                    case 2 :
                    cout << "Select the Artwork: (1) The Dance Class (2) L'Absinthe" << endl;
                    cin >> piece;
                    if(cin.fail() || (piece != 1 && piece != 2)) {
                        cout << "Please enter a valid input" << endl;
                        return 0;
                }
                else {
                    if (piece == 1) {
                        cout << "You have reserved the artwork: The Dance Class" << endl;
                        return 0;
                    }
                    else {
                        cout << "You have reserved the artwork: L'Absinthe" << endl;
                        return 0;
                    }
                }
                break;
                    case 3 :
                    cout << "Select the Artwork: (1) Luncheon of the Boating Party (2) Bal du moulin de la Galette" << endl;
                    cin >> piece;
                    if(cin.fail() || (piece != 1 && piece != 2)) {
                        cout << "Please enter a valid input" << endl;
                        return 0;
                }
                else {
                    if (piece == 1) {
                        cout << "You have reserved the artwork: Luncheon of the Boating Party" << endl;
                        return 0;
                    }
                    else {
                        cout << "You have reserved the artwork: Bal du moulin de la Galette" << endl;
                        return 0;
                    }
                }
                break;
            }
        }
    }
    if (style == 2) {
            cout << "Select the Artist: (1) Salvador Dali (2) Rena Magritte (3) Frida Kahlo" << endl;
            cin >> artist;
            if (cin.fail() || (artist != 1 && artist != 2 && artist != 3)) {
                cout << "Please enter a valid input" << endl;
                return 0;
            }
            else {
                int y;
                if (artist == 1) {y = 1;}
                if (artist == 2) {y = 2;}
                if (artist == 3) {y = 3;}
                switch (y) {
                    case 1 :
                    cout << "Select the Artwork: (1) The Persistence of Memory (2) The Elephant" << endl;
                    cin >> piece;
                    if(cin.fail() || (piece != 1 && piece != 2)) {
                        cout << "Please enter a valid input" << endl;
                        return 0;
                }
                else {
                    if (piece == 1) {
                        cout << "You have reserved the artwork: The Persistence of Memory" << endl;
                        return 0;
                    }
                    else {
                        cout << "You have reserved the artwork: The Elephant" << endl;
                        return 0;
                    }
                }
                break;
                    case 2 :
                    cout << "Select the Artwork: (1) The Son of Man (2) The Treachery of Images" << endl;
                    cin >> piece;
                    if(cin.fail() || (piece != 1 && piece != 2)) {
                        cout << "Please enter a valid input" << endl;
                        return 0;
                }
                else {
                    if (piece == 1) {
                        cout << "You have reserved the artwork: The Son of Man" << endl;
                        return 0;
                    }
                    else {
                        cout << "You have reserved the artwork: The Treachery of Images" << endl;
                        return 0;
                    }
                }
                break;
                    case 3 :
                    cout << "Select the Artwork: (1) The Two Fridas (2) Self-Portrait with Thorn Necklace" << endl;
                    cin >> piece;
                    if(cin.fail() || (piece != 1 && piece != 2)) {
                        cout << "Please enter a valid input" << endl;
                        return 0;
                }
                else {
                    if (piece == 1) {
                        cout << "You have reserved the artwork: The Two Fridas" << endl;
                        return 0;
                    }
                    else {
                        cout << "You have reserved the artwork: Self-Portrait with Thorn Necklace" << endl;
                        return 0;
                    }
                }
                break;
            }
        }
    }
}
return 0;
}