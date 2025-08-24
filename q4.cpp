#include <iostream>
using namespace std;


void concatenateStrings() {
    char s1[100], s2[100], result[200];
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int i = 0, j = 0;

   
    while (s1[i] != '\0') {
        result[i] = s1[i];
        i++;
    }
   
    while (s2[j] != '\0') {
        result[i] = s2[j];
        i++; j++;
    }
    result[i] = '\0';

    cout << "Concatenated String: " << result << endl;
}

// (b) 
void reverseString() {
    char s[100];
    cout << "Enter string to reverse: ";
    cin >> s;

    int len = 0;
    while (s[len] != '\0') 
    len++; 
    cout << "Reversed String: ";
    for (int i = len-1; i >= 0; i--) {
        cout << s[i];
    }
    cout << endl;
}


void deleteVowels() {
    char s[100], result[100];
    cout << "Enter string: ";
    cin >> s;

    int i = 0, j = 0;
    while (s[i] != '\0') {
        char ch = s[i];
        if (!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
              ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')) {
            result[j++] = ch;
        }
        i++;
    }
    result[j] = '\0';

    cout << "String without vowels is " << result ;
}


void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    string arr[100];  
    cout << "Enter strings:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted strings:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] ;
    }

   
}


void toLowercase() {
    char c;
    cout << "Enter an uppercase character: ";
    cin >> c;

    if (c >= 'A' && c <= 'Z')
        c = c + 32; 
    cout << "Lowercase character: " << c << endl;
}


int main() {
    int choice;

            concatenateStrings(); 
            reverseString(); 
            deleteVowels(); 
            sortStrings();
            toLowercase(); 
           
}
