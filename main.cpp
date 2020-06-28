#include <iostream>
#include <string>
#include<windows.h>
//Written  by ms3c
//6/27/2020
using namespace std;
static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";
const char Base64EncodingTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char* Base64EncodeTriplet(byte* vInput, const int& vLength = 3) {
    char* ret = new char[5];
    ret[4] = '\0';

    long tValue = 0;

    if(vLength >= 1) tValue += vInput[0] << 16;
    if(vLength >= 2) tValue += vInput[1] << 8;
    if(vLength >= 3) tValue += vInput[2];

    long tMask;
    for(int i = 0; i < 4; i++) {
        int bitshift = ((3-i) * 6);
        tMask = 63;
        tMask <<= bitshift;
        tMask &= tValue;
        tMask >>= bitshift;
        ret[i] = Base64EncodingTable[tMask];
    }

    if(vLength <= 2) ret[3] = '=';
    if(vLength <= 1) ret[2] = '=';

    return ret;
}

string Base64Encode(string vInput) {
    string ret;

    byte tBuffer[3];
    for(int i = 0; i < vInput.length();) {
        int j = 0;
        if(i < vInput.length()) {tBuffer[0] = vInput.at(i++); j++;}
        if(i < vInput.length()) {tBuffer[1] = vInput.at(i++); j++;}
        if(i < vInput.length()) {tBuffer[2] = vInput.at(i++); j++;}
        ret += Base64EncodeTriplet(tBuffer, j);
    }

    return ret;
}

 static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}
 std::string base64_decode(std::string const& encoded_string) {
  size_t in_len = encoded_string.size();
  size_t i = 0;
  size_t j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = static_cast<unsigned char>(base64_chars.find(char_array_4[i]));

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = static_cast<unsigned char>(base64_chars.find(char_array_4[j]));

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}
//Written  by ms3c

 int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
    MessageBox ( NULL, "Hello World!", "Test", MB_OK );
    return 0;
}

int main() {

    string              secret_msg_ = "keep going you must find secret word";
    string              word;
	string              encoded = "RkxBR3t0enMzY3IzdGhhY2szcn0=";
	string              decoded       = encoded;

    decoded=base64_decode(encoded);

    cout<<              "Enter secret word: ";
    cin>>               word;
    unsigned long       x;
    string              secret_key = "aGFja2VybWFu=";
    string              decoded_key       = secret_key;
    string              secret_msg = "This is Easy";
                        if(word == base64_decode(secret_key)){
        cout<<"Flag is : "+  decoded<< endl;
        system("PAUSE");
    }else{
                        for(x = 0; x < 5; x++){
                                cout<<"Do-s0m3-r3v3rs1ng-";

                                MessageBox ( NULL, "d0 s0m3 r3v3rs1ng", "Hacker", MB_OK );
                        }

    }



    return 0;
}

//Written  by ms3c
