#include <iostream>

using namespace std;

char toLower(char orginal) {
    if(orginal >= 'A' && orginal <= 'Z') {
        return orginal - ((int)'A' - (int)'a');
    }

    return orginal;
}

string toLower(string orginal) {
    for (int i = 0; i < orginal.size(); i++)
    {
        orginal[i] = toLower(orginal[i]);
    }

    return orginal;
}

char toUpper(char orginal) {
    if(orginal >= 'a' && orginal <= 'z') {
        return orginal + ((int)'A' - (int)'a');
    }

    return orginal;
}

string toUpper(string orginal) {
    for (int i = 0; i < orginal.size(); i++)
    {
        orginal[i] = toUpper(orginal[i]);
    }

    return orginal;
}

int main()
{
    cout << toLower("tEsT68AZ") << endl;
    cout << toUpper("Test68az") << endl;
    return 0;
}
