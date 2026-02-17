#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

#define w "\033[0m"
#define r "\033[31m"
#define g "\033[32m"
#define y "\033[33m"
#define b "\033[34m"

struct pre {
    int xpos, ypos;
    pre(int x, int z) : xpos(x), ypos(z) {};
};

void cs() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int random(int min, int max) {
    return ((rand() % max - min + 1) + min);
}

int main() {
    srand(time(NULL));
    int i, j, k, l, m, n, o, p, input, coins = 100, xp, yp, ic, coi[5] = {1000000000,800000000,500000000,100000000,10000000};
    long int c = time(NULL);
    string a[9] = {"+ 100 %"," + 75 %"," + 50 %"," + 25 %","  BASE "," - 25 %"," - 50 %"," - 75 %","- 100 %"}, com[5] = {"NVDIA","Apple","Microsoft","Amazon","Reliance"};
    vector <pre> prev;
    vector <string> inventory;
    bool space, line_on;
    cs();
    inventory.push_back(com[0]);
    inventory.push_back(com[1]);
    line_on = true;
    cout <<y<< "\n-----<||{ Welcome to Stock }||>-----\n" <<w;
    do{
        cout <<w<< "\n---< Menu >---\n1. Invest\n2. Settings\n3. Stock Shop\n4. Trading\n5. Sell Stocks\n6. Exit\n\nOption : ";
        do{
            cin >> input;
            if(input < 1 || input > 6) cout << "\n---{ Wrong Option }---\nOption : ";
        }while(input < 1 || input > 6);
        switch(input) {
            case 1:
                cs();
                cout <<b<< "Coins : " << coins <<w<< "\nInvest Coins (0 to exit) : ";
                do{
                    cin >> ic;
                    if(ic < 0) cout << "\n---{ Coins must be greater than 0 }---\nEnter : ";
                    else if(ic > coins) cout << "\n---{ Can't be more than coins }---\nEnter : ";
                }while(ic < 0 || ic > coins);
                coins -= ic;
                xp = 5, yp = 4;
                prev.clear();
                if(ic != 0) {
                    for(k = 0; k < 10; k++) {
                        cs();
                        for(i = 0; i < 9; i++) {
                            cout << a[i] << "  |";
                            for(j = 0; j < 100; j++) {
                                space = true;
                                if(xp == j && yp == i) {
                                    cout <<g<< 'O' <<w;
                                    space = false;
                                }
                                else {
                                    for(l = 0; l < prev.size(); l++) {
                                        if(prev.at(l).xpos == j && prev.at(l).ypos == i) {
                                            cout <<y<< 'o' <<w;
                                            space = false;
                                        }
                                        if(l > 0 && i != 4 && line_on == 1) {
                                            m = prev.at(l-1).xpos;
                                            n = prev.at(l).xpos;
                                            o = prev.at(l-1).ypos;
                                            p = prev.at(l).ypos;
                                            if(j > m && j < n && i == o + (p - o) * (j - m) / (n - m)) {
                                                cout << '.';
                                                space = false;
                                            }
                                        }
                                    }
                                }
                                if(k > 0 && i != 4 && line_on == 1) {
                                    m = prev.at(k-1).xpos;
                                    n = xp;
                                    o = prev.at(k-1).ypos;
                                    p = yp;
                                    if(j > m && j < n && i == o + (p - o) * (j - m) / (n - m)) {
                                        cout << '.';
                                        space = false;
                                    }
                                }
                                if(i == 4) cout << '-';
                                else if(space == 1) cout << " ";
                            }
                            if(i == 4) {
                                if(yp == 0) ic *= 2;
                                else if(yp == 1) ic = ic + ic * 0.75;
                                else if(yp == 2) ic = ic + ic / 2;
                                else if(yp == 3) ic = ic + ic * 0.25;
                                else if(yp == 5) ic = ic - ic * 0.25;
                                else if(yp == 6) ic = ic - ic / 2;
                                else if(yp == 7) ic = ic - ic * 0.75;
                                else if(yp == 8) ic /= 2;
                                cout <<b<< "  [  Present Invested Coins : " << ic << "  ]" <<w;
                            }
                            cout << endl;
                        }
                        prev.emplace_back(xp,yp);
                        xp += 10;
                        yp = random(0,8);
                        cout << endl;
                        this_thread::sleep_for(chrono::seconds(3));
                    }
                    coins += ic;
                    cout << endl;
                    for(i=0;i<130;i++) cout << "_";
                    cout <<b<< "\n---< Coins : " << coins << " >---\n" <<y << "Press Enter to Exit to main menu   " <<w;
                    cin.ignore();
                }
                cin.ignore();
                cs();
                break;
                case 2:
                do{
                    cs();
                    cout <<w<< "---<{ Settings }>---\n\n1. Lines between scatter plot points : ";
                    if(line_on == 0) cout <<r<< "OFF" <<w;
                    else cout <<b<< "ON" <<w;
                    cout << "\n2. Exit";
                    cout <<y<< "\n\nEnter respective Number to Toogle : " <<w;
                    cin >> i;
                    if(i == 1) line_on = !line_on;
                }while(i != 2);
                cs();
                break;
                case 3:
                do{
                    cs();
                    cout <<w<< "---<{ Stock Shop }>---\n" <<b<< "Coins : " << coins <<w<< "\n\n1. NVDIA : ";
                    if(coins >= 1000000000) cout <<b<< "1,000,000,000 C\n" <<w;
                    else cout <<r<< "1,000,000,000 C\n" <<w;
                    cout << "\n2. Apple : ";
                    if(coins >= 800000000) cout <<b<< "800,000,000 C\n" <<w;
                    else cout <<r<< "800,000,000 C\n" <<w;
                    cout << "\n3. Microsoft : ";
                    if(coins >= 500000000) cout <<b<< "500,000,000 C\n" <<w;
                    else cout <<r<< "500,000,000 C\n" <<w;
                    cout << "\n4. Amazon : ";
                    if(coins >= 100000000) cout <<b<< "100,000,000 C\n" <<w;
                    else cout <<r<< "100,000,000 C\n" <<w;
                    cout << "\n5. Reliance : ";
                    if(coins >= 10000000) cout <<b<< "10,000,000 C\n" <<w;
                    else cout <<r<< "10,000,000 C\n" <<w;
                    cout <<w<< "\n6. Exit\n\n" <<b<< "Your Inventory : ";
                    for(j = 0; j < inventory.size(); j++) cout << inventory.at(j) << ", ";
                    cout <<y<< "\n\nEnter respective Number to Buy : " <<w;
                    do{
                        cin >> i;
                        if(i < 1 || i > 6) cout << "\n---{ Invalid Option }---\nEnter : ";
                    }while(i < 1 || i > 6);
                    space = true;
                    switch(i) {
                        case 1:
                            if(coins >= coi[0]) {
                                for(j = 0; j < inventory.size(); j++) {
                                    if(inventory.at(j) == com[0]) {
                                        cout <<r<< "---< It already existed in Inventory >---" <<w;
                                        break;
                                    }
                                }
                                if(space == true) {
                                    inventory.push_back(com[0]);
                                    coins -= coi[0];
                                }
                            }
                            else cout <<r<< "---< Not Sufficient Coins >---" <<w;
                            break;
                        case 2:
                            if(coins >= coi[1]) {
                                for(j = 0; j < inventory.size(); j++) {
                                    if(inventory.at(j) == com[1]) {
                                        cout <<r<< "---< It already existed in Inventory >---" <<w;
                                        break;
                                    }
                                }
                                if(space == true) {
                                    inventory.push_back(com[1]);
                                    coins -= coi[1];
                                }
                            }
                            else cout <<r<< "---< Not Sufficient Coins >---" <<w;
                            break;
                        case 3:
                            if(coins >= coi[2]) {
                                for(j = 0; j < inventory.size(); j++) {
                                    if(inventory.at(j) == com[2]) {
                                        cout <<r<< "---< It already existed in Inventory >---" <<w;
                                        break;
                                    }
                                }
                                if(space == true) {
                                    inventory.push_back(com[2]);
                                    coins -= coi[2];
                                }
                            }
                            else cout <<r<< "---< Not Sufficient Coins >---" <<w;
                            break;
                        case 4:
                            if(coins >= coi[3]) {
                                for(j = 0; j < inventory.size(); j++) {
                                    if(inventory.at(j) == com[3]) {
                                        cout <<r<< "---< It already existed in Inventory >---" <<w;
                                        break;
                                    }
                                }
                                if(space == true) {
                                    inventory.push_back(com[3]);
                                    coins -= coi[3];
                                }
                            }
                            else cout <<r<< "---< Not Sufficient Coins >---" <<w;
                            break;
                        case 5:
                            if(coins >= coi[4]) {
                                for(j = 0; j < inventory.size(); j++) {
                                    if(inventory.at(j) == com[4]) {
                                        cout <<r<< "---< It already existed in Inventory >---" <<w;
                                        break;
                                    }
                                }
                                if(space == true) {
                                    inventory.push_back(com[4]);
                                    coins -= coi[4];
                                }
                            }
                            else cout <<r<< "---< Not Sufficient Coins >---" <<w;
                            break;
                    }
                    if(space == false) cout <<r<< "---< It already existed in Inventory >---\n" <<w;
                    cin.ignore();
                    cout <<y<< "\nPress Enter to Exit to main menu" <<w;
                    cin.ignore();
                }while(i != 6);
                cs();
                break;
            case 4:
                cs();
                cout <<w<< "---<{ Trading }>---\n";
                if(inventory.empty() == 1) {
                    cin.ignore();
                    cout <<r<< "-----< Your Inventory is Empty >-----\n\n" <<y<< "Press Enter to exit " <<w;
                    cin.ignore();
                }
                else if(time(NULL) - c < 180) {
                    cin.ignore();
                    cout <<r<< "-----< Trades under Cooldown : " << 180 - (time(NULL) - c) << " sec left >-----\n\n" <<y<< "Press Enter to exit " <<w;
                    cin.ignore();
                }
                else {
                    cout <<w<< "\nYour Inventory : " <<b;
                    for(i = 0; i < inventory.size(); i++) {
                        cout << '\n' << i+1 << ". " << inventory.at(i);
                    }
                    j = random(0,4);
                    cout <<g<< "\n\nTrade for : " << com[j] <<y<< "\n\nEnter number from Inventory to Trade with (0 to exit) : " <<w;
                    do{
                        cin >> k;
                        if((k < 0) || (k > inventory.size())) cout << "---< Wrong Input >---\nEnter : ";
                    }while((k < 0) || (k > inventory.size()));
                    if(k != 0) {
                        inventory.at(k-1) = com[j];
                        cin.ignore();
                        cout <<g<< "\n\n---< Trade Complete >---\n" <<y<< "Press Enter to exit " <<w;
                        cin.ignore();
                    }
                    c = time(NULL);
                }
                cs();
                break;
            case 5:
                cs();
                cout <<w<< "---<{ Sell Stocks }>---\n";
                if(inventory.empty() == 1) {
                    cin.ignore();
                    cout <<r<< "-----< Your Inventory is Empty >-----\n\n" <<y<< "Press Enter to exit " <<w;
                    cin.ignore();
                }
                else {
                    cout <<w<< "\nYour Inventory : " <<b;
                    for(i = 0; i < inventory.size(); i++) {
                        cout << '\n' << i+1 << ". " << inventory.at(i);
                    }
                    cout <<y<< "\n\nEnter number from Inventory to Sell with (0 to exit) : " <<w;
                    do{
                        cin >> k;
                        if((k < 0) || (k > inventory.size())) cout << "---< Wrong Input >---\nEnter : ";
                    }while((k < 0) || (k > inventory.size()));
                    if(k != 0) {
                        for(i = 0; i < 5; i++) {
                            if(com[i] == inventory.at(k-1)) {
                                coins += coi[i];
                                break;
                            }
                        }
                        for(j = k-1; j < inventory.size() - 1; j++) {
                            inventory.at(j) = inventory.at(j+1);
                        }
                        inventory.resize(inventory.size() - 1);
                        cout <<g<< "\n---< Sell Complete >---";
                    }
                    cin.ignore();
                    cout <<b<< "\n\nCoins : " << coins <<y<< "\n\nPress Enter to Exit " <<w;
                    cin.ignore();
                }
                cs();
                break;
        }
    }while(input != 6);
    cout <<y<< "\n---< Exit Successful >---" <<w;
    return 0;
}
/*
w = white text
r = red text
g = green text
y = yellow text
b = blue text
ic = invest coins
xp = x position
yp = y position
pre = previous stock positions
for lines - slope formula => (x-x1)/(x2-x1) = (y-y1)/(y2-y1)
here, m=x1,n=x2,o=y1,p=y2
line_on = toggle button in settings
c = cooldown on trades - 3 min
*/