#include <iostream>
#include <fstream>
#include <algorithm>

//Just as the name suggests, This app unscrambles any given word using the wordlists provided

using namespace std;

int main()
{
    ifstream Dictionary("Wordlist (Space Separated).txt");
    ifstream Compare("Wordlist (Sorted).txt");
    string sDictionary;
    getline(Dictionary,sDictionary);
    string sCompare;
    getline(Compare,sCompare);
Start:
    string s;
    string temp;
    cout << "Please enter the jumbled text below \n>";
    cin >> s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    sort(s.begin(),s.end());
    s=" "+s+" ";
    long long int pos=-1;
    int count=0;
    do
    {
        pos=sCompare.find(s,pos+1);
        if (pos!=string::npos && count==0) {cout <<endl << "You might be looking for:" << endl;}
        if (pos!=string::npos) {temp=sDictionary.substr(pos+1,s.length()-2); transform(temp.begin()+1,temp.end(),temp.begin()+1,::tolower); cout << count+1 << ". " << temp <<endl; count++;}
    }
    while (pos!=string::npos);
    if (count!=0) {cout << "\nTotal " << count << " matches found!\n";}
    else {cout << "\nNo matches found!\n";}
    cout << "\nDo you want to start again? (Y/N)>";
    cin >> s;
    if ((s.compare("Y")==0) | (s.compare("y")==0)) {cout << "\n--------------------\n\n"; goto Start;}
    else
    {
        cout << "\nThank you for using!";
        Dictionary.close();
        Compare.close();
        return 0;
    }
}
