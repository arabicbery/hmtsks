#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, const char** argv) {

   //ex 6.1.
   // Написать программу, которая создаст два текстовых файла,
   // примерно по 50-100 символов в каждом (особого значения не имеет);

   string firFileDir = "firFile.txt";
   ofstream firstFile;

   firstFile.open(firFileDir);
   firstFile << "On Tuesday I have to take the fifth laboratory work" << endl;

   firstFile.close();

   string secFileDir = "secFile.txt";
   ofstream secondFile;

   secondFile.open(secFileDir);
   secondFile << "I'm not able to read the methodological instructions for laboratory work" << endl;

   secondFile.close();

   // ex 6.2
   // Написать функцию, «склеивающую» эти файлы, предварительно буферизуя
   // их содержимое в динамически выделенный сегмент памяти нужного размера.

   char *buffer = new char[150];

   ifstream fin;
   fin.open(firFileDir);

   ifstream fin2;
   fin2.open(secFileDir);

   ofstream f_out;
   f_out.open("File.txt");

   while (!fin.eof() && !fin2.eof()){
       fin.getline(buffer, 150);
       f_out << buffer << endl;
   }
   fin.close();

   while (!fin2.eof()){
       fin2.getline(buffer, 150);
       f_out << buffer << endl;
   }
   fin2.close();

   f_out.close();

   // ex 6.3
   // Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы
   // слово в указанном пользователем файле (для простоты работаем только с латиницей).

   ifstream fin3;
   fin3.open("File.txt");

   string message = "";

   while (!fin3.eof()){            // я понимаю, что он считает по символам, а не по словам :(
       message += fin3.get();      // не хватает мозгов, чтобы додумать правильную реализацию
   }

   int needMessage = message.find("ues");
   if (needMessage != -1) {

       cout << "There is" << endl;

   } else cout << "There is none" << endl;

   fin3.close();

   return 0;
}
