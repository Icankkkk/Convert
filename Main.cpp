#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// header:
void header(char &menu); // function header
void headerD(int &menuD, long int &nD); // function header decimal
void headerO(int &menuO, long int &nO); // function header octal
void headerH(); // function header hexadecimal 
void headerB(int &menuB, long int &nB); // function header binary
// converter
// void function:
void DecimalToOctal(int decimalNum);
void DecimalToHexa(int num);
void DecimalToBinary(int n);
void OctalToDecimal(int octalNum);
void BinaryToDecimal(int n);
void BinaryToHexa(long int num);
// return function:
int OctalToBinary(int octalNum);
int HexaToDec(char num[]);
long long int hex_to_bin(char hex[]) 
{ 
    long long int bin, place; 
    int i = 0, rem, val; 
  
    bin = 0ll; 
    place = 0ll; 
  
    // Hexadecimal to binary conversion 
    for (i = 0; hex[i] != '\0'; i++) { 
        bin = bin * place; 
  
        switch (hex[i]) { 
        case '0': 
            bin += 0; 
            break; 
        case '1': 
            bin += 1; 
            break; 
        case '2': 
            bin += 10; 
            break; 
        case '3': 
            bin += 11; 
            break; 
        case '4': 
            bin += 100; 
            break; 
        case '5': 
            bin += 101; 
            break; 
        case '6': 
            bin += 110; 
            break; 
        case '7': 
            bin += 111; 
            break; 
        case '8': 
            bin += 1000; 
            break; 
        case '9': 
            bin += 1001; 
            break; 
        case 'a': 
        case 'A': 
            bin += 1010; 
            break; 
        case 'b': 
        case 'B': 
            bin += 1011; 
            break; 
        case 'c': 
        case 'C': 
            bin += 1100; 
            break; 
        case 'd': 
        case 'D': 
            bin += 1101; 
            break; 
        case 'e': 
        case 'E': 
            bin += 1110; 
            break; 
        case 'f': 
        case 'F': 
            bin += 1111; 
            break; 
        default: 
            cout << "Invalid hexadecimal input."; 
        } 
  
        place = 10000; 
    } 
  
    return bin; 
} 
  
// Function to convert Binary to Octal 
long long int bin_to_oct(long long bin) 
{ 
    long long int octal, place; 
    int i = 0, rem, val; 
  
    octal = 0ll; 
    place = 0ll; 
  
    place = 1; 
  
    // Binary to octal conversion 
    while (bin > 0) { 
        rem = bin % 1000; 
  
        switch (rem) { 
        case 0: 
            val = 0; 
            break; 
        case 1: 
            val = 1; 
            break; 
        case 10: 
            val = 2; 
            break; 
        case 11: 
            val = 3; 
            break; 
        case 100: 
            val = 4; 
            break; 
        case 101: 
            val = 5; 
            break; 
        case 110: 
            val = 6; 
            break; 
        case 111: 
            val = 7; 
            break; 
        } 
  
        octal = (val * place) + octal; 
        bin /= 1000; 
  
        place *= 10; 
    } 
  
    return octal; 
} 
  
// Function to Convert 
// Hexadecimal Number to Octal Number 
long long int hex_to_oct(char hex[]) 
{ 
    long long int octal, bin; 
  
    // convert HexaDecimal to Binary 
    bin = hex_to_bin(hex); 
  
    // convert Binary to Octal 
    octal = bin_to_oct(bin); 
  
    return octal; 
} 

// alert:
void alert();
void alertOct();
void alertHec();
void alertUlg(char &ulg);
// proses

int main(int argc, char const *argv[])
{
    char menu, ulg;
    int menu2;
    long n;
    do{
        header(menu); // call function header (void)
        switch (menu)
        {
        case 'd':
        do{
            headerD(menu2, n); // call function header decimal (void)
            switch (menu2)
            {
            case 1:
            DecimalToOctal(n); // call function Decimal-octal
                break;
            case 2:
            DecimalToHexa(n); // call function Decimal-hexa
                break;
            case 3:
            DecimalToBinary(n);
                break; 
            default:
            alert(); // call function alert if false
                break;
            }
            alertUlg(ulg);
        }while(ulg == 'y' || ulg == 'Y'); // perulangan untuk menu desimal
            break;
        case 'o':
        do{
            headerO(menu2, n); // call function header octal (void)
            switch (menu2)
            {
            case 1:
            OctalToDecimal(n); 
                break;
            case 2:
            alertOct(); // call alert
                break;
            case 3:
            cout << "Hasil convert dari " << n << " = " << OctalToBinary(n) << endl;
                break;
            default:
            alert(); // call function alert if false
                break;
            }
            alertUlg(ulg);
        }while(ulg == 'y' || ulg == 'Y'); // perulangan untuk ke menu octal
            break;
        case 'h':
        do{
            char num[100];
            headerH(); // call function header hexadecimal (void)
            cin.ignore();
            alertHec();
            cout << "Inputkan bilangan hexadecimal > "; cin.getline(num,100);
            cout << "Masukan pilihan [1/2/3] > "; cin >> menu2;
            switch (menu2)
            {
            case 1:
            cout << "Hasil convert dari " << num << " = " << HexaToDec(num) << endl;
                break;
            case 2:
            cout << "Hasil convert dari " << num << " = " << hex_to_oct(num) << endl;
                break;
            case 3:
            cout << "Hasil convert dari " << num << " = " << hex_to_bin(num) << endl;
                break;
            default:
            alert(); // call function alert
                break;
            }
            cout << "\ningin mengulang ke menu hexadecimal y/n ? "; cin >> ulg;
        }while(ulg == 'y' || ulg == 'Y');
            break;
        case 'b':
        do{
            headerB(menu2, n);// call function header binary (void)
            switch (menu2)
            {
            case 1:
            BinaryToDecimal(n);
                break;
            case 2:
            BinaryToHexa(n);
                break;
            case 3:
            cout << "Hasil convert dari binary " << n << " = " << bin_to_oct(n) << endl;
                break;
            default:
            alert();
                break;
            }
            alertUlg(ulg);
        }while(ulg == 'y' || ulg == 'Y');
            break;
        default:
            cout << "\nPilihan tidak tersedia\n";
            break;
        }
        cout << "ingin kembali ke menu awal y/n ? "; cin >> ulg;
        system("clear"); // clear screen
    }while(ulg == 'y' || ulg == 'Y'); // perulangan untuk ke menu awal

    return 0;
}
// prototype
// HEADER
void header(char &menu) {
    cout << "\n   C O N V E R T - T O O L S\n"
         << "__________by : icank__________\n\n"
         << "[d] Decimal\n"
         << "[o] Octal\n"
         << "[h] Hexadecimal\n"
         << "[b] Binary\n\n"
         << "Masukan pilihan [d/o/h/b] > "; cin >> menu;
}
// header decimal menu
void headerD(int &menuD, long int &nD) {
    cout << "\n   D E C I M A L - M E N U\n"
         << "_____________________________\n\n"
         << "1. Decimal to octal\n"
         << "2. Decimal to hexadecimal\n"
         << "3. Decimal to binary\n\n"
         << "Inputkan bilangan desimal > "; cin >> nD;
    cout << "Masukan pilihan [1/2/3] > "; cin >> menuD;
}
// header octal menu
void headerO(int &menuO, long int &nO) {
    cout << "\n   O C T A L - M E N U\n"
         << "_____________________________\n\n"
         << "1. Octal to decimal\n"
         << "2. Octal to hexadecimal\n"
         << "3. Octal to binary\n\n"
         << "Inputkan bilangan octal > "; cin >> nO;
    cout << "Masukan pilihan [1/2/3] > "; cin >> menuO;
}
// header hexadecimal menu
void headerH() {
    cout << "\n   H E X A - M E N U\n"
         << "_____________________________\n\n"
         << "1. Hexadecimal to decimal\n"
         << "2. Hexadecimal to octal\n"
         << "3. Hexadecimal to binary\n\n";
}
// header binary menu
void headerB(int &menuB, long int &nB) {
    cout << "\n   B I N A R Y - M E N U\n"
         << "_____________________________\n\n"
         << "1. Binary to decimal\n"
         << "2. Binary to hexadecimal\n"
         << "3. Binary to octal\n\n"
         << "Inputkan bilangan binary > "; cin >> nB;
    cout << "Masukan pilihan [1/2/3] > "; cin >> menuB;
}
// function converter
// convert decimal to octal
void DecimalToOctal(int decimalNum) {
   int octalNum = 0, placeValue = 1;
   int dNo = decimalNum;
   while (decimalNum != 0) {
      octalNum += (decimalNum % 8) * placeValue;
      decimalNum /= 8;
      placeValue *= 10;
   }
   cout<<"Hasil convert dari decimal " << dNo << " = " << octalNum << endl;
}
//convert decimal to hexadecimal
void DecimalToHexa(int num) {
   char arr[100];
   int i = 0;
   int dHx = num;
   while(num!=0) {
      int temp = 0;
      temp = num % 16;
      if(temp < 10) {
         arr[i] = temp + 48;
         i++;
      } else {
         arr[i] = temp + 55;
         i++;
      }
      num = num/16;
   }
   cout << "Hasil convert dari decimal " << dHx << " = ";
   for(int j=i-1; j>=0; j--) {
   cout << arr[j];
   }
   cout << endl;
}
// convert decimal to binary
void DecimalToBinary(int n) {
   int binaryNumber[100], num=n;
   int i = 0;
   while (n > 0) {
      binaryNumber[i] = n % 2;
      n = n / 2;
      i++;
   }
   cout<<"Hasil convert dari decimal " << num << " = ";
   for (int j = i - 1; j >= 0; j--)
   cout << binaryNumber[j];
   cout<<endl;
}
// convert octal to decimal
void OctalToDecimal(int octalNum) {
   int decimalNum = 0, power = 0;
   int oNo = octalNum;
   while(octalNum != 0) {
      decimalNum += (octalNum%10) * pow(8,power);
      ++power;
      octalNum/=10;
   }
   cout<<"Hasil convert dari octal " << oNo << " = " << decimalNum << endl;
}
// convert octal to binary
int OctalToBinary(int octalNum) {
   int decimalNum = 0, binaryNum = 0, count = 0;

   while(octalNum != 0) {
      decimalNum += (octalNum%10) * pow(8,count);
      ++count;
      octalNum/=10;
   }
   count = 1;
   while (decimalNum != 0) {
      binaryNum += (decimalNum % 2) * count;
      decimalNum /= 2;
      count *= 10;
   }
   return binaryNum;
}
//convert hexadecimal to decimal
int HexaToDec(char num[]) {
   int len = strlen(num);
   int base = 1;
   int temp = 0;
   for (int i=len-1; i>=0; i--) {
      if (num[i]>='0' && num[i]<='9') {
         temp += (num[i] - 48)*base;
         base = base * 16;
      }
      else if (num[i]>='A' && num[i]<='F') {
         temp += (num[i] - 55)*base;
         base = base*16;
      }
   }
   return temp;
}
// convert binary to decimal
void BinaryToDecimal(int n) {
   int decimalNumber = 0;
   int base = 1;
   int temp = n;
   while (temp) {
      int lastDigit = temp % 10;
      temp = temp/10;
      decimalNumber += lastDigit*base;
      base = base*2;
   }
   cout << "Hasil convert dari binary " << n << " = " << decimalNumber << endl;
}
// convert binary to hexa
void BinaryToHexa(long int num)
{
    int i,temp=0,hexa[20],rem;
    cout << "Hasil convert dari binary " << num << " = ";
    for(i=0;num>0;i++)
    {
        for(int y=0;y<4;y++)
        {
             rem = num % 10;
             num /= 10;
             temp += rem * pow(2,y);
       }
       hexa[i]=temp;
       temp=0;
    }
    while(i>0)
    {
        i--;
        if(hexa[i] > 9)
            cout << char(55 + hexa[i]);
        else
            cout << hexa[i];
    }
    cout << endl;
}
// alert
void alert() {
    cout << "Pilihan tidak tersedia\n";
}
void alertOct() {
    cout << "Maaf pilihan yang anda pilih saat ini sedang\n"
         << "Sedang dalam proses pengembangan.\n";
}
void alertHec() {
    cout << "Note: gunakan kapital untuk huruf, contoh: 3F456A\n\n";
}
void alertUlg(char &ulg) {
      cout << "\ningin mengulang y/n ? "; cin >> ulg;
}

